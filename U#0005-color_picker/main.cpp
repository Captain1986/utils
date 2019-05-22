#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

Mat img;

//ofstream outfile("color.txt");

void on_mouse(int event, int x, int y, int flags, void* param)
{
  switch(event)
    {
      case CV_EVENT_LBUTTONDOWN:
        {
          IplImage temp = (IplImage)img;
          Scalar color = cvGet2D(&temp, y, x);
          printf("Point(%d,%d)--> B[%d], G[%d], R[%d]\n", x, y, (int)color.val[0], (int)color.val[1], (int)color.val[2]);
          //outfile<<"cv::"<<"Point2f"<<"("<<x<<", "<<y<<")"<<", "<<endl;
        }
        break;
    }
}


int main(int agrc, char** agrv)
{
  img = imread(agrv[1]);

  if(img.empty()) {
     cout<<"No image"<<endl;
     return -1;
  }

  imshow("Image", img);

  setMouseCallback("Image", on_mouse, 0);

  waitKey(0);

  return 0;
}
 
