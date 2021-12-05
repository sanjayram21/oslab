#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int frame, framesize, pages, starting_add;

    printf("Give the no. of frames: ");
    scanf("%d", &frame);
    printf("Give the frame size: ");
    scanf("%d", &framesize);    
    printf("Give the no. of pages: ");
    scanf("%d", &pages);
    printf("Starting address: ");
    scanf("%d", &starting_add);

    int f[frame], pa[frame], pagetable[frame];
    f[0] = starting_add;

    pa[0] = -1;

    for (int i = 1; i < frame; i++)
    {
        f[i] = f[i - 1] + framesize;
        pa[i] = -1;
    }

    int count = 0;

    srand(time(NULL));
    while (count < pages)
    {
        int x = rand() % frame;
        if (pa[x] == -1)
        {
            pa[x] = count;
            pagetable[count] = x;
            count++;
        }
    }

    printf("Frame_No\t\tPage\t\tPhysical_Add");

    for (int i = 0; i < frame; i++)
    {
        printf("\n%d\t\t%d\t\t%d\n", i, pa[i], f[i]);
    }

    int pg, off;
    printf("\nEnter Pg name=");
    scanf("%d", &pg);

    printf("\nEnter Offset=");
    scanf("%d", &off);

    printf("\nPhysical address=%d", f[pagetable[pg]] + off);

    return 0;
}
