#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 29-07-20 10:00 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES ===== funciones =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arreglo[Nmax];

void heap_sort() {
  //insercion
  for(int i=2;i<=n;i++)
  {
    int h=i;
    while( h>1 && arreglo[h] > arreglo[h/2])
    {
      swap(arreglo[h],arreglo[h/2]);
      h = h/2;      
    }
  }
  //eliminacion
  for(int i=n;i>0;i--)
  {
    int p=1;
    swap(arreglo[p],arreglo[i]);
    //while one of the childs is bigger than the father 
    while(p*2 < i && arreglo[p]<arreglo[p*2] || p*2+1 < i && arreglo[p]<arreglo[p*2+1] )
    {
      //if the right child is of the margins or if bouth the left and the right childs are inside 
      //of the margins and the left child is bigger than the right child
      if(p*2+1 >=i || p*2+1<i && p*2 < i && arreglo[p*2+1]<arreglo[p*2])
      {
        swap(arreglo[p],arreglo[p*2]);
        p = p*2;
      }
      //if the two childs are on the margins and 
      //the right child is less than the left child
      else
      {
        swap(arreglo[p],arreglo[p*2+1]);
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


