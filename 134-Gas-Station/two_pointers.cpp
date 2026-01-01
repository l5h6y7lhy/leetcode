class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int head = 0;
        int tail = 0;
        int curr = gas[0] - cost[0];
        bool turn = false;

        while (1) {
            if (tail == cost.size() - 1) {turn = true;}

            if (curr >= 0) {
                if (head == 0 && tail == cost.size() - 1) {return 0;}
                if (head - tail == 1) {return head;}

                tail++;

                if (tail == cost.size()) {tail = 0;}

                curr += gas[tail] - cost[tail];
                continue;
            }

            if (turn) {break;}

            tail++;
            head = tail;
            curr = gas[head] - cost[head];
        }

        return -1;
    }
};
