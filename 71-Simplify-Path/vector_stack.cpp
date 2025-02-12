class Solution {
public:
    string simplifyPath(string path) {
        bool slash = false;
        bool letter = false;
        int period = 0;

        string curr;
        vector<string> dir;

        if (path.back() != '/') {path = path + '/';}

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (slash) {continue;}

                if (period == 2) {
                    if (!dir.empty()) {dir.pop_back();}
                }
                else if (period != 1 && !curr.empty()) {
                    dir.push_back(curr);
                }

                slash = true;
                letter = false;
                period = 0;
                curr = "";
            }
            else if (path[i] == '.') {
                slash = false;
                curr = curr + path[i];

                if (!letter) {period++;}
            }
            else {
                slash = false;
                letter = true;
                period = 0;
                curr = curr + path[i];
            }
        }

        string simP = "";

        for (int i = 0; i < dir.size(); i++) {
            simP = simP + '/' + dir[i];
        }

        if (simP.empty()) {simP = "/";}

        return simP;
    }
};
