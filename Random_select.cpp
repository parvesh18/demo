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

int randomSelect(int arr[],int f,int l,int i){
    if(f==l)
    return arr[f];
    int q=partition(arr,f,l);
    int k=q-f+1;
    if(i==k)
    return arr[q];
    else if(i<k)
    return randomSelect(arr,f,q-1,i);
    else
    return randomSelect(arr,q+1,l,i-k);
}
int main(){
    int arr[8]={3,6,4,9,7,1,5,10};
    cout<<randomSelect(arr,0,7,1)<<endl;
}