#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	// ����һ����λ����
	Mat A = Mat::eye(10, 10, CV_32S);
	// ȡ��A����ĵ�i��
	Mat line = A.row(1);
	// ȡ��A����ĵ�i�У�����һ��Ԫ�س�2�ڸ�ֵ��j��
	A.row(2) = A.row(2) * 2;
	cout << "A = " << endl << A << endl;

	// ��ȡ��һ�е������У������������У�
	Mat B = A(Range::all(), Range(1, 3));
	// ��ȡB�ĵ�5�е���9�У���������9�У�
	Mat C = B(Range(5, 9), Range::all());

	// ******** ��������ȼ� ******** //
	Mat D = A(Range(5, 9), Range(1, 3));

	// ************ ROI ************* //
	Mat img(Size(320, 240), CV_8UC3);
	// ѡȡimg�е�Rect(10, 10, 100, 100)������ΪROI
	// 1. ʹ�ù��캯��
	Mat roi(img, Rect(10, 10, 100, 100));
	Mat roi2(img, Range(10, 100), Range(10, 100));
	// 2. ʹ�����������
	Mat roi3 = img(Rect(10, 10, 100, 100));
	Mat roi4 = img(Range(10, 100), Range(10, 100));
	imshow("img", img);
	imshow("img1", roi);
	imshow("img2", roi2);
	imshow("img3", roi3);
	imshow("img4", roi4);

	// ************ ѡȡ�Խ��� ************* //
	Mat M = (Mat_<int>(4, 4) <<
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 0, 8, 7,
		6, 5, 4, 2);
	// 1. ȡ���Խ���
	Mat d0 = M.diag(0);
	cout << "d0=" << endl << d0 << endl;
	// 2. ȡ���Խ����Ϸ���2���Խ���
	Mat d1 = M.diag(2);
	cout << "d1=" << endl << d1 << endl;
	// 3. ȡ���Խ����·���1���Խ���
	Mat d2 = M.diag(-1);
	cout << "d2=" << endl << d2 << endl;

	waitKey();

	return 0;
}