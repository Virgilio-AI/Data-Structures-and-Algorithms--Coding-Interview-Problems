#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void coutArr(int n,int arr[]){for(int i=0;i<n;i++){cout<<arr[i]<<",";}}
const int capacidad = 10;const int nobjetos = 8;
int ganancias[] = {1,4,2,5,9,2,4,1};int pesos[] = {4,3,2,1,3,2,1,5};
int mochila[nobjetos];int mochila_optima[nobjetos];
int peso(int mochila[]){
  int p =0;
  for(int i=0;i<nobjetos;i++)
    if(mochila[i]==1)
      p+= pesos[i];
  return p;
}
int ganancia(int mochila[]){
  int g =0;
  for(int i=0;i<nobjetos;i++)
    if(mochila[i]==1)
      g+= ganancias[i];
  return g;
}
void backtracking(int v){
  if(peso(mochila)>capacidad){
    return;
  }
  int len =sizeof(mochila)/sizeof(mochila[0]);
  if(v>=len){
    if(ganancia(mochila)>ganancia(mochila_optima))
        for(int i=0;i<nobjetos;i++)
           mochila_optima[i] = mochila[i];            
    return;
  }    
	for(int i=0;i<2;i++){
		mochila[v]=i;
		backtracking(v+1);  		
	}
  mochila[v]=-1;
}
int main(){

for(int i=0;i<nobjetos;i++){
	mochila[i]=-1;
	mochila_optima[i]=-1;
}
backtracking(0);
cout<<"solucion: ";cout<<"[";coutArr(nobjetos,mochila_optima);cout<<"]";cout<<"peso: ";cout<<peso(mochila_optima);cout<<"ganancia: ";cout<<ganancia(mochila_optima);cout<<"\n";
return 0;
}
