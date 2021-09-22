// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
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

vector<vector<char>> a(1002, vector<char>(1002));
int dir1[]={0,0,-1,1};
int dir2[]={1,-1,0,0};
int n,m;
bool safe(int i, int j){
	
	return (i>=0 and i<n and j>=0 and j<m);
}
void dfs(int i, int j){
	//cout<<i<<" "<<j<<endl;
	a[i][j]='$';
	for(int k=0;k<4;k++){
		if(safe(i+dir1[k], j+dir2[k]) and a[i+dir1[k]][j+dir2[k]]=='.'){
			dfs(i+dir1[k], j+dir2[k]);
		}
	}
}
void solve(){
	
	cin>>n>>m;
	
	
	for0(i,n){
		for0(j,m){
			cin>>a[i][j];
		}
	}
	
	int ans=0;
	for0(i,n){
		for0(j,m){
			if(a[i][j]=='#' or a[i][j]=='$')continue;
			ans++;
			dfs(i,j);
		}
	}
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
