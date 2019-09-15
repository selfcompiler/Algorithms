package Algorithms.BST;


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


}
