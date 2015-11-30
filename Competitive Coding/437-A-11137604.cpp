#include <bits/stdc++.h>

using namespace std;
string s;
int blah[4];
bool blee[4];

int main()
{
    memset(blee,false,sizeof blee);
    for(int i=0;i<4;i++) {cin>>s;blah[i]=s.length()-2;}
    for(int i=0;i<4;i++)
    {
        int bloo=0,blaboo=0;
        for(int j=0;j<4;j++)
        {
            if(j==i) continue;
            if(blah[j]>=2*blah[i]) bloo++;
            if(2*blah[j]<=blah[i]) blaboo++;
        }
        if(bloo==3||blaboo==3) blee[i]=true;
    }
    int badakaboo=0;
    for(int i=0;i<4;i++)
        if(blee[i]) badakaboo++;
    if(badakaboo!=1)
        cout<<"C\n";
    else
        for(int i=0;i<4;i++)
            if(blee[i])
                {cout<<(char)('A'+i);
                break;}
    return 0;
}