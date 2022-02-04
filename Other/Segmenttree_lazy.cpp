#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>a;
ll n;
struct segemttree{
	vector<ll>tree,lazy;
	ll n;
	void init(ll k){
		this->n=k;
		tree.resize(4*n+1);
		lazy.resize(4*n+1);
	}
	
	void build(ll st, ll en, ll index){
		if(st==en){
			tree[index]=a[st];
			return;
		}
		
		ll mid= (st+en)/2;
		build(st,mid,index*2);
		build(mid+1,en,index*2+1);
		
		tree[index]= tree[index*2] + tree[index*2+1];
	}
	
	ll query(ll st , ll en, ll i, ll j, ll index){
		//No overlap
		if(st>j or en<i)
		return 0;//Returning Non effecting value
		
		if(lazy[index]!=0){
			tree[index]+= lazy[index]*(en-st+1);
			if(st!=en){
				lazy[2*index]=lazy[index];
				lazy[2*index+1]=lazy[index];
			}
			
			lazy[index]=0;
		}
		
		//complete overlap
		if(st>=i and en<=j)
		return tree[index];
		
		
		//Partial Overlap
		ll mid=(st+en)/2;
		ll left =query(st,mid,i,j,index*2);
		ll right=query(mid+1,en,i,j,index*2+1);
		
		return left+right;
	}
	
	void update(ll st, ll en, ll i, ll j, ll val, ll index){
			//No overlaping
			if(i>en or j<st)
			return;
			
			//Lazy Propogation
			if(lazy[index]!=0){
			tree[index]+= lazy[index]*(en-st+1);
			if(st!=en){
				lazy[2*index]=lazy[index];
				lazy[2*index+1]=lazy[index];
			}
			
			lazy[index]=0;
			}
			
			if(st>=i and en<=j){
				tree[index]+=val* (en-st+1);
				if(st!=en){
					lazy[2*index]+=val;
					lazy[2*index+1]+=val;
				}
				return;
			}
			
			//partial case
			ll mid=(st+en)/2;
			
			update(st,mid,i,j,val,2*index);
			update(mid+1,en,i,j,val,2*index);
		}	
	
}tree;
int main(){
	
	cin>>n;
	a.resize(n);
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	tree.init(n);
	tree.build(0,n-1,1);
	ll q;
	cin>>q;
	while(q--){
		ll t,x,y;
		cin>>t>>x>>y;
		if(t==1)
		cout<<tree.query(0,n-1,x,y,1)<<'\n';
		else{
			ll p;
			cin>>p;
			tree.update(0,n-1,x,y,p,1);
			cout<<tree.query(0,n-1,x,y,1)<<'\n';
		}
		
	}
	
	
}
