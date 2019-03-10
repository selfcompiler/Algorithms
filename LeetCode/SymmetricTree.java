/**

https://leetcode.com/problems/symmetric-tree/
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isMirror(TreeNode r1,TreeNode r2){
        if(r1==null && r2==null)
            return true;
        if(r1!=null && r2!=null){
            if(r1.val==r2.val && isMirror(r1.left,r2.right) && isMirror (r1.right,r2.left))
                return true;
        }
        return false;
    }
    public boolean isSymmetric(TreeNode root) {
        if(root==null)
            return true;
        return isMirror(root.left,root.right);
    }
}
