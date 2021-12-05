#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int file[10000];
    int starting_block,length;

    scanf("%d%d",&starting_block,&length);

    for (int i = 0; i < 10000; i++)
    {
        file[i] = -1;
        if(i>=starting_block-1 && i<(starting_block+length))
        {
            file[i] = 1;
        }
    }

    for(int i=starting_block;i<length;i++)
    {
        printf("BNO-%d\t\t\t%d\n",i,file[i]);
    }
    
    int ch;
    l1:printf("\nEnter 1 to allocate a set of blocks again or any other number to exit=");
    scanf("%d",&ch);

    if(ch==1)
    {

    printf("\nEnter starting block and the length=");
    scanf("%d%d",&starting_block,&length);


    int flag = 0;

    for (int i = starting_block; i < length; i++)
    {
        if(file[i]!=-1)
        {
            flag = 1;
            break;
        }
        file[i] = 1;
    }

    if(flag==1)
    {
        printf("\nThe block is already allocated\n");
        goto l1;

    }

    else
    {

    for(int i=starting_block;i<length;i++)
    {
        printf("BNO-%d\t\t\t%d\n",i,file[i]);
    }

    printf("\n\n");
    goto l1;
    }
    
    }

    else
    {
        return 0;
    }





    
    
}
