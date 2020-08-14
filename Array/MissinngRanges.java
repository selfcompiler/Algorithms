// https://leetcode.com/problems/missing-ranges/


class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
      
      List<String> missingRanges=new ArrayList<>();
      
      if(nums.length==0){
        missingRanges.add(rangeToString(lower,upper));
        return missingRanges;
      
      }
      
        
      if(nums[0]!=lower){
          
        missingRanges.add(rangeToString(lower,nums[0]-1));
        
      }
      
      for(int i=1;i<nums.length;i++){
          
          if(nums[i]==nums[i-1])
              continue;
        
          if(nums[i]>(nums[i-1]+1)){
              
              missingRanges.add(rangeToString(nums[i-1]+1,nums[i]-1));
          }
        
      }
      
      if(upper!=nums[nums.length-1]){
        
        missingRanges.add(rangeToString(nums[nums.length-1]+1,upper));
      }
      return missingRanges;
    }
  
  
  String rangeToString(int start,int end){
    
    if(start==end){
      return new Integer(start).toString();
    }
    return new Integer(start).toString()+"->"+new Integer(end).toString();
  }
}
