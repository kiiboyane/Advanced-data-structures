#include<iostream> 
#include<vector> 
#include<queue>

using namespace std; 


int n , m ; 
vector<vector<int> > v(15) ;
vector<int > degree(15 , 0) ;
queue<int> res; 
vector<bool> vis(15); 
priority_queue<int , vector<int> , greater<int> > q; 

void go(){
   for(int i=1; i<=n ; i++){
        for(int j=0; j<v[i].size(); j++){
              degree[v[i][j]]++; 
        }
   }
   for(int i=1; i<=n ;i++){
      if(degree[i] == 0)
          q.push(i) , vis[i]= true; 
   }
   while(q.size()){
      int e = q.top(); 
      q.pop(); 
      res.push(e); 
      for(int i=0; i<v[e].size(); i++){
          degree[v[e][i]]--; 
          if(degree[v[e][i]] == 0 && vis[v[e][i]]== false){
             q.push(v[e][i]); 
             vis[v[e][i]] =true ;
          }
      }
   }
}

int main(){
  int a , b ; 
  cin>>n>>m; 
  for(int i=0; i<m ; i++){
       cin>>a>>b; 
       v[a].push_back(b); 
  }
  go();
  while(res.size()){
      cout<<res.front() << " "; 
      res.pop(); 
  }

}