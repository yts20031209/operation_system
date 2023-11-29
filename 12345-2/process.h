#ifndef PROCESS_H
#define PROCESS_H


class process
{
private:
    int id;
    int priority;
    double runTime;
    double runedTime;
    bool wetherProcessed;
    bool wetherProcessing;
    bool wetherGiven;
    int channal;
    double innitialAddress;
    double space;
public:
    process();
    process(int id,int priority,double runtime,double space,double innitialAddress);
    int getId();
    double getInnitialAddress();
    double getSpace();
    void setSpace(double space);
    void setInnitialAddress(double x);
    int getPriority();
    double getRunTime();
    double getRunedTime();
    int getChannal();
    bool getWetherProcessing();
    bool getWetherProcessed();
    bool getWetherGiven();
    void setId(int id);
    void setPriority(int priority);
    void setRunTime(double runTime);
    void setRunedTime(double runedTime);
    void setWetherProcessing(bool wetherProcessing);
    void setWetherProcessed(bool wetherProcessed);
    void setWetherGiven(bool wetherGiven);
    void setChannal(int t);
};

#endif // PROCESS_H
