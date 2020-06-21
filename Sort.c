#include"Sort.h"

double duration(void function(int* list, int num), int* list, int num)
{
	clock_t start, end;

	start = clock();
	function(list, num);
	end = clock();

	double endtime = (double)((end - start))/ CLOCKS_PER_SEC;

	return endtime*1000;
}

void show(int* List, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf_s("%d ", *(List + i));
	}
}

void sort(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void BubbleSort(int* List, int num)
{
	int tag;
	for (int i = 0; i < num; i++)
	{
		tag = 1;
		for (int j = num - 1; j > i; j--)
		{
			if (List[j] < List[j - 1])
			{
				sort(List+j, List+j - 1);
				tag = 0;
			}
		}

		if (tag)
			break;
	}
}
