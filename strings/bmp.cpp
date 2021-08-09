#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arr[Nmax];

vector<int> busquedambp(string  texto,string  patron){//x=2,o=1
  vector<int> lista;
  //paso 1
  int frec[255]={-1};
   
for(int i=patron.length();i>=1;i--){
  if(i-1==0){
    break;
  }
   frec[(int)patron[patron.length()-i]]=i-1; 
}
  //parte 2
  
for(int i=patron.length();i<texto.length();i++){
  if(texto.substr(i-patron.length(),i)==patron){
    lista.push_back(i-patron.length());
  }

if(i+frec[(int)texto[i]]<texto.length()){
  i+=frec[(int)texto[i]];
}
}
  if(texto.substr(texto.length()-patron.length(),texto.length())==patron){
    lista.push_back(texto.length()-patron.length());
  }
	cout<<"\n";
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
  cout<<"B�squeda mbp: ";
  vector<int> resultado = busquedambp(texto,patron);
  cout<<"[";int cont=0;  
  for(int i:resultado){
  	cout<<(cont==0?"":",");
  	cout<<i;  	cont++;
  }
  cout<<"]";
return 0;
}
