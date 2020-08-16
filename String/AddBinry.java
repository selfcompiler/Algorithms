// https://leetcode.com/problems/add-binary/

import java.math.BigInteger;
class Solution {
  



    public String addBinary(String a, String b) {

  			
  			int m,n,carry;
  			m=a.length();
  			n=b.length();
  			
  			if(m<n){
  				return addBinary(b,a);
  			}

  			StringBuilder sb=new StringBuilder();
  			carry=0;
  			int j=n-1;
  			for(int i=m-1;i>=0;i--){

  				if(a.charAt(i)=='1')
  					carry++;
  				if( (j>-1) && b.charAt(j)=='1')
  					carry++;

  				j--;

  				if(carry%2==1)
  					sb.append("1");
  				else
  					sb.append("0");

  				carry=carry/2;

  			}

  			if(carry==1)
  				sb.append("1");
  			return sb.reverse().toString();

  	}


}
