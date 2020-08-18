#include<iostream>
#include<vector>
#include<set>
using namespace std ; 

#define N 10 
#define M 10 
#define MAX 100000000
int n , m ; 
vector<vector<int> > v(N); 
set<int> ap;
vector<bool> vis(N); 
vector<int> disc(N); // discovery time   
vector<int> low (N , MAX); 
vector<int> parent (N , MAX); 
set<pair<int , int> > brd; 

int tme = 0 ; 
void dfs(int x){ 
   vis[x] = true; 
   disc[x]=low[x] = tme ++; 
   int child = 0 ; 
   for(int i=0 ; i<v[x].size(); i++){
       if(vis[v[x][i]]){ // if it was visited
               if(parent[x] != v[x][i]) 
                    low[x] = min(low[x] , disc[v[x][i]]); 
       }else{
           parent[v[x][i]] = x ; 
           child ++ ; 
           dfs(v[x][i]); 
           low[x] = min(low[x] , low[v[x][i]]);
           if(parent[x] == MAX && child > 1  ) // for the root 
                ap.insert(x); 
           else if(parent[x] != MAX && low[v[x][i]] >= disc[x]){ // this means 3amarna wessalna lih b ch i path  mafihch x avant v[x][i]
                  ap.insert(x); 

           }  

           if(low[v[x][i]] > disc[x]){ 
                 brd.insert({min(v[x][i] , x), max(v[x][i] , x)});
           }
       }
   }
}

/*
  in a graph you have to test  if a vertex has a back edge
  which means we can get to the vertex using another parent in a shorter time ; more like a back up path 

*/
int main(){
  int a , b ; 
  cin>>n>>m; 
  for(int i=0 ;i<m ;i++){
       cin>>a>>b ; 
       v[a].push_back(b); 
       v[b].push_back(a); 
  }
  dfs(0); 
  cout<<ap.size()<< endl; 
  for(auto & c : ap ) cout<<c << " ";
  cout<<endl;
  cout<<brd.size()<< endl; 
  for(auto& c : brd){
      cout<<c.first << " "<< c.second << endl; 

  } 

}