/******************************************************************************
 Example for Pascalsche Pyramide
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Example for Pascalsche Pyramide\n");
    int size;
    printf("How many level:\n");
    scanf("%d",&size);
    if(size > 13) size=13;
    if(size < 2) size=2;
    
    printf("calculating %d levels ...\n",size);
    
    /* allocate the memory for the matrix */
    int** pyramide = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        pyramide[i] = (int*)malloc(size * sizeof(int));
 
    /* initialize the matrix */
    for (int y = 0; y < size; y++) 
        for (int x = 0; x < size; x++) {
        if ( x == 0 ) {
            pyramide[x][y] = 1;
        } else {
            pyramide[x][y] = 0;
        }
    }
    
    /* the magic */
    for(int y=1,currentLength=2;y < size;y++,currentLength++) {
        for(int x=1;x < currentLength;x++) {
            pyramide[x][y]=pyramide[x-1][y-1] + pyramide[x][y-1];
        }
    }
    
    /* print the result */
    for (int y = 0; y < size; y++) {
        for(int s=0;s < ((size-y-1)*2); s++) printf(" ");
        for (int x = 0; x < size; x++)
            if(pyramide[x][y] != 0) printf("%4d", pyramide[x][y]);
        printf("\n");
    }
 
    free(pyramide);
 
    return 0;
}

