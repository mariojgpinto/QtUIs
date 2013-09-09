#include <QtGui\QApplication>

#include <PointSelectionGUI.h>

int main(int argc, char* argv[]){
	QApplication a(argc, argv);

	PointSelectionGUI* point_selection = new PointSelectionGUI(1);
	point_selection->show();

	return a.exec();
}