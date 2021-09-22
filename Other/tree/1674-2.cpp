
// Powered by CP Editor (https://cpeditor.org)

// Problem: Subordinates
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1674
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
int N=200005;
unordered_map<int,int> mp;
void go(int k, vector<vector<int>> &a,int par){
	
	
	int ans=0;
	for(auto i:a[k]){
		if(i==par)continue;
		go(i,a,k);
		ans+=mp[i]+1;
	}
	mp[k]=ans;
}
void solve(){
	int n;
	cin>>n;
	vector<vector<int>> a(n+1,vector<int>());
	
	for(int i=2;i<=n;i++){
		int k;
		cin>>k;
		a[k].pb(i);
		a[i].pb(k);
	}
	
	go(1,a,-1);
	
	for(int i=1;i<=n;i++){
		cout<<mp[i]<<" ";
	}
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