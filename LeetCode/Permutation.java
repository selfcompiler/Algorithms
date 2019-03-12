// https://leetcode.com/problems/permutations/

class Solution {
    
    HashMap<Integer,Boolean> isTaken=new HashMap<Integer,Boolean>();
    List<List<Integer>> ans=new ArrayList< List<Integer> >();
    
    List<Integer> indexList=new ArrayList< Integer >();
    
    
    public void permute1(int size,int[] nums){
        
       // System.out.println(" "+Integer.toString(indexList.size()));
        if(indexList.size()==size){
            
            ArrayList<Integer> singlePermuation=new ArrayList<Integer>();
            for(int i=0;i<size;i++){
                singlePermuation.add(new Integer(nums[indexList.get(i)]));   
            }
            ans.add(singlePermuation);
            return ;
        }
        for(int i=0;i<size;i++){
            if(isTaken.get(new Integer(i))==false){
                isTaken.put(new Integer(i),true);
                indexList.add(i);
                permute1(size,nums);
                indexList.remove(indexList.size()-1);
                isTaken.put(new Integer(i),false);
            }
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
            
        
                    for(int i=0;i<nums.length;i++){
                        isTaken.put(new Integer(i),false);
                    }
                    
                    for(int i=0;i<nums.length;i++){
                        isTaken.put(new Integer(i),true);
                        indexList.add(new Integer(i));
                        permute1(nums.length,nums);
                        indexList.remove(indexList.size()-1);
                         isTaken.put(new Integer(i),false);
                            
                    }
        
                    return ans;
    }
}
