#ifndef TESTMODELITEMDELEGATE_HPP
#define TESTMODELITEMDELEGATE_HPP

// Qt5 includes
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QStyledItemDelegate>

// GUI includes
#include "testmodelitem.hpp"

class TestModelItemDelegate:public QStyledItemDelegate{
Q_OBJECT

public:
  TestModelItemDelegate();
  ~TestModelItemDelegate();

  QWidget* createEditor(QWidget*, QStyleOptionViewItem const&, QModelIndex const&) const override;
  void setEditorData(QWidget*, QModelIndex const&) const override;
  void setModelData(QWidget*, QAbstractItemModel*, QModelIndex const&);
  void updateEditorGeometry(QWidget* editor, QStyleOptionViewItem const& option,
                            QModelIndex const& index) const;

private:
  QWidget* createTestEditor(QWidget*) const;
};

#endif // TESTMODELITEMDELEGATE_HPP
