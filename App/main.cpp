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
    }
    w.show();
    return a.exec();
}
