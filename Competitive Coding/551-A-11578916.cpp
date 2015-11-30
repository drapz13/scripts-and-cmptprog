#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
map<int,int>::reverse_iterator it;
int a[2005];
int main()
{
    int n;
    cin>>n;
    m.clear();
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[x]++;
        a[i]=x;
    }
    int p=1,ct=1;
    for(it=m.rbegin();it!=m.rend();++it)
    {
        ct=it->second;
        it->second=p;
        p+=ct;
    }
    for(int j=0;j<n;j++) cout<<m[a[j]]<<" ";
    return 0;
}