// https://docs.google.com/document/d/1NzSHCcW_WfJ3j_Lz1blBQE73Ikc8-PnxNEHwC6297P8/edit?usp=sharing
// Author : Rahul Kumar Singh 

using System;
public class Program {
	public static int[] SmallestDifference(int[] arrayOne, int[] arrayTwo) {
Array.Sort(arrayOne);
	Array.Sort(arrayTwo);
int idxOne=0;
int idxTwo=0;
int smallest = Int32.MaxValue;
int current=Int32.MaxValue;
int[ ] smallestPair=new int [2];
while(idxOne < arrayOne.Length && idxTwo < arrayTwo.Length ){

	int firstNum=arrayOne[idxOne];
	int secondNum=arrayTwo[idxTwo];
	if (firstNum < secondNum){
		current=secondNum-firstNum;
		idxOne++;
}else if(firstNum > secondNum){
	  current=firstNum-secondNum;
   	idxTwo++;
}else{
	return new int [] {firstNum,secondNum};
}
if(current < smallest) {
	smallest=current;
	smallestPair= new int [ ] {firstNum,secondNum};
}

}

return smallestPair;	
	}
}


