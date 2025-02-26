/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date January 2025
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include "../include/ui_test2/main_window.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindowDesign)
{
  ui->setupUi(this);

  QIcon icon("://ros-icon.png");
  this->setWindowIcon(icon);

  qnode = new QNode();

  QObject::connect(qnode, SIGNAL(rosShutDown()), this, SLOT(close()));
  QObject::connect(qnode, SIGNAL(sigNewFrame()), this, SLOT(slotUpdateImg()));
  QObject::connect(qnode, SIGNAL(test()), this, SLOT(test2()));
}

void MainWindow::closeEvent(QCloseEvent* event)
{
  QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::slotUpdateImg()
{
  RCLCPP_INFO(rclcpp::get_logger("ui_test2"), "label 수신 중...");

  clone_mat = qnode->img_raw_->clone(); //qnode에 있는 포인터 이미지를 main_window내에서 복제함(나눠서 해결하면 효율적이니까)
  cv::resize(clone_mat, clone_mat, cv::Size(640, 360),0 ,0, cv::INTER_CUBIC);

  QImage RGB_Img((const unsigned char*)(clone_mat.data), clone_mat.cols, clone_mat.rows, QImage::Format_RGB888);
  ui->label->setPixmap(QPixmap::fromImage(RGB_Img));

  delete qnode->img_raw_;
  qnode->img_raw_ = NULL;
  qnode->isreceived = false;
}
void MainWindow::test2()
{
  RCLCPP_INFO(rclcpp::get_logger("ui_test2"), "되냐?");
}