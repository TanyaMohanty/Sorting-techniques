#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
int c=0;
void merge(int *a,int l,int m,int r) 
{ 
   int i,j,k; 
   int n1 = m - l + 1; 
   int n2 = r - m; 
   int *L,*R;
   L=(int*)malloc(n1*sizeof(int));
   R=(int*)malloc(n2*sizeof(int));
    for (i = 0; i < n1; i++) 
       *(L+i) = *(a+l+i); 
    for (j = 0; j < n2; j++) 
       *(R+j) = *(a+m+1+j);
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if((R+j)<(L+i)) 
        { 
            *(a+k) = *(R+j); 
            c=c+(n1-i); 
            j++;
        } 
        else 
        { 
            (a+k)=(L+i); 
            i++;
        } 
        
        k++; 
    } 
    while (i < n1) 
    { 
        (a+k)=(L+i); 
        i++; 
        k++; 
        
    }
    while (j < n2)
    { 
        *(a+k) = *(R+j); 
        j++;
        k++; 
    } 
    
} 
 
void mergesort(int *a, int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 
        mergesort(a, l, m); 
        mergesort(a, m + 1, r); 
        merge(a, l, m, r); 
    } 
} 
  

 
int main() 
{ 
  int *a,n,i;
  printf("\nEnter size of the array: ");
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  printf("\nEnter the array elements: ");
  for(i=0;i<n;i++)
   scanf("%d",a+i);
  mergesort(a,0,n-1);
  printf("\nSorted array is: \n"); 
  for(i=0;i<n;i++)
   printf("%d ",*(a+i));
  printf("\nNo. of ordered pairs : %d",c);
  return 0; 
}
