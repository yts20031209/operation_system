#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "processgiver.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    std::vector<process> processes;
    processGiver processgiver;
    handler* handlers[6];

private slots:

    void on_creatChannelPushButton_clicked();
    void on_runPushButton_clicked();
    void on_refreshPushButton_clicked();
    void on_creatProcessButton_clicked();
};
#endif // MAINWINDOW_H
