#include<iostream>
#include<vector>
 
using namespace std ;

int n; 
vector<int> v(101); 

int bubble_sort(){ // O(n^2) in both worst and average cases, because the entire array needs to be iterated for every element
  int res = 0; 
  for(int i=0; i<n-1 ; i++){
      for(int j=0; j<n-i-1; j++){
             if(v[j]>v[j+1]){
                swap(v[j], v[j+1]); 
                res++; 
             }
      }
  }
  return res; 
}
int main(){
   cin>>n; 
   for(int i=0; i<n ; i++)cin>>v[i]; 
   cout<<bubble_sort();
}