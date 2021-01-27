#include<bits/stdc++.h>
using namespace std;
/*
 * problem statement:
 * make a program that given a string of parenthesis '(' and ')' returns if the string is valid.
 * a string is valid if matematicly is valid, for example
 * ()() is valid, (()()()) is valid but )( is not valid
 * it is guaranteed that there is only going to be two chars '(' and ')'
 *
 * test cases:
 * 
 * in:
 * ()(())
 * out:
 * valid
 *
 * in:
 * )(
 * out:
 * not valid
 */

//the function works using an integer as an stack,so instead of pushing to the stack we add 1
//and instead of popping from the stack we substract 1 
//now the function is very easy, if we find a '(' we add to the stack
//if we find a ')' we push from the stack
//if we find a ')' and the stack is empty it means is not valid 
//if it iterates the whole string the we know that is true

bool ValidParenthesis(string str)
{
	int st=0;
	for(int i=0;i<(int)str.length();i++)
	{
		if(str[i] == '(') st++;
		else 
		{
			if(st==0) return false;
			else st++;
		}
	}
	return true;
}

int main()
{
	string str;
	cin>>str;
	if(ValidParenthesis(str))
	{
		cout<<"valid"<<endl;
	}
	else
	{
		cout<<"not valid"<<endl;
	}
}

