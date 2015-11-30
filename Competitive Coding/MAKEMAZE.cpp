#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int f=0,starti=-1,startj=-1,endi=-1,endj=-1;
char a[21][21];
bool tr[21][21];
int n,m;
bool val_maze(int r,int c)
{
    int ct=0;
    int i,j;
    i=0,j=0;
    //cout<<r<<c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        	if(i==0||i==r-1||j==0||j==c-1){
        	if(a[i][j]=='.')
        	{
	            if(starti==-1&&startj==-1)
            	{
	                starti=i;
                	startj=j;
            	}
            	else
            	{
	                endi=i;
                	endj=j;
            	}
            	ct++;
        	}
        	}
    	}
    }

    //cout<<ct<<endl;
    if(ct!=2)
    {
        return false;
    }
    return true;
}
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
bool dfs(int sx,int sy)
{
    //cout<<sx<<" "<<sy<<" "<<endi<<" "<<endj<<endl;
    if(sx==endi&&sy==endj) return true;
    if(tr[sx][sy]) return false;

    tr[sx][sy] = true;
    for(int i=0;i<4;i++)
    {
        int tx=sx,ty=sy;
        tx=sx+dx[i],ty=sy+dy[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m && a[tx][ty]=='.')
        {
            if(dfs(tx,ty))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    _        ///  FAST I/O
    __       ///  T TEST CASES
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        f=0,starti=-1,startj=-1,endi=-1,endj=-1;
        if(val_maze(n,m))
        {
            memset(tr,false,sizeof tr);
            if(dfs(starti,startj)) cout<<"valid\n";
            else cout<<"invalid\n";
        }
        else
        {
            cout<<"invalid\n";
        }

    }
    return 0;
}
