//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_HEAPSORT_H
#define ALGORITHM_HEAPSORT_H

#include "component.h"

template<typename T>
void adjustHeap(T* List, size_t root, size_t num)
{
    int n = 0;
    int temp = List[root-1];
    for (n = root * 2; n < num + 1; n *= 2)
    {

        if(List[n-1]<List[n]&&n!=num)
        {
            n++;
        }

        if (temp < List[n - 1])
        {
            List[n / 2 - 1] = List[n - 1];
        }
        else
        {
            break;
        }


    }
    List[n/2 - 1] = temp;
}

template<typename T>
void buildHeap(T* List, size_t num)
{
    for (int node = num / 2; node > 0; node--)
    {
        adjustHeap(List, node, num);
    }
}

template<typename T>
void HeapSort(T* List, size_t num)
{
    buildHeap<T>(List, num);
    swap<T>(List, List + num - 1);

    for (int i = num; i > 2; i--)
    {
        adjustHeap<T>(List, 1, i - 1);
        swap<T>(List, List + i - 2);
    }


}

#endif //ALGORITHM_HEAPSORT_H
