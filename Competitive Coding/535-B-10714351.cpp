#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans = 0;
	string s;
	cin>>s;
	int index, v;
	int l=s.length();
	for(int i=l-1;i>=0;i--)
    {
		index = l-1-i;
		if(s[i]=='4')	v = 1;
		else if(s[i]=='7') v = 2;
		ans+= (v << index);
	}
	cout<<ans<<endl;
	return 0;

}