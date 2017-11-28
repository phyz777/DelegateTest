#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
  :QMainWindow(parent),
   model(){
  this->model.insertTestItem(new TestClass());

  QTreeView* treeView = new QTreeView(this);
  treeView->setItemDelegate(new TestModelItemDelegate());
  treeView->setModel(&this->model);
  treeView->setRootIndex(this->model.index(0, 0, QModelIndex()));
  QMessageBox::information(nullptr, "Edit triggers",
                           "Edit triggers: " + QString::number(treeView->editTriggers()));
  this->setCentralWidget(treeView);
}

MainWindow::~MainWindow(){
  ;
}
