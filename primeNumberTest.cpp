#include<bits/stdc++.h>
using namespace std;
/*
 * problem statement:
 * create a program that checks if a number is prime or not
*/
 
bool PrimeNumberTest(int Number)
{
	//check if is divisible by 2
	if(Number%2 == 0 ) return false;
	//cut the complexity in four by only iterating throw numbers in the form 2*k + 1 so that 
	//all numbers divisible by 2 are ignored, since we already checked divisivility by 2
	//and then omiting all numbers bigger than sqrt(Number) because they cant be a factor of it 
	for(int i=1;(2*i +1)*(2*i+1)<=Number;i++)
	{
		if(Number%(2*i+1) == 0) return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	if(PrimeNumberTest(n))
	{
		cout<<"primo"<<endl;
	}
	else
	{
		cout<<"no primo"<<endl;
	}
	

	return 0;
}

