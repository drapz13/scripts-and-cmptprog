#include <bits/stdc++.h>

using namespace std;
int a[26];
int main()
{
    int n;
    cin>>n;
    char c;
    long long int ans=0;
    for(int i=0;i<2*n-2;i++)
    {
        cin>>c;
        if(c<='Z'&&c>='A')
        {
            a[c-'A']--;
            if(a[c-'A']<0)
            {
                ans++;
                a[c-'A']=0;
            }
        }
        else
        {
            a[c-'a']++;
        }
    }
    cout<<ans<<endl;
    return 0;
}