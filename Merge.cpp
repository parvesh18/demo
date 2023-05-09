#include<iostream>
using  namespace std;

void merge(int arr[],int f,int m ,int l){
    int i,j,k;
    int n1=m-f+2;
    int n2=l-m+1;
    int *L =new int[n1];
    int *R=new int[n2];

    cout << "Left sub array = ";
    for(i=0;i<n1-1;i++){
        L[i]=arr[f+i];
        cout << L[i] << " ";
    }
    cout << endl;
    cout << "Right sub array = ";
    for(i=0;i<n2-1;i++){
        R[i]=arr[m+1+i];
        cout << R[i] << " ";
    }
    cout << endl;
    L[n1-1]=INT32_MAX;
    R[n2-1]=INT32_MAX;
    for( i=0,j=0, k=f;k<=l;k++){
        if(L[i]<=R[j])
            arr[k]=L[i++];
        else
            arr[k]=R[j++];
    }
    delete [] L;
    delete [] R;
}

void mergeSort(int arr[],int f,int l){
    if(f>=l)
    return ;
    int mid=(f+l)/2;
    mergeSort(arr,f,mid);
    mergeSort(arr,mid+1,l);
    merge(arr,f,mid,l);
}


int main(){
    int arr[6]={7,6,1,2,3,9};
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    mergeSort(arr,0,5);
    //cout<<arr<<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}