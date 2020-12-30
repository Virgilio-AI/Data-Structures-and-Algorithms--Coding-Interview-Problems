#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 27-07-20 12:42 --
using namespace std;			//{{ title }}
void cinArr(int n,int arr[]){for(int i=1;i<=n;i++){cin>>arr[i];}}
void coutArr(int n,int arr[]){for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=100000007;const double pi = 2*acos(0.0);
int n,m,x,y,z,w,arr[Nmax];

int editDist(string str1, string str2, int m, int n)
{
    if(m==0)
    {
        return n;
    }
    if(n==0)
    {
        return m;
    }
    if(str1[m-1]==str2[n-1])
    {
        return editDist(str1,str2,m-1,n-1);
    }
    return 1+min(editDist(str1,str2,m-1,n-1),min(editDist(str1,str2,m-1,n),editDist(str1,str2,m,n-1)));
}

//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);

		string str1 = "estudiante"; 
        string str2 = "escuela";           
        
        cout<<editDist(str1, str2, str1.length(),str2.length())<<endl;
return 0;
}

