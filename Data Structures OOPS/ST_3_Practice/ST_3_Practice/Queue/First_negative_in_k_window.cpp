#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int k;
    cin >> k;
    queue<int>q;
    for(int i=0;i<k-1;i++){
        if(arr[i]<0) q.push(i);
    }
    for(int i=k-1;i<n;i++){
        if(arr[i]<0)q.push(i);
        while(!q.empty() && q.front()<=i-k) q.pop();
        if(q.empty()) cout << "0 ";
        else cout << arr[q.front()]<< " ";
    }
    cout << endl;
}
