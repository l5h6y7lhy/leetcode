class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {return "1";}

        string prev = "1";
        string curr = "";

        for (int i = 2; i <= n; i++) {
            char c = prev[0];
            int count = 1;

            for (int j = 1; j < prev.size(); j++) {
                if (prev[j] == c) {
                    count++;
                    continue;
                }

                curr = curr + ((char) ('0' + count)) + c;

                c = prev[j];
                count = 1;
            }

            curr = curr + ((char) ('0' + count)) + c;
            prev = curr;
            curr = "";
        }

        return prev;
    }
};
