class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        c = 0;
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

        return (c == numCourses);
    }

private:
    int c;
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
            c++;

            for (int i = 0; i < p[curr].size(); i++) {
                q[p[curr][i]]--;

                if (!q[p[curr][i]]) {
                    f.push(p[curr][i]);
                }
            }
        }

        return;
    }
};
