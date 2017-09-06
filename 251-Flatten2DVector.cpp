class Vector2D {
public:
    int i, j, nvec;
    vector<vector<int>> vec;

    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d;
        i = 0; j = 0;
        nvec = vec2d.size();
    }

    int next() {
        int ans = vec[i][j++];
        return ans;
    }

    bool hasNext() {
        if(i < nvec && j < vec[i].size()) return true;
        else{
            i++;
            while(i < nvec && vec[i].size() == 0) i++;
            j = 0;
            return (i < nvec)? true: false;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
