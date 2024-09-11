#include "MainWindow.h"
#include "CTestListView.h"
#include "CommonTestModule.h"
#include "ui_MainWindow.h"

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

void MainWindow::RegisterSignal(QObject *sender, char *signal)
{
    Q_D(MainWindow);
    if (d->m_pTestListView != nullptr) {
        d->m_pTestListView->RegisterSignal(sender, signal);
    }
}

void MainWindow::Slot_ClickedTestBtn()
{
    RUN_ALL_TESTS();
}
