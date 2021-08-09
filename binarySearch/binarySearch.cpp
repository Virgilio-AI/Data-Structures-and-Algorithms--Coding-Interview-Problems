
#include<bits/stdc++.h>			//== CREATED BY ROCKHIGHT == -- 21-07-20 14:56 --
using namespace std;			//{{ title }}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=10005;
int n,a[Nmax],target;
int bSearch(int a[],int n,int target){
	int left=1,right=n,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==target){
			return mid;
		}else if(a[mid]<target){
			left=mid+1;
		}else{
			right=mid-1;
		}
		return -1;
	}
}
//=====================		MAIN 	===================================
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	cin>>target;
	cout<<"\n"<<bSearch(a,n,target);

return 0;
}
//======== FUNCIONES ========
