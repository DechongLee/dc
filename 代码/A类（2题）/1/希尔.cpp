#include<stdio.h>
void shellsort(int *a,int n)
{
	int gap=n;
	while(gap>1)
	{
		gap=gap/3+1;
		int i;
		for(i=0;i<n-gap;i++)
		{
			int e = i;
			int temp = a[e+gap];
			while(e>=0)
			{
				if(a[e]>temp)
				{
					a[e+gap] = a[e];
					e-=gap;
				}
				else
				{
					break;
				}
			}
			a[e+gap] = temp;
		}
	}
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
	shellsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
//时间复杂度:O(n^1.5),空间复杂度:O(1)。
