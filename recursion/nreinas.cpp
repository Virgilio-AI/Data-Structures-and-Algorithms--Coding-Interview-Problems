#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int N = 13;
int reinas[N];
int soluciones[10005][10005];
bool solucion =true;
int sz=700,contsol;

bool valido(int i){
    bool v=true;
  for(int r=0;r<i;r++){
    v=v&&(reinas[i]!=reinas[r]);//comprobar si la fila esta vacia
    v=v&&((reinas[i]-i)!=(reinas[r]-r));//diagonal uno 
    v=v&&((reinas[i]+i) != (reinas[r]+r));
  }
  return v;
}

void ponerreina(int i){
    int k=0;//inicializamos el conteo de movimientos
  solucion=false;
  do{    
    reinas[i] = k;//copiamos la reina i en la fila k //reinas[0]=0;reinas[1]=1
    k++;//k=1
   // mostrartablero();    
    if(valido(i)){//      
      if(i<(N-1)){        
        ponerreina(i+1);
        //backtracking
        if(!solucion){
          reinas[i]=0;
        }       
      }else{
        //ya agregamos las reinas
        contsol++;
        for(int m=0;m<N;m++){
          soluciones[contsol][m]=reinas[m];
        }        
      }      
    }    
  }while((k<N));
}


void mostrarSoluciones(){
  for(int i=1;i<=contsol;i++){
    for(int j=0;j<N;j++){
      printf("%d|",soluciones[i][j]);
    }
    printf("\n");
  }
}
//=====================		MAIN 	===================================
int main(){
ponerreina(0);
  if(N>3){
    printf(" %d soluciones:\n",contsol);
  }else{
    printf("no existe combinacion de reinas");
  }
  mostrarSoluciones();
return 0;
}

