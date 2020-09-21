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
     parent = NULL; // I need for the linear time 
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
  you can turn an array to a cartesien in a linear time O(n)
  8 7 2 8 6 9 4 5 6 
  
*/

int main(){
  int size ; 
  cin>>size;
  if(size < 1 ) return 0; 
  vector<int> array(size);
  for(int i= 0 ; i < size ; i++) cin>>array[i]; 
  // you just parse the array and you answer accordingly 
  Tree * current = new Tree(array[0]);  
  Tree * original = current; 
  Tree * temp = new Tree(0); 
  for(int i = 1 ; i<size ; i++){
     // Creating a node for the element with index i 
     temp = new Tree(array[i]); 
     cout<<array[i]<<endl; 
     if(array[i]<= array[i-1]){ 
     	// here the element in the array is smaller so it should be the parent to the current root in the tree which should be on the left 
        cout<<"Here"<<endl;
        temp->left =  current; 
        temp->parent = current->parent;  
        cout<< &(temp->parent) << " pointers " << &(current->parent) <<endl ;
        if(current->parent){
        	cout<<" yes I exist "<< (current->parent->value)<<endl; 
        	current->parent->right = temp; 
        }
        current->parent = temp;
        cout<<(current->parent->value)<<endl; 
        if((temp->parent)) cout<<" "<< (temp->parent->value)<<endl; 
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

