#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l < n && arr[l]>arr[largest])
    largest=l;
    if(r<n && arr[r]>arr[largest])
    largest=r;
    if (largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
    
}

void heap_sort(int arr[],int n){
    //building max heap
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=1;i--){
        swap(arr[i],arr[0]);
        n--;
        heapify(arr,n,0);
    }

}
int main(){
    int arr[8]={4,2,6,5,7,1,6,9};
    heap_sort(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
}