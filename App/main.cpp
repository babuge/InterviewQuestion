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
