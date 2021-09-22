// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define for0(i,n)       for (int i=0;i<(n);i++)
#define for1(i,n)       for (int i=1;i<=(n);i++)
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define vii				vector<vi>
#define all(c) 			(c).begin(),(c).end()
#define mii             map<int,int>
#define max(a,b)		a>=b?a:b
#define min(a,b)		a<=b?a:b
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int N=200005;
vector<vector<int>> g(N,vector<int>());
vector<int> dp(N,-1);
int ans=INT_MIN;
vector<bool> visit(N,false);
// here p for parent and parent plays imp role in removing loop,
//loop exist as here storing edge as bi directional;
void go(int i, int p){
	
	vi temp;
	
	for(auto z:g[i]){
		
		if(z==p)continue;
		
		if(dp[z]==-1)
		go(z,i);
		
		temp.pb(dp[z]);
	}
	
	sort(temp.begin(),temp.end());
	int x1=-1;
	int x2=-1;
	int ans1=0;
	if(temp.size()>1){
		x1=temp[temp.size()-1];
		x2=temp[temp.size()-2];
			ans1=x1+x2+2;
	}
	else if(temp.size()==1){
		x1=temp[0];
		ans1=x1+1;
	}
	
	ans=max(ans,ans1);
	dp[i]=x1+1;
	return;
}
void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	//0 is dummy parent
	go(1,0);
	cout<<ans;
	return ;
}
int32_t main()
{	
	FIO;
	
	int t=1;
	
	while(t--){
		solve();
	}
	return 0;
}
