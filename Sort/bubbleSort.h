//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

#include "component.h"

template<typename T>
void bubbleSort(T* List, size_t num)
{
    int tag = 1;
    for (int i = 0; i < num && tag; i++)
    {
        tag = 0;
        for (int j = num - 1; j > i; j--)
        {
            if (List[j] < List[j - 1])
            {
                swap<T>(List + j, List + j - 1);
                tag = 1;
            }
        }
    }
}
#endif //ALGORITHM_BUBBLESORT_H



