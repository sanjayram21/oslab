#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct firstfit
{
    int size;
    int assign;
} ff;

int main()
{
    int n, m;
    printf("Enter no of processes");
    scanf("%d", &n);
    printf("Enter no of Holes");
    scanf("%d", &m);

    ff arr[n];

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i].size <= x[j])
            {
                arr[i].assign = j + 1;
                x[j] -= arr[i].size;
                break;
            }
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
