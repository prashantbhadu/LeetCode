class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        if(st.find(endWord)==st.end()) return 0;

        while(!q.empty()){
            auto p=q.front();
            string word=q.front().first;
            int step=q.front().second;
            if(word==endWord) return step;
            q.pop();
            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }

};