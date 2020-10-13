# include<stdio.h>
#include<conio.h>
# define Q  8 //N-queens
struct POINT {int x,y;};//Coordinate of queen
struct POINT q[Q];//array of coordinates
int N;//solution number
int chkAll(int x)//returns 0 if current queen not in path of other previous queens
{
	for ( int i =x ; i >=0 ; i--)
	{
		for(int j = i - 1; j >= 0 ; j--)
		{
			if(q[i].x == q[j].x || q[i].y == q[j].y || q[i].x + q[i].y == q[j].x + q[j].y || q[i].x - q[j].x == q[i].y - q[j].y)
			//horizontal check,vertical check,left diagonal check,right diagonal check
				return 0;
		}
	}
	return 1;
}
void MoveQueen(int x)
{

	if(x >= Q)//all coordinates of nth solution found
	{
		printf("\n\nSolution : %d \n\n\t",++N);//nth solution
		for(int i=0;i<Q;i++)
		{
			for(int j=0;j<Q;j++)
			{
				if((q[i].x==i) && (q[i].y==j))//checking whether current coordinate falls matches with a queen's coordinate.
					printf("Q%c",179);//179 ascii for '|'
				else
					printf("_%c",179);
			}
			printf("\n\t");
		}
		return;
	}
	for (int j = 0; j < Q ;j++)
	{
		q[x].y = j;
		q[x].x = x;
		//xth row jth column parsed as coordinates
		if(chkAll(x))//checks for queen crossing path
			MoveQueen(x + 1);
	}
}
int main()
{
   	for (int i = 0; i < Q; i++)
	{
		//place 1st queen at ith column of first row 
		//done for predicting various solutions
		q[0].x = 0;
		q[0].y = i;//0
		MoveQueen(1);//after 1st queen placed move to next row for second one.
		getch();
	}
	return 0;
}
