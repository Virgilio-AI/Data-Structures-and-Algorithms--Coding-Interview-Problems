#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int dp[N][N];
char Str1[N],Str2[N];


//declaracion de funciones
int LengthOfString(char str[N]);

void MinEditDistance()
{
	int Str1_Len = LengthOfString(Str1),Str2_Len = LengthOfString(Str2);
	for(int i=0;i<=;i++)
	{
		for(int j=0;j<=
}
int LengthOfString(char str[N])
{
	int cont = 0 ;
	for(int i=0;i<N;i++)
	{
		if((int)str[i] <32 || (int)str[i] > 126) break;
		cont++;
	}
	return cont;
}

			
int main()
{
	scanf("%[^\n]",Str1);
	getchar();
	scanf("%[^\n]",Str2);
	getchar();
	MinEditDistance();
	
	return 0;
}
