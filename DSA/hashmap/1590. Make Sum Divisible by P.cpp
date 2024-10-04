// LeetCode solution for Question # 1590. Uses hashmap/hashtable.

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), res = n, need = 0, curr = 0;
        for (int i : nums) need = (need + i) % p;
        unordered_map<int, int> mpp = {{0, -1}};
        for (int i=0;i<n;i++){
            curr = (curr + nums[i]) % p;
            mpp[curr] = i;
            int want = (curr - need + p) % p;
            if (mpp.count(want)) res = min(res, i - mpp[want]);
        }
        return res < n ? res : -1;
    }
};
