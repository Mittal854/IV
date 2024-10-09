#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    if(n==1){
        cout << 0<<endl;
        return 0;
    }
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++)pq.push(arr[i]);
    int cost=0;
    while(pq.size()>1){
        int cur=pq.top();
        pq.pop();
        cur+=pq.top();
        pq.pop();
        pq.push(cur);
        cost+=cur;
    }
    cout << cost<<endl;
}