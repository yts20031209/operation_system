#ifndef HANDLER_H
#define HANDLER_H

#include<QThread>
#include<QMetaObject>
#include"process.h"
#include<chrono>
#include<mutex>
#include <iostream>
#include<vector>
#include "disk.h"

class handler: public QThread
{
    Q_OBJECT;
private:

    int listSize;
    int id;//通道的id
    double queueTotalTime;//队列链表面的总时间
    double currentTime;//通道的总时间
    bool wetherFinished;
    int currentId;//正在处理的进程id
    std::vector<process> processin;
    struct processList{
        int id;
        int priority;
        double runTime;
        double runedTime;
        bool wetherProcessed;
        bool wetherProcessing;
        int channal;
        double address;
        double space;
    };
    double totalTime;
    disk disk;
    int pool[100]={0};
public:
    handler();
    handler(int id);
    handler(int id,std::vector<process> processin,class disk d);
    void run() override;

    int getId();
    void setId(int t);
    void setProcess(std::vector<process> processes);
    double getQueueTotalTime();//计算在队列里面进程的总时间
    double getCurrentTime();//获取当前通道工作的总时间
    bool getWetherFinished();//获取是否完成处理，仅用于后期，不能用于线程前期
    int getCurrentId();//获取当下执行的id
    void setTotalTime(double time);//获取通道处理过的所有的进程的总时间
    void running(int number);//模拟运行进程
    void putOutPoolToQueue();//把池子里面等待的进程塞进处理通道中
    void deleteProgressInList();//在运行完之后，把这个进程丢出去
    int findProcessToRun();//找到要运行的结点在列表中的id
    void addToPool(int num);

private:
    std::list<processList> processDataList; // 用于管理进程的链表
};

#endif // HANDLER_H
