// Operating System
// Thread Programming
// 									        Name   : Krishnamugundh P
// 									        RegNo : 21BAI900
// 									        Slot     : L49+L50

//1.) Create two threaads thread1 and thread2 and call functions fun1 and fun2 respectively.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *fun1 (void *a)
{
  int x = *((int *) a);
  printf ("1.) first function %d\n", x);
  pthread_exit (0);
}
void *fun2 (void *b)
{
  int x = *((int *) b);
  printf ("2.) second function %d\n", x);
  pthread_exit (0);
}
int main ()
{
  pthread_t pt1, pt2;
  int i1, i2;
  int i = 4;
  int j = 5;
  i1 = pthread_create (&pt1, NULL, fun1, (void *) &i);
  printf ("inbetween 1 and 2\n");
  i2 = pthread_create (&pt2, NULL, fun2, (void *) &j);
  pthread_join (pt1, NULL);
  pthread_join (pt2, NULL);
  exit (0);
  return 0;
}


//2.) Create two threaads thread1 and thread2 and call functions fun1 and fun2 respectively. 
//   Compute and print fibinnoci in fun1 and square in fun2.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *fun1(void *a){
    int x=*((int*)a),s=0,d=1,f;
    for (int i=0;i<=x;i++){
    f=s+d;
    printf("%d,",f);
    s=d;d=f;
    }
    pthread_exit(0);
}
void *fun2(void *b){
int x=*((int*)b);
printf("\nsecond function %d\n",x*x);
pthread_exit(0);
}
int main(){
    pthread_t pt1,pt2;
    int i1,i2;
    int i=10;
    int j=5;
    i1=pthread_create(&pt1,NULL,fun1,(void *) &i);
    printf("inbetween 1 and 2\n");
    i2=pthread_create(&pt2,NULL,fun2,(void *) &j);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    exit(0);
    return 0;
}

//3.) Create two threaads thread1 and thread2 and call functions fun1 and fun2 respectively. 
//    Compute and print factorial in fun1 and prime in fun2.
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *fun1 (void *a)
{
  int x = *((int *) a), s = 1;
  while (s <= x)
  {
  s = s * x;
  ++;
  }
  printf ("The factorial of %d is %d", s, x);
  pthread_exit (0);
}
void *fun2 (void *b)
{
  int x = *((int *) b), w = x - 1, r = 1;
  while (w > 1)
    {
      if (x % w == 0)
	{
	  r = 0;
	  break;
	}
      w--;
    }
  if (r == 1)
    printf ("\n%d is prime\n", x);
  else
    printf ("\n%d is not prime\n", x);
  pthread_exit (0);
}
int main ()
{
  pthread_t pt1, pt2;
  int i1, i2;
  int i = 10;
  int j = 5;
  i1 = pthread_create (&pt1, NULL, fun1, (void *) &i);
  printf ("inbetween 1 and 2\n");
  i2 = pthread_create (&pt2, NULL, fun2, (int *) &j);
  pthread_join (pt1, NULL);
  pthread_join (pt2, NULL);
  exit (0);
  return 0;
}





//4.) Create two threaads thread1 and thread2 and call functions fun1 and fun2 respectively. 
///// Compute and print Armstrong number in fun1 and reverse a number in fun2.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun1(void *e){
	int n=*((int*)e);
	int sum=0,x=10;
	while(n>0){
		x=n-((int)(n/10))*10;
		n=(int)(n/10);
		sum=sum+x*x*x;
	}
	if(sum==n){
		printf("/nthe given number is armstrong");
	}
	else{
		printf("not a armstrong");
	}
	pthread_exit(0);
}


void *fun2(void* e){
	int n=*((int*)e);
	printf("\nThe reversed number of %d:",n);
	int q=0,w=0;
        while (n != 0) {
 	   q = n % 10;
  	   w = w * 10 + q;
  	   n /= 10;
  	}
	printf("%d\n",w);
	pthread_exit(0);
}

int main(){
pthread_t pt1,pt2;
int i1,i2;
int i=163,j=1945;
i1=pthread_create(&pt1,NULL,fun1,(void*) &i);
i2=pthread_create(&pt2,NULL,fun2,(void*) &j);

pthread_join(pt1,NULL);
pthread_join(pt2,NULL);
exit(0);
return 0;
}