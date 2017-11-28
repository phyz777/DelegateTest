#ifndef TESTMODELITEM_HPP
#define TESTMODELITEM_HPP

#include <QList>

class TestModelItemBase{
public:
  enum class ITEM_TYPE{
    ISNULL, INVALID, ROOT, TEST_ITEM
  };

  TestModelItemBase();
  TestModelItemBase(ITEM_TYPE, int, TestModelItemBase*);
  virtual ~TestModelItemBase();

  ITEM_TYPE getItemType() const;
  int getIndex() const;
  TestModelItemBase* getParent();

  virtual int size();

private:
  ITEM_TYPE itemType;
  int index;
  TestModelItemBase* parent;
};

class RootItem;
class TestModelItem;
class TestClass;

class RootItem:public TestModelItemBase{
public:
  RootItem();
  ~RootItem();

  QList<TestModelItem*>& getList();

  void appendChild(TestModelItem*);

  virtual int size();
private:
  QList<TestModelItem*> list;
};

class TestModelItem:public TestModelItemBase{
public:
  TestModelItem(TestClass*, int, RootItem*);
  ~TestModelItem();

  TestClass* getData();

  virtual int size();
private:
  TestClass* data;
};

class TestClass{

};

#endif // TESTMODELITEM_HPP
