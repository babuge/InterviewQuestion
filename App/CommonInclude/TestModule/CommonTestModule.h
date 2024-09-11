#pragma once

#include "gtest/gtest.h"
#include <QMetaType>
#include <QStringList>

using ::testing::Environment;
using ::testing::Test;

struct TestInfo
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

Q_DECLARE_METATYPE(TestInfo)
