#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	/*********** һ��ʹ��Mat ***********/
	Mat grayImg(480, 640, CV_8UC1);
	for (int i = 0; i < grayImg.rows; i++) {
		// 1. ��ȡ��i�е�һ�����ص�ָ��
		uchar* p = grayImg.ptr<uchar>(i);
		for (int j = 0; j < grayImg.cols; j++) {
			double d1 = (double)((i + j) % 255);
			// 2. �� at() ��д���أ���Ҫ�ƶ�Ԫ������
			grayImg.at<uchar>(i, j) = d1;
			// 3. ���ʹ��������룬����Ԫ������ָ�����󣬻ᱨ��
			//double d2 = grayImg.at<double>(i, j);
		}
	}

	/*********** ����ʹ��Mat_ ***********/
	// ��Ҫ����������ʱָ�������Ԫ������
	Mat_<uchar> grayImg1 = (Mat_<uchar>&)grayImg;
	for (int i = 0; i < grayImg1.rows; i++) {
		// ��ȡ��i�е��׸����ص�ָ�룬���ﲻ��Ҫ��ָ��Ԫ������
		uchar* p = grayImg1.ptr(i);
		for (int j = 0; j < grayImg1.cols; j++) {
			double d1 = (double)((i + j) % 255);
			// ֱ��ʹ��MATLAB���ľ���Ԫ�ض�д�����
			grayImg1(i, j) = d1;
			double b2 = grayImg1(i, j);
		}
	}
	return 0;
}