#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/objdetect/objdetect.hpp>

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
using namespace cv;

string train_dir = "traindata/FaceLib/";
string cascader = "./haarcascade_frontalface_alt2.xml";
string sample = "1.jpg";
string model = "model";
string eyecascader = "./haarcascade_eye.xml";

int type_number = 0;

int maxnum = 200;
int model_width = 128;
int model_height = 128;
int model_size = model_width * model_height;
double energy = 0.95;
Mat vec;
Mat dat;
Mat avg;
int eignum;

int model_reader() {
	ifstream list(model);
	float f;
	char ch;
	int lv, la, lm;
	list >> lv;
	list >> la;
	list >> lm;
	list >> ch;
	eignum = lv;

	vec = Mat(Size(model_size, lv), CV_32F);
	avg = Mat(Size(model_size, 1), CV_32F);
	dat = Mat(Size(model_size, lm), CV_32F);
	
	int countf = -1;
	while (!list.eof() && lv >0) {
		if (ch == '[' || ch == ',' || ch==';') {
			list >> f;
			countf++;
			int r = countf / model_size;
			int c = countf % model_size;
			vec.at<float>(r, c) = f;
		}
		if (ch == ']') {
			lv--;
		}
		list >> ch;
	}
	countf = -1;
	while (!list.eof() && la > 0) {
		if (ch == '[' || ch == ',' || ch == ';') {
			list >> f;
			countf++;
			int c = countf % model_size;
			avg.at<float>(0, c) = f;
		}
		if (ch == ']') {
			la--;
		}
		list >> ch;
	}
	
	countf = -1;
	while (!list.eof() && lm > 0) {
		if (ch == '[' || ch == ',' || ch == ';') {
			list >> f;
			countf++;
			int r = countf / model_size;
			int c = countf % model_size;
			dat.at<float>(r, c) = f;
		}
		if (ch == ']') {
			lm--;
		}
		list >> ch;
	}

	printf("load_data_ok\n");
	return 0;
}

Mat toline(Mat img) {
	Mat iml(Size(img.size().width*img.size().height, 1), CV_32F);
	for (int r = 0; r < img.size().height; r++) {
		for (int c = 0; c < img.size().width; c++) {
			int index = r * img.size().width + c;
			iml.at<float>(0, index) = img.at<uchar>(r, c);
		}
	}
	return iml;
}

double distance(Mat a, Mat  b) {
	double d = 0;
	int size = min(a.size().width, b.size().width);
	for (int i = 0; i < size; i++)
	{
		double dd = a.at<float>(0, i) - b.at<float>(0, i);
		d += dd * dd;
	} 
	return sqrt(d);
}

Mat showpicture(int i) {
	string list_name = train_dir + "list";
	ifstream list(list_name);
	char buf[80];
	for (int l = 0; l <= i; l++) {
		list.getline(buf, sizeof(buf));
	}
	string filename = train_dir + buf;
	Mat similar,gray;
	similar=imread(filename);
	cvtColor(similar, gray, CV_BGR2GRAY);
	//equalizeHist(gray, gray);
	resize(gray, gray, Size(model_width, model_height));
	return gray;
}

Mat build_face(Mat img) {
	Mat img_l(toline(img));
	img_l = img_l - avg;
	Mat vec_t,df;

	vec_t = vec.t();

	df = img_l * vec_t;
	
	Mat temp;
	int index = 0;
	double min_dist = 999999999999999;

	for (int r = 0; r < dat.size().height; r++) {
		temp = dat.row(r)*vec_t;
		double dist = distance(df, temp);
		if (dist < min_dist) {
			index = r;
			min_dist = dist;
		}
	}

	Mat sim=Mat(showpicture(index));

	img_l = df * vec + avg;


	normalize(img_l, img_l, 0, 255, NORM_MINMAX);

	Mat img_o(Size(model_width, model_height), CV_8UC1);
	for (int r = 0; r < model_height; r++) {
		for (int c = 0; c < model_width; c++) {
			int index = r * model_width + c;
			img_o.at<uchar>(r, c) = img_l.at<float>(0, index);
		}
		
	}
	
	vector<Mat> array;
	array.push_back(img);
	array.push_back(sim);
	array.push_back(img_o);
	
	Mat tog_img;
	hconcat(array, tog_img);
	namedWindow("result", 1);
	imshow("result", tog_img);
	return tog_img;
}


int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " [sample_face_name] [model_name]" << endl;
		return -1;
	}
	//dataload
	{
		sample = String(argv[1]);
		model = String(argv[2]);
	}
	Mat s_face, gray_face;
	s_face = imread(sample);
	cvtColor(s_face, gray_face, CV_BGR2GRAY);
	equalizeHist(gray_face, gray_face);
	
	vector<Rect> faces;
	CascadeClassifier cascade(cascader);
	cascade.detectMultiScale(gray_face, faces);

	if (faces.size() == 0) {
		model_reader();
		resize(gray_face, gray_face, Size(model_width, model_height));
		build_face(gray_face);
	}
	else if(faces.size()>=1) {
		Mat roi;
		model_reader();
		vector<Rect>::const_iterator r = faces.begin();
		CascadeClassifier eyecascade(eyecascader);
		vector<Rect> eyes;
		
		roi = Mat(gray_face, *r);
		eyecascade.detectMultiScale(roi, eyes, 1.1);

		if (eyes.size() !=0 ) {
			double ratio = 3.5;
			cout << "find eyes" << endl;
			vector<Rect>::const_iterator e = eyes.begin();
			double a = e[0].y;
			double b = r[0].height - a;
			if (b >= ratio * a) {
				double y = min((double)gray_face.size().height, r[0].y - (ratio*a - b));
				double h = min(y, gray_face.size().height - y + 4 * a);
				//cout << r[0] << a << "," << b << "," << y << "," << h << endl;
				roi = Mat(gray_face, Rect(r[0].x, y, r[0].width, h));
			}
			else {
				double y = r[0].y + (ratio*a - b);
				double h = min(y, gray_face.size().height - y + 4 * a);
				//cout << r[0] << a <<"," << b << "," << y << "," << h << endl;
				roi = Mat(gray_face, Rect(r[0].x, y, r[0].width, h));
			}
		}
		roi = Mat(gray_face, *r);
		resize(roi, roi, Size(model_width, model_height));
		build_face(roi);

	}
	
	cout << "ok" << endl;
	
	waitKey();
	return 0;
}