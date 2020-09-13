#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    if(cookie.size()==1)return 0;
    
    for(int m=0;m<cookie.size()-1;m++){
        int l=m;
        int r=m+1;
        int brother1 = cookie[l];
        int brother2 = cookie[r];
        
        if(brother1==brother2)
        answer=max(answer,brother1);
   
        while(1){

            if(l>0 && brother2>brother1)
                brother1+=cookie[--l];
            else if(r<cookie.size()-1 && brother2 < brother1)
                brother2+=cookie[++r];
            else break;
            
           if(brother1==brother2){
                answer=max(answer,brother1);
            }
        }
    }
    return answer;
}
