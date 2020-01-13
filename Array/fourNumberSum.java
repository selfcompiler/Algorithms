// https://docs.google.com/document/d/1UPrq70a5C7Tj8f2c6PO32GRMWKUKQa52OgnGo3WXeVQ/edit?usp=sharing



import java.util.*;

class Program {
  public static List<Integer[]> fourNumberSum(int[] array, int targetSum) {
		Map <  Integer , List < Integer [ ] >> allPairSum=new HashMap < >();
		List < Integer [ ] > quadruplets = new ArrayList <> ();
		
		for(int i=0;i < array.length ; i++) {
			
			for(int j=i+1;j<array.length ; j++) 
				{
					int sum=array[i]+array[j];
					
					int requiredSum=targetSum-sum;
					
				  if(allPairSum.containsKey(requiredSum)){
					for(Integer[ ] pairs:allPairSum.get(requiredSum)){
						Integer[ ] temp=new Integer[] {array[i],array[j],pairs[0],pairs[1]};
						quadruplets.add(temp);
}
					}
}

for(int k=0; k < i ;k++) {
	int sum=array[i]+array[k];
	if(allPairSum.containsKey(sum)){
		allPairSum.get(sum).add(new Integer[] {array[i],array[k]});	
}else{

allPairSum.put(sum,new ArrayList < Integer [ ] > ( ))	;
allPairSum.get(sum).add(new Integer[] {array[i],array[k]});	
}
}
}

return quadruplets;

  }
}
