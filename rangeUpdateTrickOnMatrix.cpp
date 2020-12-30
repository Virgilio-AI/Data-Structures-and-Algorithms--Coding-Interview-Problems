#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 20-07-20 15:44 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=10007;
int b[Nmax][Nmax]={0},a[Nmax][Nmax]={0},s[Nmax][Nmax]={0},cols,rows,updts;

void update(int x1,int y1,int x2,int y2,int val){
	b[x1][y1]+=val;
	b[x1][y2+1]-=val;
	b[x2+1][y1]-=val;
	b[x2+1][y2+1]+=val;
}

void createSumMatrix(){
	for(int i=1;i<=cols;i++){
		for(int j=1;j<=rows;j++){
			s[i][j]=s[i][j-1]+s[i-1][j]+b[i][j]-s[i-1][j-1];
		}
	}
}
void inputMatrix(){
	for(int i=1;i<=cols;i++){
		for(int j=1;j<=rows;j++){
			cin>>a[i][j];
		}
	}
	return;
}
void updateMatrix(){
	for(int i=1;i<=cols;i++){
		for(int j=1;j<=rows;j++){
			a[i][j]+=s[i][j];
		}
	}
}
void printMatrix(int arr[][Nmax]){
	for(int i=1;i<=cols;i++){
		for(int j=1;j<=rows;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
//=====================		MAIN 	===================================
int main(){
cin>>cols;cin>>rows;
inputMatrix();
cin>>updts;
while(updts--){
	int x1,x2,y1,y2,val;
	cin>>x1>>y1>>x2>>y2>>val;
	update(x1,y1,x2,y2,val);
}
createSumMatrix();	
updateMatrix();
printMatrix(a);
return 0;
}
//======== FUNCIONES ========
