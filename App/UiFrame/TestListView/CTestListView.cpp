#include "CTestListView.h"
#include "CTestStandardItemModel.h"
#include "CTestStyledItemDelegate.h"
#include "CommonTestModule.h"
#include <QDebug>

CTestListView::CTestListView(QWidget *parent)
    : QListView(parent)
    , m_pModel(new CTestStandardItemModel)
    , m_pDelegate(new CTestStyledItemDelegate)
{
}

CTestListView::~CTestListView()
{
    if (m_pModel != nullptr) {
        delete m_pModel;
        m_pModel = nullptr;
    }
    if (m_pDelegate != nullptr) {
        delete m_pDelegate;
        m_pDelegate = nullptr;
    }
}

void CTestListView::init()
{
    if (m_pModel == nullptr || m_pDelegate == nullptr) {
        return;
    }
    setViewMode(QListView::ListMode);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSpacing(5);
    m_pModel->setColumnCount(3);
    setModel(m_pModel);
    setItemDelegate(m_pDelegate);
}
void CTestListView::RegisterSignal(const QObject *sender, const char *signal)
{
    QObject::connect(sender,
                     signal,
                     this,
                     SLOT(Slot_UpdateTestInfo(const QVariant &)),
                     Qt::ConnectionType(Qt::UniqueConnection | Qt::QueuedConnection));
}

void CTestListView::Slot_UpdateTestInfo(const QVariant &data)
{
    if (m_pModel == nullptr) {
        return;
    }
    CustomTestInfo info         = data.value<CustomTestInfo>();
    QList<QStandardItem *> list = { new QStandardItem, new QStandardItem, new QStandardItem };
    int count                   = m_pModel->rowCount();
    m_pModel->insertRow(count, list);
    for (int i = 0; i < list.size(); ++i) {
        QModelIndex index = m_pModel->index(count, i);
        if (i == 0) {
            m_pModel->setData(index, data, Qt::UserRole + 1);
        }
        m_pModel->setData(index, QBrush(Qt::lightGray), Qt::BackgroundRole);
    }
}
