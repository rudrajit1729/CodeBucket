// CPP program to reverse the number
// using a stack
#include <bits/stdc++.h>
using namespace std;
// Stack to maintain order of digits
stack <int> st;
// Function to push digits into stack
void push_digits(int number)
{
while (number != 0)
{
st.push(number % 10);
number = number / 10;
}
}
// Function to reverse the number
int reverse_number(int number)
{
// Function call to push number's
// digits to stack
push_digits(number);
int reverse = 0;
int i = 1;
// Popping the digits and forming
// the reversed number
while (!st.empty())
{
reverse = reverse + (st.top() * i);
st.pop();
i = i * 10;
}
// Return the reversed number formed
return reverse;
}
// Driver program to test above function
int main()
{
int number = 39997;
// Function call to reverse number
cout << reverse_number(number);
return 0;
}