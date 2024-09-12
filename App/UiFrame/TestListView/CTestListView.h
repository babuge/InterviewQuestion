#pragma once

#include <QListView>

class CTestStandardItemModel;
class CTestStyledItemDelegate;
class CTestListView : public QListView
{
    Q_OBJECT
public:
    explicit CTestListView(QWidget *parent = nullptr);
    virtual ~CTestListView();

    void RegisterSignal(const QObject *sender, const char *signal);
    void init();
private Q_SLOTS:
    void Slot_UpdateTestInfo(const QVariant &);

private:
    CTestStandardItemModel *m_pModel;
    CTestStyledItemDelegate *m_pDelegate;
};
