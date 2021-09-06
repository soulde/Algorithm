//
// Created by lyjly on 2021/9/6.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include "component.h"


int Qsort(int* List, int lowIdx, int highIdx)
{

    int pivotValue = List[lowIdx];

    while (lowIdx < highIdx)
    {
        while (lowIdx < highIdx && List[highIdx] > pivotValue)
            highIdx--;
        List[lowIdx] = List[highIdx];

        while (lowIdx < highIdx && List[lowIdx] < pivotValue)
            lowIdx++;
        List[highIdx] = List[lowIdx];
    }

    List[lowIdx] = pivotValue;

    return lowIdx;
}


void QuickSort(int* List, int num)
{
    int pivot = 0;
    Node* head = creatLinklist();

    addNode(head, 0, -1);
    addNode(head, 1, num);

    while (head->next->next != NULL)
    {
        Node* del = NULL;
        while (head->next->next != NULL && head->next->next->numData - head->next->numData <= 2)
        {
            del = head->next;
            head->next = head->next->next;
            free(del);
        }

        for (Node* p = head->next; p != NULL && p->next != NULL; p = p->next->next)
        {
            if (p->next->numData - p->numData <= 2)
            {
                continue;
            }

            pivot = Qsort(List, p->numData + 1, p->next->numData - 1);

            Node* item = (Node*)malloc(NLEN);
            item->numData = pivot;

            item->next = p->next;
            p->next = item;



        }
    }

    clear(head);
}

#endif //ALGORITHM_QUICKSORT_H
