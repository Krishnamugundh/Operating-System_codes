
// 1.) Create process and print parent id and child id.
// Code:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
pid_t child_pid;
child_pid = fork();
if (child_pid < 0) {
fprintf(stderr, "Fork failed.\n");
return 1;
} else if (child_pid == 0) {
printf("Child process is running. PID = %d\n", getpid());
sleep(2);
printf("Child process is exiting.\n");
return 0;
} else {
printf("Parent process is running. PID = %d\n", getpid());
printf("Parent process is exiting.\n");
return 0;
}
}

 

// 2.) Create Orphan process program.
// Code:
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int pid;
pid = fork();
if(pid == 0)
{
printf("I am the child, my process ID is %d\n",getpid());
printf("My parent's process ID is %d\n",getppid());
sleep(30);
printf("\nAfter sleep\nI am the child, my process ID is %d\n",getpid());
printf("My parent's process ID is %d\n",getppid());
exit(0);
}
else
{
sleep(20);
printf("I am the parent, my process ID is %d\n",getpid());
printf("The parent's parent, process ID is %d\n",getppid());
printf("Parent terminates\n");
}
abort();
return 0;
}


 

// 3.) Write a C program using wait() System call.
// Code:
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main(){
pid_t pid;
pid = fork();
if(pid<0){
fprintf(stderr,"fork not created");
}
else if(pid == 0){
printf("Parent process started"); 
}
else{
wait(NULL);
execlp("/home/ex2/21BAI1900_fork","ls",NULL);
}
return 0;
}


 

// 4.) Create a process and compute factorial in child and fibbinoci in parent as executable.
// Code:
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
void ParentProcess(int n){
int t1 = 0, t2 = 1, next = 0, i;
if(n == 0 || n == 1){
printf("The %dth Fibonacci Number is %d\n", n, n);
}
else{
next = t1 + t2;
}
for (i = 3; i <= n; ++i){
t1 = t2;
t2 = next;
next = t1 + t2;
}
printf("The %dth Fibonacci Number is %d\n", n, t2);
}
void ChildProcess(int n){
int ans = 1;
for (int i=1; i<=n; i++){
ans = ans*i;
}
printf("The factorial of %d is %d\n", n, ans);
}
int main(){
pid_t pid;
pid = fork();
int num = 6;
if (pid==0){
ChildProcess(num);
}
else if (pid>0){
ParentProcess(num);
return 1;
}

 

// 5.) Create a process and let child do some task like compurting sum of N numbers.
// Code:
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main() {
pid_t pid;
int n, i, sum = 0;
printf("Enter the value of N: ");
scanf("%d", &n);
pid = fork();
if (pid == 0) {
for (i = 1; i <= n; i++) {
sum += i;
}
printf("Sum of first %d numbers: %d\n", n, sum);
} else if (pid > 0) {
printf("Parent process is waiting for the child to complete...\n");
wait(NULL);
printf("Child process completed.\n");
} else {
printf("Fork failed\n");
return 1;
}
return 0;
}
 

// 6.) Palindrome and Odd or Even as a parent and child with fork.
// Code:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int pallindrome(char arr[],int c){
for (int i=0;i<(int)(c/2);i++){
if(arr[i]!=arr[c-i-1])
return 0;
}
return 1;
int main() {
pid_t pid;
int number;
char arr[5]={'a','d','b','d','a'};
printf("Enter a number: ");
scanf("%d", &number);
pid = fork();
if (pid < 0) {
fprintf(stderr, "Fork failed.\n");
return 1;
}
else if(pid == 1){
printf("Parent is process: %d\n and the number is", number);
if(pallindrome(arr,5))
printf("a pallindrome");
else
printf("not a pallindrome");
}
else{
if (number % 2 != 0)
printf("Parent process: %d is an odd number.\n", number);
else
printf("Parent process: %d is an even number.\n", number);
}
return 0;
}
