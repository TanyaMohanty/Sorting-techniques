#include<stdlib.h>
#include<stdio.h> 
void Quicksort(int*,int,int);
void partition(int*,int,int);
int lp,rp;

void swap(int *x,int *y) 
{ 
 int c;
 c=*x;
 *x=*y;
 *y=c; 
} 
  
void QuickSort(int *a,int low,int high) 
{  
  if(low<high)
  {
   partition(a,low,high); 
   QuickSort(a,low,lp-1);
   QuickSort(a,lp+1,rp-1); 
   QuickSort(a,rp+1,high); 
  }
} 
  
void partition(int *a,int low,int high) 
{ 
 int i,j,k,pivot1,pivot2;
 if ((a+high-1)>(a+high))
  swap(a+high-1,a+high); 
 i=low-1,j=high-1,k=low,pivot1=(a+high-1),pivot2=(a+high);
 while (k<j) 
 {  
  if(*(a+k)<pivot1) 
  { 
   i++;
   swap(a+k,a+i); 
  } 
  if(*(a+k)>=pivot2) 
  { 
   do
   {
    j--;
   }while(j>k && *(a+j)>pivot2);
   swap(a+k,a+j);
   if(*(a+k)<pivot1)
   {
    i++;
    swap(a+k,a+i);
   }
  }
  k++;         
 } 
 swap(a+high-1,a+j);
 swap(a+j,a+i+1);
 swap(a+high,a+j+1);
 lp=i+1;
 rp=j+1;
} 
  
int main() 
{ 
 int *a,n,i;
 printf("Enter size of the array: ");
 scanf("%d",&n);
 a=(int*)malloc(n*sizeof(int));
 printf("Enter the array elements: ");
 for(i=0;i<n;i++)
  scanf("%d",a+i);
 printf("The original array : ");
 for(i=0;i<n;i++)
  printf("%d ",*(a+i));
 QuickSort(a,0,n-1);
 printf("\nSorted array: ");
 for(i=0;i<n;i++)
  printf("%d ",*(a+i));
 return 0; 
}
