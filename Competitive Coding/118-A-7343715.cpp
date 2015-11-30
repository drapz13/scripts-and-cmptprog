#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char a[]="AEIOUYaeiouy";
    char b[100];
    cin>>b;
    for(int i=0;i<strlen(b);i++)
    {
        if(count(a,a+12,b[i])) {}
        else
        {
            cout<<".";
            if(b[i]<91) cout<<(char)(b[i]+32);
            else cout<<b[i];
        }
    }
    return 0;
}