#include "mainwindow.h"
#include "ui_mainwindow.h"
int numOfProcess;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    for (int i = 0; i < 6; i++) {
        this->handlers[i] = new handler;
    }

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_creatChannelPushButton_clicked()
{
    for (int i = 0; i < 6; ++i) {
        this->handlers[i]->setId(i+1);
        this->handlers[i]->setProcess(this->processes);

    }

    for (int i=0;i<6;i++) {
        std::string de = std::to_string(this->handlers[i]->getId());



        QListWidgetItem *item = new QListWidgetItem();
        item->setText(QString::fromStdString(de));
        ui->channalListWidget->addItem(item);
    }

}

void MainWindow::on_runPushButton_clicked()
{
    QString r=ui->processTextLineEdit->toPlainText();
    numOfProcess=r.toInt();
    int po=numOfProcess/6;
    for(int i=0;i<po;i++){
        for(int i=0;i<6;i++){

            this->handlers[i]->start();
        }
    }
}




void MainWindow::on_refreshPushButton_clicked()
{
    QString r=ui->processTextLineEdit->toPlainText();
    numOfProcess=r.toInt();
    int po=numOfProcess/6;
    for(int i=0;i<numOfProcess;i++){
        this->processes[i].setChannal(i/po+1);
    }
    for (process& process : this->processes) {
        std::string de = std::to_string(process.getId()) + "           " +
                         std::to_string(process.getChannal()) + "           " ;


        QListWidgetItem *item = new QListWidgetItem();
        item->setText(QString::fromStdString(de));
        ui->finishedProcesslistWidget->addItem(item);
    }
    ui->UnfinishedProcesslistWidget->show();
}


void MainWindow::on_creatProcessButton_clicked()
{
        QString r=ui->processTextLineEdit->toPlainText();
        numOfProcess=r.toInt();
        int po=numOfProcess/6;



        /*
        //传递进程
        for(int i=0;i<6;i++){
            int deliverChannalId=1;
            for(int t=0;t<6;t++){
                double time1=this->handlers[i]->getCurrentTime();
                double time2=this->handlers[i+1]->getCurrentTime();
                if(time1<=time2){
                    deliverChannalId=handlers[t]->getId();
                }
                else{
                    deliverChannalId=handlers[t+1]->getId();
                }
            }
        }
*/
        //传递进程（出现了较为奇特的bug，暂时不支持运行）

    numOfProcess=r.toInt();
    this->processes=this->processgiver.CreatProcess(numOfProcess);
        for(int i=0;i<6;i++){
            for(int t=0;t<po;t++){
                this->handlers[i]->addToPool(po*i+t+1);
            }
    }
    for (process& process : this->processes) {
        std::string de = std::to_string(process.getId()) + "           " +
                         std::to_string(process.getPriority()) + "           " +
                         std::to_string(process.getRunTime());

        QListWidgetItem *item = new QListWidgetItem();
        item->setText(QString::fromStdString(de));
        ui->UnfinishedProcesslistWidget->addItem(item);
    }
    ui->UnfinishedProcesslistWidget->show();
}

