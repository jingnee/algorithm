#include <iostream>
#include <stack>
#include<string>
using namespace std;

stack<char> st;
int solution(string s)
{
    for(auto a:s){
        if(st.empty() || a!=st.top())st.push(a);
        else st.pop();
    }

    if(st.empty())return 1;
    else return 0;
}
