package Algorithms.Greedy;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PairedTasks {

    public static class PairedTaskSet {
        Integer task1;
        Integer task2;

        public PairedTaskSet(Integer task1,Integer task2){
            this.task1=task1;
            this.task2=task2;
        }
    }

    public static List<PairedTaskSet> optimumAssignment(List<Integer> taskDuration){

        Collections.sort(taskDuration);

        List<PairedTaskSet> pairedTaskSetList=new ArrayList<>();

        for(int i=0,j=taskDuration.size()-1;i<j;++i,--j){

            pairedTaskSetList.add(new PairedTaskSet(taskDuration.get(i),taskDuration.get(j)));
        }
        return pairedTaskSetList;
    }
}
