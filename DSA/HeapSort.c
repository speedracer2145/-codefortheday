//ALOK P
//2022BCS0014
#include<stdio.h>
#include<stdlib.h>
int n;
void heapify(int i,int arr[]){
    while(i<n){
        int l=2*i+1;//l=left node
        int r=2*i+2;//r=right node
        if(l<n && arr[l]>arr[i]){
            int temp = arr[l];
            arr[l]=arr[i];
            arr[i]=temp;
            i=l;
        }
        else if(r<n && arr[r]>arr[i]){
            int temp = arr[r];
            arr[r]=arr[i];
            arr[i]=temp;
            i=r;
        }
        else{
            break;
        }
    }
}
void heapifyleaf(int i,int arr[]){
    while(i>0){
        int root=(i-1)/2;
        if(arr[root]<arr[i]){
            int temp = arr[root];
            arr[root]=arr[i];
            arr[i]=temp;
            i=root;
        }
        else{
            break;
        }
    }
}
void main(){
    scanf("%d",&n);
    int ab = n;
    int arr[n];
    int res[n],arr1[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        arr1[i]=arr[i];
        heapifyleaf(i,arr);
    }
    printf("Input array:");
    for(int i=0;i<n;i++){
        printf("%d",arr1[i]);
        if(i!=n-1){
            printf(",");
        }
    }
    printf("\n");
    int kk = 0;
    for(int i=0;i<ab;i++){
        res[kk++]=arr[0];
        arr[0]=arr[n-1];
        n--;
        heapify(0,arr);
    }
    printf("Sorted array:");
    for(int i=ab-1;i>=0;i--){
        printf("%d",res[i]);
        if(i!=0){
            printf(",");
        }
    }
}