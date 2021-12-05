#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct worstfit
{
    int size;
    int assign;
} wf;

int main()
{
    int n, m;
    printf("Enter no of processes");
    scanf("%d", &n);
    printf("Enter no of Holes");
    scanf("%d", &m);

    wf arr[n];

    int x[m];
    int y[m];

    printf("Enter process size one by one");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].size);
        arr[i].assign = -1;
    }

    printf("\nEnter the hole size one by one");

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < m; i++)
    {
        y[i] = x[i];
    }

    int touch=-1;
    int index= -1;

    for (int i = 0; i < n; i++)
    {
        touch = -1;
        index = -1;
        
        for (int j = 0; j < m; j++)
        {
            if (arr[i].size <= x[j])
            {
                if(touch<x[j])
                {
                    touch = x[j];
                    index = j;
                }                
            }
        }

        if(touch==-1 || index==-1)
        {
            arr[i].assign = -1;
        }
        else
        {
            arr[i].assign = index+1;
            x[index]-=arr[i].size;
        }
    }
    
    printf("Process\t\t\tHoles");
    for (int i = 0; i < n; i++)
    {
        if(arr[i].assign==-1)
        {
            printf("\np%d\t\t\t%d(%d)\n", i + 1, 0,0);
        }
        else
        printf("\np%d\t\t\t%d(%d)\n", i + 1, y[arr[i].assign - 1], x[arr[i].assign - 1]);
    }

    return 0;
}
