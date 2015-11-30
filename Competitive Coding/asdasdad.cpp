#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define __ int t;cin>>t;while(t--)
#define endl '\n'

using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main()
{
    _        ///  FAST I/O
    // __       ///  T TEST CASES
    {
        string s;
	cin>>s;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{

		int l1,l2,r1,r2;
			scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
			if(r2-l2!=r1-l1)
            {
                printf("No\n");
                continue;
            }

	  if (s.compare(l1-1,(r1-l1)+1,s,l2-1,(r2-l2)+1) == 0)

		printf("Yes\n");
		else
		printf("No\n");

	}
    }
    return 0;
}
