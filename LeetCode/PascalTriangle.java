/*
Link : https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
    List<List<Integer>>  ans=new LinkedList< >();
    if(numRows==0)
        return ans;
    LinkedList<Integer> row=new  LinkedList<>();  
    row.add(new Integer(1));
    ans.add(row);
    int idx1,idx2;
    for(int i=2;i<=numRows;i++){
        
        LinkedList<Integer> currentRow=new  LinkedList<>();
        for(int j=1;j<=i;j++){
            
            idx1=j-2;
            idx2=j-1;
            
            Integer sum=new Integer(0);
            
            if(idx1>=0)
                sum+=ans.get(i-2).get(idx1);
            if(idx2<=(i-2))
                sum+=ans.get(i-2).get(idx2);
            currentRow.add(sum);   
        }
        ans.add(currentRow);
        
    }    
    return ans;    
    }
        
    
}
