#include<stdio.h>
#define max 25

int main()
{
    int frag[max],b[max],f[max],i,j,nb,nf,temp;
    static int bf[max],ff[max];
    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);
    printf("Enter the number of Process:");
    scanf("%d",&nf);
    printf("\nEnter the size of the blocks:-\n");
    for(i=1;i<=nb;i++)
    {
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }
    printf("Enter the size of the Process:-\n");
    for(i=1;i<=nf;i++)
    {
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }
    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                {
                    ff[i]=j;
                    break;
                }
            }
        }
        frag[i]=temp;
        bf[ff[i]]=1;
    }
    printf("\nBlock_no:\tBlock_size :\tProcess_no:\tProcess_size:\tFreeSpace");
    int free=0,used=0;
    for(i=1;i<=nf;i++){
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",ff[i],b[ff[i]],i,f[i],frag[i]);
    free+=frag[i];
    used+=b[ff[i]];
    }
    printf("Free Space= %d\n",free);
    printf("Used Space= %d\n",used-free);
}
