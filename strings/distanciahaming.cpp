#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arr[Nmax];

int distancia_hamming(string s1,string s2){	
  int tamano_minimo = min(s1.length(),s2.length());  
  int dist = 0;
  for(int i=0;i<tamano_minimo;i++){
    if(s1[i] != s2[i] )
       dist++;
  }
  int a = s1.length()-s2.length();
  int diferencia_cadenas = abs(a);
  dist = dist + diferencia_cadenas;
  return dist;
}

//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
string str1 = "escuela";
string str2 = "estudiante";

cout<<distancia_hamming(str1,str2);
return 0;
}

