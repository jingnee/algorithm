#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int len = A.size();
    for(int i=0;i<len;i++){
        answer += A[i]*B[len-i-1];
    }

    return answer;
}
