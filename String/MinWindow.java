// https://leetcode.com/problems/minimum-window-substring/

class Solution {
    public String minWindow(String s, String t) {
        
        if(s.equals("")||t.equals("")){
            return "";
        }
        int left=0,right=0;
        Map<Character,Integer> c_count=new HashMap<Character,Integer>();
        for(Character c:t.toCharArray()){
            if(!c_count.containsKey(c)){
                c_count.put(c,1);
            }else{
                c_count.put(c,c_count.get(c)+1);
            }
        }
        
        Map<Character,Integer> window_map=new HashMap<Character,Integer>();
        window_map.put(getCharObject(s.charAt(right)),1);
        String result="";
        
        int min_len=s.length()+1;
        
        while(right < s.length()){
            
          //   System.out.println("left = "+left+" right="+right);
            
            if(isDesiredWindow(c_count,window_map)){
                
            //    System.out.println("Desired : left = "+left+" right="+right);
                
                if((right-left+1) <=min_len){
                    
                    min_len=right-left+1;
                    result=s.substring(left,right+1);
                    
                }
        
                window_map.put(getCharObject(s.charAt(left)),window_map.get(getCharObject(s.charAt(left)))-1);    
                
                left++;
                
            }
            else{
                
                
                right++;
                if(right < s.length()){
                    
                if(!window_map.containsKey(getCharObject(s.charAt(right)))){
                    window_map.put(getCharObject(s.charAt(right)),1);
                }else{
                
                    window_map.put(getCharObject(s.charAt(right)),window_map.get(getCharObject(s.charAt(right)))+1);
                }
            }
            }
            
        }
        return result;
    }
    
    boolean isDesiredWindow(Map<Character,Integer> original,Map<Character,Integer> windowMap){
        
        for(Character key:original.keySet()){
            
          //  System.out.println("Comp Map Key = "+key);
            if(!windowMap.containsKey(key)){
                return false;
            }
            if(original.get(key)>windowMap.get(key)){
                return false;
            }
        }
        return true;
    }
    
    Character getCharObject(char c){
        return new Character(c);
    }
}
