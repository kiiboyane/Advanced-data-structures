#include<iostream>
#include<vector>
 
using namespace std ;

int n; 
vector<int> v(101); 
int x  , daba = 0;
void selection_sort(){ // O(N^2) , with comparaison and swaps 
   int minimum ; 
   for(int i=0; i< n ; i++){
      minimum = i; 
      for(int j = i+1 ; j<n ; j++){
         if(v[j]<v[minimum]){
             minimum = j ; 
         }
      }
      swap(v[i], v[minimum]); 
      daba ++; 
      if(daba == x) {
          for(int k=0; k<n ; k++) cout<<v[k]<<" ";  // ghir for an exercice lol 
      }
   }
}
int main(){
   cin>>n >> x; 
   for(int i=0; i<n ; i++)cin>>v[i]; 
   selection_sort();
}