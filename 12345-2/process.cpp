#include "process.h"

process::process()
{
}
process::process(int id,int priority,double runTime,double space,double x){
    this->id=id;
    this->priority=priority;
    this->runTime=runTime;
    this->runedTime=0;
    this->wetherProcessing=0;
    this->wetherProcessed=0;
    this->setSpace(space);
    this->innitialAddress=x;
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
void process::setInnitialAddress(double x){
    this->innitialAddress=x;
}
void process::setSpace(double space){
    this->space=space;
}
double process::getInnitialAddress(){
    return this->innitialAddress;
}
double process::getSpace(){
    return this->space;
}
