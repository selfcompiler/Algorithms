// https://leetcode.com/problems/happy-number/


class Solution {
    public boolean isHappy(int n) {
        
        Set<Integer> myset=new HashSet<Integer>();
   
        int newnum=0;
        myset.add(new Integer(n));
        while(n!=1){
           newnum=0; 
           while(n>0){
               newnum+=(n%10)*(n%10);
               n=n/10;
           }
            n=newnum;
            if(myset.contains(newnum))
            {
                myset.clear();
                return false;
            }
            myset.add(new Integer(n));   
        }
        myset.clear();
        return true;
    }
}
