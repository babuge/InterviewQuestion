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
 * FileName :           main.cpp
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

#include <QApplication>

#include "CTestModule.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testing::InitGoogleTest(&argc, argv);
    MainWindow w;
    if (g_pTestModule) {
        testing::AddGlobalTestEnvironment(g_pTestModule);
        w.RegisterSignal(g_pTestModule, SIGNAL(Signal_UpdateTestInfo(const QVariant &)));
        QObject::connect(&w,
                         &MainWindow::Signale_RunAllTest,
                         g_pTestModule,
                         &CTestModule::Slot_RunAllTest,
                         Qt::ConnectionType(Qt::UniqueConnection | Qt::QueuedConnection));
    }
    w.show();
    return a.exec();
}
