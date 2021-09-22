// Problem: Round Trip
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1669
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
int n,m;
vector<int> g[N];
vector<int> visit(N,false);
vector<int> parent(N);
int st_vertex,en_vertex;
void print_ans(){
	int ans=1;
	string res=to_string(st_vertex);

	while(st_vertex!=en_vertex){
		res+=" ";
		res+=to_string(en_vertex);
		en_vertex=parent[en_vertex];
		ans++;
	}
		ans++;
		res+=" ";
		res+=to_string(en_vertex);
		//cout<<"YES\n";
		cout<<ans<<endl;
		cout<<res;
		return;
}

bool dfs(int i, int par){
	
	visit[i]=true;
	parent[i]=par;
	for(auto z: g[i]){
		if(z==par)continue;
		
		if(visit[z]==true and z!=par){
		st_vertex=z;
		en_vertex=i;
		return true;	
		}
		
		if(dfs(z,i))return true;
	}
	return false;
}
bool visit_all(){
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			if(dfs(i,-1))return true;
		}
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	if(visit_all()){
		print_ans();
		
		
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
