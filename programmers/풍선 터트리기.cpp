#include <vector>

using namespace std;

int solution(vector<int> a) {
   int answer = 2;
    int l=a[0];
    int r=a[a.size()-1];
    
    for(int i=1;i<a.size()-1;i++){
        if(a[i] < l){
            l=a[i];
            answer++;
        }
        if(a[a.size()-i-1] < r){
            r=a[a.size()-i-1];
            answer++;
        }
    }
    return l==r?answer-1:answer;
}
