#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=1000006;
int n,arr[Nmax];

void quick_sortR(int arreglo[],int inicio,int fin){
  if( inicio>=fin) return;
  if( inicio+1 == fin){
    if(arreglo[inicio]>arreglo[fin]) swap(arreglo[inicio],arreglo[fin]);
    return;
  }
  int p = inicio;
  int i = inicio+1;
  int d = fin;
  while( i<d ){
    while( i<d && arreglo[i] <= arreglo[p] ) i++;
    while( i<d && arreglo[d] > arreglo[p] ) d--;
    if( i<d ){
       swap(arreglo[i],arreglo[d]);
    }
  }
  if(arreglo[p]<=arreglo[i]){
    swap(arreglo[p],arreglo[i-1]);
    p = i-1;
  }else{
    swap(arreglo[p],arreglo[i]);
    p = i;
  }
  quick_sortR(arreglo,inicio,p-1);
  quick_sortR(arreglo,p+1,fin);
}
void quickSort(){
	quick_sortR(arr,1,n);
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
cin>>n;
cinArr(n,arr);
quickSort();
coutArr(n,arr);
return 0;
}

