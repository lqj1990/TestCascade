#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

void main(){
	string cascade_name = "D:\\project\\TestCascade\\test\\LBP\\cascade.xml";
	CascadeClassifier cascade;
	bool open = cascade.load(cascade_name);
	std::vector<Rect> cars;
	Mat frame = imread("D:\\project\\TestCascade\\test\\test.jpg");
	Mat frame_gray;
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	//-- Detect objects
	cascade.detectMultiScale(frame_gray, cars, 1.01, 1, 0, Size(10, 10));
	std::cout << "Total: " << cars.size() << " cars detected." << std::endl;
	for (int i = 0; i < cars.size(); i++)
	{
		rectangle(frame, Rect(cars[i].x, cars[i].y, cars[i].width, cars[i].height), CV_RGB(255, 0, 0), 2, 8, 0);
	}
	imshow("video", frame);
	waitKey(0);
}