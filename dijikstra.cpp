#include<string> 
#include<iostream>
#include<vector>
#include<queue>
using namespace std ; 

#define INF (long long)1000000000
#define N 10004
#define M 1000006

vector<vector<pair<int ,long long> > > v(N); 
int n , m; 
vector<long long> dist(N , INF); 
void dij(){
priority_queue<pair<long long , int> , vector<pair<long long , int> > , greater<pair<long long , int> > > pq; 
pq.push({0 , 1 });
dist[1] = 0;  
while(pq.size()){
   int   p = pq.top().second ; 
   long long w = pq.top().first; 
   pq.pop();
   for(int i = 0 ; i < v[p].size()  ; i++){
      if(dist[v[p][i].first] > dist[p] + v[p][i].second ){
         dist[v[p][i].first] = dist[p] + v[p][i].second ;
         pq.push({dist[v[p][i].first] , v[p][i].first});  
      }
   }
}
}
int main(){
int a ,b ; 
long long w ; 
cin>>n>>m ; 
for(int i=0; i<m ; i++){
    cin>>a>>b>>w ;
    v[a].push_back({b , w});
    v[b].push_back({a , w});
}
dij(); 
for(int i=2 ; i<=n ; i++) cout<<dist[i]<< " ";


}