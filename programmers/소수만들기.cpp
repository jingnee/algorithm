#include <vector>
#include <iostream>
using namespace std;
int prime[3000];
int solution(vector<int> nums) {
    int answer = 0;
    int num = 0;
    prime[0]=prime[1]=1;
    //소수배열. 소수면0, 소수가 아니면 1
    for(int i=2;i<3000;i++){
        if(prime[i]==1)continue;
        for(int j=i+i;j<3000;j+=i)
            prime[j]=1;
    }
    
    for(int i=0;i<nums.size()-2;i++){
        num+=nums[i];
        for(int j=i+1;j<nums.size()-1;j++){
            num+=nums[j];
            for(int k=j+1;k<nums.size();k++){
                num+=nums[k];
                if(prime[num]==0){
                 answer++;
                }
                num-=nums[k];
            }num-=nums[j];
        }num-=nums[i];
    }

    return answer;
}
