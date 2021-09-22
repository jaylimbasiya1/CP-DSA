// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
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
int n,m;
vector<bool> visit(N,false);
vector<int> parent(N);
class node{
	public:
	int i;
	int par;
	node(int k, int parent){
		i=k;
		par=parent;
	}
};
int length=0;
void show_ans(int n1){
	length++;
	if(n1==1){
		cout<<length<<endl;
		cout<<n1<<" ";
		return;
	}
	show_ans(parent[n1]);
	cout<<n1<<" ";
	return;
}
void solve(){
	cin>>n>>m;
	for1(i,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	queue<node*> q;
	q.push(new node(1,-1));
	visit[1]=true;
	parent[1]=-1;
	while(q.size()>0){
		auto temp=q.front();
		q.pop();
		
		if(temp->i==n){
			show_ans(n);
			return;
		}
		int ii=temp->i;
		int p=temp->par;
		for(auto z:g[ii]){
			if(z==p or visit[z])continue;
			
			visit[z]=true;
			parent[z]=ii;
			q.push(new node(z,ii));
		}
	}
	cout<<"IMPOSSIBLE\n";
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
