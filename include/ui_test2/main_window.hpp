/**
 * @file /include/ui_test2/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date January 2025
 **/

#ifndef ui_test2_MAIN_WINDOW_H
#define ui_test2_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "QIcon"
#include "qnode.hpp"
#include "ui_mainwindow.h"
#include <cv_bridge/cv_bridge.h>

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QNode *qnode;

public Q_SLOTS:
  void slotUpdateImg();
  void test2();

private:
  Ui::MainWindowDesign *ui;
  void closeEvent(QCloseEvent *event);
  cv::Mat clone_mat;
};

#endif // ui_test2_MAIN_WINDOW_H
