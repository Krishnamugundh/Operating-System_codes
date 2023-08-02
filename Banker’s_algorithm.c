#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("no of process:");
    int p; scanf("%d",&p);
    printf("no of resources:");
    int r; scanf("%d",&r);
   
    int max[p][r],all[p][r],ava[r];

    printf("Maximum Resources array\n");

    for(int i=0;i<p;i++){
        for (int j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("Allocation Array:\n");

    for(int i=0;i<p;i++){
        for (int j=0;j<r;j++){
            scanf("%d",&all[i][j]);
        }
    }

    printf("Available Array:\n");

    for (int j=0;j<r;j++){
        scanf("%d",&ava[j]);
    }

    int k,i,j;

    int f[p], ans[p], ind = 0;  
    for (k = 0; k < p; k++)  
    {  
        f[k] = 0;  
    }  
    int need[p][r];  
    for (i = 0; i < p; i++)  
    {  
        for (j = 0; j < r; j++)  
            need[i][j] = max[i][j] - all[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < p; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < r; j++)  
                {  
                    if (need[i][j] > ava[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < r; y++)  
                        ava[y] += all[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }
    int flag = 1;  
    for (int i = 0; i < p; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe\n");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < p - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d\n", ans[p - 1]);

        for (i=0;i<p;i++){
            for (j=0;j<r;j++){
                printf("%d ",need[i][j]);
            }
            printf("\n");
        }  
    }  
    return (0);    
}