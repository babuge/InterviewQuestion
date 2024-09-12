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
 * FileName :           MainWindow.cpp
 * FileIdentification :
 * Abstract :           
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :   
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#include "MainWindow.h"
#include "CTestListView.h"
#include "ui_MainWindow.h"

#include <QDebug>

class MainWindowPrivate
{
    Q_DECLARE_PUBLIC(MainWindow)
public:
    explicit MainWindowPrivate(MainWindow *qPtr);
    ~MainWindowPrivate();
    void init();

private:
    MainWindow *q_ptr;
    CTestListView *m_pTestListView;
};

MainWindowPrivate::MainWindowPrivate(MainWindow *qPtr)
    : q_ptr(qPtr)
    , m_pTestListView(nullptr)
{
}

MainWindowPrivate::~MainWindowPrivate()
{
    if (m_pTestListView != nullptr) {
        delete m_pTestListView;
        m_pTestListView = nullptr;
    }
}

void MainWindowPrivate::init()
{
    Q_Q(MainWindow);
    if (q->ui == nullptr || q->ui->listViewLayout == nullptr) {
        return;
    }
    if (m_pTestListView == nullptr) {
        m_pTestListView = new CTestListView();
        if (m_pTestListView == nullptr) {
            return;
        }
        m_pTestListView->init();
        q->ui->listViewLayout->addWidget(m_pTestListView);

        QObject::connect(
            q->ui->testBtn, &QPushButton::clicked, q, &MainWindow::Slot_ClickedTestBtn);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , d_ptr(new MainWindowPrivate(this))
{
    ui->setupUi(this);
    if (d_ptr) {
        d_ptr->init();
    }
    // ui->listViewLayout
    // ui->testBtn;
}

MainWindow::~MainWindow()
{
    if (d_ptr != nullptr) {
        delete d_ptr;
        d_ptr = nullptr;
    }
    delete ui;
}

void MainWindow::RegisterSignal(const QObject *sender, const char *signal)
{
    Q_D(MainWindow);
    if (d->m_pTestListView != nullptr) {
        d->m_pTestListView->RegisterSignal(sender, signal);
    }
}

void MainWindow::Slot_ClickedTestBtn()
{
    emit this->Signale_RunAllTest();
}
();
}
