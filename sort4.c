#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
 int c;
 c=*x;
 *x=*y;
 *y=c;
}

void max_heapify(int *a,int n,int i) 
{ 
 int largest=i; 
 int l=2*i+1; 
 int r=2*i+2;  
 if(l<n && *(a+l)>*(a+largest)) 
  largest=l;
 if(r<n && *(a+r)>*(a+largest))
  largest=r;
 if(largest!=i) 
 { 
  swap(a+i,a+largest); 
  max_heapify(a,n,largest); 
 } 
} 
 
void build_max_heap(int *a,int n)
{
 for(int i=n/2-1;i>=0;i--) 
  max_heapify(a,n,i);
}

void heapSort(int *a,int n) 
{  
 build_max_heap(a,n);
 for(int i=n/2-1;i>=0;i--) 
  max_heapify(a,n,i); 
 for(int i=n-1;i>0;i--) 
 { 
  swap(a,a+i); 
  max_heapify(a,i,0);
 } 
} 
  

int main() 
{ 
 int *a,n,i;
 printf("\nEnter size of the array");
 scanf("%d",&n);
 a=(int*)malloc(n*sizeof(int));
 printf("\nEnter the array elements:");
 for(i =0;i<n;i++)
  scanf("%d",a+i);
 printf("\nOriginal array:\n");
 for(i=0;i<n;i++)
  printf("%d ",*(a+i));
 heapSort(a,n);
 printf("The sorted array is:\n"); 
 for(i=0;i<n;i++)
  printf("%d ",*(a+i));
}
