#ifndef POINTSELECTIONGUI_H
#define POINTSELECTIONGUI_H

#include <QtGui/QMainWindow>

namespace Ui {
	class PointSelectionGUI;
}

#include <opencv2\opencv.hpp>

#include <ToolBoxQT.h>

class __declspec(dllexport) PointSelectionGUI : public QMainWindow
{
public:
	PointSelectionGUI(int dummy, QWidget *parent = 0, Qt::WFlags flags = 0);
	~PointSelectionGUI();

public:
    void mousePressEvent(QMouseEvent *event);

public slots:
	void on_save();
	void on_reset();

private:
	Ui::PointSelectionGUI* _ui;
	QAction* _close;

	ToolBoxQT::CVWidget* _widget;

	std::vector<cv::Point>* _points;

	cv::Mat _image_orig;
	cv::Mat _image;
};

#endif // POINTSELECTIONGUI_H
