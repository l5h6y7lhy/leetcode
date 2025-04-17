class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;

        while (i < word.size() && j < abbr.size()) {
            if (abbr[j] == '0') {return false;}

            if (abbr[j] >= 'a' && abbr[j] <= 'z') {
                if (word[i] != abbr[j]) {return false;}
                i++;
                j++;
                continue;
            }

            string num;
            int tmp = j;

            while (tmp < abbr.size() && abbr[tmp] >= '0' && abbr[tmp] <= '9') {
                num += abbr[tmp];
                tmp++;
            }

            j = tmp;
            i += std::stoi(num);
        }

        if (i < word.size() || i > word.size()) {return false;}

        return (j == abbr.size());
    }
};
