#include<bits/stdc++.h>			//== CREATED BY Virgilio-AI 
using namespace std;			//{{ quick sort algorithm }}
/*
statement
create a program that recieves the number n and recieves an array of n numbers separated by a space.
then sort the array in ascendent order using Quick Sort
*/
// function to input an array
void cinArr(int n,int arr[])
{
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
  }
}
//function to output an array
void coutArr(int n,int arr[])
{
  for(int i=1;i<=n;i++)
  {
    cout<<arr[i]<<" ";
    }
}
//===== VARIABLES GLOBALES === -> === PROTOTIPOS DE FUNCIONES =====
const int Nmax=1000006;
int n,arr[Nmax];
//main quick sort function
void quick_SortR(int array[],int beggining,int end){
  //check if the beggining is bigger than the end
  //is >= because you actually can run into a beggining bigger than the 
  //end, for example if you arrive to line 47 and you have the three numbers 1 2 3
  //hence the pivot at 1 and left,right in 3,2 respectively
  //pivote will be still pointing to 1 respectively and in line 58 you would pass something like 
  // quick_Sort(array,1,-1)
  if(beggining >= end) return;
  //the limit case for the recursion
  if(beggining == end-1)
  {
    if(array[beggining] > array[end])
    {
      swap(array[beggining],array[end]);
    }
  }  
  int left = beggining+1,right = end,pivote = beggining;
  //just apply algorithm, swap the numbers in the positions of the pointers of left and right 
  //untill they are in the same place and hence the pivot is less than the elements on the right of the center
  //and bigger or equal to the elements on the left of the center
  while(left<right)
  {
    while(left<right && array[pivote] >= array[left]) left++;
    while(left < right && array[pivote] < array[right]) right--;
    if(left < right) 
    {
      swap(array[left],array[right]);
    }
  }
  // if the center is the greater or equal to the pivote, the pivote will pass to be less than left 
  // to have all greater or equal elements on the right and all lesser elements on the left
  if(array[pivote] <= array[left])
  {
    swap(array[pivote],array[left-1]);
    pivote = left-1;    
  }
  else
  {
    swap(array[pivote],array[left]);
    pivote = left;
  }
  quick_SortR(array,beggining,pivote-1);
  quick_SortR(array,pivote+1,end);    
}
void quickSort(){
	quick_SortR(arr,1,n);
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);
cin>>n;
cinArr(n,arr);
quickSort();
coutArr(n,arr);
return 0;
}

