#include <string>
#include <stack>
#include <algorithm>

using namespace std;

stack<char> st;
string solution(string number, int k) {
    st.push(number[0]);
    string answer = "";
    for(int i=1; i<number.size();i++){
while(!st.empty() && k>0 && st.top()<number[i]){
st.pop();
    k--;
}
        st.push(number[i]);
}
    string str="";
    while(!st.empty()){
str+=st.top();
        st.pop();
}
    reverse(str.begin(),str.end());
    answer=str.substr(0,number.size()-k);
    return answer;
}
