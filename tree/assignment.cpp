#include <iostream>
#include <queue>
#include <stack>
#include<map>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;
    node(int val)
    {
        value = val;
        left = right = NULL;
    }
};

int calculateleaf(node *root)
{
    int countleaf = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        if (current->left == NULL and current->right == NULL)
        {
            countleaf++;
        }
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
    return countleaf;
}

void leftseefun(node *rootnode, vector<int> &v, queue<node *> &q)
{

    q.push(rootnode);
    while (!q.empty())
    {
        int n = q.size();
        int m = n;

        while (n)
        {
            node *currnode = q.front();
            q.pop();
            if (m == n)
            {
                v.push_back(currnode->value);
            }
            if (currnode->left)
            {
                q.push(currnode->left);
            }
            if (currnode->right)
            {
                q.push(currnode->right);
            }
            n--;
        }
    }
}
vector<int> leftsee(node *rootnode)
{
    vector<int> v;
    queue<node *> q;
    leftseefun(rootnode, v, q);
    return v;
}

int maxDiamfun(node *root, int &maxDiam)
{
    if (root == NULL)
        return 0;

    int leftmax = maxDiamfun(root->left,maxDiam);
    int rightmax = maxDiamfun(root->right,maxDiam);

    maxDiam = max(maxDiam, leftmax + rightmax);
    return 1+max(leftmax,rightmax);
}
int maxDiam(node *root)
{
    if (root == NULL)
        return 0;
    int maxDiam = 0;
    maxDiamfun(root,maxDiam);
    return maxDiam+1;
}

bool Targetsumhelp(node* root , int target , int sum,bool &ans){
   
    if(root==NULL){
    return ans;
    }
    sum+=root->value;
    if(root->left==NULL and root->right == NULL){
        if(sum==target){
            ans = true ; 
            return true;
        }
    }
    if(root->left){
        ans = Targetsumhelp(root->left,target,sum,ans);
    }
    if(root->right){
       ans =  Targetsumhelp(root->right,target,sum ,ans);
    }
    return ans;
}
bool Targetsum(node* root , int target){
    bool ans = false;
    return Targetsumhelp(root,target,0,ans );
}

vector<int> bottomview(node* root){
    vector<int> ans;
    queue<pair<node*,int>> q;
    q.push({root,0});
    map<int,int> mp;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        node* ptr =  it.first;
        int data = it.second;
        mp[data] = it.first ->value;
        if(ptr->left){
            q.push({ptr->left,data-1});
        }
        if(ptr->right){
            q.push({ptr->right,data+1});
        }     
    }
     for(auto Node : mp){
            ans.push_back(Node.second);
        }
     return ans;
}

void Iscousinsfun(node* root , node* parent , int depth , int x , int y ,int &lvlx ,int &lvly , node* &parentX ,node* &parentY){
    if(!root) return ;
    if(root->value==x){
        lvlx = depth;
        parentX = parent;
    }else if ( root->value==y){
        lvly = depth;
        parentY = parent;
    }
    if(lvlx!=-1 and lvly!=-1) return ; // we have fount each desired element .
    Iscousinsfun(root->left,root,depth+1,x,y,lvlx,lvly,parentX,parentY);
    Iscousinsfun(root->right,root,depth+1,x,y,lvlx,lvly,parentX,parentY);
}
bool Iscousins(node* root , int x ,int y){
    int lvlx = -1 , lvly = -1;
    node* parentX = NULL;
    node* parentY = NULL;
    Iscousinsfun(root,nullptr,0,x,y,lvlx,lvly,parentX,parentY);
    return lvlx==lvly and parentX!=parentY;
}


int main()
{   

    node *rootnode = new node(2);
    rootnode->left = new node(3);
    rootnode->right = new node(4);
    rootnode->left->left = new node(6);
    rootnode->left->right = new node(7);
    rootnode->right->left = new node(10);
    vector<int> ans = bottomview(rootnode);
    if(Iscousins(rootnode,6,7)){
        cout<<"Yes they are cousins ";
    }else cout<<"They are not cousins";

    return 0;
}
