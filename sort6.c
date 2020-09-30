#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *arr, int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
     { 
        if(*(arr+i)%2==0)
        { 
		key = *(arr+i); 
         	j = i - 1; 
        		while (j >= 0 && *(arr+j)%2!=0)
		 { 
          		 *(arr+j+1) = *(arr+j); 
            		j = j - 1; 
       		 } 
       		 *(arr+j+1) = key; 
         } 
     }
}
int binarySearch(int *arr, int l, int r) 
{ 
    	if(r >= l)
     	{ 
       		 int mid= (l + r)/2;
       		 if (*(arr+mid)==1 && *(arr+mid-1)==0)  
           		 return mid; 
		 else if(*(arr+mid)==0 && *(arr+mid+1)==1)
           		   return (mid+1);
       		 else if (*(arr+mid)==1 && *(arr+mid-1)==1) 
        			    return binarySearch(arr, l, mid-1); 
    	}
} 
void printArray(int *arr, int n) 
{ 
    for(int i=0;i<n;i++)
     printf("%d ",*(arr+i));
    printf("\n");
} 
int main() 
{ 
    int *arr,n,i;
    printf("\nEnter size of the array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("\nEnter the binary array elements: ");
    for(i=0;i<n;i++)
     scanf("%d",arr+i);
    insertionSort(arr, n);
     printf("\nThe array elements:\n");
    printArray(arr, n);
    int result = binarySearch(arr, 0, n - 1);
    printf("\nElement 1 is first present at index %d and at position %d.\n",result,result+1);
    return 0; 
}
