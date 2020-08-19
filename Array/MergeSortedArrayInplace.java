

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int last_idx=m+n-1;
        int m_last=m-1,n_last=n-1;
        while( (m_last >=0) &&  (n_last >=0) ){
            
            if(nums1[m_last]>nums2[n_last]){
                nums1[last_idx]=nums1[m_last];
                m_last--;
                last_idx--;
            }else{
                nums1[last_idx]=nums2[n_last];
                n_last--;
                last_idx--;
            }
            
        }
       while(n_last>=0){
           nums1[last_idx]=nums2[n_last];
           n_last--;
           last_idx--;
       }
        
    }
}
