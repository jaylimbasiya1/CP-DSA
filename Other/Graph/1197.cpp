// Problem: Cycle Finding
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1197
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: High Score
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1673
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
#define inf             1e15
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

const int ninf=-1*inf;
class node{
	public:
	int u,v,w;
	node(int i,int j, int k){
		u=i;
		v=j;
		w=k;
	}
};
const int N=2505;
vector<node*> edges(5005);
vector<int> g[N];
//default initiaL VALUE OF VECTOR IS ZERO.
vector<int> d(N,0);
vector<int> relaxant(N,-1);
int n,e;

void bellman(){

    int x;
    for(int i=1;i<=n;i++){
    //store last relaxed node.
    	x=-1;
        for(int j=0;j<e;j++){
            int u=edges[j]->u;
            int v=edges[j]->v;
            int weight=edges[j]->w;
            
            if(d[u]+weight<d[v]){
            	d[v]=d[u]+weight;
            	relaxant[v]=u;
            	x=v;
            }
           
        }
    }    
        
   if(x==-1){
   	cout<<"NO";
   	return;
   }
   
   for(int i=1;i<=n;i++)
   x=relaxant[x];
   
   vector<int> cycle;
   
   for(int v=x; ;v=relaxant[v]){
   	cycle.pb(v);
   	
   	if(v==x and cycle.size()>1)
   	break;
   
   }
   
   reverse(cycle.begin(),cycle.end());
   cout<<"YES\n";
   for(auto z: cycle)
   cout<<z<<" ";
   
   return;
}


void solve(){
	cin>>n>>e;
	
	for0(i,e){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i]=new node(u,v,w);
		
	}
	
	bellman();
	
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
