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

int find_face(Mat img) {
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

//    Mat sim=Mat(showpicture(index));
    cout << index << endl;
    return index;
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

void progressGoo(int old, int value, QProgressDialog* ptr){
    for(int i=old;i<value;i++)
    {
      for(int j=0;j<40000;j++);
      ptr->setValue(i);
      QApplication::processEvents();
      if(ptr->wasCanceled())
        break;
    }
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
    progressGoo(10, 20, progressDialog);
    QString *a = new QString("loading data from dataPath...");
    progressDialog->setLabelText(*a);
    while (!info_list.eof() && type_number<maxnum)
    {
        progressGoo(20, 30, progressDialog);
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
    progressDialog->setLabelText("generating cov mat...");
    progressGoo(30, 35, progressDialog);

    get_cov_mat();
    string modeldata = dataPath + "/"+model;

    progressDialog->setLabelText("building model...");
    progressGoo(35, 50, progressDialog);
    build_model(modeldata);
    progressDialog->setLabelText("cleaning memory...");
    progressGoo(50, 90, progressDialog);
    Mat* empty = new Mat();
    avg = *empty;
    vec = *empty;
    vec1 = *empty;
    dat = *empty;
    type_matrix = *empty;
    progressDialog->setLabelText("fsinishing ...");
    progressGoo(90, 100, progressDialog);
    return true;
}

Mat annotate_faces(string modelPath, cv::Mat sample){
    int flag = -1;
    double y = 10;
    double yy = 15;
    double h = 10;
    double x = 15;
    model = modelPath;
    cv::Mat s_face, gray_face;
    s_face = sample;
    std::cout<<s_face.size()<<std::endl;
    if (s_face.type() == CV_8UC1)
    {

        gray_face = s_face;

    }

    else if (s_face.type() == CV_8UC3)

    {

        gray_face = s_face;


    }
//    equalizeHist(gray_face, gray_face);

    vector<Rect> faces;
    CascadeClassifier cascade(cascader);
    cascade.detectMultiScale(gray_face, faces);
    if (faces.size() == 0) {
        model_reader();
        resize(gray_face, gray_face, Size(model_width, model_height));
        flag = find_face(gray_face);
        char buf[32];
        memset(buf, 0, 32);
        sprintf(buf, "%d", flag);
        IplImage *ipl_img = new IplImage(sample);
        CvFont font;
        cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX,0.5,0.5,0,2,8);
        cvPutText(ipl_img, buf, Point((int)x,(int)yy), &font, cvScalar(255,0,0,1));
        sample = cvarrToMat(ipl_img);
    }
    else if(faces.size()>=1) {
        Mat roi;
        model_reader();
        for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); ++ r){
            CascadeClassifier eyecascade(eyecascader);
            roi = Mat(gray_face, *r);
            resize(roi, roi, Size(model_width, model_height));
            flag = find_face(roi);
            char buf[32];
            memset(buf, 0, 32);
            sprintf(buf, "%d", flag);
            IplImage *ipl_img = new IplImage(sample);
            CvFont font;
            cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX,0.5,0.5,0,2,8);
            cvPutText(ipl_img, buf, Point(r->x,r->y), &font, cvScalar(255,0,0,1));
            sample = cvarrToMat(ipl_img);
        }
    }
    return sample;
}

Mat detecte_faces(string classifierPath, cv::Mat sample){

    cv::Mat s_face, gray_face;
    s_face = sample;
    std::cout<<s_face.size()<<std::endl;
    if (s_face.type() == CV_8UC1)
    {
        gray_face = s_face;
    }
    else if (s_face.type() == CV_8UC3)
    {
        gray_face = s_face;

    }
    vector<Rect> faces;
    CascadeClassifier cascade(classifierPath);
    cascade.detectMultiScale(gray_face, faces);
    if (faces.size() == 0) {
        resize(gray_face, gray_face, Size(model_width, model_height));
        char buf[32];
        memset(buf, 0, 32);
        IplImage *ipl_img = new IplImage(sample);
        cvRectangle(ipl_img, Point(0,0), Point(model_width, model_height),cvScalar(0,255,0));
        sample = cvarrToMat(ipl_img);
    }
    else if(faces.size()>=1) {
        Mat roi;
        for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); ++ r){
            CascadeClassifier eyecascade(eyecascader);
            roi = Mat(gray_face, *r);
            resize(roi, roi, Size(model_width, model_height));
            char buf[32];
            memset(buf, 0, 32);
            IplImage *ipl_img = new IplImage(sample);
            cvRectangle(ipl_img, Point(r->x, r->y), Point(r->x+r->width, r->y + r->height),cvScalar(0,255,0));
            sample = cvarrToMat(ipl_img);
        }
    }
    return sample;
}

Mat beautify(Mat image){
    Mat dst;
    int value1 = 3, value2 = 1;
    int dx = value1 * 5;
    double fc = value1*12.5;
    int p = 50;
    Mat temp1, temp2, temp3, temp4;
    bilateralFilter(image, temp1, dx, fc, fc);
    temp2 = (temp1 - image + 128);
    GaussianBlur(temp2, temp3, Size(2 * value2 - 1, 2 * value2 - 1), 0, 0);
    temp4 = image + 2 * temp3 - 255;
    dst = (image*(100 - p) + temp4*p) / 100;
    dst.copyTo(image);
    return image;
}


Mat beautify_faces(cv::Mat sample){

    cv::Mat s_face, gray_face;
    s_face = sample;
    std::cout<<s_face.size()<<std::endl;
    if (s_face.type() == CV_8UC1)
    {
        gray_face = s_face;
    }
    else if (s_face.type() == CV_8UC3)
    {
        gray_face = s_face;

    }
    vector<Rect> faces;
    CascadeClassifier cascade(cascader);
    cascade.detectMultiScale(gray_face, faces);
    if (faces.size() == 0) {
        //cannot find faces
    }
    else if(faces.size()>=1) {
        for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); ++ r){
            CascadeClassifier eyecascade(eyecascader);
            Mat roiroi = gray_face(*r);
            roiroi = beautify(roiroi);
            Mat rr = gray_face(*r);
            Mat rrr = roiroi.clone();
            rrr.copyTo(rr);
        }
    }
    return gray_face;
}


bool generate_headshots(string outputdir,cv::Mat sample){
    int count = -1;
    cv::Mat s_face, gray_face;
    s_face = sample;
    std::cout<<s_face.size()<<std::endl;
    if (s_face.type() == CV_8UC1)
    {
        gray_face = s_face;
    }
    else if (s_face.type() == CV_8UC3)
    {
        gray_face = s_face;

    }
    vector<Rect> faces;
    CascadeClassifier cascade(cascader);
    cascade.detectMultiScale(gray_face, faces);
    if (faces.size() == 0) {
        //cannot find faces
        return false;
    }
    else if(faces.size()>=1) {
        for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); ++ r){
            count ++;
            CascadeClassifier eyecascade(eyecascader);
            Mat roiroi = gray_face(*r);
            roiroi = beautify(roiroi);
            Mat rr = gray_face(*r);
            Mat rrr = roiroi.clone();
//            rrr.copyTo(rr);
            char buf[15];
            sprintf(buf,"%03d",count);
            string filename = outputdir + "/Headshot_"+ buf + ".jpeg";
            imwrite(filename, roiroi);
        }
    }
    return true;
}
