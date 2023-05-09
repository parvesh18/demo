#include <bits/stdc++.h>
using namespace std;
struct activity
{
    int start;
    int finish;
    int deadline;
    int length;
};
void count_sort(activity arr[], int n)
{
    int man = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (man < arr[i].deadline)
        {
            man = arr[i].deadline;
        }
    }
    // man denotes the range for finish time

    int freq[man + 1] = {0};

    activity out[n];
    for (int i = 0; i < n; i++)
    {
        freq[arr[i].deadline]++;
    }
    for (int i = 1; i < man + 1; i++)
    {
        freq[i] += freq[i - 1];
    }
    // for(int i=0;i<10;i++){
    //     cout<<freq[i]<<" ";
    // }cout<<endl;
    for (int i = n - 1; i >= 0; i--)
    {
        int j = arr[i].deadline;
        freq[j]--;
        // out[freq[j]]=j;
        out[freq[j]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }
}
class Schedule
{
    activity *request;
    int *lateness;
    int starttime;
    int n;

public:
    void input()
    {
        cout << "Enter the start time: ";
        cin >> starttime;
        cout << "Enter the number of requests: ";
        cin >> n;
        lateness = new int[n];
        request = new activity[n];

        for (int i = 0; i < n; i++)
        {
            cout << "For " << i << " request";
            cout << "Enter time taken by job: ";
            cin >> request[i].length;
            cout << "Enter the deadline : ";
            cin >> request[i].deadline;
        }
    }

    void schedule()
    {

        count_sort(request, n);
        int f = starttime;
        for (int i = 0; i < n; i++)
        {
            request[i].start = f;
            request[i].finish = f + request[i].length;
            f = f + request[i].length;
        }
        int ans, late = 0;
        for (int i = 0; i < n; i++)
        {
            ans = starttime + request[i].length - request[i].finish;
            if (ans > 0)
            {
                lateness[i] = 0;
            }
            else
            {
                lateness[i] = abs(ans);
                late += abs(ans);
            }
        }
        cout << "Id"
             << "\t"
             << "start"
             << "\t"
             << "finish"
             << "\t"
             << "length"
             << "\t"
             << "deadline"
             << "\t"
             << "Lateness\n";
        for (int i = 0; i < n; i++)
        {
            cout << i << "\t";
            cout << request[i].start << "\t" << request[i].finish << "\t" << request[i].length << "\t" << request[i].deadline << "\t" << lateness[i] << endl;
        }
        cout << "Toatl minimum lateness: " << late << endl;
    }
    //}
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << endl;
            cout << request[i].length << " " << request[i].deadline << endl;
        }
        cout << endl;
    }
};
int main()
{
    Schedule s1;
    s1.input();
    s1.display();
    s1.schedule();
    // s1.display();
}