#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'
#define ispow2(n) (n&&(!(n&(n-1))))      ///check if its perfect power of 2
using namespace std;
template <typename T>
T modpow(T base, T exp) {
  /// base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base); ///  % modulus;
    base = (base * base); ///  % modulus;
    exp >>= 1;
  }
  return result;
}
#define ll long long
struct data {
	ll ore,xore;
	ll b1[25],b0[25];
};
ll a[200005];
data stree[200005];

data create(ll x) {
	data v;
	v.ore=v.xore=0;
	for(int i=0;i<25;++i) {
		if((x>>i)&1) {
			v.b1[i]=1;
			v.b0[i]=0;
		}
		else {
			v.b1[i]=0;
			v.b0[i]=1;
		}
	}
	return v;
}
ll p2[25];
data combine(data lc, data rc) {
	data p;
	ll o=0,x=0;
	o=lc.ore+rc.ore;
	x=lc.xore+rc.xore;
	for(int i=0;i<25;++i) {
		o+=(lc.b1[i]*rc.b1[i]+lc.b1[i]*rc.b0[i]+lc.b0[i]*rc.b1[i])*p2[i];
		x+=(lc.b1[i]*rc.b0[i]+lc.b0[i]*rc.b1[i])*p2[i];
	}
	p.ore=o;
	p.xore=x;
	for(int i=0;i<25;++i) {
		p.b1[i]=lc.b1[i]+rc.b1[i];
		p.b0[i]=lc.b0[i]+rc.b0[i];
	}
	return p;
}

void build(int node, int tl, int tr) {
	if (tl == tr) {
		stree[node] = create(a[tl]);
	}
	else {
		int tm = (tl+tr)/2;
		build(2*node,tl,tm);
		build(2*node+1,tm+1,tr);
		stree[node] = combine(stree[2*node],stree[2*node+1]);
	}
}

data query(int node, int tl, int tr, int i, int j) {
	if (i == tl && j == tr) return stree[node];
	int tm = (tl+tr)/2;
	if(j <= tm) return query(2*node,tl,tm,i,j);
	if(i > tm) return query(2*node+1,tm+1,tr,i,j);
	return combine(query(2*node,tl,tm,i,tm),query(2*node+1,tm+1,tr,tm+1,j));
}

void update(int node, int i, int val, int tl, int tr) {
	if (tl == tr) {
		stree[node] = create(val);
		return;
	}
	int tm = (tl+tr)/2;
	if (i <= tm) update(2*node, i, val, tl, tm);
	else update(2*node+1, i, val, tm+1, tr);
	stree[node] = combine(stree[2*node],stree[2*node+1]);
}
int main() {
	int n,i,j;
	data x;
	ll k1,k2,ct=0;
	cin>>n>>k1>>k2;
	p2[0]=1;
	for(i=1;i<25;++i) p2[i]=p2[i-1]*2;
	for(i=0;i<n;++i) cin>>a[i];
	build(1,0,n-1);
	for(i=0;i<n;++i) {
		for(j=i+1;j<n;++j) {
			x=query(1,0,n-1,i,j);
			if(x.ore>k1&&x.xore>k2) ++ct;
		}
	}
	cout<<ct<<endl;
	return 0;
}
