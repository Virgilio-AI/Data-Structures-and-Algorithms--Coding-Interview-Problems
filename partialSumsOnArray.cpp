#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 13-07-20 14:44 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
void buildPartialSumsSubArray(int a[],int *s,int n);
long long query(int x,int y,int s[]);
//=====================		MAIN 	===================================
int main(){
int n;cin>>n;
int a[n+1],s[n+1];
a[0]=0;
for(int i=1;i<=n;i++){
	int temp;cin>>temp;
	a[i]=temp;
}
buildPartialSumsSubArray(a,s,n);
int k;cin>>k;
while(k--){
	int UpLimit,LoLimit;
	cin>>UpLimit;cin>>LoLimit;
	cout<<query(UpLimit,LoLimit,s)<<"\n";
}
return 0;
}
//======== FUNCIONES ========
void buildPartialSumsSubArray(int a[],int *s,int n){
	s[0]=0;s[1]=a[1];
	for(int i=0;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
}
long long query(int x,int y,int s[]){
	return s[y]-s[x-1];
}
