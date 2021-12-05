#include <stdio.h>
#include <stdlib.h>

int indexno,no_of_files,file[10000];

typedef struct indexed
{
    int val;
    int assign;
}index;



int main()
{

    for (int i = 0; i < 10000; i++)
    {
        file[i] = -1;  
    }
    
    index indexing[10000];
    printf("Enter indexno of the block=");
    scanf("%d",&indexno);
    printf("\nEnter the no of files to be inserted into the index %d=",indexno);
    scanf("%d",&no_of_files);

    for (int i = 0; i < no_of_files; i++)
    {
        scanf("%d",&indexing[i].val);
        indexing[i].assign = 1;
    } 

    printf("Starting Block\t\tNumber\t\tAllocated\n");

    for (int i = 0; i < no_of_files; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\n",indexno,indexing[i].val,indexing[i].assign);  
    }

    int ch;

    l1:printf("Enter 1 to add more files and any other number to exit");
    scanf("%d",&ch);

    if(ch==1)
    {
        int nof;
        int buffer[10000];
        printf("Enter indexno of the block=");
        scanf("%d", &indexno);
        printf("\nEnter the no of files to be inserted into the index %d=", indexno);
        scanf("%d", &nof);

        for (int i = 0; i < nof; i++)
        {
            scanf("%d",&buffer[i]);           
        }

        int flag = 0;

        for (int i = 0; i < nof; i++)
        {
            for (int j = 0; j < no_of_files; j++)
            {
                if(indexing[j].val == buffer[i])
                {
                    flag = 1;
                    break;
                }
            }
            
        }

        if(flag==1)
        {
            printf("Memory already allocated");
            goto l1;
        }
        else
        {
            int j = 0;
            for (int i = no_of_files; i < no_of_files+nof; i++)
            {
                indexing[i].val = buffer[j++];
                indexing[i].assign = 1;
            }

            no_of_files+=nof;
            
            for (int i = 0; i < nof; i++)
            {
                printf("%d\t\t\t%d\t\t\t%d\n", indexno, buffer[i], 1);
            }

            goto l1;
        }
        
    }

    else
    {
        return 0;
    }
}
