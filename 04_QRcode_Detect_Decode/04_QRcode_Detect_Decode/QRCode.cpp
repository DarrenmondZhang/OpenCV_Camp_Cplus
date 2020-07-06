#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;


int main(int argc, char* argv[]) {
	Mat img = imread("H:/OpenCV_Camp_Cplus/data/images/QRcode.jpg");
	if (img.empty()) {
		cout << "��������ȷ��ͼ��" << endl;
		return -1;
	}
	Mat gray, qrcode_bin;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	QRCodeDetector qrcodedetector;
	vector<Point> points;
	string information;
	bool isQRcode;
	isQRcode = qrcodedetector.detect(gray, points); //ʶ���ά��
	if (isQRcode) {
		// ������ά��
		information = qrcodedetector.decode(gray, points, qrcode_bin);
		cout << points << endl;  // ����ĸ���������
		cout << information << endl;  // ����ĸ���������
	}
	else {
		cout << "�޷�ʶ���ά��" << endl;
		return -1;
	}

	// ���Ʊ߿�
	for (int i = 0; i < points.size(); i++) {
		if (i == points.size() - 1) {
			line(img, points[i], points[0], Scalar(0, 0, 255), 2, 8);
			break;
		}
		line(img, points[i], points[i+1], Scalar(0, 0, 255), 2, 8);
	}

	// ���������������ͼƬ��
	putText(img, information.c_str(), Point(20, 30), 0, 1.0, Scalar(0, 0, 255), 2, 8);

	// ���ú���ֱ�Ӷ�λ��ά�벢�ҽ���
	string information2;
	vector<Point> points2;
	information2 = qrcodedetector.detectAndDecode(gray, points2);
	cout << "information2" << information2 << endl;  
	putText(img, information2.c_str(), Point(20, 55), 0, 1.0, Scalar(0, 0, 255), 2, 8);

	// ������
	imshow("result", img);
	//namedWindow("qrcode_bin", WINDOW_AUTOSIZE);
	//imshow("qrcode_bin", qrcode_bin);
	waitKey();
	return 0;
}