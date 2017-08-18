/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, int> plc;

    // Euler's gcd algorithm
    int gcd(int a, int b){
        // cout << a << "  ~~  " << b << endl;
        if (a == 0 || b == 0)
           return 0;
        if(a == 1 || b == 1) return 1; // for speedup reasons, case: a = 94911150, b = 1;

        if (a == b)
            return a;

        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }

    pair<int, int> calculateSlope(Point a, Point b){
        int num = b.y-a.y;
        int den = b.x-a.x;
        int hcf = gcd((num<0)?-num:num, (den<0)?-den:den); // convert -ve numbers to positive

        if(hcf == 0) return make_pair((num==0)?0:1, (den==0)?0:1);
        return make_pair(num/hcf, den/hcf);
    }

    int maxPoints(vector<Point>& points) {
        int maxcount = 0;

        int len = points.size();

        if(len <= 1) return len;

        for(int i = 0; i < len; i++){
            int offset = 0;
            for(int j = 0; j < len; j++){
                if(points[i].x != points[j].x || points[i].y != points[j].y){
                    pair<int, int> temp = calculateSlope(points[i], points[j]);
                    if(mp.find(temp.first) == mp.end()){
                        mp[temp.first] = plc;
                    }
                    mp[temp.first][temp.second] += 1;
                    if(mp[temp.first][temp.second]+offset > maxcount) maxcount = mp[temp.first][temp.second]+offset;
                }else{
                    offset += 1;
                    if(offset > maxcount) maxcount = offset;
                }
            }
            mp.clear();
        }

        return maxcount;
    }
};
