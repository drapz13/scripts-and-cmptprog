#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
        cin>>n>>m;
        if(m>n)cout<<"-1\n"<<endl;
        else{
        for(int i=n/2;i>=0;i--)
        {
            if(((n-i)%m)==0)
            {
                cout<<n-i<<endl;
                break;
            }
        }
        }

    return 0;
}