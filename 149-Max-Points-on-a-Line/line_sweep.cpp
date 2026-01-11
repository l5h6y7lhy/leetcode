class Solution {
public:
    struct Line {
        double xc, yc;
        double slope;
        double next_y;
        int nump;

        Line(int& lx, int& ly, double& s) {
            nump = 2;
            xc = static_cast<double>(lx);
            yc = static_cast<double>(ly);
            slope = s;
        }

        void update(int& x) {
            next_y = yc + (slope * (x - xc));
        }

        int add() {
            return ++nump;
        }

        double slop() {
            return slope;
        }

        bool operator<(const Line& other) const {
            return next_y <= other.next_y;
        }
    };

    int maxPoints(vector<vector<int>>& points) {
        int l1, l2;
        int result = 1;
        set<Line> s1, s2;

        sort(points.begin(), points.end());

        for (l1 = 1; l1 < points.size(); l1++) {
            if (points[l1][0] != points[0][0]) {break;}
        }

        result = max(result, l1);

        while (l1 < points.size()) {
            for (l2 = l1 + 1; l2 < points.size(); l2++) {
                if (points[l1][0] != points[l2][0]) {break;}
            }

            result = max(result, l2 - l1);

            set<Line>& curr_s = s1.empty() ? s2 : s1;
            set<Line>& next_s = s1.empty() ? s1 : s2;

            auto it = curr_s.begin();

            for (int i = l1; i < l2; i++) {
                double EPS = 1e-9;
                unordered_set<double> slp;

                while (it != curr_s.end()) {
                    if (it->next_y > points[i][1] + EPS) {break;}

                    Line tmp = *it;

                    if (it->next_y >= points[i][1] - EPS &&
                        it->next_y <= points[i][1] + EPS) {
                        result = max(result, tmp.add());
                        slp.insert(tmp.slop());
                    }

                    if (l2 < points.size()) {
                        tmp.update(points[l2][0]);
                        next_s.insert(tmp);
                    }

                    ++it;
                }

                for (int j = 0; j < l1; j++) {
                    double curr_s = ((double) (points[i][1] - points[j][1])) /
                                    ((double) (points[i][0] - points[j][0]));

                    if (slp.find(curr_s) == slp.end()) {
                        Line curr_l(points[j][0], points[j][1], curr_s);

                        if (l2 < points.size()) {
                            curr_l.update(points[l2][0]);
                            next_s.insert(curr_l);
                        }

                        result = max(result, 2);
                    }
                }
            }

            if (l2 < points.size()) {
                while (it != curr_s.end()) {
                    Line tmp = *it;
                    tmp.update(points[l2][0]);
                    next_s.insert(tmp);

                    ++it;
                }
            }

            curr_s.clear();
            l1 = l2;
        }

        return result;
    }
};
