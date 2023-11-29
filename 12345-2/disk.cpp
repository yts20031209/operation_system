#include "disk.h"

disk::disk()
{

}
void disk::setElement(double row, double col, double value) {
    if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[row].size()) {
        matrix[row][col] = value;
    }
}

double disk::getElement(double row, double col) {
    if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[row].size()) {
        return matrix[row][col];
    }

}
void disk::insertRowInOrder(std::vector<double> newRow) {
    if (newRow.empty()) {
        // 如果新行为空，直接返回
        return;
    }

    // 遍历matrix寻找插入点
    for (auto it = this->matrix.begin(); it != this->matrix.end(); ++it) {
        if (!it->empty() && it->front() >= newRow.front()) {
            // 在找到的位置插入新行
            this->matrix.insert(it, newRow);
            return; // 插入后返回
        }
    }

    // 如果没有找到合适的插入点，将新行添加到末尾
    this->matrix.push_back(newRow);
}
