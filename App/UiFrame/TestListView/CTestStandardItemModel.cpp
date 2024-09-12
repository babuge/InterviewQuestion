/******************************************************************************
 * Copyright (C) [2024] [github.com/babuge]
 *
 * [InterviewQuestion] is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 *
 * FileName :           CTestStandardItemModel.cpp
 * FileIdentification :
 * Abstract :           
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :   
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#include "CTestStandardItemModel.h"

CTestStandardItemModel::CTestStandardItemModel(QObject *parent)
    : QStandardItemModel{ parent }
{
}
CTestStandardItemModel::~CTestStandardItemModel() {}
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
e);
}
