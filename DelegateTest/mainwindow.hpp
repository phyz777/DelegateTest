#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

// Qt5 includes
#include <QMainWindow>
#include <QMessageBox>
#include <QTreeView>

// GUI includes
#include "testmodel.hpp"
#include "testmodelitem.hpp"
#include "testmodelitemdelegate.hpp"

class MainWindow : public QMainWindow{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = 0);
  ~MainWindow();
private slots:

private:
  TestModel model;
};

#endif // MAINWINDOW_HPP
