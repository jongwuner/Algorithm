class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vvi;
        set<tuple<int, int, int>> SET;


        sort(nums.begin(), nums.end());
        int N = nums.end() - nums.begin();
        for (int i = 0; i < N; i++) {
            int L = i + 1, R = N - 1;
            if (N <= L || N <= R) continue;
            while (L < R) {
                if (nums[i] + nums[L] + nums[R] < 0)
                    L++;
                else if (nums[i] + nums[L] + nums[R] > 0)
                    R--;
                else if (nums[i] + nums[L] + nums[R] == 0) {

                    if (SET.find({ nums[i], nums[L], nums[R] }) == SET.end()) {
                        vector<int> vi;
                        vi.push_back(nums[i]);
                        vi.push_back(nums[L]);
                        vi.push_back(nums[R]);
                        vvi.push_back(vi);
                        SET.insert({ nums[i], nums[L], nums[R] });

                    }

                    L++; R--;

                }
            }
        }
        return vvi;
    }
};