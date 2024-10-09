#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsets(string cur,string &s,int index){
    if(index>=s.size()){
        cout << cur<<endl;
        return;
    }
    subsets(cur+s[index],s,index+1);
    subsets(cur,s,index+1);
}

int main(){
    string s;
    cin >>s;
    subsets("",s,0);
}