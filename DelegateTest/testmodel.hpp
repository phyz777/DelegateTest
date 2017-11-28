#ifndef TESTMODEL_HPP
#define TESTMODEL_HPP

// Qt5 includes
#include <QAbstractItemModel>
#include <QMessageBox>

// GUI includes
#include "testmodelitem.hpp"

class TestModel:public QAbstractItemModel{
public:
  TestModel();
  ~TestModel();

  int rowCount(QModelIndex const& =QModelIndex()) const;
  int columnCount(QModelIndex const& =QModelIndex()) const;

  QModelIndex index(int, int, QModelIndex const& =QModelIndex()) const;
  QModelIndex parent(QModelIndex const&) const;

  QVariant headerData(int, Qt::Orientation, int=Qt::DisplayRole) const;
  QVariant data(const QModelIndex&, int=Qt::DisplayRole) const;
  Qt::ItemFlags flags(QModelIndex const&);

  bool setHeaderData(int, Qt::Orientation, QVariant const&, int);
  bool setData(QModelIndex const&, QVariant const&, int);

  void insertTestItem(TestClass*);

  RootItem* getRoot();
private:
  RootItem* root;
};

#endif // TESTMODEL_HPP
