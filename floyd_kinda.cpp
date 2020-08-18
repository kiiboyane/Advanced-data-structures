#include<string> 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std ; 
 
#define INF (long long)1000000000000000000
#define N 505
#define M 1000006
 
long long v[N][N]; 
long long dist[N][N]={INF}; 
vector<bool> vis(N , false); 
int n ; 
 
long long  go(int t){
 // apply warshell 
 long long   sum = 0;
 for(int i=1  ; i<=n ; i++){
    for(int j =1 ; j<=n ; j++){   
            if( dist[j][t]>dist[j][i] + dist[i][t]){
                dist[j][t] =  dist[j][i] + dist[i][t]; 
            }
    }
 } 
    
 for(int i=1  ; i<=n ; i++){
         for(int k = 1 ; k<=n ; k++){      
            if( dist[t][k]>dist[t][i] + dist[i][k]){
                dist[t][k] =  dist[t][i] + dist[i][k]; 
            }
         }
 }
 for(int j =1 ; j<=n ; j++){
         for(int k = 1 ; k<=n ; k++){      
            if( dist[j][k]>dist[j][t] + dist[t][k]){
                dist[j][k] =  dist[j][t] + dist[t][k]; 
            }
         }
  }
 
 for(int j =1 ; j<=n ; j++){
         for(int k = 1 ; k<=n ; k++){
             if(vis[j] && vis[k]) {
                 sum+=dist[j][k];  
             }
        }
  }
 return sum;
}
void add(int x){
 
   vis[x] = true ; 
   for(int i=1; i<=n  ; i++){
        if(!vis[i]) continue; 
        dist[x][i] = v[x][i]; 
        dist[i][x] = v[i][x]; 
   }
}
int main(){
int a ; 
cin>>n; 
vector<long long> removed(n),result(n+5); 
for(int i=1 ; i<=n ; i++){
   for(int j=1 ; j<=n ; j++){
      dist[i][j] = INF; 
   }
}
 
for(int i=1; i<=n ; i++){
    for(int  j=1 ; j<=n ; j++){
         cin>>v[i][j];
    }
}
 
for(int i=0 ; i<n ; i++){
   cin>>removed[i];
}
 
for(int i = n-1; i>=0 ; i--){
     add(removed[i]); 
     result[i] = go(removed[i]);
}
for(int i=0 ; i<n ; i++ )cout<<result[i] << " ";
}
Click to see test details

Codeforces (c) Copyright 2010-2019 Mike Mirzayanov
The only programming contests Web 2.0 platform
Server time: Dec/15/2019 20:12:53UTC+1 (g1).
Desktop version, switch to mobile version.
Privacy Policy
Supported by
Telegram ИТМО
