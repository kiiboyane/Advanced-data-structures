#include<string> 
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std ; 

#define N 10004
#define M 100005
int n , m ; 
//vector<vector<pair <int , int> > > v (N);  
vector<int> v(N); 
priority_queue<pair<int,pair<int,int>  >  , vector<pair<int ,pair<int,int> > >  , greater<pair<int ,pair<int,int> > > > pq;  // we want the smallest weight \ 

void initialize(){
   for(int i=1; i<=n ; i++ )
     v[i] = i ; 
}
int root(int x){
   while( v[x] != x){
       x = v[x]; 
   } 
   return x ; 
}

void unite(int x ,int y){
    int A = root(x) , B = root(y); 
    v[A] = B ; 
}

int main(){
int a ,b ,w ; 
cin>>n>>m ; 
for(int i=0; i<m ; i++){
    cin>>a>>b>>w ;
    pq.push({w , {a, b}}) ;
}
long long sum = 0 ; 
initialize();
while(pq.size()){ 
   int w = pq.top().first , a = pq.top().second.first , b =pq.top().second.second; 
   pq.pop(); 
   if(root(a) != root(b)){
     sum+=w; 
     unite(a, b) ;
   }  
}
cout<<sum ; 

}