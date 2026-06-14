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

        int result = 0;

        while (result < n) {
            int tmp = read4(buf);
            buf = buf + tmp;
            result = result + tmp;

            if (!tmp) {break;}
        }

        if (result > n) {return n;}

        return result;
    }
};
