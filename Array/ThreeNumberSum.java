using System.Collections.Generic;
using System;
public class Program {
	public static List<int[]> ThreeNumberSum(int[] array, int targetSum) {
	Array.Sort(array);
	
	List < int [ ] > result=new List< int [ ] >();
  int n=array.Length;
	for(int i=0;i<n-2;i++) {
		
		int left=i+1;
		int right=array.Length-1;
		
		while(left < right){
			
			int sum=array[i]+array[left]+array[right];
			

			if(sum==targetSum){

	int[ ] triplet={array[i],array[left],array[right]};

            result.Add(triplet);
	left++;
	right--;
	
}else if(sum < targetSum){
	
left++;
}else if(sum > targetSum){

right--;
}
}

}
return result;

	}
}


// https://docs.google.com/document/d/1-aiEp_n66upLaVTrSX-UerWwx7oAOJKWsqcMWrPZdeY/edit?usp=sharing 


