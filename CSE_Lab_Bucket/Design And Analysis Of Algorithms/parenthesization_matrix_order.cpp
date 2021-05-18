// Parenthesization - Matrix muliplication - DP Approach
// Author - rudrajit1729
#include<bits/stdc++.h>
#define INF 99999999
using namespace std;

int solve(int p[], int n);
void printSolution(int i, int j, int n, int *DP, char& name);

/*
 Input:  p[] = {40, 20, 30, 10, 30}  
  Output: Optimal parenthesization is  ((A(BC))D)
          Optimal cost of parenthesization is 26000
  There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30} 
  Output: Optimal parenthesization is (((AB)C)D)
          Optimal cost of parenthesization is 30000
  There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

  Input: p[] = {10, 20, 30}  
  Output: Optimal parenthesization is (AB)
          Optimal cost of parenthesization is 6000
  There are only two matrices of dimensions 10x20 and 20x30. So there 
  is only one way to multiply the matrices, cost of which is 10*20*30
  */

int main()
{
	int n;
	cout<<"Enter Number of matrices : ";
	cin>>n;
	n += 1;// Chain will contain n+1 items
	int p[n];
	cout<<"Enter Dimension chain array\n";
	for(int i = 0; i < n; i++)
		cin >> p[i];
	cout<<"Optimal Parenthesization : ";
	cout<<"\nOptimal Cost : "<<solve(p, n)<<endl;
}

int solve(int p[], int n)
{
	// Table to store cost of multiplying matrices
	// m[i][j] = cost of multiplying matrices A[i]A[i+1]...A[j]
	// Dimension of each matrix A[i] = P[i-1] x P[i]
	int m[n][n];
	int DP[n][n]; // Stores the breakpoints

	// Initializing 
	// Cost of multiplying one matrix = 0
	for(int i = 1; i < n; i++)
	{
		m[i][i] = 0; 
		DP[i][i] = 0;
	} 

	// Solving parenthesization - O(n^3)

	// Trying every substring structure
	// Starting chain length(S) = 2 
	// We already know cost for multiplying 1 matrix
	// Here after 1 iteration we would know optimal costs to multiply S matrices
	for(int S = 2; S < n; S++)
	{
		// Finding out optimal ways to multiply matrices A[i...n-S+1] 
		for(int i = 1; i < n - S + 1; i++)
		{
			int j = i + S - 1;
			m[i][j] = INF;
			// Finding the breakpoint such that cost is minimum 
			for(int k = i; k <= j-1; k++)
			{
				// 	Dimension of matrix A[i...k] = p[i-1] * p[k]
				// 	and of matrix A[k+1...j] = p[k] * p[j]
				// 	Cost of multiplying two matrices of order m x n, p x q= mpq
				int cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if (cost < m[i][j])
				{
					m[i][j] = cost;
					// Each entry DP[i, j] = k shows where to split
					// so as to get min cost for A[i...j]
					DP[i][j] = k;
				}
			}
		}
	}

	// First matrix is A, next B and so on
	char name = 'A';
	printSolution(1, n - 1, n, (int*)DP, name);
	// Rightmost element on 1st row gives the cost
	// for multiplying matrices A[1...n-1] -> ans
	return m[1][n-1];
}

void printSolution(int i, int j, int n, int *DP, char& name)
{
	// Base Case - Single matrix left in segment
	if(i == j)
	{
		cout<<name++;
		return;
	}

	cout<<"(";
	// Recursively put brackets around subexpression
	// Subexpression - i to k (i.e. DP[i][j])
	int x = *((DP + i*n) + j);// Pointer issues DP[i][j] didnt work directly
	// Fix later - but *((DP + i*n) + j) = DP[i][j]
	printSolution(i, x, n, DP, name);
	// Recursively put brackets around subexpression
	// Subexpression - k+1(DP[i][j] + 1) to j
	printSolution(x + 1, j, n, DP, name);
	cout<<")";
}