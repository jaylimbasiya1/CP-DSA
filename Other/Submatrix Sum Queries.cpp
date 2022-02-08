#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll r,c;
	cin>>r>>c;
	vector<vector<ll>>a(r,vector<ll>(c));
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<ll>>dp(r,vector<ll>(c));

	dp[0][0]=a[0][0];
	for(int i=1;i<c;i++)
	dp[0][i]=a[0][i]+ dp[0][i-1];
	
	for(int i=1;i<r;i++)
	dp[i][0]=a[i][0]+ dp[i-1][0];

	
	for(int i=1;i<r;i++){
		for(int j=1;j<c;j++){
			dp[i][j]= a[i][j]+ dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}	
	ll q;
	cin>>q;
	while(q--){
		ll x,y,p,q;
		cin>>x>>y>>p>>q;
		
		ll tmp=0;
		
		
		if(x>0)
		tmp+=dp[x-1][q];
		
		if(y>0)
		tmp+=dp[p][y-1];
		
		if(x>0 and y>0)
		tmp-=dp[x-1][y-1];
		
		ll sum= dp[p][q]-tmp;
		cout<<sum<<'\n';
	}
}
