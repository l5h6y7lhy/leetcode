/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int prev = min(n, leftover);

        for (int i = 0; i < prev; i++) {
            buf[i] = buf[index + i];
        }

        leftover -= prev;
        index += prev;
        buf = buf + prev;

        while (prev < n) {
            int tmp = read4(buf);
            buf = buf + tmp;
            prev += tmp;

            if (!tmp) {break;}
        }

        if (prev <= n) {return prev;}

        leftover = prev - n;
        index = n;

        return n;
    }

private:
    int index;
    int leftover = 0;
};
