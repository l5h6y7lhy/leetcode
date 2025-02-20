class Solution {
public:
    int strStr(string haystack, string needle) {
        int j;
        int objl = haystack.size();
        int tarl = needle.size();

        if (objl < tarl) {return -1;}

        for (int i = 0; i <= objl - tarl; i++) {
            for (j = i; j < i + tarl; j++) {
                if (haystack[j] != needle[j - i]) {break;}
            }

            if (j - i == tarl) {return i;}
        }

        return -1;
    }
};
