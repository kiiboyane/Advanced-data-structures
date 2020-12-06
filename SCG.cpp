#include<bits/stdc++.h>
using namespace std;

#define M 16
int n , m,num=0;
vector<set<int> >  adj(M),revAdj(M);

bool vis[M];
stack<int> s;
void dfss(int n){
	vis[n]=true;
	for(auto& a : adj[n])
		if(!vis[a])
					dfss(a);
	s.push(n);
}
void dfs(int n){
	num++;
	vis[n]=true;
	for(auto& a : revAdj[n])
		if(!vis[a])
					dfs(a);
}


int main() {
	int l , r, odd=0, even=0;
	cin>>n>>m;
	for(int i=0 ; i<m; i++){
		cin>>l>>r;
		adj[l].insert(r);
		revAdj[r].insert(l);
	}
	memset(vis,false,sizeof(vis));
	for(int i=1; i<=n ; i++)
		if(!vis[i])
			dfss(i);
	memset(vis,false,sizeof(vis));

	while(!s.empty()){
		num=0;
		l=s.top();
		s.pop();
		if(!vis[l])
		{
					   dfs(l);
					   if(num%2)
						   odd+=num;
					   else even+=num;
		}

	}
	cout<<odd-even;
}
