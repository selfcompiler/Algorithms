package Algorithms.BST;


import java.util.LinkedList;
import java.util.Queue;

public class BSTUtility {


    public static BSTNode<Integer> searchBST(BSTNode<Integer> tree,int key){

        if( tree == null || tree.data == key ){

            return tree;
        }

        return key < tree.data ? searchBST(tree.left,key):searchBST(tree.right,key);
    }

    public static boolean isBinaryTreeBST(BinaryTreeNode<Integer> tree){


        return areKeysInRange(tree,Integer.MIN_VALUE,Integer.MAX_VALUE);


    }

    private static boolean areKeysInRange(BinaryTreeNode<Integer> tree,Integer lower,Integer higher){

        if(tree==null){

            return true;
        }

        else if(Integer.compare(tree.data,lower)<0 || Integer.compare(tree.data,higher)>0){

            return false;

        }

        return areKeysInRange(tree.left,lower,tree.data)&&areKeysInRange(tree.right,tree.data,higher);

    }

    public static boolean isBinaryTreeBSTOptimized(BinaryTreeNode<Integer> treeNode){

        Queue<QueueEntry> BFSQueue=new LinkedList<>();

        BFSQueue.add(new QueueEntry(treeNode,Integer.MIN_VALUE,Integer.MAX_VALUE));

        QueueEntry headEntry;

        while ((headEntry=BFSQueue.poll())!=null){

                if(headEntry.treeNode!=null){

                    if((headEntry.treeNode.data<headEntry.lower)||(headEntry.treeNode.data>headEntry.higher)){

                        return false;
                    }

                    BFSQueue.add(new QueueEntry(headEntry.treeNode.left,headEntry.lower,headEntry.treeNode.data));
                    BFSQueue.add(new QueueEntry(headEntry.treeNode.right,headEntry.treeNode.data,headEntry.higher));

                }
        }
        return true;
    }

        public static BSTNode<Integer> firstNodeGreaterThanK(BSTNode<Integer> tree,int k){

        BSTNode<Integer> subTree=tree,firstSoFar=null;

        while (subTree!=null){


            if(subTree.data>k){

                firstSoFar=subTree;
                subTree=subTree.left;
                
            }else {
                
                subTree=subTree.right;
            }
        }
        return firstSoFar;
    }
    
        public static BSTNode<Integer> firstNodeEqualWithKWithDuplicate(BSTNode<Integer> tree,int k){
        
        BSTNode<Integer> subTree=tree,firstSoFar=null;
        
        while (subTree!=null){
            
            if(subTree.data<k){
                
                subTree=subTree.right;
                
            }else if(subTree.data==k){
                
                firstSoFar=subTree;
                subTree=subTree.left;
                
            }else{
                
                subTree=subTree.left;
            }
            
        }
        
        return firstSoFar;
    }

}
