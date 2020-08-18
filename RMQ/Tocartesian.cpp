#include<bits/stdc++.h>

 
using namespace std;

struct Tree{
  int value; 
  Tree *left;
  Tree * right; 
  Tree * parent;
  Tree(int n){
     value = n;
     left = NULL; 
     right = NULL; 
     parent = NULL; 
  }

};

/*
  to get the original order from the cartesian tree 
  the travesal is LNR 
*/
void traverse(Tree* root){
    if(root == NULL) return ; 
    if(root->left != NULL){
        traverse(root->left);
    }    
    cout<<root->value<<" ";
    if(root->right != NULL){
        traverse(root->right);
    } 
}

/*
  8 7 2 8 6 9 4 5 6 
  
*/
int main(){
  int size ; 
  cin>>size;
  if(size < 1 ) return 0; 
  vector<int> array(size);
  for(int i= 0 ; i < size ; i++) cin>>array[i]; 
  Tree * current = new Tree(array[0]);
  Tree * original = current; 
  Tree * temp = new Tree(0); 
  for(int i = 1 ; i<size ; i++){
      temp = new Tree(array[i]);
     if(array[i]<= array[i-1]){
        temp->left =  current; 
        temp->parent = current->parent;
        if(current->parent)current->parent->right = temp; 
        current->parent = temp;
        current = temp ;
        if(original->value >= current->value)  original = current;
     }else{
        current->right = temp;
        temp->parent = current; 
        current = temp; 
     }
  }
  cout<<" the tree traversal LNR of the Cartesean tree " ;
  traverse(original);
}

 st