#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; 

int getheight(node * root){
      if(root == NULL) return -1 ; 
       return root->ht; 
}
int height(node * root){
     if(root == NULL)
         return -1; 
     root->ht = max(getheight(root->left) , getheight(root->right)) + 1; 
     return root->ht; 
}
int balance (node * root){
     if(root == NULL) return 0; 
     return height(root->left) - height(root->right); 
}

node * rightRotation(node * root){
    node * n = root;
    node * tp = root->left;  
    n->left = tp->right; 
    tp->right = n;  
    tp->ht = height(tp); 
    n->ht = height(n); 
    return tp;    
}
node * leftRotation(node * root){
     node * n = root; 
     node * tp = root->right; 
     n->right = tp->left; 
     tp->left = n; 
     tp->ht = height(tp); 
     n->ht = height(n); 
     return tp;  
}
void inorder(node * root) {
     if(root == NULL) 
             return; 
     if(root->left != NULL){
          inorder(root->left);
     } 
     cout<<root->val<<" ";
     if(root->right != NULL){
          inorder(root->right); 
     }
     return ; 
}
void preorder(node * root) {
     if(root == NULL) 
             return; 
     cout<<root->val <<" ";
     if(root->left != NULL){
          preorder(root->left);
     }
     if(root->right != NULL){
          preorder(root->right); 
     }
     return ; 
}
node * insert(node * root,int val)
{
  if(root == NULL){ 
         node * nw = new node() ; 
         nw->left = NULL;         
         nw->right = NULL;
         nw->val = val; 
         nw->ht = 0; 
         return nw; 
    }
    if( root->val > val){
         root->left = insert(root->left, val );
    }else{
          root->right = insert(root->right, val); 
    }
    int balanceRoot = balance (root), balanceRight = balance(root->right) , balanceLeft =  balance(root->left); 
    if(abs(balanceRoot) <= 1 ){
         return root; 
    }
    if(balanceRoot == 2  && balanceLeft == 1){
          root = rightRotation(root); 
    }
    if( balanceRoot == 2 && balanceLeft == -1){
           root->left = leftRotation(root->left); 
           root = rightRotation(root); 
    }
    if(balanceRoot == -2 && balanceRight == -1){
          root = leftRotation(root); 
    }
    if(balanceRoot == -2 && balanceRight == 1){
         root->right = rightRotation(root->right); 
         root =  leftRotation(root);
    } 
    root->ht = height(root); 
    return root ; 
}

int main(){

   int n , a; 
   cin>>n;
   node * root = NULL;  
   while(n--){
       cin>>a; 
       root = insert(root, a);
   }
    preorder(root);

  

}