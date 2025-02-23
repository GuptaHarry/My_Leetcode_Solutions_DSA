

// Q.3 -> Given an array of size n , proint all the sums possible from its subsequence  

#include<iostream>
using namespace std;



 void subsetsum( int arr[] , int sum , int index, int n ){
   
    // base case 
    if(index ==n){
        cout<<"sum is "<<sum<<endl;
        return;
    }


    //No
    subsetsum(arr,sum , index+1,n);
    // Yes
    subsetsum(arr, sum+arr[index],index+1,n);
 }


 
int main (){
   
    int arr[] = {1,2,3};
    int sum=0;

    subsetsum(arr, sum ,0,3);
    return 0 ; 
}

