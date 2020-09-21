#include<bits/stdc++.h> 
 
using namespace std ; 
 
class FEN {
	public : 
	   int sz; 
	   vector<long long> table; 
	FEN(int sz){
		this->sz = sz+1 ; 
		(this->table).resize(sz+1) ; 
	}
 
	void update(int i , long long delta){
       while(i<sz){
             table[i] = table[i] + delta; 
             i += i & (-i); 
		}
	}
	long long  sum(int i){
		long long count = 0 ; 
		while(i){
             count = count + table[i]; 
             i -= i & (-i); 
		}
		return count; 
	}
 
}; 
int main(){
  long long n , q, a,b; 
  cin>>n>>q ; 
  vector<long long> v(n);
  std::vector<pair<long long , int> >  times(n+1) ,request(q+5);
  FEN * fin = new FEN(n+5); 
  for(int i=0; i<n ; i++) cin>>v[i]; //n  
  for(int i=0; i<n ; i++) times[i].second = i ; //n
  for(int i=0 ; i<q ;i++){
       cin>>a>> b; 
       a--;b--;
       times[a].first ++ ; 
       times[b+1].first -- ; 
       request[i] = {a, b}; // 6*n
  }
  for(int i=1 ; i<n ; i++) times[i].first +=  times[i-1].first; // n
  sort(times.begin(), times.end());  // log(n)
  sort(v.begin(), v.end()); //log(n)
 
  for(int i=1; i<=n; i++){
  	 //  times[i].first is the smallest one 
  	 fin->update(times[i].second+1 , v[i-1]); 
  }
  long long sum  = 0 ; 
  for(int i=0 ;i<q ; i++ ){
  	  sum += fin->sum(request[i].second+1) - fin->sum(request[i].first) ; 
  }
  cout<<sum ; 
 
 
 
} 