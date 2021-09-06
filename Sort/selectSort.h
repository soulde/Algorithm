//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_SELECTSORT_H
#define ALGORITHM_SELECTSORT_H

#endif //ALGORITHM_SELECTSORT_H


template<typename T>
void SelectSort(T* List, size_t num)
{
    int minIndex = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (List[j] < List[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap<T>(List + i, List + minIndex);
        }
    }
}