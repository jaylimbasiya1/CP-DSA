// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
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

int N=1005;
vector<vector<char>> g(N,vector<char>(N));
vector<vector<char>> visit(N,vector<char>(N,'z'));

int n,m;
int dir1[]={-1,1,0,0};
int dir2[]={0,0,-1,1};
string dir="UDLR";
int st_i,st_j;
bool safe(int i, int j){
	return (i>=0 and i<n and j>=0 and j<m and (g[i][j]=='.' or g[i][j]=='B')  and visit[i][j]=='z' ); 
}
int ans=0;
void show_ans(int i, int j){
	
	if(st_i==i and st_j==j){
		cout<<"YES\n";
		cout<<ans<<endl;
		return;
	}
	ans++;
	if(visit[i][j]=='U'){
		
		show_ans(i+1,j);
		cout<<"U";
		
	}
	else if(visit[i][j]=='D'){
		show_ans(i-1,j);
		cout<<"D";
	}
	else if(visit[i][j]=='L'){
		show_ans(i,j+1);
		cout<<"L";
	}
	else{
		show_ans(i,j-1);
		cout<<"R";
	}
	
	return;
}
void solve(){
	cin>>n>>m;
	
	for0(i,n){
		for0(j,m){
			cin>>g[i][j];
			if(g[i][j]=='A'){
				st_i=i;
				st_j=j;
			}
		}
	}
	
	queue<pair<int,int>> q;
	q.push({st_i,st_j});
	visit[st_i][st_j]='S';
	
	while(q.size()>0){
		auto temp=q.front();
		q.pop();
		
		int u,v;
		u=temp.ff;
		v=temp.ss;
		
		if(g[u][v]=='B'){
			show_ans(u,v);
			return;
		}
		
		for(int i=0;i<4;i++){
			if(safe(u+dir1[i], v+dir2[i])){
				visit[u+dir1[i]][v+dir2[i]]=dir[i];
				q.push({u+dir1[i], v+dir2[i]});
			}
		}
	}
	cout<<"NO\n";
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
