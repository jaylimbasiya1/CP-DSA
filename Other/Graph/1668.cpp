// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
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

const int N=100005;
vector<int> g[N];
vector<int> color(N,-1);
int n,e;

bool dfs(int i, int clr, int par){
	color[i]=clr;
	
	for(auto z:g[i]){
		if(z==par)continue;
		
		if(color[z]==-1){
			if(!dfs(z,clr%2+1,i)){
			return false;
			}
		}
		
		if(color[z]==clr)
		return false;
	}
	
	return true;
}
bool color_all(){
	for(int i=1;i<=n;i++){
		if(color[i]!=-1)continue;
		//parent of root is -1 and color is 1;
		if(!dfs(i,1,-1)){
			return false;
		}
	}
	return true;
}
void solve(){
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	//all color
	
	
	if(color_all()){
		for1(i,n)cout<<color[i]<<" ";
	}
	else{
		cout<<"IMPOSSIBLE\n";
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
