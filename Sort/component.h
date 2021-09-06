//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_COMPONENT_H
#define ALGORITHM_COMPONENT_H

#include <iostream>
#include <ctime>
#include "Node.h"

template<typename T>
double duration(void function(T *list, size_t num), T *list, size_t num) {
    clock_t start, end;

    start = clock();
    function(list, num);
    end = clock();

    double endTime = (double) ((end - start)) * 1000 / CLK_TCK;

    return endTime;
}

template<typename T>
void show(T *List, size_t num) {
    for (int i = 0; i < num; i++) {
        std::cout << *(List + i) << std::endl;
    }
}


template<typename T>
void swap(T *first, T *second) {
    T temp = *first;
    *first = *second;
    *second = temp;
}


#endif //ALGORITHM_COMPONENT_H
