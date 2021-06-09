#include<bits/stdc++.h>
using namespace std;
const int Nmax=100000007;
int n,m,x,y,z,w,arr[Nmax];
/*
 * problem statement:
 * given a string and a substring, where is the current substring in the string.
 * use the kmp algorithm to find it faster, since iterating throw all comparisons is very naive
 * if the substring is found two times in the current string, for example int the string 
 * "xoxoxox" and the sub string "xox", "xox" is found int pos i=0 but also found in the 
 * position i=2 but since we are using the last x from the presvios ocurrance we don't count it
 */

vector<int> KMP_stringPatternSearching(string text, string pattern) {
	vector<int> instances;

	int pat_len = pattern.length(), txt_len = text.length();
	int state;
	int recurrence[pat_len];
	recurrence[0]=-1;
	//first fill the recurrence integer array and then 
	//just by making the pattern you can save time
	for(int i=1;i<pat_len;i++)
	{
		state = recurrence[i-1] + 1;
		while(pattern[state] != pattern[i])
		{
			if(state==0)
			{
				state=-1;
				break;
			}
			state = recurrence[state-1]+1;
		}
		recurrence[i] = state;
	}
	//after created the pattern, in the default case recurrence[] = {-1,-1,0,1,2,0,1};
	//you now have to iterate the text to find the place where is found the current pattern
	//you initialize a counter to -1 to see if you already completed the full size of the pattern
	//and the magic comes when you dont have to compare your hole string in n^2 but you can do it in constant time
	int counter =-1;
	for(int i=0;i<txt_len;i++)
	{
		counter++;
		while(text[i] != pattern[counter])
		{
			if(counter==0)
			{
				counter=-1;
				break;
			}
			counter = recurrence[counter-1]+1;
		}
		if(counter==pat_len-1)
		{
			instances.push_back(i-counter);
			counter = recurrence[counter];
		}
	}
	return instances;
}
//=====================		MAIN 	===================================
int main(){
ios::sync_with_stdio(0);

  string text = "abcabcabcabc";
  string pattern = "abcabc";
  //change current text to lower characters
  transform(text.begin(),text.end(),text.begin(),::tolower);
  //change current pattern to lower characters
  transform(pattern.begin(),pattern.end(),pattern.begin(),::tolower);

  cout<<"text: "<<text;cout<<"\n";
  cout<<"pattern: "<<pattern;cout<<"\n";
  cout<<"Busqueda kmp: ";
  vector<int> answer = KMP_stringPatternSearching(text,pattern);
  //print result
  cout<<"[";
  int counter=0;  
  for(int i:answer){
  	cout<<(counter==0?"":",");
  	cout<<i;  	counter++;
  }
  cout<<"]";
	        	       
return 0;
}


