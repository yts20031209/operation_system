#include "processgiver.h"

processGiver::processGiver()
{

}


void processGiver::run(){

}
processGiver::processGiver(int numberOfProcess,int numberOfHandler,int frequencyOfHandler){
    this->frequencyOfHandler=frequencyOfHandler;
    this->numberOfProcess=numberOfProcess;
    this->numberOfHandler=numberOfHandler;
}
std::vector<process> processGiver::CreatProcess(int num) {
    std::vector<process> processes;
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 1; i <= num; i++) {
    int id = i;
    int priority = std::rand() % 10 + 1; // 生成1到10之间的随机整数
    double runTime = static_cast<double>(std::rand()) / RAND_MAX * 10.0; // 生成0到10之间的随机浮点数

    process process(id, priority, runTime);
    processes.push_back(process);
    }

    return processes;
}

void processGiver::deliverProcess(std::vector<handler>& handlers, std::vector<process>& processes) {
    if (handlers.empty() || processes.empty()) {
        std::cout << "No handlers or processes provided." << std::endl;
        return;
    }

    double fewestTimeHandler = handlers[0].getCurrentTime();
    size_t fewestTimeHandlerIndex = 0;

    for (size_t i = 1; i < handlers.size(); i++) {
        if (handlers[i].getCurrentTime() <= fewestTimeHandler) {
            fewestTimeHandler = handlers[i].getCurrentTime();
            fewestTimeHandlerIndex = i;
        }
    }

    double id = 0;

    for (process& p : processes) {
        if (!p.getWetherGiven()) {
            id = p.getId();
            break;  // Exit the loop once an unallocated process is found.
        }
    }

    if (id == 0) {
        std::cout << "All processes have been allocated." << std::endl;
    } else {
        handlers[fewestTimeHandlerIndex].addToPool(id);
    }
}
