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
		int i,count=0;
		for(i=0;i<s.length()-1;)
		{
			//cout<<"i= "<<i<<endl;
			if(s[i]-'0'!=s[i+1]-'0')
			{
				count++;
				i=i+2;
			}
			else 
				i+=1;
		}
		cout<<count<<endl;
	}
	return 0;
}
