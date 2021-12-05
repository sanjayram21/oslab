#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, i, j, k, flag = 0, y;
    printf("Enter no of processes: ");
    scanf("%d", &n);
    printf("Enter no of resources: ");
    scanf("%d", &m);
    int Alloc[n][m], Max[n][m], need[n][m];
    int available[m];
    int work[m], finish[n], safestate[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter allocation of process P%d for resources %d:", i, j + 1);
            scanf("%d", &Alloc[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        printf("Enter the available instance of resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("enter the max for process P%d for resource %d: ", i, j + 1);
            scanf("%d", &Max[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = Max[i][j] - Alloc[i][j];
        }
    }
    printf("NEED\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)

        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        int b = 0;
        for (j = 0; j < n; j++)

        {
            b += Alloc[j][i];
        }
        available[i] = available[i] - b;
    }
    printf("Available resources: ");
    for (i = 0; i < m; i++)
        printf("%d ", available[i]);
    for (i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    int x = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    safestate[x++] = i;
                    for (y = 0; y < m; y++)
                        work[y] = work[y] + Alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    flag = 0;
    for (i = 0; i < n; i++)
        if (finish[i] == 0)
            flag++;

    if (flag > 0)
    {
        printf("\nDEADLOCK....\n");
    }
    else
    {
        printf("\nSAFE STATES : ");
        for (i = 0; i < n; i++)
            printf("P%d ", safestate[i]);
        printf("\n");
        return 0;
    }
}
