#include "zebtrackpdi.h"
#include "ui_zebtrackpdi.h"
#include "labeltrack.h"
#include <QtGui>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <processamento.h>
#include <windows.h>
using namespace std;
using namespace cv;

ZebtrackPDI::ZebtrackPDI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ZebtrackPDI)
{
    ui->setupUi(this);
    connect(ui->figura,SIGNAL(mudou_tamanho()),this,SLOT(mudaram_tamanho()));
}

ZebtrackPDI::~ZebtrackPDI()
{
    delete ui;
}
void ZebtrackPDI::popup(QString String){
    QMessageBox msgBox;
    msgBox.setText(String);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Ok:
          break;
      default:
          break;
    }
}
void ZebtrackPDI::calcframes(){
    maxframe=(video.get(CV_CAP_PROP_FRAME_COUNT)-1); // get number of frames
    fps=video.get(CV_CAP_PROP_FPS);
    ui->Slider_Inicial->setRange(0,maxframe-1);
    ui->Slider_Final->setRange(0,maxframe);
}
QImage ZebtrackPDI::mat2qimage(cv::Mat mat) {
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }

}

void ZebtrackPDI::tinicial(VideoCapture& vid, int num, Mat& image){
    frame_ini=num;

    vid.set(CV_CAP_PROP_POS_FRAMES,num);

    vid.read(image);
}
void ZebtrackPDI::tfinal(VideoCapture& vid, int num, Mat& image){
    frame_fim=num;

    vid.set(CV_CAP_PROP_POS_FRAMES,num);

    vid.read(image);
}
void ZebtrackPDI::setimage(Mat& image){
    Mat fundon;
    if(image.type()==CV_32FC1){
        image.convertTo(fundon,CV_8UC1);
    }
    else
        image.convertTo(fundon,CV_8UC3);
    // resize the label to keep aspect ratio
   wim = fundon.cols;
   him = fundon.rows;
   wlabel = ui->figura->width();
   hlabel = ui->figura->height();
   if(wim>him){
       ui->figura->resize(wlabel,int(floor(wlabel*him/wim)));

   }else{

        ui->figura->resize(int(floor(hlabel*wim/him)),hlabel);
   }
   // display on label

    ui->figura->setPixmap(QPixmap::fromImage(mat2qimage(fundon)));

}
///ainda não botei esses labels
/*
void ZebtrackPDI::set_image_inicial(Mat& image){
    // resize the label to keep aspect ratio
    Size size(100,100);//the dst image size,e.g.100x100
    Mat dst;//dst image
    cv::resize(image,dst,size);

    ui->frame_inicial->setPixmap(QPixmap::fromImage(mat2qimage(dst)));
}
void ZebtrackPDI::set_image_final(Mat& image){
    Size size(100,100);//the dst image size,e.g.100x100
    Mat dst;//dst image
    cv::resize(image,dst,size);

    ui->frame_final->setPixmap(QPixmap::fromImage(mat2qimage(dst)));
}
*/


void ZebtrackPDI::on_Abrir_Video_clicked()
{

    QString nombre= QFileDialog::getOpenFileName();
        QFile file(nombre);
        if(!file.open(QIODevice::ReadOnly)){
                    QMessageBox::critical(this, tr("Error"),
                            tr("Could not open file"));
            return;
        }
    VideoCapture vid(nombre.toStdString());

    video=vid;

   calcframes();
   tinicial(vid,0,image);
  // set_image_inicial(image);
   tfinal(vid,maxframe,image);
  // set_image_final(image);
   calcfundo(vid,image,60);
   setimage(image);

   ui->Slider_Inicial->setValue(0);
   ui->T_inicial->setText(s= QString::number(0));
   ui->Slider_Final->setValue(maxframe);
   ui->T_final->setText(s = QString::number(maxframe));
   ui->sampleRate->setValue(int(maxframe/120));
   ui->sampleRate->setMinimum(1);
   ui->sampleRate->setMaximum(maxframe-2);
   ui->threshold->setValue(8);
   ui->processRate->setValue(1);
   ui->mostraFore->setCheckState(Qt::Unchecked);
   ui->Estatistico->setCheckState(Qt::Unchecked);
     mostrafore=false;
}

