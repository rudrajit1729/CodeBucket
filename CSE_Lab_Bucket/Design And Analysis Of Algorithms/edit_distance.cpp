// Edit Distance - DP Approach
// Author - rudrajit1729

// Description 
/*
Given two strings x and y and below operations that can performed on x.
Find minimum number of edits (operations) required to convert x into y.

> Insert
> Remove
> Replace
All of the above operations are of equal cost.
Here we take cost as 1
*/

#include <bits/stdc++.h> 
using namespace std; 

// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int solve(string x, string y) 
{ 
	int m = x.size(), n = y.size();
	// Create a table to store results of subproblems 
	int DP[m + 1][n + 1]; 

	// Fill d[][] in bottom up manner 
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i == 0) 
				DP[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j == 0) 
				DP[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (x[i - 1] == y[j - 1]) 
				DP[i][j] = DP[i - 1][j - 1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				// Cost of insert, delete, replace are same = 1
				DP[i][j] = 1 + min(DP[i][j - 1], // Insert 
								DP[i - 1][j], // Remove 
								DP[i - 1][j - 1]); // Replace 
		} 
	} 

	return DP[m][n]; 
} 


int main() 
{ 
	// your code goes here 
	string x; 
	string y; 
	cout<<"Enter string 1 : ";
	cin>>x;
	cout<<"Enter string 2 : ";
	cin>>y;
	cout << "Minimum Operations : "<<solve(x, y)<<endl; 

	return 0; 
} 
