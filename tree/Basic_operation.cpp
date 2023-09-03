#include<iostream>
#include<queue>
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

void preorder(node* rootnode){
    if(rootnode==NULL){
        return ;
    }

     cout<<rootnode->value<<" ";

     preorder(rootnode->left);
     preorder(rootnode->right);

}
void postorder(node* rootnode){
    if(rootnode==NULL){
        return ;
    }
     postorder(rootnode->left);

     postorder(rootnode->right);
     cout<<rootnode->value<<" ";

}
void inorder(node* rootnode){
    if(rootnode==NULL){
        return ;
    }
     inorder(rootnode->left);
     cout<<rootnode->value<<" ";
     inorder(rootnode->right);    
}
void lvlorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            node* currnode = q.front();
            q.pop();
            cout<<currnode->value<<" ";
            if(currnode->left){
                q.push(currnode->left);
            }
            if(currnode->right){
                q.push(currnode->right);
            }
        }
        cout<<endl;
    }
}
int maxdepth(node* root){
    if(root==NULL){
        return 0;
    }
    int left = maxdepth(root->left);
    int right = maxdepth(root->right);
    return max(left,right)+1;
}

int main()
{
    node* rootnode = new node(2);
    rootnode->left =new node(3);  
    rootnode->right=new node(4);  
    rootnode->left->left =new node(5);  
    rootnode->left->right =new node(6);  
    rootnode->right->left=new node(7);  
    rootnode->right->right=new node(8);  
    rootnode->right->right->right=new node(9);  
    // rootnode->right->right->left=new node(10);  
    //preorder(rootnode);
    // postorder(rootnode);
    // inorder(rootnode);
    // lvlorder(rootnode);
    cout<<maxdepth(rootnode);
    return 0;
}
//       2
//   3      4
// 5   6  7   8
//          10 9
