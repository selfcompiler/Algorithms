package Algorithms.Greedy;
/*
Assuming Majority Element always exist
*/
import java.util.Iterator;

public class MajoritySearch {

    public static String majoritySearch(Iterator<String> sequence){

        String candidate="";
        String iter;
        int candidateCount=0;
        while (sequence.hasNext()){

            iter=sequence.next();

            if(candidateCount==0){
                candidateCount++;
                candidate=iter;
            }else if(iter.equals(candidate)){
                candidateCount++;
            }else{
                candidateCount--;
            }
        }
        return candidate;
    }
}
