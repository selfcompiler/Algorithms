// doc link : https://docs.google.com/document/d/1LCnMilgACfX2x0dWAKBo9yStraN3h0bhXZCNJ1JFjoo/edit?usp=sharing


import java.util.*;

class Program {
  public static List<Integer> moveElementToEnd(List<Integer> array, int toMove) {
    // Write your code here.
		
    	int b=0;
	int e=array.size() -1 ;
	
	while(b < e){
		
	if(array.get(e)==toMove){
		e--;
}else if(array.get(b)!=toMove){
	b++;
}else if(array.get(b)==toMove){
	
	if(array.get(e)!=toMove){
		
		int temp=array.get(e);
		array.set(e,array.get(b));
		array.set(b,temp);
		e--;
		b++;
}else{
	e--;
}
}
}
	return array;

  }
}
