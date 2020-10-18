#include<stdio.h>
#include<string.h>
int pal(char *s,int st,int en)
{
	int flag=1,i,j;
	for(i=st,j=en;i<=en,j>=i;i++,j--)
		if(s[i]!=s[j])
		{
			flag=0;
			break;
		}
	return flag;
}
int main()
{
	int n,i,j,k,flag=1,max=-1,start,end,count;
	scanf("%d",&n);
	char s[n];
	scanf("%s",s);
	for(j=n-1;j>=0;j--)
	{
		for(i=0;i<j;i++)
		{
			count=0;
			if(pal(s,i,j))
			{
				count=j-i+1;
				if(count>max)
				{
					start=i;end=j;
					max=count;
				}
			}
		}
	}
	printf("%d\n",max);
	for(k=start;k<=end;k++)
		printf("%c",s[k]);
	return 0;			
}
	
