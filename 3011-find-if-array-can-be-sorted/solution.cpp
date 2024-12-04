class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return true;
        
        int left = 0;
        while (left < n) {
            const int currentBits = __builtin_popcount(nums[left]);
            int right = left + 1;
            
            while (right < n && __builtin_popcount(nums[right]) == currentBits) {
                right++;
            }
            
            if (left > 0) {
                const int prevBits = __builtin_popcount(nums[left - 1]);
                if (prevBits != currentBits) {
                    const int prevMax = *ranges::max_element(nums.begin(), nums.begin() + left);
                    const int curMin = *ranges::min_element(nums.begin() + left, nums.begin() + right);
                    if (prevMax > curMin) return false;
                }
            }
            
            ranges::sort(nums.begin() + left, nums.begin() + right);
            left = right;
        }
        
        return true;
    }
};