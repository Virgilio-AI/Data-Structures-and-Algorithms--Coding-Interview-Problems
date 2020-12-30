#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 14-07-20 13:06 --
using namespace std;			//{{ frequency array }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
long long maxSumSubarray(int a[],int n){
long long sum=0,ans=a[1];
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>ans)
			ans=sum;
		if(sum<0)
			sum=0;
		}
return ans;
}
//=====================		MAIN 	===================================
int main(){
int n;cin>>n;
int a[n];
for(int i=1;i<=n;i++){int temp;cin>>temp;a[i]=temp;}
for(int i=1;i<=n;i++){cout<<a[i]<<" ";}
cout<<"\n"<<maxSumSubarray(a,n);
return 0;
}
//======== FUNCIONES ========
