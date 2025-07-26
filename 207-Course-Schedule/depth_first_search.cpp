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
                dfs(i);
            }
        }

        return (c == numCourses);
    }

private:
    int c;
    vector<bool> v;
    vector<int> q;
    vector<vector<int>> p;

    void dfs(int start) {
        v[start] = true;
        c++;

        for (int i = 0; i < p[start].size(); i++) {
            q[p[start][i]]--;

            if (!q[p[start][i]]) {
                dfs(p[start][i]);
            }
        }

        return;
    }
};
