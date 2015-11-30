#include<bits/stdc++.h>
#define s(a) scanf("%d",&a)
#define f(i,n) for(i=0;i<n;i++)
using namespace std;
pair<int,int> a[1001];
pair<int,int> b[1001];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    f(i,n)
    {
        s(a[i].first);
        a[i].second=i;
        b[i].second=i;
        b[i].first=a[i].first;
    }
    int c=a[0].first;
    int d=c;
    sort(b,b+n);
    while(b[n-1].second!=0)
    {
        for(j=0;j<n;j++)
        {
            if(b[j].second==0)
            {
                break;
            }
        }
        b[j].first++;
        b[n-1].first--;
        sort(b,b+n);
    }
    cout<<b[n-1].first-a[0].first;

    return 0;
}