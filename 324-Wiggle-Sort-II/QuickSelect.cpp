class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if ((l = nums.size()) == 1) {return;}

        hal = l / 2;
        ul = l - 1;

        if (l % 2 == 0) {hal--;}
        if (l % 2 == 1) {ul--;}

        int start = 0, end = l - 1, tmp;

        int half = l / 2;
        if (l % 2 == 1) {half++;}

        while (1) {
            if (end - start == 1) {
                if (nums[coordinate(start)] > nums[coordinate(end)]) {
                    tmp = nums[coordinate(start)];
                    nums[coordinate(start)] = nums[coordinate(end)];
                    nums[coordinate(end)] = tmp;
                }
                break;
            }

            int pl = start;
            int pr = end;
            int ml = (pr + pl) / 2;
            int mr = ml + 1;
            int target = nums[coordinate(ml)];

            while (1) {
                if (pr <= pl) {break;}
                if (ml < pl && mr > pr) {break;}

                if (nums[coordinate(pl)] > target &&
                    nums[coordinate(pr)] < target) {
                    tmp = nums[coordinate(pl)];
                    nums[coordinate(pl)] = nums[coordinate(pr)];
                    nums[coordinate(pr)] = tmp;
                }

                if (nums[coordinate(pl)] < target) {
                    pl++;
                    continue;
                }

                if (nums[coordinate(pr)] > target) {
                    pr--;
                    continue;
                }

                if (ml >= start && nums[coordinate(ml)] == target) {
                    ml--;
                    continue;
                }

                if (mr <= end && nums[coordinate(mr)] == target) {
                    mr++;
                    continue;
                }

                if (ml > pl && nums[coordinate(ml)] < target) {
                    tmp = nums[coordinate(ml)];
                    nums[coordinate(ml)] = nums[coordinate(pl)];
                    nums[coordinate(pl)] = tmp;
                    pl++;
                    continue;
                }

                if (ml >= start && nums[coordinate(ml)] > target) {
                    tmp = nums[coordinate(ml)];
                    nums[coordinate(ml)] = nums[coordinate(pr)];
                    nums[coordinate(pr)] = tmp;
                    pr--;
                    continue;
                }

                if (mr <= end && nums[coordinate(mr)] < target) {
                    tmp = nums[coordinate(mr)];
                    nums[coordinate(mr)] = nums[coordinate(pl)];
                    nums[coordinate(pl)] = tmp;
                    pl++;
                    continue;
                }

                if (mr < pr && nums[coordinate(mr)] > target) {
                    tmp = nums[coordinate(mr)];
                    nums[coordinate(mr)] = nums[coordinate(pr)];
                    nums[coordinate(pr)] = tmp;
                    pr--;
                    continue;
                }
            }

            int left = pl - start;
            int central = pr - pl + 1;

            if (left > half) {
                end = pl - 1;
            }
            else if (left + central >= half) {
                break;
            }
            else {
                start = pr + 1;
                half -= (left + central);
            }
        }

        return;
    }

private:
    int l;
    int hal;
    int ul;

    int coordinate(int& i) {
        if (i <= hal) {return (hal - i) * 2;}
        return ul - (2 * (i - hal - 1));
    }
};
