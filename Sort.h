#pragma once
#include<stdlib.h>
#include<time.h>
#include"Node.h"

double duration(void function(int* list, int num), int* list, int num);

void show(int* List,int num);

void swap(int* first, int* second);

void BubbleSort(int* List, int num);

void SelectSort(int* List, int num);

void InsertSort(int* List, int num);

void ShellSort(int* List, int num);

void adjustHeap(int* List, int root, int num);

void buildHeap(int* List, int num);

void HeapSort(int* List, int num);

//QuickSort Part

int Qsort(int* List, int lowIdx, int highIdx);

void QuickSort(int* List, int num);