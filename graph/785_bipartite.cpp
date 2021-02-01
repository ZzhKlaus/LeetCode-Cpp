class Solution {
public:
/*
判断二分图
定义一：若我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图
定义二：染色图，一种广度优先算法，若能用两种颜色对图中的所有节点染色并且能够让所有相邻节点颜色都不同，则为二分图。

思路： 设置一个队列q用于存储待染色的节点位置，列表color存储每个位置的染色记录。用广度优先算法实现

out：64.36%  39.75%
*/

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 0) return true;
        vector<int> color(n, 0);
        queue<int> q;

        for(int i=0; i<n; ++i){
            if(!color[i]){
                q.push(i);
                //对于为染色的第一个部分染1色
                color[i] = 1;
            }
            while(!q.empty()){
                //广度优先实现
                int node = q.front();
                q.pop();
                for(const int & j:graph[node]){
                    //未染色，根据其前任处理节点颜色判断给其染色
                    if(color[j] == 0){
                        q.push(j);
                        //node若染1, j染2, 反之.
                        color[j] = color[node] == 1? 2:1;
                    //若已染色
                    } else if(color[j] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