void ZebtrackPDI::calcfundo(cv::VideoCapture& vid, Mat& backgpb, int frameSkip){
///calculando fundo pela média
    Mat I,Ipb,variancepb,sumpb,sqsumpb;
    int image_count=0;
    int j=frame_ini;
    while(j<frame_fim){
        vid.set(CV_CAP_PROP_POS_FRAMES,j);
        vid.read(I);
        I.convertTo(Ipb,CV_8UC3);
        cv::cvtColor(Ipb,Ipb,CV_BGR2GRAY);

        if( sumpb.empty() ) {
            sumpb = Mat::zeros( Ipb.size(),  CV_32FC(Ipb.channels()) );
            sqsumpb = cv::Mat::zeros( Ipb.size(), CV_32FC(Ipb.channels()) );
            backgpb = cv::Mat::zeros( Ipb.size(), CV_32FC(Ipb.channels()) );
//            frameprev = Ipb;
        }
        cv::accumulate(Ipb,sumpb);
        cv::accumulateSquare(Ipb,sqsumpb);
        image_count++;
        j=j+frameSkip;
    }

    ///media
    backgpb=sumpb/image_count; ///fundo_m_pb
    fundo_m_pb=backgpb;

    ///variancia
    double one_by_N= 1.0/image_count;
    variancepb = one_by_N*sqsumpb-(one_by_N*one_by_N)*sumpb.mul(sumpb);
    var_pb=variancepb;
    cv::pow(var_pb,0.5,var_pb);
    for(int i=0;i<var_pb.rows;i++){
        for(int j=0;j<var_pb.cols;j++){
            if ((var_pb.at<float>(i,j))<0.5)
                var_pb.at<float>(i,j)=0.5;
        }
    }

    String="Fundo Calculado!";
    popup(String);
    background=fundo_m_pb;
}

Mat ZebtrackPDI::calculaForeground(cv::Mat &frame, cv::Mat &fundo){ /// calcula a diferença entre o fundo e o frame atual
////ok
    Mat auxFrame, auxFundo, auxFore, foreGray, foreground;
    frame.convertTo(auxFrame, CV_8UC3);
        fundo.convertTo(auxFundo, CV_32FC1);
        cv::cvtColor(auxFrame,auxFrame,CV_BGR2GRAY);
        auxFrame.convertTo(auxFrame,CV_32FC1);
        absdiff(auxFundo,auxFrame,auxFore);

        blur (auxFore,foreGray,Size(3,3));
        // apply threshold to foreground image
        if(!media){
            Mat Ilow;
            var_pb.convertTo(var_pb, CV_32FC1);
//            QTextStream out(stdout);

            Ilow=auxFundo-((var_pb)*th);
            Mat Ihi=auxFundo+((var_pb)*th);
            cv::inRange(auxFrame,Ilow,Ihi,foreground);
            foreground=255-foreground;
        }
        else if(media){
              threshold(foreGray,foreground,th,255,0);
        }

    return foreground;

}



void ZebtrackPDI::on_Estatistico_clicked()
{
    if(ui->figura->pixmap()==0){
            ui->Estatistico->setChecked(false);
    }
    else{
        if(ui->Estatistico->isChecked()==true)
            media=false;
        else
            media=true;
    }

}

void ZebtrackPDI::mudaram_tamanho(){
    wlabel = ui->figura->width();
    hlabel = ui->figura->height();
    if(wim>him){
        ui->figura->resize(wlabel,int(floor(wlabel*him/wim)));

    }else{
       ui->figura->resize(int(floor(hlabel*wim/him)),hlabel);
    }
}


void ZebtrackPDI::on_Slider_Inicial_valueChanged(int value)
{
    if (ui->figura->pixmap()==0){

    }
    else if(value>=maxframe){
            ui->Slider_Inicial->setValue(maxframe-1);
            ui->T_inicial->setText (s = QString::number(maxframe-1));
            tinicial(video,(maxframe-1),image);
            //set_image_inicial(image);
    }
        else{
            ui->T_inicial->setText (s = QString::number(value));
            tinicial(video,value,image);
            //set_image_inicial(image);
            if(frame_fim<frame_ini){
                ui->Slider_Final->setValue(frame_ini+1);
                ui->T_final->setText(QString::number(frame_ini+1));
                frame_fim=frame_ini+1;
            }
        }
}


void ZebtrackPDI::on_Slider_Final_valueChanged(int value)
{
    if (ui->figura->pixmap()==0){

    }
    else if (frame_ini<value){
        ui->T_final->setText (s = QString::number(value));
        frame_fim=value;
        tfinal(video,value,image);
        //set_image_final(image);
    }
    else{
        ui->Slider_Final->setValue(frame_ini+1);
        ui->T_final->setText(QString::number(frame_ini+1));
        frame_fim=frame_ini+1;
        tfinal(video,frame_fim,image);
        //set_image_final(image);
    }
}


void ZebtrackPDI::on_back_frame_clicked()
{
    if(ui->figura->pixmap()==0){
        String="Video não selecionado";
        popup(String);
    }
    else if((video.get(CV_CAP_PROP_POS_FRAMES)-2)==0){
        String="Início do Vídeo";
        popup(String);
    }
    else{
    video.set(CV_CAP_PROP_POS_FRAMES,(video.get(CV_CAP_PROP_POS_FRAMES)-2));
    video>>image;
    setimage(image);
    }
}



