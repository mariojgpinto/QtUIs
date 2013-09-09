#include <QtGui\QApplication>

#ifdef _DLL_BUILD_
#undef _DLL_BUILD_
#endif

#include <PointSelectionGUI.h>

int main(int argc, char* argv[]){
	QApplication a(argc, argv);

	
	cv::Mat img = cv::imread("img.png");

	PointSelectionGUI* point_selection = new PointSelectionGUI();
	point_selection->set_image(img);
	point_selection->show();

	return a.exec();
}