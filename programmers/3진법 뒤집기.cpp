#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> st;
    while(n>0){
        st.push(n%3);
        n/=3;
    }
    int m=1;
    answer = st.top()*m;
    st.pop();
    while(!st.empty()){
        m*=3;
        answer += st.top()*m;
        st.pop();
    }
    return answer;
}
