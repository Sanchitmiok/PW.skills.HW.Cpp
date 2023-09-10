#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;

class Treenode{
    public:
    int data;
    vector<Treenode*> next;
    Treenode(int val){
        data = val;
    }
};
void preorder(Treenode* root){
    if(root == NULL) return ;
    cout<<root->data<<" ";
    for(auto x:root->next){
        preorder(x);
    }
    return;
}
void postorder(Treenode* root){
    if(root == NULL) return;
    for(auto x:root->next){
        postorder(x);
    }
    cout<<root->data<<" ";
    return;
}
void inorder(Treenode* root){
    if(root == NULL);
    int childnodes = root->next.size();
    for(int i=0 ; i<childnodes-1 ; i++){
        inorder(root->next[i]);
    }
    cout<<root->data<<" ";
    if(childnodes>0){
        inorder(root->next[childnodes-1]);
    }
}
void lvlorder(Treenode* root){
    if(root==NULL) return ;
    queue<Treenode*> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        while(count--){
            Treenode* currnode = q.front();
            q.pop();
            cout<<currnode->data<<" ";
            if(currnode->next.size()!=0){
                for(auto ptr:currnode->next){
                    q.push(ptr);
                }
            }
        }
        cout<<endl;
    }
   return ;  
}

void justgreaterfun(Treenode* root,Treenode* &ans ,int x){
    if(root == NULL) return;
    if(ans == NULL and root->data>x){
        ans = root;
    }
    if(root->data > x and root->data < ans->data){
        ans = root;
    }
   if(root->next.size()!=0){ for(auto Y:root->next){
        justgreaterfun(Y,ans,x);
    }}
    return;
}
Treenode* justgreater(Treenode* root , int x){
    Treenode* ans = NULL;
    justgreaterfun(root,ans,x);
    return ans;
}

void ReverseThetree(Treenode* root){
    if(root==NULL) return ;
    if(root->next.size()==1){
        return ;
    }
    reverse(root->next.begin(),root->next.end());
    for(auto x : root->next){
        ReverseThetree(x);
    }
}

void seriealised(Treenode* root , string &str){
     if(root==NULL) return;
     queue<Treenode*> q;
     q.push(root);
     while(!q.empty()){
        int count = q.size();
        while(count--){
            Treenode* curr = q.front();
            q.pop();
            str+=to_string(curr->data);
            str.push_back(':');
            str+=to_string(curr->next.size());
            str.push_back(':');
            for(auto x:curr->next){
                q.push(x);
                str+=to_string(x->data);
                str.push_back(',');
            }
            str.pop_back();
            str.push_back('\n');
        }
     }
return;
}


Treenode* Deserialisedhelp(int nodeval , unordered_map<int,string> mp){
    Treenode* node = new Treenode(nodeval);
    string nodestr = mp[nodeval];
    if(nodestr[0]=='0'){
        return node;
    }
    int breakpos = nodestr.find(':');
    int childnodenum = stoi(nodestr.substr(0,breakpos));
    string childnodestr = nodestr.substr(breakpos+1);
    int start = 0;
    for(int i=0 ;i<childnodenum ; i++){
        int end = childnodestr.find(',',start);
        if(end == string::npos) end = childnodestr.size();
        int childnodeval = stoi(childnodestr.substr(start,end));
        node->next.push_back(Deserialisedhelp(childnodeval,mp));
        start = end + 1;
    }
    return node;
}
Treenode* Deserialised(string str){
    if(str == "") return NULL;
   unordered_map<int,string> mp;
   int start = 0;
   for(int i=0 ; i<str.size() ; i++){
    if(str[i]=='\n'){
        string nodestr = str.substr(start , i - start);
        int breakpos1 = nodestr.find(':');
        int nodeval = stoi(nodestr.substr(0,breakpos1));
        mp[nodeval] = nodestr.substr(breakpos1+1);
        start = i+1;
    }
   }
   int rootnodeval = stoi(str.substr(0,str.find(':')));
   return Deserialisedhelp(rootnodeval , mp);
}


int main()
{
    Treenode* root = new Treenode(2);
    root->next.push_back(new Treenode(12));
    root->next.push_back(new Treenode(13));
    root->next.push_back(new Treenode(25));
    root->next[0]->next.push_back(new Treenode(7));
    root->next[0]->next.push_back(new Treenode(19));
    root->next[1]->next.push_back(new Treenode(90));
    root->next[2]->next.push_back(new Treenode(100));
    return 0;
}
