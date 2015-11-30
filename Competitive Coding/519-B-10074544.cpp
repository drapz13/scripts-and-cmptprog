#include<iostream>
#include<map>
using namespace std;
map <int,int> a1,a2;
int a[100007],b[100007],c[100007];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a1[a[i]]++;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>b[i];
        a1[b[i]]++;
        a2[b[i]]++;
    }
    for(int i=0;i<n-2;i++)
    {
        cin>>c[i];
        a2[c[i]]++;
    }
    for(int i=0;i<n;i++)
        if(a1[a[i]]%2==1)
        {
            cout<<a[i]<<endl;
            break;
        }
    for(int i=0;i<n-1;i++)
        if(a2[b[i]]%2==1)
        {
            cout<<b[i]<<endl;
            break;
        }
    return 0;
}