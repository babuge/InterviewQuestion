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
 * FileName :           CTestListView.h
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

#include <QListView>

class CTestStandardItemModel;
class CTestStyledItemDelegate;
class CTestListView : public QListView
{
    Q_OBJECT
public:
    explicit CTestListView(QWidget *parent = nullptr);
    virtual ~CTestListView();

    void RegisterSignal(const QObject *sender, const char *signal);
    void init();
private Q_SLOTS:
    void Slot_UpdateTestInfo(const QVariant &);

private:
    CTestStandardItemModel *m_pModel;
    CTestStyledItemDelegate *m_pDelegate;
};
