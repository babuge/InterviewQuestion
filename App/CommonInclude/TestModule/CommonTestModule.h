#pragma once

#include "gtest/gtest.h"
#include <QMetaType>
#include <QStringList>
using ::testing::EmptyTestEventListener;
using ::testing::Environment;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

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
