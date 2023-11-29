#include "handler.h"

std::mutex poolMutex;
std::mutex poolMutex1;
handler::handler()
{

}

handler::handler(int id, std::vector<process> processive,class disk h){
    this->id=id;
    this->processin=processive;
    this->disk=h;
}
int handler::findProcessToRun() {

    int highestPriorityProcessId=0;
    for (auto it = processDataList.begin(); it != std::prev(processDataList.end()); ++it) {
        if (it->priority >= std::next(it)->priority) {
            highestPriorityProcessId=it->id;
        }
        else{

        }

    }
    return highestPriorityProcessId;
}

void handler::run(){
    this->putOutPoolToQueue();
    int num=this->findProcessToRun();
    this->running(num);
    this->deleteProgressInList();
}
double handler::getQueueTotalTime(){
    double totalTime = 0.0;
    for (const processList& processStructure : processDataList) {
        totalTime += processStructure.runTime-processStructure.runedTime;
    }
    return totalTime;
}

double handler::getCurrentTime(){
    double totaltime=0;
    poolMutex1.lock();
    for(int i=0;i<100;i++){
        if(this->pool[i]!=0){
            int num=this->pool[i];
            totaltime+=this->processin[num].getRunTime();
        }
    }
    poolMutex1.unlock();
    return this->getQueueTotalTime()+totaltime;
}
bool handler::getWetherFinished(){
    poolMutex.lock();
    int x=static_cast<int>(processDataList.size());//队列中
    int j=0;//池子中的进程数目
    for(int i=0;i<100;i++){
        if(pool[i+1]!=0){
            j++;
        }
    }
    poolMutex.unlock();
    if(x+j==0){
        return true;
    }
    else{
        return false;
    }
}
int handler::getCurrentId(){
    return this->processDataList.front().id;
}
void handler::setId(int t){
    this->id=t;
}
void handler::setProcess(std::vector<process> processessss){
    this->processin=processessss;
}
void handler::running(int n) {
    std::list<processList>::iterator it = this->processDataList.begin();
    std::advance(it, n); // 移动迭代器到第 n 个元素

    // 现在 it 指向第 n 个元素
    processList& nthElement = *it;
    int ipd=nthElement.id-1;
    this->processin[ipd].setWetherProcessed(1);
    // msleep(this->processin[ipd].getRunTime());
    // 在 nthElement 中执行你的操作
}
int handler::getId(){
    return this->id;
}
handler::handler(int id){
    this->id=id;
}
void handler::putOutPoolToQueue() {
    poolMutex.lock();
    for(int i = 0; i < 100; i++) {
        if(this->pool[i] != 0) {
            processList newPcb;
            newPcb.id = this->processin[i].getId();
            newPcb.runTime = this->processin[i].getRunTime();
            newPcb.priority = this->processin[i].getPriority();
            newPcb.channal = this->processin[i].getChannal();
            newPcb.space = this->processin[i].getSpace();

            // 为进程分配内存
            for (auto entry : this->disk.matrix) {
                if (entry[1] >= newPcb.space) { // 假设matrix的第二个属性足够大
                    newPcb.address = entry[0];   // 将matrix的第一个属性赋值给process的address
                    // 可能需要更新matrix以反映内存分配

                    // 获取磁盘块的 vector
                    std::vector<double>& p = entry; // 注意：这里假设 entry 是一个 std::vector<double>
                    this->processin[i].setInnitialAddress(newPcb.address);
                    // 将新的 PCB 分配到磁盘块的 vector 中
                    p.push_back(newPcb.address);
                    p.push_back(newPcb.space);

                    // 可以选择更新磁盘块的其他属性，如果需要的话

                    // 如果需要，你还可以将磁盘块的 vector 按照某种顺序排序

                    break;
                }
            }


            this->processDataList.push_back(newPcb);
        }
        pool[i] = 0;
    }
    poolMutex.unlock();
}
void handler::deleteProgressInList() {//如果被处理，就删除节点
    for (auto it = processDataList.begin(); it != processDataList.end();) {
        if (it->wetherProcessed == 1) {
            std::vector<double> newRow;
            newRow.push_back(it->address);
            newRow.push_back(it->space);
            this->disk.insertRowInOrder(newRow);
            it = processDataList.erase(it);


        }
        }
    }

void handler::addToPool(int num){
    for(int i=0;i<100;i++){
        if(this->pool[i]==0){
            this->pool[i]=num;
        }
    }
}

