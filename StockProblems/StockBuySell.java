import java.util.ArrayList;

/**
 * Problem Link: https://www.geeksforgeeks.org/stock-buy-sell/
 */

class Interval{
    int buy,sell;
}
public class StockBuySell {

    void stockBuySell(int  price[],int n){
        if(n<=1)
            return;
        int count=0;
        ArrayList<Interval> sol=new ArrayList<Interval>();
        int i=0;
        while(i<n-1){
            // Local Minima :
            while((i<n-1)&&(price[i+1]<=price[i]))
                i++;
            if(i==n-1)
                break;
            Interval interval=new Interval();
            interval.buy=i;
            i++;
            while((i<n-1)&&(price[i]>=price[i-1]))
                i++;
            interval.sell=i-1;
            sol.add(interval);
            count++;
        }
        if(count==0){
            System.out.printf("0");
        }
        else{
            for(int j=0;j<count;j++){
                System.out.printf("Buy Day("+sol.get(j).buy+") Sell Day("+sol.get(j).sell+") Profit="+(sol.get(j).sell-sol.get(j).buy));
            }
        }

    }

    public static void main(String[] args) {
        StockBuySell stockBuySell=new StockBuySell();
        int price[] = {100, 180, 260, 310, 40, 535, 695};
        int n = price.length;
        stockBuySell.stockBuySell(price, n);

    }
}
