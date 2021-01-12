#include<bits/stdc++.h>
using namespace std;
//paste code 
/*
statement:
You are given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        for(auto a:s)
        {
            //if you find a ')' reverse all leters untill you find a 
            // '('             
            if(a == ')')
            {
                string str;                
                while(st.top() != '(')
                {
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto ch : str)
                {
                    st.push(ch);
                }                
            }
            else
            {
                    st.push(a);                       
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    //variables
    string str;
    int Int;
    float ft;
    vector<int> vi;
    
    Solution sol;
    cin>>str;
    cout<<sol.reverseParentheses(str);
    //cin variable

    //cout solution    
    return 0;
}