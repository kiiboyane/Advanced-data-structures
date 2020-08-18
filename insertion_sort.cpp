#include<iostream>
#include<vector>
#include<map>
 
using namespace std ;

int n; 
vector<int> v(101), vv(101); 
map<int , int> mp; 
void insertion_sort(){ // O(N^2) in worst case 
   int j ; 
   for(int i=0; i<n ; i++){
        j=i;
        while(j>0 && v[j-1]>v[j]){
            swap(v[j-1], v[j]); 
            mp[v[j]] =  j; 
            mp[v[j-1]] =  j-1; 
            j--; 
        }
   }
}
int main(){
   cin>>n; 
   for(int i=0; i<n ; i++){
       cin>>v[i];
       mp[v[i]]=i; 
       vv[i]=v[i];
   } 
   insertion_sort();
   for(int i=0 ; i<n ; i++) cout<<mp[vv[i]]+1<<" "; 
}