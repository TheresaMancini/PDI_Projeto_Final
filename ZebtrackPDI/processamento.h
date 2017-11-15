#ifndef PROCESS_H
#define PROCESS_H
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
using namespace std;

class Process
{
public:
    Process();
    cv::Mat find_contours(cv::Mat fore);
    void dilatErosion(cv::Mat &fore);
//    void calculaForeground(cv::Mat &frame, cv::Mat &fundo,int th, bool cor,bool media,cv::Mat var_pb, cv::Mat var_cor, cv::Mat foreground);
    int associate(cv::Point2f posicao_ant,vector<vector<cv::Point> > contours,int max);
    void find(cv::Mat fore,cv::Mat drawing,int framesps,int nframe);
    void displaygraph(int cols,int rows);


private:
    vector<cv::Point2f> cm;
    vector<cv::Point2f> posicao;
    cv::Point2f posicaotmp;
    vector<float> tempo;
    cv::Rect ultimobounding;
    int fps;
    float time;
    //Mat fore;

};

#endif // PROCESS_H
