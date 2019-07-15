#include "facelib.h"

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

//    outputTopn(vec1, 10);

    return (k+1);
}


int build_model(const string model_name) {
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

bool train_eigen_face(string dataPath, QProgressDialog* progressDialog){
    train_dir = dataPath;
    CascadeClassifier cascade(cascader);
    type_matrix = Mat( Size(model_size, maxnum), CV_32F);
    string list_name = dataPath+"/list";
    ifstream info_list(list_name);
    char buf[100];
    if (!info_list.is_open()) {
        cerr << "cannot open the file" << endl;
        return false;
    }
    while (!info_list.eof() && type_number<maxnum)
    {
        memset(buf, 0, 100);
        info_list.getline(buf, 100);
        buf[strlen(buf)-1]=0;
        const string name = train_dir + "/" + string(buf);
        cout << name << endl;
        cv::Mat img,gray;
        vector<Rect> faces;
        img = cv::imread(name);
        cout << img.size() << endl;
        if (!img.empty()) {
            cout << name << endl;
            addphoto();
            cvtColor(img, gray, CV_BGR2GRAY);
            equalizeHist(gray, gray);
            resize(gray, gray, Size(model_width, model_height));
            addrow(gray);

        }
    }
    get_cov_mat();
    string modeldata = dataPath + "/"+model;

    build_model(modeldata);

    Mat* empty = new Mat();
    avg = *empty;
    vec = *empty;
    vec1 = *empty;
    dat = *empty;
    type_matrix = *empty;

    return true;
}
