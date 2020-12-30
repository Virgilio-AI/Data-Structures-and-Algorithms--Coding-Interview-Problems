#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 29-07-20 10:00 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES ===== funciones =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arreglo[Nmax];

void heap_sort() {
  // Insercion
  for (int i=2; i<=n; i++) {
    int h = i;
    while ( h>1 && arreglo[h] > arreglo[h/2]) {
      swap(arreglo[h],arreglo[h/2]); //swap(arreglo, h, h/2);
      h = h/2;
    }
  }
  // Eliminacion
  for (int i=n; i>0; i--) {
   swap(arreglo[1],arreglo[i]);// swap(arreglo, 1, i);
    int p = 1;
    // el hijo 1 está dentro del heap y es más grande que el papá
    while ( (p*2<i && arreglo[p*2]>arreglo[p])||(p*2+1<i && arreglo[p*2+1]>arreglo[p])  ) {
      if ( (p*2<i && p*2+1<i && arreglo[p*2]>=arreglo[p*2+1])  || (p*2+1>=i)) {
        swap(arreglo[p],arreglo[p*2]);
        p = p*2;
      } else {
        swap(arreglo[p],arreglo[p*2+1]);//swap(arreglo, p, p*2+1);
        p = p*2+1;
      }
    }
  }
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
srand(time(NULL));
n=5;
arreglo[0]=0;
for(int i=1;i<=n;i++){
	arreglo[i]=rand()%51;
}
coutArr(n,arreglo);cout<<"\n";
heap_sort();
coutArr(n,arreglo);
return 0;
}


