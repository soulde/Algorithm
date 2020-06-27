#include"Sort.h"

double duration(void function(int* list, int num), int* list, int num)
{
	clock_t start, end;

	start = clock();
	function(list, num);
	end = clock();

	double endtime = (double)((end - start)) * 1000 / CLK_TCK;

	return endtime;
}

void show(int* List, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf_s("%d ", *(List + i));
	}
}

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void BubbleSort(int* List, int num)
{
	int tag = 1;
	for (int i = 0; i < num && tag; i++)
	{
		tag = 0;
		for (int j = num - 1; j > i; j--)
		{
			if (List[j] < List[j - 1])
			{
				swap(List + j, List + j - 1);
				tag = 1;
			}
		}
	}
}

void SelectSort(int* List, int num)
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
			swap(List + i, List + minIndex);
		}
	}
}

void InsertSort(int* List, int num)
{
	int temp,j;
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

void ShellSort(int* List, int num)
{
	int increasement = num;
	int j =0,temp =0;
	do
	{
		
		increasement = increasement / 3 + 1;
		for (int i = 0; i < num - increasement ; i++)
		{
			if (List[i + increasement] < List[i])
			{
				temp = List[i + increasement];
				for (j = i; j >= 0 && temp < List[j]; j -= increasement)
				{
					List[j + increasement] = List[j];
				}
				List[j + increasement] = temp;
			}
			
		}
	} while (increasement > 1);
}

void HeapSort(int* List, int num)
{

}