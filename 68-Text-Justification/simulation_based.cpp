class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int head = 0, tail = 0;
        int l = words.size();
        int cl = words[tail].size();

        string curr;
        vector<string> result;

        while (tail < l - 1) {
            if (cl + 1 + words[tail + 1].size() <= maxWidth) {
                cl += (1 + words[tail + 1].size());
                tail++;
            }
            else {
                cl -= (tail - head);
                int lo = maxWidth - cl;

                int count = tail - head;

                if (!count) {
                    string extra = string(lo, ' ');
                    curr = words[head] + extra;
                    result.push_back(curr);
                }
                else {
                    curr = words[head];
                    string extra = string(lo / count, ' ');

                    for (int i = 0; i < count; i++) {
                        curr = curr + extra;
                        if (i < (lo % count)) {curr = curr + " ";}
                        curr = curr + words[head + i + 1];
                    }

                    result.push_back(curr);
                }

                head = tail + 1;
                tail = tail + 1;
                cl = words[tail].size();
            }
        }

        curr = words[head];

        for (int i = head + 1; i < l; i++) {
            curr = curr + " ";
            curr = curr + words[i];
        }

        int lo = maxWidth - cl;
        string extra = string(lo, ' ');
        curr = curr + extra;

        result.push_back(curr);
        return result;
    }
};
