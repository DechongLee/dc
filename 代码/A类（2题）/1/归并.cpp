#include<stdio.h>
void _MergeSort(int* arr, int left, int right, int* temp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, temp);
	_MergeSort(arr, mid + 1, right, temp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			temp[i] = arr[begin1];
			begin1++;
		}
		else
		{
			temp[i] = arr[begin2];
			begin2++;
		}
		i++;
	}

	while (begin1 <= end1)
	{
		temp[i] = arr[begin1];
		begin1++;
		i++;
	}

	while (begin2 <= end2)
	{
		temp[i] = arr[begin2];
		begin2++;
		i++;
	}
	for (i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
}
int main(void)
{
	int a[1000],n,temp[1000]={'0'};
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int begin = 0,end = n-1;
	_MergeSort(a,begin,end,temp);
	_MergeSort(a, 0, n - 1, temp);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
//时间复杂度：O（nlogn）、空间复杂度：O（n）。
