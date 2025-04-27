class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (!n) {return 0;}

        uint32_t digit = 32;
        uint32_t result = 0;

        while (n) {
            result = (result * 2) + (n % 2);
            digit--;
            n = n / 2;
        }

        result = result << digit;
        return result;
    }
};
