class Solution {
public:
    struct Event {
        int xc, height;
        bool start;

        Event(int x, int h, bool s) {
            xc     = x;
            height = h;
            start  = s;
        }

        bool operator<(const Event& other) const {
            if (xc < other.xc) {return true;}
            if (xc > other.xc) {return false;}
            if (start && !other.start) {return true;}
            if (!start && other.start) {return false;}
            if (start && other.start) {return height >= other.height;}
            return height <= other.height;
        }
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<Event> r;
        map<int, int> hr;
        hr[0] = 1;

        vector<int> tmp;
        tmp.resize(2);
        vector<vector<int>> result;

        for (int i = 0; i < buildings.size(); i++) {
            r.insert(Event(buildings[i][0], buildings[i][2], true));
            r.insert(Event(buildings[i][1], buildings[i][2], false));
        }

        for (auto i = r.begin(); i != r.end(); ++i) {
            if (i->start) {
                if (i->height > hr.rbegin()->first) {
                    tmp[0] = i->xc;
                    tmp[1] = i->height;
                    result.push_back(tmp);
                }

                hr[i->height]++;
                continue;
            }

            hr[i->height]--;
            if (!hr[i->height]) {hr.erase(i->height);}

            if (i->height > hr.rbegin()->first) {
                tmp[0] = i->xc;
                tmp[1] = hr.rbegin()->first;
                result.push_back(tmp);
            }
        }

        return result;
    }
};
