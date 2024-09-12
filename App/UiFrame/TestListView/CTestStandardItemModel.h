#pragma once

#include <QStandardItemModel>

class CTestStandardItemModel : public QStandardItemModel
{
public:
    explicit CTestStandardItemModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
};
