#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(void) {
	// Load the Face Image
	string faceImagePath = "H:/OpenCV_Camp_Cplus/data/images/musk.jpg";
	Mat faceImage = imread(faceImagePath);
	// Load the Sunglass image with Alpha channel
	string glassMaskPath = "H:/OpenCV_Camp_Cplus/03_Sunglasses_for_Musk/03_Sunglasses_for_Musk/sunglassAlpha.png";
	Mat glassMask1 = imread(glassMaskPath, 0);

	// Load the Sunglass image with BGR channel
	string glassBGRPath = "H:/OpenCV_Camp_Cplus/03_Sunglasses_for_Musk/03_Sunglasses_for_Musk/sunglassRGB.png";
	Mat glassBGR = imread(glassBGRPath);

	Mat glassMask;
	// ��Ϊ����ͼ������ͨ��ͼ��Ҳ����3ͨ����maskͼ��
	Mat glassMaskChannels[] = {glassMask1, glassMask1, glassMask1};
	merge(glassMaskChannels, 3, glassMask);
	glassMask = glassMask / 255;

	// ��������ͼ��
	Mat faceWithGlassesArithmetic = faceImage.clone();

	// ѡȡ�۾�����
	Mat eyeROI = faceWithGlassesArithmetic(Range(150, 250), Range(140, 440));

	Mat eyeROIChannels[3];
	split(eyeROI, eyeROIChannels);
	Mat maskedEyeChannels[3];
	Mat maskedEye;

	for (int i = 0; i < 3; i++) {
		// ����ī��maskͼ�������۾������maskͼ��
		multiply(eyeROIChannels[i], (1 - glassMaskChannels[i]), maskedEyeChannels[i]);
	}
	merge(maskedEyeChannels, 3, maskedEye);
	imshow("Masked eye region", maskedEye);

	Mat maskedGlass;
	// ����maskͼ��������Ĥ��ī������
	multiply(glassBGR, glassMask, maskedGlass);
	imshow("Masked Sunglass Region", maskedGlass);

	Mat eyeRoiFinal;
	// ��ī�����۾�����ϲ�������յ�Ч��
	add(maskedEye, maskedGlass, eyeRoiFinal);
	imshow("Augmented Eye and Sunglass", eyeRoiFinal);

	// ����ī�����۾�ͼ���Ƶ�����ͼ����
	eyeRoiFinal.copyTo(eyeROI);
	imwrite("withSunglasses.png", faceWithGlassesArithmetic);
	imshow("With Sunglasses", faceWithGlassesArithmetic);
	waitKey(0);

	return 0;
}