
#include<iostream>
#include<vector>
#include<map>
using namespace std ;

#define M 108086391056891903 // a prime number close to 10^18 ( the bigger the better for the collision problem )
vector<long long> powert(123456); 
 long long add (long long a , long long b){
        return (a%M + b%M)%M ;    
    }
    long long substract(long long a ,long long b){
          return (a%M - b%M + M)%M;
    }
    long long mult (long long a ,long long b){
         return (a%M * b%M) %M;
    }
    long long pw(long long a ,int n){
         if(n==0) return 1; 
         if(n==1) return a%M; 
         long long h  = pw(a, n/2); 
         if(n%2 == 0) return  mult(h ,h);
         return mult(a , mult(h ,h)); 
    }
    long long inverse(long long a){
         return pw(a, M-1)%M; 
    }
    void computePowers(){
         powert[0] = 1 ; 
         powert[1] = 27; 
         for(int i=2 ; i<100001 ; i++){
             powert[i] =  mult(powert[i-1] , 27) ; 
         }
    }
    long long turn(string s){ 
       int n = s.size();
       long long ans = 0 ;
       // ab  == 1*27^1 + 2*27^0 
       for(int i=0 ; i<n ; i++){
            ans = add (ans , mult((long long)(s[i]-'a'+1) , powert[n-1-i] ));
       }
        return ans ; 
    }
    int  check(string s , int x){ 
         long long k = 0 ; 
         string a = "" ; 
         map<long long , int> mp ; 
         for(int i=0; i< x ;i++)  a+=s[i]; 
         k = turn(a) % M ;
         mp[k] = 1 ; 
         int kk=-1 , i = 1;
         for( i= 1 ; i<s.size()-x+1; i++ ){
              // so in here we want to remove x and add y from xabcdy 
              k = substract( k ,mult(powert[x-1], s[i-1]-'a'+1) ) ;
              k = add (mult(k , 27)  , (long long)(s[i+x-1]-'a'+1 )) ;
              if(mp.find(k) == mp.end()) mp[k] = 1; 
              else mp[k]++; 
              if(mp[k]>1) kk=i;
         }
         return kk;
    }
    string longestDupSubstring(string s) {
         /*
            if u noticed for example that if X is the longest dublicate Substring  X.size() = p
             then we will find dublicates of length p-1 , p-2 , p-3 
             once we move to smthg then p then we find nothing  ===> BS 
         */
        computePowers();
        string ans = ""; 
        int low = 0 , high = s.size() , current  = -1  , as = -1 ;
        while(low < high){
             int mid = (high+low+1)/2 ; 
             //1111111X00000000
            current = check(s, mid); 
             if(current == -1){
                 high = mid-1; 
             }else {
                  low = mid ;
                  as = current ;   

             }
        }
        for(int i=as ; i<as+low  &&  i<s.size() &&  i>=0 ; i++){
                 ans +=s[i]; 
        }
        return ans ;
    }
int main(){

     cout<<longestDupSubstring("qwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnm")<<endl; 

 }