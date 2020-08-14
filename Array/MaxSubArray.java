
// https://leetcode.com/problems/maximum-subarray/


class Solution {
    public int maxSubArray(int[] nums) {
      
      int maxsum=nums[0];
      int csum=0;
      int maxVal=nums[0];
      for(int i=0;i<nums.length;i++){
        
        csum=csum+nums[i];
        if(csum>maxsum){
        
          maxsum=csum;
        }
        
        if(csum<0){
          
          csum=0;
        }
        
        if(maxVal<nums[i]){
          maxVal=nums[i];
        }
        
      }
      return maxVal>maxsum?maxVal:maxsum;
      
    }
}
