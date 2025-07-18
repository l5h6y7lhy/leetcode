/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> q;

        for (int i = 0; i < nestedList.size(); i++) {q.push(nestedList[i]);}

        int d = 0, total = 0;

        while (!q.empty()) {
            int s = q.size();
            d++;

            for (int i = 0; i < s; i++) {
                NestedInteger& curr = q.front();

                if (curr.isInteger()) {
                    total += (d * curr.getInteger());
                }
                else {
                    vector<NestedInteger>& l = curr.getList();

                    for (int m = 0; m < l.size(); m++) {q.push(l[m]);}
                }

                q.pop();
            }
        }

        return total;
    }
};
