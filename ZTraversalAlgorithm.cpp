#include<bits/stdc++.h> 
using namespace std;
int x,y,power=8;
/*
 * problem statement:
 * given an array such that is made by the z traversal of it
 * 1  2  5  6 ...
 * 3  4  7  8 ...
 * 9  10 13 14 ...
 * 11 12 15 16 ...
 * .   .  .  .  
 * .   .  .  .  .
 * .   .  .  .    .
 * of max width n of 50'000 and max height m of 50'000 
 * create a program such that given a coordinate in the array gives the value of it
 * it has to be in log complexity
 * examples:
 * in:
 * 2 2 
 * out:
 * 4
 *
 * in:
 * 3 4
 * out:
 * 13
 */





//explanation
//given the fact that is a z traversal we can do a divide and conquer aproach
//for example if you imagina that the matrix is just a 2*2 then you know you can compute the answer without having to 
//iterate throw the four elements
//if you are given 1 1 you return 1 since is the base of the recursion
//if you are given 1 2 you just have to add 1 and add the computed answer recursively so you will have 2 again
//if you are given 2 1 you do the same procedure than before but with the difference that you add 2
//if you are given 2 2 you do the same procedure than before but with the difference that you add 3

long long ZTraversal(int power,int x,int y)
{
	if(power == 0 ) return 1;
	if(x<=pow(2,power-1))
	{
		if(y<=pow(2,power-1))
		{
			return ZTraversal(power-1,x,y);
		}
		return 2*pow(4,power-1) + ZTraversal(power-1,x,y-pow(2,power-1));
	}
	if(y<=pow(2,power-1))
	{
		return pow(4,power-1) + ZTraversal(power-1,x-pow(2,power-1),y);
	}
	return 3*pow(4,power-1) + ZTraversal(power-1,x-pow(2,power-1),y-pow(2,power-1));
}

int main()
{
	cin>>x>>y;
	cout<<ZTraversal(power,x,y)<<endl;
	return 0;
}

