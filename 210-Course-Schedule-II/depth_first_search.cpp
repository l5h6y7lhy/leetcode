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
                dfs(i);
            }
        }

        if (seq.size() < numCourses) {seq.clear();}

        return seq;
    }

private:
    vector<bool> v;
    vector<int> q;
    vector<int> seq;
    vector<vector<int>> p;

    void dfs(int start) {
        v[start] = true;
        seq.push_back(start);

        for (int i = 0; i < p[start].size(); i++) {
            if (q[p[start][i]]) {
                q[p[start][i]]--;
            }

            if (!q[p[start][i]]) {
                dfs(p[start][i]);
            }
        }

        return;
    }
};
