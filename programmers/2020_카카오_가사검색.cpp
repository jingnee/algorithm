#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Trie{
private:
    Trie* node[26];
    bool finish;
    int cnt;
public:
    Trie(): finish(false), cnt(1){
        memset(node,0,sizeof(node));
    }
    
    ~Trie(){
        for(int i=0;i<26;i++){
            if(node[i])delete(node[i]);
        }
    }
    void insert(string word){
        Trie *trie = this;
        for(auto w:word){
            int idx= w-'a';
            if(!trie->node[idx]) 
                trie->node[idx]= new Trie();
           else 
               trie->node[idx]->cnt++;
            
            trie = trie->node[idx];
        }
       trie->finish = true;
    }
    
    int find(string word){
        Trie *trie = this;
        for(auto w : word){
            int idx= w-'a';
            if(w=='?')
                return trie->cnt;
            if(!trie->node[idx])return 0;
            trie = trie->node[idx];   
        }
        //word의 길이와 똑같은 트라이 배열을 탐색했기때문에 마지막까지 탐색한경우 하나는 존재하는거 하지만 ?가 없는 경우는 없기때문에 여기는 안들어올듯
        return 1;
    }
};

Trie *root[10001];
Trie *re_root[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<int> wildcard(100001,0);
    
    //words들 모두 트라이에 담기
    for(auto word : words){
        int ssize = word.size();
        if(!root[ssize])root[ssize]=new Trie();
        root[ssize]->insert(word);
        
        reverse(word.begin(),word.end());
        if(!re_root[ssize])re_root[ssize]=new Trie();
        re_root[ssize]->insert(word);
        
        wildcard[ssize]++;
    }
    
    
    for(auto query : queries){
        int size = query.size();
        int num = 0;
        //모든문자 ?인경우
        if(query[0]=='?' && query[size-1]=='?'){
            num = wildcard[size];
         }
        else if(query[0]=='?'){
            reverse(query.begin(),query.end());
            if(!re_root[size])num=0;
            else num = re_root[size]->find(query);            
        }
        else{
            if(!root[size])num=0;
            else num = root[size]->find(query);       
        }
        answer.push_back(num);
    }
    
    return answer;
}
