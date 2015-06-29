#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int low, int mid, int high)
{
	int n1,n2,i,j,k;

	n1 = mid - low + 1;
	n2 = high - mid;
	int L[n1+1],R[n2+1];
	for (i = 0; i < n1; i++)
		L[i] = a[low + i];
	for (i = 0; i < n2; i++)
		R[i] = a[mid + i + 1];	
	i = 0;
	j = 0;
	L[n1] = 1234544454;
	R[n1] = 1223323344;
	for (k = low; k <= high; k++)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i += 1;
		}
		else{
			a[k] = R[j];
			j += 1;
		}
	}
	
}

void merge_sort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high)/2;
	
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
	
}

int main()
{	
	int i,n;

   // printf("Enter the total number of elements: ");
    scanf("%d",&n);
	int merge[n];
   // printf("Enter the elements which to be sort: ");
    for(i=0;i<n;i++){
       // scanf("%d",&merge[i]);

		merge[i]=rand();
    }

	for(i=0;i<n;i++)
	printf("%d  ",merge[i]);
    merge_sort(merge,0,n-1);

    printf("\nAfter merge sorting elements are: \n");
    for(i=0;i<n;i++){
         printf("%d ",merge[i]);
    }

	return 0;
}