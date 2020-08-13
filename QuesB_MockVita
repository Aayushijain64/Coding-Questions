#include <iostream>
#include<climits>
using namespace std;

int bitScore(int num){
    int largest = INT_MIN;
    int smallest = INT_MAX;
    int rem =0;
    while(num>0){
        rem = num%10;
        if(rem>largest){
            largest = rem;
        }
        if(rem<smallest){
            smallest = rem;
        }
        num= num/10;
    }
    int bitscore = ((largest*11) +(smallest*7))%100;
    return bitscore;
}

int main() {
    int N,num,bit_score[500],number,numOfPairs=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        bit_score[i] = bitScore(num);
    }
    for(int i=1;i<9;i++)
    {
    int count=0;
    for(int j=0;j<N;j=j+2)
    {
        number=bit_score[j]/10;
        if(number==i)
        count++;
        
    }
    if(count==2)
    {
        numOfPairs++;
    }
    else if(count>=3)
    {
        numOfPairs=numOfPairs+2;
    }
    count=0;
    for(int j=1;j<N;j=j+2)
    {
        number=bit_score[j]/10;
        if(number==i)
        count++;
        
    }
    if(count==2)
    {
        numOfPairs++;
    }
    else if(count>=3)
    {
        numOfPairs=numOfPairs+2;
    }
    
  }
  cout<<numOfPairs;     
}