
// Problem: Two Knights
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1072
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int dir1[]={-2,-2,2,2,1,1,-1,-1};
int die2[]={1,-1,1,-1,-2,2,2,-2};
void go(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		
		if(i==1)cout<<0<<endl;
		else{
			
			int k=i;
			int ans=0;
			
			for(int j=1;j<=k;j++){
				for(int m=1;m<=k;m++){
					
					
				}
			}
			
		}
		
		
	}
	
	
	
	return ;
}
int32_t main()
{	
	FIO;
	//vector<vector<bool>> v(21, vector<bool>(21,false));
	int t=1;
	cin>>t;
	while(t--){
		go();
	}
	return 0;
}
