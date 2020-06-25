#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	// ***** һ��Mat������ << ��������ʹ������������������ݣ���֧�ֲ�ͬ�����ʽ ***** //
	
	// ����һ��3*2�ľ��󣬲������ʼ��Ԫ��
	Mat R = Mat(3, 2, CV_8UC3);
	randu(R, Scalar::all(0), Scalar::all(255));

	// 1. Ĭ�������ʽ
	cout << " R(default) = " << endl << R << endl;

	// 2. python�����ʽ
	cout << " R(python) = " << endl << format(R,Formatter::FMT_PYTHON) << endl;

	// 3. Numpy�����ʽ
	cout << " R(numpy) = " << endl << format(R, Formatter::FMT_NUMPY) << endl;

	// 4. C���������ʽ
	cout << " R(C) = " << endl << format(R, Formatter::FMT_C) << endl;

	// 5. CSV�����ʽ
	cout << " R(CSV) = " << endl << format(R, Formatter::FMT_CSV) << endl;

	// ***** ��������Mat����Ҳ֧����������ʹ��������������� ***** //
	// 1. ��ά��
	Point2f P1(5, 1);
	cout << "point (2d) = " << P1 << endl;
	// 2. ��ά��
	Point3f P2(5, 1, 8);
	cout << "Point (3d) = " << P2 << endl;

	getchar();
	return 0;
}