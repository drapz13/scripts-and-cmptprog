#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int pow2[20];
int main()
{
    pow2[0]=1;
    for(int i=1;;i++)
    {
        pow2[i]=2*pow2[i-1];
        if(2*pow2[i]>maxn) break;
    }
    int sum,lim;
    cin>>sum>>lim;
    vector< pair<int,int> > v(lim);
    vector<int> achha;
    for(int i=1;i<=lim;i++)
    {
        int temp=i,ct=0;
        while(temp%2==0)
        {temp/=2;ct++;}
        v[i-1]=make_pair(pow2[ct],i);
    }
    sort(v.begin(),v.end());
    //for(int i=0;i<lim;i++) cout<<v[i].first<<" "<<v[i].second<<'\n';
    int ansct=0;
    for(int i=lim-1;i>=0;i--)
    {
        if(sum-v[i].first>=0)
        {
            achha.push_back(v[i].second);
            sum-=v[i].first;
            ansct++;
            if(sum==0) break;
        }
    }
    if(sum==0)
    {
        cout<<ansct<<'\n';
        for(int i=0;i<ansct;i++) cout<<achha[i]<<" ";
    }
    else cout<<"-1";
    return 0;
}