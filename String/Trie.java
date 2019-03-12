package DataStructures;

public class Trie {
    static final int ALPHABET_SIZE=26;

    static class TrieNode{
        TrieNode[] child=new TrieNode[ALPHABET_SIZE];
        boolean isEndOfWord;

        TrieNode(){
            isEndOfWord=false;
            for(int i=0;i<ALPHABET_SIZE;i++)
                child[i]=null;
        }
    };

    static TrieNode root;

    static void insert(String input){

        TrieNode currentNode=root;
        int idx;
        for(int i=0;i<input.length();i++){
                idx=input.charAt(i)-'a';
                if(currentNode.child[idx]==null) {

                    TrieNode newNode = new TrieNode();
                    if (i == (input.length() - 1)) {
                        // mark end of word
                        newNode.isEndOfWord = true;
                    }
                    currentNode.child[idx] = newNode;
                    currentNode=newNode;
                }else{
                    currentNode=currentNode.child[idx];
                    if (i == (input.length() - 1)) {
                        currentNode.isEndOfWord=true;
                    }
                }
        }
    }

    static boolean search(String input){
        TrieNode currentNode=root;
        int idx,i;
        i=0;
        while(currentNode!=null){
            idx=input.charAt(i)-'a';
            if(currentNode.child[idx]==null)
                return false;
            i++;
            currentNode=currentNode.child[idx];
            if(i==input.length()){
                return currentNode.isEndOfWord;
            }
        }
        return false;
    }

    static boolean subStr(String input){
        TrieNode currentNode=root;
        int idx,i;
        i=0;
        while(currentNode!=null){
            idx=input.charAt(i)-'a';
            if(currentNode.child[idx]==null)
                return false;
            i++;
            currentNode=currentNode.child[idx];
            if(i==input.length()){
                return true;
            }
        }
        return false;
    }

    public static void main(String args[]) throws Exception{
        String keys[] = {"the", "a", "there", "answer", "any",
                "by", "bye", "their"};
        root=new TrieNode();
        for (int i = 0; i < keys.length ; i++)
            Trie.insert(keys[i]);

        if(search("answer") == true)
            System.out.println("the Exist");
    }
}
