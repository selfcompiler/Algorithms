package BinarySearchTrees;

import apple.laf.JRSUIUtils;

public class BinarySearchTrees {

    public static class TreeNode {

        public Integer data;

        public TreeNode left,right;

        public TreeNode(Integer data, TreeNode left, TreeNode right){

            this.data=data;
            this.left=left;
            this.right=right;
        }
    }

    private TreeNode root=null;

    public boolean insert(Integer key){

        if(root==null){

            root=new TreeNode(key,null,null);
        }else {

            TreeNode curr=root;

            TreeNode parent=curr;

            while (curr!=null){

                parent=curr;
                int cmp=Integer.compare(key,curr.data);

                if(cmp<0){

                    curr=curr.left;
                }
                else if(cmp>0){

                    curr=curr.right;
                }else{

                    return false; // key already present
                }
            }

            if(Integer.compare(key,parent.data)<0){

                parent.left=new TreeNode(key,null,null);
            }else{
                parent.right=new TreeNode(key,null,null);
            }

        }
        return true;
    }


    public boolean delete(Integer key){

        // Find the node with key

        TreeNode parent=null;
        TreeNode curr=root;

        while (curr!=null && (Integer.compare(key,curr.data)!=0)){
            parent=curr;
            curr=Integer.compare(key,curr.data)>0?curr.right:curr.left;
        }

        if(curr==null){ // node does not exist

            return false;
        }

        TreeNode keyNode=curr;

        if(keyNode.right!=null){  //has right subtree

                    // Find the minimum of Right Subtree

            TreeNode rKeyNode=keyNode.right;
            TreeNode rParent=keyNode;

            while (rKeyNode.left!=null){
                rParent=rKeyNode;
                rKeyNode=rKeyNode.left;
            }

            keyNode.data=rKeyNode.data;

            // Move Links to erase data

            if(rParent.left==rKeyNode){

                rParent.left=rKeyNode.right;
            }else{

                rParent.right=rKeyNode.right;
            }
            rKeyNode.right=null;

        }else{  // has only left subtree

            if(root==keyNode){  // if node to be deleted is root

                root=keyNode.left; // making new root
                keyNode.left=null; // unlinking initial root's left pointer
            }
            else{

                if(parent.left==keyNode){  // if  nodes to be deleted  is a left child of it's parent

                    parent.left=keyNode.left;
                }else{          // // if  nodes to be deleted  is a right child of it's parent

                    parent.right=keyNode.left;
                }

            }

        }
        return true;
    }
}
