#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arr[Nmax];

vector<int> busqueda_kmp(string texto, string patron) {
  vector<int> lista;
  //primera parte
  int pat_len=patron.length(),text_len=texto.length();
  int regreso[pat_len];
  int estado;
  regreso[0] = -1;
  for (int i=1; i<pat_len; i++) {
    estado = regreso[i-1]+1;
    while (patron[i]!=patron[estado]) {
      if (estado == 0) {
        estado=-1;
        break;
      }
      estado = regreso[estado-1]+1;
    }
    regreso[i] = estado;
  }
  //segunda parte
  int contador=-1;
  for (int i=0; i<text_len; i++) {   
   contador = contador+1;
    while (texto[i]!=patron[contador]) {     
      if (contador == 0) {
        contador=-1;
        break;
      }      
      contador = regreso[contador-1]+1;
    }  
    if (contador==patron.length()-1) {
      lista.push_back(i-pat_len+1);
    }
  }
  return lista;
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);

  string texto = "XOXXOOXXOXXXOXOOXOXOXOXXO";
  string patron = "XOXOXXO";

  transform(texto.begin(),texto.end(),texto.begin(),::tolower);
  transform(patron.begin(),patron.end(),patron.begin(),::tolower);
  cout<<"texto: "<<texto;cout<<"\n";
  cout<<"patron: "<<patron;cout<<"\n";
  cout<<"Búsqueda kmp: ";
  vector<int> resultado = busqueda_kmp(texto,patron);
  cout<<"[";int cont=0;  
  for(int i:resultado){
  	cout<<(cont==0?"":",");
  	cout<<i;  	cont++;
  }
  cout<<"]";
	        	       
return 0;
}

