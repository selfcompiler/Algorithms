package Algorithms.Strings;

import com.sun.tools.javac.code.Attribute;

import java.util.ArrayList;
import java.util.List;

public  final class SuperStrings {

    public enum SUBSTRING_ALGORITHM {
        BRUTE_FORCE,
        RABIN_KARP,
        KMP,
        Z_ALGORITHM
    }

    /***
     *
     * @param text
     * @param pattern
     * @param algorithm
     * @return
     */
    public static boolean isSubString(String text,String pattern,SUBSTRING_ALGORITHM algorithm){

        switch (algorithm){

            case BRUTE_FORCE:
                    return isSubStringBruteForce(text,pattern);
            case RABIN_KARP:
                    return isSubStringRabinKarp(text,pattern);
            case KMP:
                return isSubStringKMPSearch(text,pattern,createFailureFunction(pattern));
            default:
                    return isSubStringBruteForce(text,pattern);
        }
    }

    /***
     *
     * @param text
     * @param pattern
     * @return
     */
    private static boolean isSubStringBruteForce(String text,String pattern){
            int i,j,m;
            m=pattern.length();
            if(m==0)
                return true;
            for(i=0;i<(text.length()-m);i++){

                for(j=0;j<pattern.length();j++){
                    if(text.charAt(i)!=pattern.charAt(j))
                        break;
                }
                if(j==m)
                {
                    return true;
                }
            }
            return false;
    }

    /***
     *
     * @param text
     * @param pattern
     * @return
     */
    private static boolean isSubStringRabinKarp(String text,String pattern){

        int i,j,k,pl,tl;
        int patternSum=0;
        int rollingSum=0;
        int rollingWindowidx=0;
        pl=pattern.length();
        tl=text.length();
        if(pl>tl){
            return false;
        }
        for(i=0;i<pl;i++){

            patternSum+=(int)pattern.charAt(i);
            rollingSum+=(int)text.charAt(i);

        }
        rollingWindowidx=0;
        for(i=pl;i<tl;i++){

            if(rollingSum==patternSum){
                j=0;
                k=rollingWindowidx;
                while (k<tl){
                    if(pattern.charAt(j)!=text.charAt(k))
                        break;
                    j++;
                    k++;
                }
                if(j==pl)
                    return true;
            }
            rollingSum+=text.charAt(i);
            rollingSum-=text.charAt(rollingWindowidx);
            rollingWindowidx++;

        }
            return false;
    }

    /***
     *
     * @param pattern
     * @return
     */
    public static ArrayList<Integer> createFailureFunction(String pattern){

        ArrayList<Integer> failureFunction=new ArrayList<>(pattern.length()+1);
        int len=0;
        int i=1;
        failureFunction.add(0,0);

        while (i < pattern.length()){

            if(pattern.charAt(i)==pattern.charAt(len)){

                len++;
                failureFunction.add(i,len);
                i++;
            }
            else {

                if(len!=0){
                    len=failureFunction.get(len-1);
                }else {
                    failureFunction.add(i,0);
                    i++;
                }
            }
        }
        return failureFunction;
    }


    /***
     *
     * @param text
     * @param pattern
     * @param failureFunction
     * @return
     */
    public static boolean isSubStringKMPSearch(String text,String pattern,ArrayList<Integer> failureFunction){

        int i=0;
        int j=0;
        while (i< text.length()){

            if(pattern.charAt(j)==text.charAt(i)){
                j++;
                i++;
            }
            if(j==pattern.length()){
                return true;
            }else if(i<text.length() && pattern.charAt(j)!=text.charAt(i)){

                if(j!=0){
                    j=failureFunction.get(j-1);
                }else
                {
                    i++;
                }
            }
        }
        return false;
    }


}