void ZebtrackPDI::on_next_frame_clicked()
{
    if (ui->figura->pixmap()==0){
        String="Video não selecionado";
        popup(String);
    }
    else if(video.get(CV_CAP_PROP_POS_FRAMES) == video.get(CV_CAP_PROP_FRAME_COUNT)){
        String="Fim do Video";
        popup(String);
    }
    else{
    video>>image;
    setimage(image);
    }
}


void ZebtrackPDI::on_Novo_Fundo_clicked()
{
    if(video.isOpened()==true){
        calcfundo(video,image,skip);
        setimage(image);
   }
}


void ZebtrackPDI::on_sampleRate_valueChanged(int arg1)
{
    skip=arg1;
}



void ZebtrackPDI::on_threshold_valueChanged(int arg1)
{
    th=arg1;
}



void ZebtrackPDI::on_init_process_clicked()
{
    pause=false;
   ui->pause_process->setText("Pausar");
   frameatual=0;
   passar_video(frameatual);
}

void ZebtrackPDI::passar_video(int &atual){
    if(ui->figura->pixmap()==0){
     String="Não há video aberto";
     popup(String);
    }
    else{
        QTextStream out(stdout);
        out << "inicio"<< endl;
        int i=atual;
        video.set(CV_CAP_PROP_POS_FRAMES,i);
        while(!pause&&i<=maxframe){
            Mat fore;
            Mat drawing = Mat::zeros( fore.size(), CV_8UC3 );
            video>>image;
            drawing = image.clone(); //testar assim
            drawing.convertTo(drawing,CV_8UC3); //testar assim
            fore=calculaForeground(image,background);
            Mat foresc=fore.clone();
            processar.dilatErosion(fore);
            int nframe;
            nframe = video.get(CV_CAP_PROP_POS_FRAMES)-1;
            processar.find(foresc,drawing,fps,nframe);
            //setimage(drawing);
            if (mostrafore == true){
               setimage(foresc);
            }
            else
                 setimage(drawing);
            QCoreApplication::processEvents();
            i=i+rate;
//            out  << "i= "<< i <<endl;
            video.set(CV_CAP_PROP_POS_FRAMES,i);
        }
    }
}

void ZebtrackPDI::on_pause_process_clicked()
{
    if(!pause){
        pause=!pause;
        frameatual=(video.get(CV_CAP_PROP_POS_FRAMES)-1);
        ui->pause_process->setText("Continuar");
    }
    else{
        pause=!pause;
        ui->pause_process->setText("Pausar");
        passar_video(frameatual);
    }
}



void ZebtrackPDI::on_back_process_clicked()
{
    if(ui->figura->pixmap()==0){
        String="Video não selecionado";
        popup(String);
    }
    else if((video.get(CV_CAP_PROP_POS_FRAMES)-(rate+1))==0){
        String="Início do Vídeo";
        popup(String);
    }
    else{
    video.set(CV_CAP_PROP_POS_FRAMES,(video.get(CV_CAP_PROP_POS_FRAMES)-(rate+1)));
    video>>image;
    Mat fore=calculaForeground(image,background);
    Mat drawing = Mat::zeros( fore.size(), CV_8UC3 );
    drawing = image.clone();
    drawing.convertTo(drawing,CV_8UC3);
    setimage(drawing);
    processar.dilatErosion(fore);
    int nframe;
    nframe = video.get(CV_CAP_PROP_POS_FRAMES)-1;
    processar.find(fore,drawing,fps,nframe);;
    setimage(drawing);
    }


}

void ZebtrackPDI::on_next_process_clicked()
{
    if (ui->figura->pixmap()==0){
        String="Video não selecionado";
        popup(String);
    }
    else if(video.get(CV_CAP_PROP_POS_FRAMES) == video.get(CV_CAP_PROP_FRAME_COUNT)){
        String="Fim do Video";
        popup(String);
    }
    else{
    video.set(CV_CAP_PROP_POS_FRAMES,(video.get(CV_CAP_PROP_POS_FRAMES)+rate));
    video>>image;
    Mat fore=calculaForeground(image,background);
    Mat drawing = Mat::zeros( fore.size(), CV_8UC3 );
    drawing = image.clone();
    drawing.convertTo(drawing,CV_8UC3);
    setimage(drawing);
    processar.dilatErosion(fore);
    int nframe;
    nframe = video.get(CV_CAP_PROP_POS_FRAMES)-1;
    processar.find(fore,drawing,fps,nframe);
    setimage(drawing);
    }
}


void ZebtrackPDI::on_processRate_valueChanged(int arg1)
{
    rate=arg1;
}

void ZebtrackPDI::on_mostraFore_clicked()
{
    if (ui->figura->pixmap()==0){
        String="Video não selecionado";
        popup(String);
    }
    else{
        if (ui->mostraFore->isChecked()==true)
                mostrafore=true;
        else{
            mostrafore=false;
        }
   }
}

void ZebtrackPDI::on_gerar_graficos_clicked()
{
    processar.displaygraph(background.cols,background.rows);
}
