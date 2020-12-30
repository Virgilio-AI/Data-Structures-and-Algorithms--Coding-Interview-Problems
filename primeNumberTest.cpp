//====================== CREATED BY ROCKHIGHT ==========================
//---------------------- 07-07-20 16:56 -----------------------------
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{PRIME NUMBER TEST}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#include<bits/stdc++.h>
using namespace std;
//===================== VARIABLES GLOBALES =============================

//===================== PROTOTIPOS DE FUNCIONES ========================
bool primeNumberTest(int n);
//=====================		MAIN 	===================================
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main(){
int number;
cout<<"ingrese el numero para checar si es un numero primo o es un número no primo\n";
cin>>number;
if(primeNumberTest(number)==true){
	cout<<"es un numero primo";
}else{
	cout<<"no es un numero primo";
}

return 0;
}
//==================== FUNCIONES =======================================
bool primeNumberTest(int n){
	if(n<=1){
		return false;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
