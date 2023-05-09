#include<iostream>
using namespace std;

int hoare_partition(int arr[],int f,int l){
    
    int pivot=arr[f];
    int i=f-1;
    int j=l+1;
    while (true)
    {
        do
    {
        i++;
    } while (arr[i]<pivot);

    do
    {
        j--;
    } while (arr[j]>pivot);
    if(i>=j)
    return j;
    swap(arr[i],arr[j]);
    }

}

void QuickSort(int arr[],int f,int l){
    if(f>=l)
    return ;
    int p=hoare_partition(arr,f,l);
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