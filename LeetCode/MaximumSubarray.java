// https://leetcode.com/problems/maximum-subarray/

class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length<=0)
            return 0;
        int maxsum=nums[0];
        int csum=nums[0];
        for(int i=1;i<nums.length;i++){
            csum+=nums[i];
            csum=Math.max(csum,nums[i]);
            maxsum=Math.max(maxsum,csum);
        }
     return maxsum;   
    }
}
