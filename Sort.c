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

void adjustHeap(int* List, int root, int num)
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

void buildHeap(int* List, int num)
{
	for (int node = num / 2; node > 0; node--)
	{
		adjustHeap(List, node, num);
	}
}

void HeapSort(int* List, int num)
{
	buildHeap(List, num);
	swap(List, List + num - 1);

	for (int i = num; i > 2; i--)
	{
		adjustHeap(List, 1, i - 1);
		swap(List, List + i - 2);
	}


}






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
