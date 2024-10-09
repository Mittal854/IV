#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int mi=INT_MAX;
    vector<int>left;
    for(int i=0;i<n;i++){
        mi=min(mi,arr[i]);
        left.push_back(mi);
    }
    int ma=INT_MIN;
    vector<int>right;
    for(int i=n-1;i>=0;i--){
        ma=max(ma,arr[i]);
        right.push_back(ma);
    }
    reverse(right.begin(),right.end());
    int diff=0;
    for(int i=0;i<n;i++){
        diff=max(diff,right[i]-left[i]);
    }
    cout << diff<<endl;
}