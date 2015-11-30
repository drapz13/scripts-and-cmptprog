#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define ll long long

using namespace std;

vector<int> g[100010];
int f[100010];
bool v[100010];
bool n=false;
int ff=0;
void dfs(int cs, int mx){
	v[cs]=true;
	forn(i,g[cs].size()){
		if(!v[g[cs][i]]){
			if( f[g[cs][i]] > mx ){
				ff=1;
				return;
			} else dfs(g[cs][i],max(1,mx-1));
		}
	}
}

int main(void){
	ll n; cin>>n;
	forn(i,n-1){
		ll a,b;cin>>a>>b;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
		f[a]++;
		f[b]++;
	}

	ll m=0;
	forn(i,n) if(f[i]>f[m]) m=i;

	if( f[m]>=4 ) dfs(m,3);
	if(ff) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
