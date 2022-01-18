#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define 2dv vetor<vector<>>
//vector<ll>a;
//vector<vector<ll>>a;
// ll dim;
vector<vector<ll>>a;
vector<vector<ll>>dim;
vector<vector<ll>> matrix_mult(vector<vector<ll>> a, vector<vector<ll>> b){
	
	ll n=a.size();
	ll m=b[0].size();
	vector<vector<ll>>res(n,vector<ll>(m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			res[i][j]=0;
			
			for(int k=0;k<a[0].size();k++){
				res[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return res;
}
vector<vector<ll>> power(vector<vector<ll>>d,ll n){
	if(n==1)
	return d;
	
	if(n&1){
		vector<vector<ll>>res=power(d,n-1);
		res=matrix_mult(res,d);
		return res;
	}
	else{
		vector<vector<ll>>res=power(d,n/2);
		res=matrix_mult(res,res);
		return res;
	}
}
void go(){
	// cin>>n;
	
	/
	
	a={{0,1}};
	dim={{0,1},{1,1}};
	ll n;
	cin>>n;
	
	dim=power(dim,n);
	
	
	vector<vector<ll>>res=matrix_mult(a,dim);
	cout<<res[0][0]<<'\n';
	
}
int main(){
	ll t=1;
	// cin>>t;
	while(t--){
		go();
	}
}