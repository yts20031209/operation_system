#ifndef PROCESSGIVER_H
#define PROCESSGIVER_H
#include "handler.h"

class processGiver:public handler
{
private:

    int numberOfProcess;
    int numberOfHandler;
    int frequencyOfHandler;
    std::vector<process> processes;

    std::vector<int> finish;

public:
    void run() override;
    processGiver();

    processGiver(int numberOfProcess,int numberOfHandler,int frequencyOfHandler);
    std::vector<process> CreatProcess(int num);
    //创建进程
    void deliverProcess(std::vector<handler>& handlers,std::vector<process>& processes);//将创建的传入handler线程里面


};

#endif // PROCESSGIVER_H
