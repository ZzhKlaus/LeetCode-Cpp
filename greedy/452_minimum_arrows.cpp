class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        //case of 0 and 1 balloon
        if(len < 2) return len;
        //put in ascending order according to first element 
        sort(points.begin(), points.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        int i = 1, total = 1;
        //recording of minimal common area
        int maxS = points[0][0], minE = points[0][1];
        while(i < len){
            //have common area
            if(points[i][0] <= minE){
                maxS = max(maxS, points[i][0]);
                minE = min(minE, points[i][1]);
            } else {
                // no common area, need another arrow
                ++total;
                maxS = points[i][0];
                minE = points[i][1];
            }
            ++i;
        }
        return total;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        //case of 0 and 1 balloon
        if(len < 2) return len;
        //put in ascending order according to second element 
        sort(points.begin(), points.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int pos = points[0][1], total = 1;
        for(const vector<int>& ballon : points){
            if(ballon[0] > pos){
                pos = ballon[1];
                ++total;
            }
        }
        return total;
    }
};
