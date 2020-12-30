#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 09-07-20 14:11 --
using namespace std;			//{{ practica factorización }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
void primeFactorization(int temp);
//=====================		MAIN 	===================================
int main(){
int n;
cin>>n;
while(n--){
	int temp;cin>>temp;
	primeFactorization(temp);
}
return 0;
}
//======== FUNCIONES ========
void primeFactorization(int temp){
	int expo[100],primeNumbers[100],len=0;
	if(temp==1){
		len++;
		expo[len]=0;
		primeNumbers[len]=2;	
		return;	
	}
	int divisor=2;
	while(temp>1&&1ll*divisor*divisor<=temp){
		int expoCont=0;
		while(temp%divisor==0){
			temp/=divisor;
			expoCont++;
		}
		if(expoCont>1){
			len++;
			primeNumbers[len]=divisor;
			expo[len]=expoCont;
		}
		divisor++;
	}
	if(temp>1){
		len++;
		primeNumbers[len]=temp;
		expo[len]=1;		
	}
	cout<<"("<<primeNumbers[1]<<"^"<<expo[1]<<")";
	for(int i=2;i<=len;i++){
		cout<<"*("<<primeNumbers[i]<<"^"<<expo[i]<<")";	
	}
	cout<<"\n";
}
