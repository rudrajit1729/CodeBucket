#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int k,x,n,ans=0;
		cin>>k>>x;
		n=s.length();
		int w[26] {0};
		int i;
		for(i=0;i<n;i++)
		{
			w[s[i]-'a']++;
			if(w[s[i]-'a']>x){
				
				k--;
				w[s[i]-'a']--;
			
			if(k<0)
				break;
			else
				continue;
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
			
