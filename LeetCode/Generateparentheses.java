// https://leetcode.com/problems/generate-parentheses/

class Solution {
    
    
    List<String> ans=new ArrayList();
    
    public void solve(int o,int c,int n,char[] valid){
        if(c==n){
            ans.add(new String(valid));
            return ;
        }
        if(o > c){
            
            if(o<n){
                valid[o+c]='(';
                solve(o+1,c,n,valid);
                valid[o+c]=')';
                solve(o,c+1,n,valid);
            }
            if(o==n){
                valid[o+c]=')';
                solve(o,c+1,n,valid);
            }
            
        }else if(o<n){
                valid[o+c]='(';
                solve(o+1,c,n,valid); //solve(1,0,n,valid)
            }
        
    }
    
    public List<String> generateParenthesis(int n) {
        char[] valid=new char[2*n];  
        solve(0,0,n,valid);
        return ans;
    }
}
