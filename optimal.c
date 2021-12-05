#include <stdio.h>

int size =  (int)4;

int max(int i , int j)
{
	if(i>j)
	{
		return i;
	}
	return j;
}
int search(int a[] , int n , int s)
{
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] == s)
		{
			return i;
		}
	}
	return -1;
}
int count_sort(int a[] , int l , int r , int frame[] , int size)
{
	int count[1000];

	for(int i = 0;i<1000;i++)
	{
		count[i] = 0;
	}
	for(int i = 0 ; i < size ; i++)
	{
		if(frame[i] == -1)
		{
			return i;
		}
	}
	for(int j = l ; j < r ; j++)
	{
		int ok = 0;

		int pos = 0;

		count[a[j]]++;

		for(int i = 0;i<size;i++)
		{
			if(count[frame[i]] == 0)
			{
				ok++;
				pos = i;
			}
		}
		if(ok == 1)
		{
			return pos;
		}
	}
	for(int i = 0 ; i < size ; i++)
	{
		if(count[frame[i]] == 0)
		{
			return i;
		}
	}
}
int main()
{
	printf("\nPage Replacement Technique OPT\n");
	int n, a[100];
	printf(" Enter Number Of Frames : "); scanf("%d",&size);
	printf(" Enter Length Of Page Reference String : "); scanf("%d",&n);
	printf("\n\n Page Reference String Input \n\n");
	for(int i = 0; i < n ; i++)
	{
		printf(" Enter Value %d : ", i + 1);
		scanf("%d",&a[i]);
		printf("\n");
	}
	int frame[100];
	int fault = 0;
	for(int i = 0;i<size;i++)
	{
		frame[i] = 0;
	}
	for(int i = 0;i<n;i++)
	{
		printf("\n\nReferencing : %d",a[i]);
		if(search(frame , size , a[i]) == -1)
		{
			printf("\nFAULT");
			fault++;
			int data = count_sort(a , i + 1 , n , frame , size);
			frame[data] = a[i];
		}
		for(int i = 0 ; i < size ; i++)
		{
			printf("\nFrame Number %d : %d", i + 1 ,frame[i]);
		}
	}	
	printf("\n\nNumber Of Faults : %d \n", fault);
	return 0;
}
