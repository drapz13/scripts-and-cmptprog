#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'


using namespace std;


int mini3(int a,int b,int c)
{
    int a1[3];
    a1[0]=a;
    a1[1]=b;
    a1[2]=c;
    return *min_element(a1,a1+3);
}

int mini4(int a,int b,int c,int d)
{
    int a1[4];
    a1[0]=a;
    a1[1]=b;
    a1[2]=c;
    a1[3]=d;
    return *min_element(a1,a1+4);
}
int main()
{
    _        ///  FAST I/O
    //__       ///  T TEST CASES
    int n,ct=1;
    while(cin>>n && n!=0)
    {
        vector<int> v[n];
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            v[i].push_back(x);
            v[i].push_back(y);
            v[i].push_back(z);
            if(i==0) v[i][2]+=v[i][1];
            else if(i==1) v[i][0]+=v[i-1][1],v[i][1]+=mini3(v[i-1][1],v[i-1][2],v[i][0]),v[i][2]+=mini3(v[i-1][1],v[i-1][2],v[i][1]);
            else
            {
                v[i][0]+=min(v[i-1][0],v[i-1][1]);
                v[i][1]+=mini4(v[i-1][0],v[i-1][1],v[i-1][2],v[i][0]);
                v[i][2]+=mini3(v[i-1][1],v[i-1][2],v[i][1]);
            }
        }
        cout<<ct<<". "<<v[n-1][1]<<endl;
    }
    return 0;
}
