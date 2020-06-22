#pragma once
#include<stdlib.h>
#include<time.h>

double duration(void function(int* list, int num), int* list, int num);

void show(int* List,int num);

void swap(int* first, int* second);

void BubbleSort(int* List, int num);

void SelectSort(int* List, int num);

void InsertSort(int* List, int num);

void HillSort(int* List, int num);