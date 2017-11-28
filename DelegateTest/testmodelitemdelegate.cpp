#include "testmodelitemdelegate.hpp"

TestModelItemDelegate::TestModelItemDelegate(){
  ;
}

TestModelItemDelegate::~TestModelItemDelegate(){
  ;
}

QWidget* TestModelItemDelegate::createEditor(QWidget* parent,
                                             QStyleOptionViewItem const& option,
                                             QModelIndex const& index) const{
  QMessageBox::information(nullptr, "Create editor", "Creating editor...");

  TestModelItemBase* item = reinterpret_cast<TestModelItemBase*>(index.internalPointer());

  switch(item->getItemType()){
    case TestModelItemBase::ITEM_TYPE::TEST_ITEM:
      return TestModelItemDelegate::createTestEditor(parent);
    default:
      break;
  }
}

void TestModelItemDelegate::setEditorData(QWidget*, QModelIndex const&) const{
  QMessageBox::information(nullptr, "Set editor data", "Doing nothing");
}

void TestModelItemDelegate::setModelData(QWidget*, QAbstractItemModel*,
                                         QModelIndex const&){
  QMessageBox::information(nullptr, "Set model data", "Doing nothing");
}

void TestModelItemDelegate::updateEditorGeometry(QWidget* editor, QStyleOptionViewItem const& option,
                                                 QModelIndex const& index) const{
  QMessageBox::information(nullptr, "Update editor geometry", "Doing nothing");
}

QWidget* TestModelItemDelegate::createTestEditor(QWidget* parent) const{
  QMessageBox::information(nullptr, "Create test editor", "Editor for testing");

  QWidget* editor = new QWidget(parent);

  QHBoxLayout* layout = new QHBoxLayout(editor);

  layout->addWidget(new QPushButton(editor));
  layout->addWidget(new QLineEdit(editor));

  editor->setLayout(layout);

  return editor;
}
