
#include <iostream>
using namespace std;
#define MAXN 500000
long long int bitCount[MAXN]={0};
long long int arr[MAXN]={0};
int n;
long long int getCarry(long long int bitC){
    return bitC/2;
}
int getBit(long long int bitC){
    if(bitC%2)
        return 1;
    else
        return 0;
}
int main()
{
   int tc;
   cin>>tc;
   while(tc--){
       cin>>n;
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       for(int i=0;i<n;i++){
           arr[i+1]+=getCarry(arr[i]);
           arr[i]=getBit(arr[i]);
       }
       int idx=n;
       while(arr[idx]){
           arr[idx+1]=getCarry(arr[idx]);
           arr[idx]=getBit(arr[idx]);
           idx++;
       }
       long long int sum=0;
       for(int i=0;i<=idx;i++){
          if(arr[i])
            sum++;
           arr[i]=0;
       }
        cout<<sum<<"\n";    
   }        
    return 0;
}
