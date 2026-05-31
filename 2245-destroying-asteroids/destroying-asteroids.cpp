class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long store=mass;
        for(int i=0;i<asteroids.size();i++){
            if(store<asteroids[i])return false;
            store+=asteroids[i];
        }
        return true;
    }
};