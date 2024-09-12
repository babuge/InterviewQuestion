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
