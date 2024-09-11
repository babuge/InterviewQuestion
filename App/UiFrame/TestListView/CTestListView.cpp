#include "CTestListView.h"
#include "CTestStandardItemModel.h"
#include "CTestStyledItemDelegate.h"
#include <QDebug>

CTestListView::CTestListView(QWidget *parent)
    : QListView(parent)
    , m_pModel(new CTestStandardItemModel)
    , m_pDelegate(new CTestStyledItemDelegate)
{
}
void CTestListView::init()
{
    if (m_pModel == nullptr || m_pDelegate == nullptr) {
        return;
    }
    setViewMode(QListView::ListMode);
    setSelectionMode(QAbstractItemView::NoSelection);
    m_pModel->setColumnCount(3);
    setModel(m_pModel);
    setItemDelegate(m_pDelegate);
}
void CTestListView::RegisterSignal(QObject *sender, char *signal)
{
    connect(sender,
            signal,
            this,
            SLOT(Slot_UpdateTestInfo(const QVariant &)),
            Qt::ConnectionType(Qt::UniqueConnection | Qt::QueuedConnection));
}

void CTestListView::Slot_UpdateTestInfo(const QVariant &data)
{
    //
    qDebug() << "receive: " << data;
}
