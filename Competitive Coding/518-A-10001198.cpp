#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[104],b[104];
    cin>>a>>b;
    int f=0,w=-1;
    int l=strlen(a);
    int i=l-1,g=0;
    while(a[i]=='z') i--;
    a[i]+=1;
    for(int j=i+1;j<l;j++) {a[j]='a';}
    //cout<<a;
    if(strcmp(a,b)==0) cout<<"No such string\n";
    else cout<<a<<endl;
    return 0;
}