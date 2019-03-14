// Kth Smallest Element in a Sorted Matrix

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int[] pointer=new int[matrix[0].length];
        int size=matrix[0].length;
        for(int i=0;i<size;i++){
            pointer[i]=0;
        }
        
        int idx=0,minelement=matrix[0][0];
        while(k>=1){
            
            minelement=matrix[size-1][size-1]+1;
            for(int i=0;i<size;i++){
                
                if(pointer[i]<size){
                    if(minelement>=matrix[i][pointer[i]]){
                        minelement=matrix[i][pointer[i]];
                        idx=i;
                    }
                }
            }
            
            k--;
            pointer[idx]++;
        }
        return minelement;
    }
}
