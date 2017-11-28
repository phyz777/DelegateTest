#include "testmodel.hpp"

TestModel::TestModel()
  :root(new RootItem()){

}

TestModel::~TestModel(){

}

int TestModel::rowCount(QModelIndex const& parent) const{
  TestModelItemBase* itemBase =
    reinterpret_cast<TestModelItemBase*>(parent.internalPointer());
  switch(itemBase->getItemType()){
    case TestModelItemBase::ITEM_TYPE::ROOT:
      {
        RootItem* item = dynamic_cast<RootItem*>(itemBase);
        return item->getList().size();
      }
    case TestModelItemBase::ITEM_TYPE::TEST_ITEM:
      {
        TestModelItem* item = dynamic_cast<TestModelItem*>(itemBase);
        return 0;
      }
    default:
      return -1;
  }
}

int TestModel::columnCount(QModelIndex const& parent) const{
  return 1;
}

QModelIndex TestModel::index(int row, int column, QModelIndex const& parent) const{
  if(0!=column){
    return QModelIndex();
  }
  if(!parent.isValid()){
    if(row==0){
      return this->createIndex(0, 0, this->root);
    }
    return QModelIndex();
  }
  TestModelItemBase* parentItemBase = reinterpret_cast<TestModelItemBase*>(parent.internalPointer());
  TestModelItemBase::ITEM_TYPE itemType = parentItemBase->getItemType();
  switch(itemType){
    case TestModelItemBase::ITEM_TYPE::ROOT:
      {
        RootItem* parentItem = dynamic_cast<RootItem*>(parentItemBase);
        return this->createIndex(row, 0, reinterpret_cast<void*>(parentItem->getList().at(row)));
      }
    case TestModelItemBase::ITEM_TYPE::TEST_ITEM:
      return QModelIndex();
    default:
      return QModelIndex();
  }
}

QModelIndex TestModel::parent(QModelIndex const& index) const{
  TestModelItemBase* parent =
    reinterpret_cast<TestModelItemBase*>(index.internalPointer());
  return this->createIndex(parent->getIndex(), 0,
                           reinterpret_cast<void*>(parent->getParent()));
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const{
  if (0==section && Qt::Orientation::Horizontal==orientation && Qt::DisplayRole==role) {
    int i = 42;
    return QVariant(i);
  } else {
    return QVariant();
  }
}

QVariant TestModel::data(QModelIndex const& index, int role) const{
  TestModelItemBase* item = reinterpret_cast<TestModelItemBase*>(index.internalPointer());
  if(Qt::DisplayRole==role){
    switch(item->getItemType()){
      case TestModelItemBase::ITEM_TYPE::TEST_ITEM:
        return QString("Test item");
      default:
        return QString("");
    }
  }else{
    if(Qt::EditRole==role){
      QMessageBox::information(nullptr, "Model data", "We have an edit role");
    }
    if(Qt::UserRole==role){
      QMessageBox::information(nullptr, "Model data", "We have a user role");
    }

    return QVariant();
  }
}

Qt::ItemFlags TestModel::flags(QModelIndex const&){
  QMessageBox::information(nullptr, "Model Flags", "Selectable, Editable, Enabled");

  return (Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled);
}

bool TestModel::setHeaderData(int, Qt::Orientation, const QVariant&, int){
  QMessageBox::information(nullptr, "Set header data", "Just return true");

  return true;
}

bool TestModel::setData(const QModelIndex&, const QVariant&, int){
  QMessageBox::information(nullptr, "Set data", "Just return true");

  return true;
}

void TestModel::insertTestItem(TestClass* testClass){
  if(nullptr==testClass){
    QMessageBox::critical(nullptr, "Critical", "Not inserting nullptr");
    return;
  }

  TestModelItem* child = new TestModelItem(testClass, this->root->size(), this->root);
  this->beginInsertRows(this->createIndex(0, 0, reinterpret_cast<void*>(this->root)),
                        this->root->size(), this->root->size());
  this->root->appendChild(child);
  this->endInsertRows();
}

RootItem* TestModel::getRoot(){
  return this->root;
}
