#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    while(n>0 && arr[n-1]==-1)n--;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            cout << "NO"<<endl;
            return 0;
        } 
    }
    cout << "YES"<<endl;

}
