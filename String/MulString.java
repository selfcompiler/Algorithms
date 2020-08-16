// https://leetcode.com/problems/multiply-strings/

class Solution {
    public String multiply(String num1, String num2) {
      
      if(num1.equals("0")||num2.equals("0")){
        return "0";
      }
      int size_1=num1.length();
      int size_2=num2.length();  
      int[] res=new int[size_1+size_2];
      int pos1,pos2,prod,x,y;
      for(int i=size_1-1;i>=0;--i){
        
        
        for(int j=size_2-1;j>=0;--j){
            x=Character.getNumericValue(num1.charAt(i));
            y=Character.getNumericValue(num2.charAt(j));
          System.out.println("x="+x+" y="+y);
            pos1=i+j+1;
            pos2=i+j;
            prod=x*y;
           System.out.println("P="+prod);
            res[pos1]+=prod%10;
            res[pos2]+=prod/10;
        }
      }
        
        for(int i=0;i<size_1+size_2;i++){
          System.out.print(res[i]+" ");
        }
        System.out.println("");
        StringBuilder result=new StringBuilder();
        for(int i=size_1+size_2-1;i>=0;i--){
          
          if(i==0 && res[i]==0)
            continue;
          result.append(res[i]%10);
          if(res[i]>=10){
            
            res[i-1]+=res[i]/10;
            
          }
          
        }
    return result.reverse().toString();    
    
    }
}
