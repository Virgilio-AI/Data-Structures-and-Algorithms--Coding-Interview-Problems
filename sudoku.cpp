#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====

bool isSafe(int tablero[9][9],int fila, int columna,int num){ 
    //checando las filas y las columnas
    for (int d = 0; d < 9; d++){ 
        if (tablero[fila][d] == num)  { 
            return false; 
        } 
    }  
    for (int r = 0; r < 9; r++) { 
        if (tablero[r][columna] == num) { 
            return false; 
        } 
    }
    //checando los cuadrados
    
    int root = (int) sqrt(9); 
    int iniciofilacaja = fila - fila % root; // iniciofilacaja = 0 
    int iniciocolumnacaja = columna - columna % root;//iniciocolumnacaja = 
    //(0,3)
  
    for (int r = iniciofilacaja; r < iniciofilacaja + root; r++){ 
        for (int d = iniciocolumnacaja; d < iniciocolumnacaja + root; d++)  { 
            if (tablero[r][d] == num)  { 
                return false; 
            } 
        } 
    } 
    return true; 
} 

bool solveSudoku(int tablero[9][9], int n){ 
    int fila = -1; 
    int col = -1; 
    bool vacio = true; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++)  { 
            if (tablero[i][j] == 0)  { 
                fila = i; 
                col = j;                
                vacio = false;  
                break; 
            } 
        } 
        if (!vacio) { 
            break; 
        }
        
    }     
    if(vacio){ 
        return true; 
    }
    
    for(int num = 1; num <= n; num++){ 
        if(isSafe(tablero, fila, col, num)) { 
            tablero[fila][col] = num;
           // imprimirconsola(tablero,tablero.length);
            if (solveSudoku(tablero, n))  { 
                // print(board, n); 
                return true; 
            }  
            else{ 
                tablero[fila][col] = 0; // replace it 
            } 
        } 
    } 
    return false; 
}


void imprimirconsola(int board[9][9],int N){
    
    for (int r = 0; r < N; r++) { 
        for (int d = 0; d < N; d++) { 
            printf("%d ",board[r][d]);            
        } 
        printf("\n");
          
        if ((r + 1) % (int) sqrt(N) == 0)  { 
            printf("");
        } 
    } 
    printf("\n");
} 
//=====================		MAIN 	===================================
int main(){
	const int N =9;
int board[N][N] = 
    { 
            {9, 6, 0, 1, 0, 4, 0, 5, 8}, 
            {0, 7, 8, 3, 2, 5, 6, 0, 9}, 
            {2, 5, 0, 6, 0, 0, 7, 0, 1},
            {8, 0, 1, 4, 0, 7, 5, 0, 6}, 
            {0, 9, 6, 0, 0, 2, 3, 0, 7}, 
            {7, 0, 5, 9, 6, 1, 0, 2, 4},
            {5, 0, 0, 7, 1, 0, 4, 6, 2}, 
            {3, 1, 7, 2, 0, 6, 9, 0, 0}, 
            {0, 4, 0, 5, 0, 8, 0, 7, 3} 
    };   
    if (solveSudoku(board, N)) { 
        //print(board, N); // print solution 
      //  mostrarsolucion();
      imprimirconsola(board,N);
    }  
    else{ 
        cout<<"no solution\n";
    } 
return 0;
}

