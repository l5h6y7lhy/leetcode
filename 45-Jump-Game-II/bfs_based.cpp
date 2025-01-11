class Solution {
public:
    int jump(vector<int>& nums) {
        int l = nums.size();
        int last = 0;

        vector<int> dist;
        dist.assign(l, 0);

        queue<int> r;
        r.push(0);

        while (last < l - 1) {
            int curr = r.front();
            r.pop();

            if (curr + nums[curr] <= last) {continue;}

            int i = last + 1;

            while (i <= curr + nums[curr] && i < l) {
                if (!dist[i]) {
                    dist[i] = dist[curr] + 1;
                    r.push(i);
                }
                i++;
            }

            last = i - 1;
        }

        return dist[l - 1];
    }
};
