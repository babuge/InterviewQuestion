#include "CTestStandardItemModel.h"

CTestStandardItemModel::CTestStandardItemModel(QObject *parent)
    : QStandardItemModel{ parent }
{
}

QVariant CTestStandardItemModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return QStandardItemModel::data(index, Qt::UserRole + 1);
    }
    return QStandardItemModel::data(index, role);
}
bool CTestStandardItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (Qt::ForegroundRole == role) {

        QStandardItemModel::setData(index, QVariant::fromValue(Qt::darkYellow), role);
        return true;
    }
    else if (role == Qt::UserRole + 1) {
        QStandardItemModel::item(index.row(), index.column())->setData(value);
        return true;
    }
    return QStandardItemModel::setData(index, value, role);
}
