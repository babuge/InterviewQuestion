#pragma once

#include <QListView>

class CTestStandardItemModel;
class CTestStyledItemDelegate;
class CTestListView : public QListView
{
public:
    explicit CTestListView(QWidget *parent = nullptr);

    void RegisterSignal(QObject *sender, char *signal);
    void init();
private Q_SLOTS:
    void Slot_UpdateTestInfo(const QVariant &);

private:
    CTestStandardItemModel *m_pModel;
    CTestStyledItemDelegate *m_pDelegate;
};
