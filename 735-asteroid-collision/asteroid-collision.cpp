class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>result;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else if(st.empty() && asteroids[i]<0) result.push_back(asteroids[i]);
            else{
                while(!st.empty() && st.top()<=abs(asteroids[i])){
                    if(st.top()==abs(asteroids[i])){
                        st.pop();
                        break;
                    }
                    st.pop();
                    if(st.empty()) result.push_back(asteroids[i]);
                }
            }
        }
        stack<int>q;
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            result.push_back(q.top());
            q.pop();
        }
       
        return result;
    }
};