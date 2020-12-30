#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arreglo[Nmax];
void merge_sortR(int aux[],int inicio,int fin){
  if( inicio>=fin) return;
  if( inicio+1 == fin){
    if(arreglo[inicio]>arreglo[fin]) swap(arreglo[inicio],arreglo[fin]);//swap(arreglo,inicio,fin);
    return;
  }
  int m = (fin+inicio)/2;
  merge_sortR(aux,inicio,m);
  merge_sortR(aux,m+1,fin);
  int i = inicio; //lista 1
  int j = m+1;    //lista 2
  for(int k=inicio;k<=fin;k++){
    if( (i<=m && j<=fin && arreglo[i] <= arreglo[j]) || j>fin ){
        aux[k] = arreglo[i++];
    }else{
        aux[k] = arreglo[j++];
    }
  }
  for(int k=inicio;k<=fin;k++){
    arreglo[k] = aux[k];
  }  
}

void merge_sort(){
	int aux[n+1];
	merge_sortR(aux,0,n);
}

//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
srand(time(NULL));
n=5;
for(int i=1;i<=n;i++){
	arreglo[i]=50+rand()%51;
}
coutArr(n,arreglo);cout<<"\n";
merge_sort();
coutArr(n,arreglo);
return 0;
}

