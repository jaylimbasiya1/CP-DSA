// Problem: E - Through Path
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>g;
ll n;
vector<pair<ll,ll>>e;
vector<ll>dis;
vector<ll>val;
vector<ll>res;
void dfs1(ll i,ll par){
	dis[i]=dis[par]+1;
	
	for(auto k:g[i]){
		if(dis[k]!=-1)
		dfs1(k,i);
	}
}
int main(){
	ll n;
	cin>>n;
	g.resize(n+2);
	for(int i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;
		e.push_back({u,v});
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dis.resize(n+2,-1);
	dfs1(1,0);
	val.resize(n+2,0);
	res.resize(n+2,0);
	ll q;
	cin>>q;
	while(q--){
		ll t,i,k;
		cin>>t;
		if(t==1){
			cin>>i>>k;
			ll a=e[i].first;
			ll b=e[i].second;
			if(dis[a]>dis[b]){
				val[a]+=k;
			}
			else{
				val[b]-=k;
				val[1]+=k;
			}
		}
		else{
			cin>>i>>k;
			ll b=e[i].first;
			ll a=e[i].second;
			if(dis[a]>dis[b]){
				val[a]+=k;
			}
			else{
				val[b]-=k;
				val[1]+=k;
			}
		}
	}
	dfs2()
}