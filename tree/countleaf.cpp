#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
   public:
   int value;
   node* left;
   node* right;
   node(int val){
    value = val;
    left = right = NULL;
   }
};
// int fun(node* root , int count){
//     //base case 
//     if(root->left==NULL and root->right==NULL){
//         return count+1;
//     }
//     if(root->left){
//        count+= fun(root->left,count);
//     }
//     if(root->right){
//        count+= fun(root->right,count);
//     }
//     return count;

// }
// int countleaf(node* root){
//     return fun(root,0);
// }
int calculateleaf(node* root){
    int countleaf = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
       node* current=q.front();
       q.pop();
       if(current->left == NULL and current->right == NULL){
        countleaf++;
       }
       if(current->left){
       q.push(current->left);
       }
       if(current->right){
        q.push(current->right);
       }
    }
    return countleaf;
}

int main()
{   
    node* rootnode = new node(2);
    rootnode->left =new node(3);  
    rootnode->right=new node(4);  
    rootnode->left->left = new node(6);
    rootnode->left->right = new node(7);

    int ans = calculateleaf(rootnode);
    cout<<ans;


    return 0;
}
//       2
//   3      4
// 5   6  7   8
//      20    10 9
