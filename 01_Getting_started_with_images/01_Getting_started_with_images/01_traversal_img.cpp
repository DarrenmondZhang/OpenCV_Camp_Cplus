#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat grayImg(480, 480, CV_8UC1);
	Mat colorImg(480, 640, CV_8UC3);

	/*at()������Ч�ʲ��ߣ����Ƽ�ʹ��at()��������ͼ��*/
	// �����Ҷ�ͼ�����е����أ�����������
	//for (int i = 0; i < grayImg.rows; i++) {
	//	for (int j = 0; j < grayImg.cols; j++) {
	//		grayImg.at<uchar>(i, j) = (i + j) % 255;
	//	}
	//}

	//// �������в�ɫͼ���������أ�����������ֵ
	//for (int i = 0; i < grayImg.rows; i++) {
	//	for (int j = 0; j < grayImg.cols; j++) {
	//		Vec3b pixel;
	//		pixel[0] = i % 255; // blue
	//		pixel[1] = j % 255; // green
	//		pixel[2] = 0;
	//		colorImg.at<Vec3b>(i, j) = pixel;
	//	}
	//}


	//// ********************* ʹ�õ����� ********************* //
	//// �����Ҷ�ͼ�����е����أ�����������
	//MatIterator_<uchar> grayItr, grayEnd;
	//for (grayItr = grayImg.begin<uchar>(),
	//	grayEnd = grayImg.end<uchar>();
	//	grayItr != grayEnd; grayItr++
	//	) {
	//	*grayItr = rand() % 255;
	//}

	//// ������ɫͼ�����е����أ�����������
	//MatIterator_<Vec3b> colorItr, colorEnd;
	//for (colorItr = colorImg.begin<Vec3b>(),
	//	colorEnd = colorImg.end<Vec3b>();
	//	colorItr != colorEnd; colorItr++) {
	//	(*colorItr)[0] = rand() % 255; // Blue
	//	(*colorItr)[1] = rand() % 255; // Green
	//	(*colorItr)[2] = rand() % 255; // Red
	//}
	
	// ********************* ʹ��ָ�� ********************* //
	for (int i = 0; i < grayImg.rows; i++) {
		// ��ȡ��i��������ָ��
		uchar* p = grayImg.ptr<uchar>(i);
		for (int j = 0; j < grayImg.cols; j++) {

		}
	}


	// ��ʾ���
	imshow("grayImg", grayImg);
	imshow("colorImg", colorImg);
	waitKey(0);
	return 0;
}