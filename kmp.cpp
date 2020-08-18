#include<iostream> 
#include<string>  
#include<vector>
using namespace std ; 


#define M 123456
vector<int> lps(M); 
int num = 0; 
void canLPS(string s){
   lps[0]=0; 
   int i=1, j=0 , n = s.size();
   while(i<n){
       if(s[i]==s[j]){
            lps[i] = j+1; 
            j++; i++;
       }else{
          while(s[i]!=s[j] && j) j = lps[j-1] ; 
          if(s[i]==s[j]) lps[i] = j+1; 
          else lps[i] = 0 ; 
          i++;
       }
   }
}
void canKMP(string s , string pat){ 
   int j=0 ; 
   for(int i=0; i<s.size() ;i++){
       if(s[i]==pat[j]){
            j++; 
            if(j == pat.size()) j=lps[j-1] , num++ ; 
       }else{
          if(j) j = lps[j-1], i--; 
       }
   }
}
int main(){
   string p  , t; 
   cin>>t>>p ;
   canLPS(p); 
   canKMP(t , p); 
   cout<<num ;
  

}