#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    lli w,h,n;
    cin>>w>>h>>n;
    set<lli>hcut;
    set<lli>vcut;
    multiset<lli>hmax;
    multiset<lli>wmax;
    hcut.insert(0);
    hcut.insert(h);
    vcut.insert(0);
    vcut.insert(w);
    hmax.insert(h);
    wmax.insert(w);
    set<lli>::iterator it;
    multiset<lli>::iterator it1,it2;
    while(n--)
    {
        char c;
        lli cut,pre,fro,ans;
        cin>>c>>cut;
        if(c=='H')
        {
            hcut.insert(cut);
            it=hcut.find(cut);
            it--;
            pre=*(it);
            it++;
            it++;
            fro=*(it);
            it--;
            //cout<<fro<<pre<<endl;
            it1=hmax.find(fro-pre);
            hmax.erase(it1);
            hmax.insert(cut-pre);
            hmax.insert(fro-cut);
        }
        else
        {
            vcut.insert(cut);
            it=vcut.find(cut);
            it--;
            pre=*(it);
            it++;
            it++;
            fro=*(it);
            it--;
            //cout<<fro<<pre<<endl;
            it1=wmax.find(fro-pre);
            wmax.erase(it1);
            wmax.insert(cut-pre);
            wmax.insert(fro-cut);
        }
        it1=hmax.end();
        it1--;
        it2=wmax.end();
        it2--;
        //cout<<*it1<<endl<<*it2<<endl;
        ans=(*it1)*(*it2);
        cout<<ans<<endl;
    }
    return 0;
}