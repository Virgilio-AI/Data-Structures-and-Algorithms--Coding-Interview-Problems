#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====

bool isSafe(int tablero[9][9],int fila, int columna,int num){
	for(int i=0;i<9;i++)
	{
		if(i!= fila && tablero[columna][i] == num || i!= columna && tablero[i][fila] == num ) return false;
	}
	int FilaCaja = fila - fila%3;
	int ColumnaCaja = columna - columna%3;
	for(int i=ColumnaCaja;i<= ColumnaCaja + 2;i++)
	{
		for(int j=FilaCaja;j<=FilaCaja + 2;j++)
		{
			if(i != columna && j!= fila && tablero[i][j] == num)
			{
				return false;
			}
		}
	}
	return true;
} 

bool solveSudoku(int tablero[9][9], int n){
	int fila = -1,columna =-1;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(tablero[i][j] == 0)
			{
				columna = i;
				fila = j;
				goto endo;
			}
		}
	}
endo:
	if(fila == -1 && columna == -1) return true;
	for(int i=1;i<=9;i++)
	{
		if(isSafe(tablero,fila,columna,i))
		{
			tablero[columna][fila] = i;
			if(solveSudoku(tablero,n))
			{
				return true;
			}
			else
			{
				tablero[columna][fila] = 0;
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

