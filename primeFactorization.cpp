//====================== CREATED BY ROCKHIGHT ==========================//---------------------- 08-07-20 13:21 -----------------------------//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{problema 2 algoritmos para competicion}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#include<bits/stdc++.h>
using namespace std;
//===================== VARIABLES GLOBALES =============================//===================== PROTOTIPOS DE FUNCIONES ========================
void factorization(int num);
//=====================		MAIN 	===================================//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main(){
int n;cin>>n;
for(int i=0;i<n;i++){	int numTemp;	cin>>numTemp;	factorization(numTemp);	}
return 0;
}//==================== FUNCIONES =======================================
void factorization(int num){
int expo[100],primo[100],len=0;
if(num==1){
	len++;
	primo[len]=2;
	expo[len]=0;
	return;
}
	int d=2;
	while(1ll*d*d<=num&&num>1){
		int k=0;
		while(num%d==0){
			num/=d;
			k++;
		}
		if(k>0){
			len++;
			primo[len]=d;
			expo[len]=k;
		}
		d++;
	}
	if(num>1){
		len++;
		primo[len]=num;
		expo[len]=1;
	}
		cout<<"("<<primo[1]<<"^"<<expo[1]<<")";
	for(int i=2;i<=len;i++){
		cout<<"*("<<primo[i]<<"^"<<expo[i]<<")";
	}
	cout<<"\n";
}
