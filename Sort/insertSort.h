//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_INSERTSORT_H
#define ALGORITHM_INSERTSORT_H

#include "component.h"

template<typename T>
void InsertSort(T* List, size_t num)
{
    T temp;
    int j;
    for (int i = 0; i < num-1; i++)
    {
        if (List[i] > List[i +1])
        {
            temp = List[i+1];
            for (j = i ; List[j] > temp && j > -1; j--)
            {
                List[j+1] = List[j];
            }
            List[j+1] = temp;
        }
    }
}

#endif //ALGORITHM_INSERTSORT_H

