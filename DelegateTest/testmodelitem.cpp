#include "testmodelitem.hpp"

TestModelItemBase::TestModelItemBase()
  :itemType(TestModelItemBase::ITEM_TYPE::INVALID), index(-1), parent(nullptr){

}

TestModelItemBase::TestModelItemBase(TestModelItemBase::ITEM_TYPE type, int i, TestModelItemBase* p)
  :itemType(type), index(i), parent(p){

}

TestModelItemBase::~TestModelItemBase(){

}

TestModelItemBase::ITEM_TYPE TestModelItemBase::getItemType() const{
  if(nullptr==this){
    return TestModelItemBase::ITEM_TYPE::ISNULL;
  }
  return this->itemType;
}

int TestModelItemBase::getIndex() const{
  if(nullptr==this){
    return -2;
  }
  return this->index;
}

TestModelItemBase* TestModelItemBase::getParent(){
  if(nullptr==this){
    return nullptr;
  }
  return this->parent;
}

int TestModelItemBase::size(){
  return -1;
}

RootItem::RootItem()
  :TestModelItemBase(TestModelItemBase::ITEM_TYPE::ROOT,
                     0, nullptr){

}

RootItem::~RootItem(){

}

QList<TestModelItem*>& RootItem::getList(){
  return this->list;
}

void RootItem::appendChild(TestModelItem* child){
  this->list.append(child);
}

int RootItem::size(){
  return this->list.size();
}

TestModelItem::TestModelItem(TestClass* d, int index, RootItem* parent)
  :data(d),
   TestModelItemBase(TestModelItemBase::ITEM_TYPE::TEST_ITEM,
                     index, parent){

}

TestModelItem::~TestModelItem(){

}

TestClass* TestModelItem::getData(){
  return this->data;
}

int TestModelItem::size(){
  return 0;
}
