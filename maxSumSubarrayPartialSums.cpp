#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 14-07-20 14:26 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=10001;
long long maxSumSubarray(int a[],int n){
	if(n==0)
		return 0;
	long long s[Nmax],ans=a[1],minS=0;
	s[1]=a[1];
	for(int i=2;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(s[i]-minS>ans)
			ans=s[i]-minS;
		if(s[i]<minS)
			minS=s[i];
	}
	return ans;
}
//=====================		MAIN 	===================================
int main(){
int n,a[Nmax];
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];	
}
cout<<maxSumSubarray(a,n);
return 0;
}
//======== FUNCIONES ========
