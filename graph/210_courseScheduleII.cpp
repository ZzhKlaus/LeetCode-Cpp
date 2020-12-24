class Solution {
/*
210. 课程表 II
正向思维，广度优先算法，首先将所有边反向放入edges中， 计算所有nodes的入度，把入度为0的node放入答案，并将其相邻节点入度减1
*/

private:   
    //存储有向图
    vector<vector<int>> edges;
    //存储每个节点的入度
    vector<int> indeg;
    //答案
    vector<int> ans;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        //反向并计算每个节点入度
        for(int i=0; i < prerequisites.size(); ++i){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++indeg[prerequisites[i][0]];
        }
        /*
        for(const vector<int>& i : prerequisites){
            edges[i[1]].push_back(i[0]);
            ++indeg[i[0]];
        }
        */
        //处理队列
        queue<int> q;
        //将所有入度为0的节点放入队列
        for(int i=0; i < numCourses; ++i){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //放入答案
            ans.push_back(node);
            //对于该节点连接的所有点，入度减一， 若减为0,放入q， 表示节点v的先修课已完成
            for(int v: edges[node]){
                --indeg[v];
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        // 若图中存在循环
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};
