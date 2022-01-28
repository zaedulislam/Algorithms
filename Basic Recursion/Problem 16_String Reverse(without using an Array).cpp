/*
Problem 16_String Reverse(without using an Array).cpp
Read a string from keyboard and print it in reversed order. You must not use any array to store the characters.
Write a recursive solutions to solve this problem.
*/

#include <bits/stdc++.h>
using namespace std;




void PrintReverseOrder()
{
	char ch;
	scanf("%c", &ch);

	if(ch == '\n')
		return;

	PrintReverseOrder();
	printf("%c", ch);

}



int main()
{

	PrintReverseOrder();
	printf("\n");

	return 0;
}


/*
Input:
helloo
john

Output:
oolleh
nhoj
*/