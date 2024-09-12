#pragma once

#include <QMetaType>
#include <QStringList>

struct CustomTestInfo
{
    QString itemName;
    QString indexName;
    bool isFold;
    QStringList rowName;
    QStringList rowData;
    QString date;
    QStringList btnNames;
    QList<bool> btnSelected;
};

Q_DECLARE_METATYPE(CustomTestInfo)
