class Solution {
public:
    //dfs algorithm
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            //set all connected cities to "true" in one dfs loop, each time finding a new unvisited city, we add one to count.  
            if(!visited[i]){
                dfs(isConnected, i, visited);
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        visited[i] = true;
        for(int k = 0; k < isConnected.size(); ++k){
            //for a new city, search based on it
            if(isConnected[i][k] == 1 && !visited[k]){
                dfs(isConnected, k, visited);
            }
        }       
    }
};
