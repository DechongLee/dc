#include<stdio.h> 
void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int GetMidIndex(int* arr, int left, int right)
{
    int mid = (left + right) / 2;
    
	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[left])
		{
			return left;
		}
		else if (arr[mid] <arr[right])
		{
			return mid;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (arr[mid] < arr[right])
		{
			return right;
		}
		else if (arr[mid] < arr[left])
		{
			return mid;
		}
		else
		{
			return left;
		}
	}
}
int PartSort(int* arr, int left, int right)
{
    int key = GetMidIndex(arr, left, right);
    Swap(&arr[key], &arr[left]);
    
    key = arr[left];
    int hole = left;
    
    while (left < right)
    {
        while (left < right && arr[right] >= key)
        {
            right--;
        }
        arr[hole] = arr[right];
        hole = right;
        
        while (left < right && arr[left] <= key)
        {
            left++;
        }
        arr[hole] = arr[left];
        hole = left;
    }
    
    arr[hole] = key;
    return hole;
}
void QuickSort(int* arr, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    
    int key = PartSort(arr, begin, end);
    QuickSort(arr, begin, key-1);
    QuickSort(arr, key+1, end);
}
int main(void)
{
	int a[1000],n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int begin = 0,end = n-1;
	QuickSort(a,begin,end);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
//时间复杂度：O（nlogn）、空间复杂度：O（logn）。
