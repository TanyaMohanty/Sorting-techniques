#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int partition(char*,int,int,char);
void swap(char*,char*);
int main()
{
 char a[100],n,p,q;
 printf("\nEnter a string");
 gets(a);
 n=strlen(a);
 p=partition(a,0,n,'B');
 q=partition(a,0,p+1,'G');
 printf("\nThe new string is:\n");
 puts(a);
 return 0;
}

int partition(char a[],int low,int high,char pivot)
{
 int i=low-1;
 for(int j=low;j<high;j++)
 {
  if(*(a+j)!=pivot)
  {
   i++;
   swap(a+i,a+j);
  }
 }
 return i;
}

void swap(char *x,char *y)
{
 char c;
 c=*x;
 *x=*y;
 *y=c;
}
