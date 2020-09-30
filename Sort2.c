#include<stdio.h>
#include<stdlib.h>
void partition(int*,int,int);
void swap(int*,int*);
int main()
{
 int *a,n;
 printf("\nEnter size of the array: ");
 scanf("%d",&n);
 a=(int*)malloc(n*sizeof(int));
 printf("\nEnter the array elements: ");
 for(int i=0;i<n;i++)
  scanf("%d",a+i);
 printf("Input array:\n");
 for(int i=0;i<n;i++)
  printf("%d ",*(a+i));
 partition(a,0,n-1);
 printf("\nResultant/Output array is: ");
 for(int i=0;i<n;i++)
  printf("%d ",*(a+i));
 return 0;
}

void partition(int*a,int low,int high)
{
 int i=low-1;
 for(int j=low;j<=high;j++)
 {
  if(*(a+j)<0)
  {
   i++;
   swap(a+i,a+j);
  }
 }
}

void swap(int *x,int *y)
{
 int c=*x;
 *x=*y;
 *y=c;
}
