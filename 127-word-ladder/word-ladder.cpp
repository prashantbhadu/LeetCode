class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        for(int j=0;j<wordList.size();j++){
            
                string s=beginWord,t=wordList[j];
                int count=0;
                for(int k=0;k<s.size();k++){
                    if(s[k]!=t[k]) count++;
                }
                if(count==1){
                    adj[beginWord].push_back(wordList[j]);
                    adj[wordList[j]].push_back(beginWord);
                }
            }
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                string s=wordList[i],t=wordList[j];
                int count=0;
                for(int k=0;k<s.size();k++){
                    if(s[k]!=t[k]) count++;
                }
                if(count==1){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(adj.find(endWord)==adj.end()) return 0;
        int count=1;
        queue<string>q;
        unordered_map<string, int> visited;
        q.push(beginWord);
        visited[beginWord]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string str=q.front();
                q.pop();
                for(auto it:adj[str]){
                    if(visited[it]!=1){
                        q.push(it);
                        visited[it]=1;
                        if(it==endWord) return count+1;
                    }
                }
            }
            count++;
        }
        return 0;
    }
};