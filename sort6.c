#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int partition(char*,int,int);
void quicksort(char*,int,int);
void swap(char*,char*);
int main()
{
 char a[50];
 int n;
 printf("\nEnter a string:");
 gets(a);
 n=strlen(a);
 quicksort(a,0,n-1);
 printf("\nThe output string is:\n");
 puts(a);
 return 0;
}
void quicksort(char *a,int low,int high)
{
 if(low<high)
 {
  int pi=partition(a,low,high);
  quicksort(a,low,pi-1);
  quicksort(a,pi+1,high);
 }
}

int partition(char *a,int low,int high)
{
 int i=low-1,pivot=*(a+high);
 for(int j=low;j<high;j++)
 {
  if(*(a+j)<=pivot)
  {
   i++;
   swap(a+i,a+j);
  }
 }
 swap(a+i+1,a+high);
 return i+1;
}

void swap(char *x,char *y)
{
 char c;
 c=*x;
 *x=*y;
 *y=c;
}
