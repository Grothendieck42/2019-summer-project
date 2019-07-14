#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/objdetect/objdetect.hpp>

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
using namespace cv;

string train_dir = "traindata/FaceLib/";
string cascader = "haarcascade_frontalface_alt2.xml";
string nestedcascader = "";

int type_number=0;
Mat type_matrix;
Mat avg;
int maxnum = 202;
int model_width = 128;
int model_height = 128;
int model_size = model_width * model_height;
double energy = 0.95;
Mat vec;
Mat vec1;

int addphoto() {
	type_number++;
	return 0;
}

int addrow(Mat img) {
	resize(img,img,Size(model_width,model_height));
	for (int r = 0; r < img.size().height; r++) {
	    for (int c = 0; c < img.size().width; c++) {
			int pos = r * img.size().width + c;
			type_matrix.at<float>(type_number - 1, pos) = img.at<uchar>(r, c);
		}
	}
	return 0;
}

Mat create_average() {
	Mat ave(Size(model_width,model_height),CV_32F);
	for (int r = 0; r < model_height; r++) {
		for (int c = 0; c < model_width; c++) {
			int index = r * model_width + c;
			float sum=0;
			for (int i = 0; i < type_number; i++) {
				sum += (int)type_matrix.at<float>(i, index);
			}
			sum /= type_number;
			ave.at<float>(r, c) = sum;
		}
		
	}
	return ave;
}

Mat trans_back(Mat line) {
	Mat out(Size(model_width, model_height), CV_8UC1);
	for (int r = 0; r < model_height; r++) {
		for (int c = 0; c < model_width; c++) {
			int index = r * model_width + c;
			out.at<uchar>(r, c) = (int)line.at<float>(0, index);
		}
	}
	return out;
}

int outputTopn(Mat eve, int n) {
	vector<Mat> out1;
	vector<Mat> out2;
	for (int i = 0; i < n/2; i++) {
		out1.push_back(trans_back(eve.row(i)));
	}
	for (int i = n/2; i < n ; i++) {
		out2.push_back(trans_back(eve.row(i)));
	}
	Mat tmp1,tmp2,image;
	hconcat(out1,tmp1);
	hconcat(out2, tmp2);
	vconcat(tmp1, tmp2, image);
	cout << "showing" << endl;
	imshow("eigenfaces", image);
	return 0;
}


int get_cov_mat() {
	avg=Mat(create_average());
	for (int r = 0; r < model_height; r++) {
		for (int c = 0; c < model_width; c++) {
			int index = r * model_width + c;
			for (int i = 0; i < maxnum; i++) {
				type_matrix.at<float>(i, index) -= avg.at<float>(r, c);
			}
		}
	}
	Mat t(Size(maxnum, model_size), CV_32F);

	t = type_matrix.t();

	Mat bmat(maxnum, maxnum, CV_32F);

	for (int r = 0; r < maxnum; r++) {
		for (int c = 0; c < maxnum; c++) {
			float vb = 0, vg = 0, vr = 0;
			for (int i = 0; i < model_size; i++) {
				vb += t.at<float>(i, c)*type_matrix.at<float>(r, i );
			}
			bmat.at<float>(r, c) = (float)vb/(float)model_size;
		}
	}
	Mat eva;
	Mat eve;

	eigen(bmat, eva, eve);
	   	
	

	vec = Mat(eve.size().height, model_size, CV_32F);
	vec1 = Mat(eve.size().height, model_size, CV_32F);
	for (int r = 0; r < eve.size().height; r++) {
		float max = 0, min = 9999999;
		for (int c = 0; c < model_size; c++) {
			vec.at<float>(r, c) = 0;
			for (int m = 0; m < maxnum; m++) {
				vec.at<float>(r, c) += eve.at<float>(r, m)*t.at<float>(c, m);
			}
			if (vec.at<float>(r, c) > max) {
				max = vec.at<float>(r, c);
			}
			if (vec.at<float>(r, c) < min) {
				min = vec.at<float>(r, c);
			}
		}
		for (int c = 0; c < model_size; c++) {
			vec1.at<float>(r, c) = (vec.at<float>(r, c)-min)/(max-min);
			vec1.at<float>(r, c) *= 255;
		}
	}
	for(int i=0;i<vec.size().height;i++)
		normalize(vec.row(i), vec.row(i), 1,0,NORM_L2);

	double lambda_sum = sum(eva)[0];
	double energy_thresh = energy * lambda_sum;
	double sum = 0;
	int k;
	for (k = 0; k < eva.size().height; k++) {
		sum += eva.at<float>(k, 0);
		if (sum >= energy_thresh) {
			break;
		}
	}
	eve = eve.rowRange(0, k);
	vec1 = vec1.rowRange(0, k);
	vec = vec.rowRange(0, k);

	outputTopn(vec1, 10);

	return (k+1);
}


int build_model(const char * model_name) {
	ofstream model(model_name);
	model << vec.size().height << endl;
	model << avg.size().height << endl;
	model << type_matrix.size().height << endl;
	model << "vec" << endl;
	for (int i = 0; i < vec.size().height; i++) {
		model << vec.row(i) << endl;
	}
	model << "avg" << endl;
	for (int i = 0; i < avg.size().height; i++) {
		model << avg.row(i) << endl;
	}
	model << "dat_matrix" << endl;
	for (int i = 0; i < type_matrix.size().height; i++) {
		model << type_matrix.row(i) << endl;
	}
	return 0;
}


int main(int argc, char* argv[]) {
	//data_loading
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " [energy] [model_name]" << endl;
		return -1;
	}

	{
		energy = atof(argv[1]);
	}
	
	CascadeClassifier cascade(cascader);
		
	type_matrix = Mat( Size(model_size, maxnum), CV_32F);
	string list_name = train_dir + "list";
	ifstream info_list(list_name);
	char buf[100];
	if (!info_list.is_open()) {
		cerr << "cannot open the file" << endl;
		return -1;
	}
	while (!info_list.eof() && type_number<maxnum)
	{
		info_list.getline(buf, 100);
		
		string name = train_dir + string(buf);
		cout << name << endl;
		Mat img,gray;
		vector<Rect> faces;
		img = imread(name);

		if (!img.empty()) {
			cout << name << endl;
			addphoto();
			cvtColor(img, gray, CV_BGR2GRAY);
			equalizeHist(gray, gray);
			resize(gray, gray, Size(model_width, model_height));
			addrow(gray);

		}
	}					
	namedWindow("eigenfaces", 1);
	get_cov_mat();
	build_model(argv[2]);
	cout <<"ok" << endl;
	waitKey();
	return 0;
}