#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[100];
        cin>>a;
        int l=strlen(a);
        if(l>10)
        {
            cout<<a[0]<<l-2<<a[l-1]<<endl;
        }
        else cout<<a<<endl;
    }
    return 0;
}