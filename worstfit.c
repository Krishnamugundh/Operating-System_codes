#include<stdio.h>
#define max 25

int main(){
    int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
    static int bf[max],ff[max];
    printf("\t\tWorst Fit");
    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);
    printf("Enter the number of Process:");
    scanf("%d",&nf);
    int s2=0;
    printf("\nEnter the size of the blocks:-\n");
    for(i=1;i<=nb;i++){
        printf("Block %d:",i);
        scanf("%d",&b[i]);
        s2+=b[i];
    }
    printf("Enter the size of the Process :-\n");
    for(i=1;i<=nf;i++){
        printf("Process %d:",i);
        scanf("%d",&f[i]);
    }
    for(i=1;i<=nf;i++){
        for(j=1;j<=nb;j++){
            if(bf[j]!=1){
                temp=b[j]-f[i];
                if(temp>=0){
                    if(highest<temp){
                        ff[i]=j;
                        highest=temp;
                    }
                }
            }
        }
        frag[i]=highest;
        bf[ff[i]]=1;
        highest=0;
    }
    int s1=0,s3=0;
    for(int i=0;i<=nf;i++){
        s1=s1+f[i];
        s3=s3+frag[i];
    }

 

 

    printf("\nBlock_no:\tBlock_size:\tProcess_no:\tProcess_size\tfree_space");
    for(i=1;i<=nf;i++)
        printf("\n\t%d\t%d\t\t%d\t\t%d\t\t%d\n",ff[i],b[ff[i]],f[i],i,frag[i]);
    printf("\n");
    printf("Free Space: %d",s2-s1);
    printf("\nUsed Space: %d",s1);
    printf("\n");
}
