#ifndef DISK_H
#define DISK_H
#include<iostream>
#include<vector>

class disk
{
private:
    double osSpace;
    double totalSpace;
    double cruuentLocation;

public:
    disk();
    std::vector<std::vector<double>> matrix;
    double getOsSpace();
    double getTotalSpace();
    double getCurrentLocation();
    void setOsSpace(double space);
    void setTotalSpace(double space);
    void setCurrentLocation(double currentLocation);
    void setElement(double row, double col, double value);
    double getElement(double row, double col);
    void insertRowInOrder(std::vector<double> newRow);

};

#endif // DISK_H
