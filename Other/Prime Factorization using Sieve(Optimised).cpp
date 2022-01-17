#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>a(1e6,-1);
void precomputation(){
	a[0]=0;
	a[1]=1;
	
	for(int i=2;i*i<1e6;i++){
		if(a[i]!=-1)
		continue;
		
		for(ll j=i;j<1e6;j+=i)
		a[j]=i;
	}
}
void go(){
	ll n;
	cin>>n;
	
	while(n>1){
		if(a[n]==-1)
		a[n]=n;
		cout<<a[n]<<" ";
		n/=a[n];
	}
	cout<<n<<"\n";
	
}
int main(){
	ll t=1;
	cin>>t;
	precomputation();
	while(t--){
		go();
	}
}
