#include<bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int finish;
    int profit;
};
void count_sort(activity arr[],int n){
    int man=INT32_MIN;
    for(int i=0;i<n;i++){
        if(man<arr[i].finish){
            man=arr[i].finish;
        }
    }
    //man denotes the range for finish time
    
    int freq[man+1]={0};
    
    activity out[n];
    for(int i=0;i<n;i++){
        freq[arr[i].finish]++;
    }
    for(int i=1;i<man+1;i++){
        freq[i]+=freq[i-1];
    }
    // for(int i=0;i<10;i++){
    //     cout<<freq[i]<<" ";
    // }cout<<endl;
    for(int i=n-1;i>=0;i--){
        int j=arr[i].finish;
        freq[j]--;
        //out[freq[j]]=j;
        out[freq[j]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=out[i];
    }
}

class Schedule{
    activity* request;
    int n;
    public:
    void input(){
        cout<<"enter the number of requests: ";
        cin>>n;
        request=new activity[n];
        for(int i=0;i<n;i++){
            cout<<"For "<<i<<" request";
            cout<<"Enter start time: ";
            cin>>request[i].start;
            cout<<"Enter the finish time: ";
            cin>>request[i].finish;
            cout<<"Enter the Profit: ";
            cin>>request[i].profit;
        }
    }  

    int non_conflicting(int i){
        for(int j=i-1;j>=0;j--){
            if(request[j].finish <= request[i].start)
            return j;
        }return -1;
    }  

    int findProfit(){
        count_sort(request,n);
        int* sol=new int[n];
        sol[0]=request[0].profit;
        for(int i=1;i<n;i++){
        int incljob=request[i].profit;
        int p=non_conflicting(i);
        if(p!=-1){
            incljob+=sol[p];
        }
        sol[i]=max(incljob,sol[i-1]);
        }
        int ans=sol[n-1];
        for(int i=0;i<n;i++){
            cout<<sol[i]<<" ";
        }cout<<endl;
        delete [] sol;
        return ans;
    }
    
};
int main(){
    Schedule s1;
    s1.input();
    cout<<"Maximum profit is: "<<s1.findProfit()<<endl;
}