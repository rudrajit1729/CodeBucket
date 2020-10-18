#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int s,n;
		cin>>s>>n;
		if(s==1||s==n)
			cout<<"1"<<endl;
		else if(s<n){
			if(s%2==0)
				cout<<"1"<<endl;
			else 
				cout<<"2"<<endl;
		}
		else{
			long long int ct=0,r;
			ct=int(s/n);
			r=s%n;
			if(r==0)
				ct+=0;
			else if(r%2==0||r==1)
				ct+=1;
			else
				ct+=2;
		cout<<ct<<endl;
		}
		cout<<"z"<<int('z')<<endl;
	}
	return 0;
}
			
