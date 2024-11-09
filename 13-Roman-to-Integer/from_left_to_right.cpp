class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int l = s.size();
        int prior = 0, result = 0, current;

        while(i < l) {
            switch (s[i]) {
                case 'I':
                    current = 1;
                    break;
                case 'V':
                    current = 5;
                    break;
                case 'X':
                    current = 10;
                    break;
                case 'L':
                    current = 50;
                    break;
                case 'C':
                    current = 100;
                    break;
                case 'D':
                    current = 500;
                    break;
                case 'M':
                    current = 1000;
                    break;
                default:
                    current = 0;
                    break;
            }

            if (current > prior) {
                result = result - prior + current - prior;
            }
            else {
                result += current;
            }

            prior = current;
            i++;
        }

        return result;
    }
};
