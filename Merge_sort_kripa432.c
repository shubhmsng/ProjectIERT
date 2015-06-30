#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>

int merge(int *arr1,int start,int mid,int end){
	int p=start,q=mid+1;
	int i;
	int arr[end-start+1],k=0;
	for(i=start;i<=end;i++){
		if(p>mid)						//if first string length is greater than other
			arr[k++]=arr1[q++];
		else if(q>end)					//if second string is greater
			arr[k++]=arr1[p++];
		else if(arr1[p]<arr1[q])			//if arr[i]<arr[j]
			arr[k++]=arr1[p++];
		else
			arr[k++]=arr1[q++];			//if arr[i]>arr[j]
	}
	for(p=0;p<k;p++)
		arr1[start++]=arr[p];

}



int merge_sort(int *arr,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}


int main()
{
    int arr[]={10,2,1,4,3,7,4,5,7,8};
    merge_sort(arr,0,9);
    int i;
    for(i=0;i<10;i++)
    	printf("%d\n",arr[i] );

    return 0;
}
