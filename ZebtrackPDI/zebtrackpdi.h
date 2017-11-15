#ifndef ZEBTRACKPDI_H
#define ZEBTRACKPDI_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <processamento.h>

namespace Ui {
class ZebtrackPDI;
}

class ZebtrackPDI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZebtrackPDI(QWidget *parent = 0);
    ~ZebtrackPDI();
    QImage mat2qimage(cv::Mat mat);
        void calcfundo(cv::VideoCapture& vid, cv::Mat& image, int frameSkip);
        void tinicial(cv::VideoCapture& vid, int num,cv:: Mat& image);
        void tfinal(cv::VideoCapture& vid, int num,cv:: Mat& image);
        void setimage(cv::Mat& image);
        void calcframes();
        void popup(QString String);
        void set_image_inicial(cv::Mat& image);
        void set_image_final(cv::Mat& image);
        void passar_video(int &atual);
        cv::Mat calculaForeground(cv::Mat &frame, cv::Mat &fundo);
        bool excluiu=false;
        char area;
        QPolygon inter,process,exclus;
        std::vector<QPolygon> areas_inter, areas_exclus;
        Process processar;

private slots:

        void mudaram_tamanho();

        void on_Abrir_Video_clicked();

        void on_Estatistico_clicked(bool checked);

        void on_Estatistico_clicked();

        void on_Slider_Inicial_valueChanged(int value);

        void on_Slider_Final_valueChanged(int value);

        void on_back_frame_clicked();

        void on_next_frame_clicked();

        void on_Novo_Fundo_clicked();

        void on_sampleRate_valueChanged(int arg1);

        void on_threshold_valueChanged(int arg1);

        void on_init_process_clicked();

        void on_pause_process_clicked();

        void on_back_process_clicked();

        void on_next_process_clicked();

        void on_processRate_valueChanged(int arg1);

        void on_mostraFore_clicked();

        void on_gerar_graficos_clicked();

private:
    Ui::ZebtrackPDI *ui;
    QString s,String;
       cv::VideoCapture video;
       cv::Mat image, d, fundo_m_pb, var_pb, background;
       int wim, him, wlabel, hlabel,frame_ini,frame_fim,maxframe,skip,th,frameatual=0,rate,fps;
       bool pause=false,media=true,mostrafore=false;
};

#endif // ZEBTRACKPDI_H
