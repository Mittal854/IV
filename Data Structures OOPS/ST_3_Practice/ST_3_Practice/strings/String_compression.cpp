#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string s;
    cin >>s;
    char last=s[0];
    int count=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==last) count++;
        else {
            cout << last;
            if(count>1) cout << count;
            count=1;
            last=s[i];
        }
    }
    cout << last<<count;
    cout <<endl;

}