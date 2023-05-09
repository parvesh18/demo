#include<iostream>
#include<ctime>
using namespace std;

int partition(int arr[],int f,int l){
    srand(time(0));
    int p= rand()%(l-f+1) +f;

    swap(arr[l],arr[p]);
    int pivot=arr[l];
    int i=f-1;
    for(int j=f;j<l;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }swap(arr[i+1],arr[l]);
    return i+1;
}

void QuickSort(int arr[],int f,int l){
    if(f>=l)
    return ;
    int p=partition(arr,f,l);
    QuickSort(arr,f,p-1);
    QuickSort(arr,p+1,l);
}

int main(){
    int arr[5]={4,3,5,2,9};
    QuickSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}