#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 09-07-20 15:13 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
void sieveOfErathosthenes(int limit);

const int Nmax=100001;
bool isPrime[Nmax];
 
//=====================		MAIN 	===================================
int main(){
	int n;cin>>n;
	sieveOfErathosthenes(n);
	for(int i=0;i<=n;i++)
		if(isPrime[i]==true)
			cout<<i<<" ";			
return 0;
}
//======== FUNCIONES ========
void sieveOfErathosthenes(int n){
	for(int i=2;i<=n;i++)
		isPrime[i]=true;
	for(int i=2;i<=n/2;i++)
		if(isPrime[i]==true)
			for(int j=i*2;j<=n;j+=i)
				isPrime[j]=false;	
}
