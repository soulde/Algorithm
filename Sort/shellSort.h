//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_SHELLSORT_H
#define ALGORITHM_SHELLSORT_H

template<typename T>
void ShellSort(T* List, size_t num)
{
    int increase = num;
    int j =0,temp =0;
    do
    {

        increase = increase / 3 + 1;
        for (int i = 0; i < num - increase ; i++)
        {
            if (List[i + increase] < List[i])
            {
                temp = List[i + increase];
                for (j = i; j >= 0 && temp < List[j]; j -= increase)
                {
                    List[j + increase] = List[j];
                }
                List[j + increase] = temp;
            }

        }
    } while (increase > 1);
}

#endif //ALGORITHM_SHELLSORT_H

