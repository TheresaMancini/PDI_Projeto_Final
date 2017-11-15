#include "processamento.h"
#include <QTextStream>

using namespace cv;
using namespace std;

Process::Process()
{


}

void Process::dilatErosion(Mat &fore){
//   Mat Kernel= getStructuringElement(cv::MORPH_RECT,cv::Size(5),cv::Point(-1,-1));
   int morph_size=3;
   Mat element = getStructuringElement( MORPH_RECT, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
   erode(fore,fore,cv::Mat());
//   dilate(fore,fore,element);
   dilate(fore,fore,cv::Mat());
}
int Process::associate(Point2f posicao_ant, vector<vector<Point> > contours,int max){
    //percorrer os contornos achar o mais próximo de pocisao_ant
   int indice;
   int min=3;
   Point2f cmtmp;
   vector<Moments> mu(contours.size());
   double res,nres;
   double xDiff ;//= posicaotmp.x - cmtmp.x;
   double yDiff ;//= posicaotmp.y - cmtmp.y;
   QTextStream out(stdout);
       mu[0] = moments( contours[0], false);
       cmtmp=Point2f(mu[0].m10/mu[0].m00, mu[0].m01/mu[0].m00);
       xDiff = posicaotmp.x - cmtmp.x;
       yDiff = posicaotmp.y - cmtmp.y;
       indice=0;
       res=sqrt((xDiff * xDiff) + (yDiff * yDiff));
     for( int i = 1; i < contours.size(); i++){
          mu[i] = moments( contours[i], false);
          if(mu[i].m00 > min && mu[i].m00 <= max ){
                cmtmp=Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
                xDiff = posicao_ant.x - cmtmp.x;
                yDiff = posicao_ant.y - cmtmp.y;
                nres=sqrt((xDiff * xDiff) + (yDiff * yDiff));
                if(nres<res)
                    indice=i;
//                out <<"indice do associate" << indice << endl;
           }
     }

    return indice; //retorna indice i do contours mais próximo.

}

void Process::displaygraph(int cols, int rows){
    if(cols!=0){
        Mat myimage = Mat::zeros(rows,cols, CV_8UC3);
        if (posicao.size()>0){
            int myradius=5;
            for (int i=0;i<posicao.size();i++)
                circle(myimage,cvPoint(posicao[i].x,posicao[i].y),myradius,CV_RGB(100,0,0),-1,8,0);
        }
        namedWindow("myimage",WINDOW_AUTOSIZE);
        imshow("myimage",myimage);
    }
}

void Process::find(Mat fore,Mat drawing,int framesps,int nframe,bool novo){
    Mat contorno;
    vector<vector<cv::Point> > contours;
//    vector<Point2f> cm;
//    vector<Point2i> posicao;
//    vector<float> tempo;
    vector<Vec4i> hierarchy;
    int max=80;
    Scalar color2 = Scalar( 0,255,0  );
    Scalar color = Scalar( 255,255,255);
    int bloob;
    fore.convertTo(contorno,CV_8UC1);
    fps=framesps;
    findContours( contorno, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) ); 

    vector<vector<Point> > contours_poly( contours.size() );
    vector<Moments> mu(contours.size());
    if(novo==true)
        posicao.clear();

    if (posicao.empty()==true){
        posicaotmp.x=fore.cols/2;
        posicaotmp.y=fore.rows/2;
    }

    if(contours.size() > 0){
        bloob=associate(posicaotmp,contours,max);
        mu[bloob] = moments( contours[bloob], false);
        if (mu[bloob].m00>3){
            posicaotmp=( Point2f(mu[bloob].m10/mu[bloob].m00, mu[bloob].m01/mu[bloob].m00));
            //cm.push_back(posicaotmp);
            posicao.push_back(posicaotmp);
            time=(float)nframe/(float)fps;
            tempo.push_back(time);
            approxPolyDP( Mat(contours[bloob]), contours_poly[bloob], 3, true );
            //boundRect.push_back(boundingRect( Mat(contours_poly[bloob]) ));
           Rect rec= boundingRect( Mat(contours_poly[bloob])) ;
           ultimobounding=rec;

            //minEnclosingCircle( (Mat)contours_poly[bloob], center[bloob], radius[bloob] );
            rectangle( fore, rec.tl(), rec.br(), color, 2, 8, 0 );
            rectangle( drawing, rec.tl(), rec.br(), color2, 2, 8, 0 );
        }

    }
    else{
//        out << "Não achou " <<endl;
       // cm.push_back(posicaotmp);
        posicao.push_back(posicaotmp);
//        out << posicaotmp.x << " " <<posicaotmp.y << endl;
        time= time+1.0/(float)fps;
        tempo.push_back(time);
        rectangle( fore, ultimobounding.tl(), ultimobounding.br(), color, 2, 8, 0 );
        rectangle( drawing,  ultimobounding.tl(), ultimobounding.br(), color2, 2, 8, 0 );

    }
//    if (posicao.size()>0){
//        Mat myimage = Mat::zeros(fore.size(), CV_8UC3);
//        int myradius=5;
//        for (int i=0;i<posicao.size();i++)
//            circle(myimage,cvPoint(posicao[i].x,posicao[i].y),myradius,CV_RGB(100,0,0),-1,8,0);
//        namedWindow("myimage",WINDOW_AUTOSIZE);
//        imshow("myimage",myimage);
//    }
    /*if(contours.size() > 0)
    {

//        bloob=associate(posicao,contours,1);
//        mu[bloob] = moments( contours[bloob], false);
//        cm.push_back( Point2f(mu[bloob].m10/mu[bloob].m00, mu[bloob].m01/mu[bloob].m00));
//        approxPolyDP( Mat(contours[bloob]), contours_poly[bloob], 3, true );
//        boundRect.push_back(boundingRect( Mat(contours_poly[bloob]) ));
//        minEnclosingCircle( (Mat)contours_poly[bloob], center[bloob], radius[bloob] );
//        rectangle( fore, boundRect[bloob].tl(), boundRect[bloob].br(), color, 2, 8, 0 ); // Desenha retângulo nos blobs
//        rectangle( drawing, boundRect[bloob].tl(), boundRect[bloob].br(), color2, 2, 8, 0 );
            /// saiu do associate calcula o boundingRect do contorno e o cm.

       // no else o peixe mantem no mesmo ponto anterior e o boundingbox igual


        /// Approximate contours to polygons + get bounding rects and circles
        vector<vector<Point> > contours_poly( contours.size() );
        vector<Rect> boundRect(contours.size());
//        boundRect.resize(contours.size()); se declarado como parametro da função usar esse aqui
        vector<Point2f>center( contours.size() );
        vector<float>radius( contours.size() );
        vector<Moments> mu(contours.size());

//        cout << "::: Area total da imagem = " << imgSeguimentada.cols * imgSeguimentada.rows << " ::: " << endl << endl;

        for( int i = 0; i < contours.size(); i++)
        {

            approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
            boundRect[i] = boundingRect( Mat(contours_poly[i]) );
            boundRect.push_back(boundingRect( Mat(contours_poly[i]) )); ///TESTAR SE O BOUND TA SALVANDO MESMO


            minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
            mu[i] = moments( contours[i], false);

//            out << "--- Area do blob: " << mu[i].m00 << endl;

            if(mu[i].m00 > 5 && mu[i].m00 <= (fore.cols*fore.rows)/2 ){
//                nbarcosAchados++;
//                fore.convertTo(fore,CV_8UC3);
                Scalar color2 = Scalar( 0,255,0  );
                Scalar color = Scalar( 255,255,255  ); //Cor do retângulo Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) )//
//                circle(fore,Point(100,100),70,Scalar(0,0,0),5,8,0);
                rectangle( fore, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 ); // Desenha retângulo nos blobs
                rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color2, 2, 8, 0 );
//                vector<Point2f> cm;
                cm.push_back( Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00)); // Calculando centro de massa

                ///comparar se é mais proximo o cm e se do tamanho certo.

//                out << "Centro de massa: " << cm[i].x << " " << cm[i].y << endl;
//                out << endl << endl;

//                int cantosuperiorleftx=boundRect[i].tl().x;
//                int cantosuperiorlefty=boundRect[i].tl().y;
//                int cantoinferiorrightx=boundRect[i].br().x;
//                int cantoinferiorrighty=boundRect[i].br().y;


//                centrox = boundRect[i].tl().x + tamx/2;//Centro dos retângulos
//                centroy = boundRect[i].tl().y + tamy/2;

//                Mat imgCortada(imgORG, Rect(boundRect[i].tl().x, boundRect[i].tl().y, tamx, tamy) );
                //mostraimagem("Cortada", imgCortada);
                //sprintf(nome, "0%d.jpeg", i + 27);
                //imwrite(nome, imgCortada);

//                line(imgORG, {(centrox - 3), (centroy - 3)} , {(centrox + 3), (centroy + 3)}, color, 2, CV_AA, 0); //Desenha X nos centros
//                line(imgORG, {(centrox - 3), (centroy + 3)} , {(centrox + 3), (centroy - 3)}, color, 2, CV_AA, 0); //dos retângulos
            }
        }
    }*/
}
