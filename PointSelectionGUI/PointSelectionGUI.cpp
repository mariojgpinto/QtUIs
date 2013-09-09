#include "PointSelectionGUI.h"

#include "ui_PointSelectionGUI.h"

#include <QMouseEvent>

//#include <ToolBoxCV.h>


PointSelectionGUI::PointSelectionGUI(int dummy, QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),
	_ui(new Ui::PointSelectionGUI)
{
	_ui->setupUi(this);
	
	QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(true);

	this->_widget = new ToolBoxQT::CVWidget(this->_ui->widget);
    this->_widget->setObjectName(QString::fromUtf8("Widget"));
    this->_widget->setSizePolicy(sizePolicy1);
	this->_widget->setFixedSize(this->_ui->widget->width(),this->_ui->widget->height());

	this->_image_orig = cv::imread("img.png");
	this->_image = cv::imread("img.png");

	this->_widget->setImage(&this->_image);

	this->_points = new std::vector<cv::Point>();

	connect(this->_ui->pushButton_save, SIGNAL(clicked()), this, SLOT(on_save()));
	connect(this->_ui->pushButton_reset, SIGNAL(clicked()), this, SLOT(on_reset()));
	
	//connect(this->ui.widget,SIGNAL(clicked()),this,SLOT(mousePressEvent(QGraphicsSceneMouseEvent *event)));
}

PointSelectionGUI::~PointSelectionGUI()
{

}

void PointSelectionGUI::on_save(){

	this->hide();
	exit(0);
}

void PointSelectionGUI::on_reset(){
	this->_image_orig.copyTo(this->_image);

	this->_points->clear();
	this->_widget->setImage(&this->_image);
}

void PointSelectionGUI::mousePressEvent(QMouseEvent *event){
	QPoint pos = this->_ui->widget->mapFrom(this->_ui->centralWidget,event->pos());

	cv::circle(this->_image,cv::Point(pos.x(),pos.y()),5,cv::Scalar(0,0,255),-1);
	this->_points->push_back(cv::Point(pos.x(),pos.y()));

	this->_widget->setImage(&this->_image);
}