#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int index=1;
    Node* root=new Node(arr[0]);
    queue<Node*>q;
    q.push(root);
    while(index<n && !q.empty()){
        Node* front=q.front();
        q.pop();
        if(arr[index]==-1){
            front->left=NULL;
        }else{
            Node* l=new Node(arr[index]);
            front->left=l;
            q.push(l);
        }
        index++;

        if(index<n){
            if(arr[index]==-1){
                front->right=NULL;
            }else{
                Node* r=new Node(arr[index]);
                front->right=r;
                q.push(r);
            }
        }
        index++;
    }
}