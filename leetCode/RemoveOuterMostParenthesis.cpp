#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans="";
        int st=0;
        for(auto a:S)
        {
            if(a=='(')
            {
                st++;
                if(st!=1)
                {
                    ans+=a;
                }
            }                        
            else
            {
                st--;
                if(st!=0)
                {
                    ans+=a;
                }
            }                                                            
        }
        return ans;
    }
};			
			
int main()
{    
    string str;
    int Int;
    float ft;
    vector<int> vi;
    
    Solution sol;    
    cin>>str;
    cout<<sol.removeOuterParentheses(str)<<endl;

    return 0;
}