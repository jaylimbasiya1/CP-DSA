// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

char a[1009][1009] ;
int dir1[]={0,0,-1,1};
int dir2[]={1,-1,0,0};
string direction="RLUD";
int n,m;
bool safe(int i, int j){
	
	return (i>=0 and i<n and j>=0 and j<m and (a[i][j]=='.' or a[i][j]=='B'));
}
void bord(int n , int m){
	for0(i,n){
		for0(j,m){
			a[i][j]='.';
		}
	}
}
class node{
	public:
	int i,j;
	string s;
	node(int p,int q,string x=""){
		i=p;
		j=q;
		s=x;
	}
};
void solve(){
	
	cin>>n>>m;
	int st_i=0,st_j=0;
	bord(1000,1000);
	int answer=0;
	// for0(i,n){
		// for0(j,m){
			// cin>>a[i][j];
			// if(a[i][j]=='A'){
				// st_i=i;
				// st_j=j;
			// }
// 			
		// }
	// }
	n=1000,m=1000;
	a[0][0]='A';
	a[990][990]='B';	
	queue<node*> q;
	q.push(new node(st_i,st_j,""));
	
	while(q.size()){
		answer++;
		auto tt=q.front();
	
		q.pop();
		
		int u=tt->i;
		int v=tt->j;
		string tk=tt->s;
		
		
		
		for(int k=0;k<4;k++){
			if(safe(u+dir1[k], v+dir2[k])){
				// i was changing its value;
				int u1=u+dir1[k];
				int v1=v+dir2[k];
				string tk1=tk+direction[k];
				if(a[u1][v1]=='B'){
				cout<<"YES\n";
				cout<<answer<<endl;
				cout<<tk1.size()<<endl;
				cout<<tk1<<endl;
	
				return;
				}
				// insted of visit array i am doing this.
				a[u1][v1]='~';
				q.push(new node(u1,v1,tk1));
			}
		}
			
	}
	
	cout<<"NO";
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
