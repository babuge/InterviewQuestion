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
 * FileName :           CTestStandardItemModel.h
 * FileIdentification :
 * Abstract :           
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :   
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#pragma once

#include <QStandardItemModel>

class CTestStandardItemModel : public QStandardItemModel
{
public:
    explicit CTestStandardItemModel(QObject *parent = nullptr);
    virtual ~CTestStandardItemModel();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
};
e;
};
