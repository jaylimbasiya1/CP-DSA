// Problem: Apple Division
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1623
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
unordered_map<string,int> mp;

bool  solve(vector<int> a, int sum ,int i){
	
	if(sum==0)return true;
	if(i<0 and sum>0){
		return false;
	}
	
	string temp=to_string(sum)+" "+to_string(i);
	
	if(mp.count(temp))return mp[temp];
	return mp[temp]=(solve(a,sum-a[i],i-1) or solve(a,sum,i-1));
}
void go(){
	mp.clear();
	int n ;
	cin>>n;

	vector<int> a(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];	
		sum+=a[i];
	}
	if(n==1){
		cout<<a[0];
		return;
	}
	
	int res=INT_MIN;
	
	
		
		for(int mask=0;mask<1<<n;mask++){
			
			int sum1=0;
			
			for(int i=0;i<n;i++){
				if(mask&(1<<i))sum1+=a[i];
			}
			//cout<<mask<<" "<<sum1<<endl;
			if(sum1<=sum/2)res=max(res,sum1);
		}
		//cout<<res;
	cout<<sum-2*res	;
	
	
	return ;
}
int32_t main()
{	
	FIO;
	//vector<vector<bool>> v(21, vector<bool>(21,false));
	int t=1;
	
	while(t--){
		go();
	}
	return 0;
}