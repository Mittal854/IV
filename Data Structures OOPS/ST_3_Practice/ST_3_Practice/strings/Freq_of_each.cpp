#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<char,int>mp;
    for(auto ch:s)mp[ch]++;
    for(auto it:mp) cout <<it.first<< " : "<<it.second<<endl;
}
