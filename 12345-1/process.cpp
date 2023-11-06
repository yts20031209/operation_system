#include "process.h"

process::process()
{
}
process::process(int id,int priority,double runTime){
    this->id=id;
    this->priority=priority;
    this->runTime=runTime;
    this->runedTime=0;
    this->wetherProcessing=0;
    this->wetherProcessed=0;
}
int process::getId(){
    return this->id;
}
int process::getPriority(){
    return this->priority;
}
double process::getRunTime(){
    return this->runTime;
}
double process::getRunedTime(){
    return this->runedTime;
}
bool process::getWetherProcessed(){
    return this->wetherProcessed;
}
bool process::getWetherProcessing(){
    return this->wetherProcessing;
}
bool process::getWetherGiven(){
    return this->wetherGiven;
}
void process::setId(int id){
    this->id=id;
}
void process::setPriority(int priority){
    this->priority=priority;
}
void process::setRunTime(double time){
    this->runTime=time;
}
void process::setRunedTime(double time){
    this->runedTime=time;
}
void process::setWetherProcessed(bool x){
    this->wetherProcessed=x;
}
void process::setWetherProcessing(bool x){
    this->wetherProcessing=x;
}
void process::setWetherGiven(bool wetherGiven){
    this->wetherGiven=wetherGiven;
}
int process::getChannal(){
    return this->channal;
}
void process::setChannal(int t){
    this->channal=t;
}
