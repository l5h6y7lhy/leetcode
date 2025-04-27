class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        book.resize(6);
        book[1] = 2;
        uint32_t f = 2;

        for (int i = 2; i < 6; i++) {
            f = f * f;
            book[i] = f;
        }

        return process(n, 5);
    }

private:
    vector<uint32_t> book;

    uint32_t process(uint32_t& n, uint32_t factor) {
        if (!n) {return 0;}
        if (!factor) {return n;}

        uint32_t l = n / book[factor];
        uint32_t r = n % book[factor];

        uint32_t left  = process(r, factor - 1);
        uint32_t right = process(l, factor - 1);

        return (left * book[factor]) + right;
    }
};
