class Solution {
public:
    priority_queue<pair<int, int>> pq; // will hold <height, endtime>.. sorted by height, then endtime.
    vector<pair<int, int>> answer;

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        //sort by starting time, then ending time.
        sort(buildings.begin(), buildings.end(), [](vector<int> a, vector<int> b){
            if(a[0] < b[0]) return true;
            if(a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        });

        int cur = 0, curx = 0, curh = -1, len = buildings.size();

        // we do !pq.empty() because when the entire array is over, we still have some work to finish
        while(cur < len || !pq.empty()){
            // each of curx is a point where we do some processing, which is either the start or end of a building, we prefer to do processing
            // at ending point of the tallest building, or if pq is empty then the beginning of the next building.
            curx = pq.empty()? buildings[cur][0]:pq.top().second;

            // if the next building starts at after our processing time, then we must rid the pq of all buildings that are before current
            // processing time
            if(cur >= len || buildings[cur][0] > curx){
                while(!pq.empty() && pq.top().second <= curx) pq.pop();
            }else{
                // curx would be some time point that is beyond or equal to buildings[cur][0], we will reset it to current building starting time
                curx = buildings[cur][0];
                // push all buildings that start at curx
                while(cur < len && buildings[cur][0] == curx){
                    pq.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }

            // get maximum height at this time
            curh = pq.empty()?0:pq.top().first;
            // if it's different from the previous height entry, make an update
            if(answer.empty() || answer.back().second != curh) answer.push_back(make_pair(curx, curh));
        }

        return answer;
    }
};
