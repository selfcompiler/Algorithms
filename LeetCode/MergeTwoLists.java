/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
       /* Recursive 
       if(l1==null)
           return l2;
        if(l2==null)
            return l1;
        ListNode head;
        if(l1.val < l2.val){
            l1.next=mergeTwoLists(l1.next,l2);
            head=l1;
        }else{
            l2.next=mergeTwoLists(l1,l2.next);
            head=l2;
        }
        return head; */
        
        // Iterative 
       // 
       
       if(l1==null)
           return l2;
        if(l2==null)
            return l1;
        
       ListNode tmp,c1,c2,n1,n2;
       if(l1.val>l2.val){
           tmp=l1;
           l1=l2;
           l2=tmp;
       }
        c1=l1;
        c2=l2;
        n1=l1.next;
        n2=l2.next;
        while(n1!=null && n2!=null){
            if(c1.val<=c2.val && n1.val>=c2.val){
                
                c1.next=c2;
                c2.next=n1;
                c1=c2;
                c2=n2;
                n2=c2.next;
            }else if(c2.val>=n1.val){
                c1=n1;
                n1=n1.next;
            }  
        }
       if(n1==null){
           c1.next=c2;
       }
        if(n2==null){
           while(n1!=null && n1.val<c2.val){
               c1=n1;
               n1=n1.next;
           }
          if(n1==null){
              c1.next=c2;
          }else{
              c1.next=c2;
              c2.next=n1;
          } 
        }
        return l1;
    }
}
