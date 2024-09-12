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
 * FileName :           MainWindow.h
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

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindowPrivate;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void RegisterSignal(const QObject *sender, const char *signal);

Q_SIGNALS:
    void Signale_RunAllTest();
private Q_SLOTS:
    void Slot_ClickedTestBtn();

private:
    Ui::MainWindow *ui;

private:
    Q_DECLARE_PRIVATE(MainWindow);
    MainWindowPrivate *d_ptr;
};
r;
};
