#include <bits/stdc++.h>
#define ll long long
using namespace std;

multiset<ll> hpt, hdiff, vpt, vdiff;
multiset<ll>::iterator it1, it2, it3;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll w,h,n,temp;
    cin>>w>>h>>n;
    hpt.insert(0);hpt.insert(w);
    vpt.insert(0);vpt.insert(h);
    hdiff.insert(w);
    vdiff.insert(h);
    char c;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        cin>>temp;
        if(c=='H')
        {
            vpt.insert(temp);
            it1=it2=it3=vpt.find(temp);
            it2--;
            it3++;
            ll dif= *it3-*it2;
            ll dif1= *it1-*it2;
            ll dif2= *it3-*it1;
            it1=vdiff.find(dif);
            vdiff.erase(it1);
            vdiff.insert(dif1);
            vdiff.insert(dif2);
        }
        else
        {
            hpt.insert(temp);
            it1=it2=it3=hpt.find(temp);
            it2--;
            it3++;
            ll dif= *it3-*it2;
            ll dif1= *it1-*it2;
            ll dif2 = *it3-*it1;
            it1=hdiff.find(dif);
            hdiff.erase(it1);
            hdiff.insert(dif1);
            hdiff.insert(dif2);
        }
        it1=hdiff.end();
        it1--;
        it2=vdiff.end();
        it2--;
        ll ans= (*it1) * (*it2);
        cout<<ans<<'\n';
    }
}