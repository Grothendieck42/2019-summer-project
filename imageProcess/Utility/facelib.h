#ifndef FACELIB_H
#define FACELIB_H
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv/cv.h>
#include <fstream>
#include <iostream>
#include <QProgressDialog>
#include <QApplication>
#include <string.h>
#include "../Common/myImage.h"
using namespace std;
using namespace cv;

static string face_home = "/home/ren/Documents/summer/2019-summer-project/imageProcess/Utility/facenote";
static string train_dir = face_home + "/FaceLib-default";
static string cascader = face_home + "/classifier/haarcascade_frontalface_alt2.xml";
static string model = "model";
static string eyecascader = face_home + "/classifier/haarcascade_eye.xml";
static int type_number = 0;
static int maxnum = 50;
static int model_width = 128;
static int model_height = 128;
static int model_size = model_width * model_height;
static int eignum;
static double energy = 0.95;
static cv::Mat vec;
static cv::Mat vec1;
static cv::Mat dat;
static cv::Mat avg;
static cv::Mat type_matrix;

int model_reader();

int addphoto();

int addrow(Mat img);

int find_face(Mat img);

Mat toline(Mat img);

Mat showpicture(int i);

Mat create_average();

Mat trans_back(Mat line);

int outputTopn(Mat eve, int n);

int get_cov_mat();

int build_model(const char * model_name);

double distance(Mat a, Mat  b);

bool train_eigen_face(string dataPath, QProgressDialog* progressDialog);

Mat annotate_faces(string modelPath, cv::Mat sample);

Mat detecte_faces(string classifierPath, cv::Mat sample);

Mat beautify_faces(cv::Mat sample);



#endif // FACELIB_H
