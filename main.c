#include"Sort.h"

#include<stdio.h>

//change solution here
#define SORT ShellSort
#define LEN 30

int main()
{
	//init the list
	srand(time(0));
	int testlist[LEN] = {0};
	for (int i = 0; i < LEN; i++)
	{
		*(testlist + i) = rand();
	}

	//show before sort
	show(testlist,LEN);

	printf_s("\n");

	//sort
	double durtime = duration(SORT, testlist, LEN);

	//show after sort
	show(testlist,LEN);

	printf_s("\n");
	printf_s("sort using time: %f ms",durtime);

	system("pause");

	return 0;
}