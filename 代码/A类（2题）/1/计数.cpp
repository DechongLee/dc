#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void CountSort(int* arr, int n)
{
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i]-min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[j] = i + min;
			j++;
		}
	}

	free(countArr);
}
int main()
{
	int a[1000],n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	CountSort(a, n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
//时间复杂度：O（n+k）、空间复杂度：O（k）。n为数组长度、k为数组中元素的取值范围 
