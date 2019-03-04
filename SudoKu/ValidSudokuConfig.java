package sudoko;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class ValidSudokuConfig {

    public static boolean isValidSudoku(ArrayList<ArrayList<Character>> board){

        System.out.printf(board.toString());
        // Row Checking
        for(int i=0;i<9;i++){
            if(hasDuplicate(board,i,i+1,0,9)){
                System.out.printf("Row Failed : "+i);
                return false;
            }
        }

        // Column Checking

        for(int i=0;i<9;i++){
            if(hasDuplicate(board,0,9,i,i+1)){
                System.out.printf("Column Failed : "+i);
                return false;
            }
        }

        // Box Chceking

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int r1,r2,c1,c2;
                r1=i-i%3;
                r2=r1+3-1;
                c1=j-j%3;
                c2=c1+3-1;
                if(hasDuplicate(board,r1,r2,c1,c2)){
                    System.out.printf("Box Failed + ("+i+","+j+")");
                    return false;
                }
            }
        }

        return true;
    }
    public static boolean hasDuplicate(ArrayList<ArrayList<Character>> board,int r1,int r2,int c1,int c2){
        /*
          [r1,r2)
          [c1,c2)
        * */
        System.out.printf("\n");
        System.out.printf(board.toString()+"\n");
        System.out.printf("\n");
        System.out.printf(" Row "+r1+","+r2+"\n");
        System.out.printf(" Col "+c1+","+c2+"\n");

        Set<Character> characterSet=new HashSet<>();
        for(int i=r1;i<r2;i++){
            for(int j=c1;j<c2;j++){
                Character currentChar=board.get(i).get(j);
                System.out.println(currentChar+"\n");
                if(Character.compare('.',currentChar)==0){
                    continue;
                }else{
                    if(characterSet.contains(currentChar)){
                        System.out.printf(String.valueOf(currentChar));
                        System.out.println("Failed Bhayo <"+currentChar+">");
                        return true;
                    }else{
                        characterSet.add(currentChar);
                    }
                }
            }
        }
        return false;
    }
    public static void main(String args[]){

        char[][] byb = {
                        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
                        };

        ArrayList<ArrayList<Character>> board=new ArrayList<>();
        for(int i=0;i<9;i++){
            ArrayList<Character> characterArrayList=new ArrayList<>();
            for(int j=0;j<9;j++){
                characterArrayList.add(j,byb[i][j]);
            }
            board.add(i,characterArrayList);
        }
        System.out.printf("Validattion "+isValidSudoku(board));

    }


}
