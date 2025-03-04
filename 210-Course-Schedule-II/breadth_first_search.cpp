class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        v.assign(numCourses, false);
        q.assign(numCourses, 0);
        p.resize(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            p[prerequisites[i][1]].push_back(prerequisites[i][0]);
            q[prerequisites[i][0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (!q[i] && !v[i]) {
                bfs(i);
            }
        }

        if (seq.size() < numCourses) {seq.clear();}

        return seq;
    }

private:
    vector<int> seq;
    vector<bool> v;
    vector<int> q;
    vector<vector<int>> p;

    void bfs(int start) {
        queue<int> f;
        f.push(start);

        while (!f.empty()) {
            int curr = f.front();
            f.pop();
            v[curr] = true;
            seq.push_back(curr);

            for (int i = 0; i < p[curr].size(); i++) {
                if (q[p[curr][i]]) {
                    q[p[curr][i]]--;
                }

                if (!q[p[curr][i]]) {
                    f.push(p[curr][i]);
                }
            }
        }

        return;
    }
};
