// Knapsack(0-1) - DP Approach
// Author - rudrajit1729

#include<bits/stdc++.h>
using namespace std;

void KnapSack(int S, int n, vector<int> &values, vector<int> &weights)
{
	// Table to store maximum values for given capacity
	int DP[n+1][S+1];

	// Build up table in bottom up manner
	for(int i = 0; i <= n; i++)
	{
		// X <= S -> Remaining Capacity
		for(int X = 0; X <=S; X++)
		{
			// If remaining items or sack size is 0 
			if(i==0 || X == 0)
				DP[i][X] = 0;

			else if(weights[i-1] <= X)
				DP[i][X] = max(values[i-1] + DP[i-1][X - weights[i-1]],// Included item
								DP[i-1][X] // Not included item
							   );
			else
				DP[i][X] = DP[i-1][X]; 
		}
	}

	// Store the result of the knapsack
	int res = DP[n][S];

	cout<<"Maximum Value : "<<res<<endl;
	cout<<"\nWeights\t\tValues\n";
	int X = S;
	for(int i = n; i > 0; i--)
	{
		// If res 0 i.e. if nothing could be packed
		if (res == 0)
			break;
		/*
		Now if res is non zero it has come from either
		Upper block DP[i-1][X] or from DP[i-1][X - weights[i-1]] + values[i]
		If it comes from later one it implies we have taken that item
		Add that item and reduce Size
		*/
		if (res == DP[i-1][X])
			continue;
		else
			// Item Included
			cout<<weights[i-1]<<"\t\t"<<values[i-1]<<endl;
			// As weight is included its value is deducted
			X -= weights[i-1];
			res -= values[i-1];
	}

}

int main()
{

	//vector<int> values{60, 100, 120}, weights{10, 20, 30}; int S = 50, n = 3;
	vector<int> values, weights; int S, n, v, w;
	cout<<"Enter Number of items : ";
	cin>>n;
	cout<<"Enter values : ";
	for(int i = 0; i < n; i++)
	{
		cin>>v;
		values.push_back(v);
	}
	cout<<"Enter weights : ";
	for(int i = 0; i < n; i++)
	{
		cin>>w;
		weights.push_back(w);
	}
	cout<<"Enter Size of Sack : ";
	cin>>S;
	KnapSack(S, n, values, weights);

}