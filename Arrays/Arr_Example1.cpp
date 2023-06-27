// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
// Good Problem:
// Two Approaches:
    // <i> Sort the array and then compare the beginning and the end of mismatches. 
    // <ii> This method in code

#include<bits/stdc++.h>
using namespace std;

pair<int,int> giveIndexes(int *arr, int n){
    // First step in finding an anomoly, find the number which is greater than next number
    int first;
    int second;
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            first = i;
            break;
        }
    }
    for(int i=n-1;i>0;i--){
        if(arr[i] < arr[i-1]){
            second = i;
            break;
        }
    }    
    int mini=INT_MAX, maxi=INT_MIN;
    for(int i=first;i<=second;i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    int finalfirst = first;
    int finallast = second;
    for(int i=0;i<first;i++){
        if(arr[i] > mini){
            finalfirst = i;
            break;
        }
    }
    for(int i=n-1;i>second;i--){
        if(arr[i] < maxi){
            finallast = i;
            break;
        }
    }
    return {finalfirst, finallast};
}

int main(){

    int arr[] = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    pair<int,int> val;
    val = giveIndexes(arr, n);
    cout<<val.first<<" "<<val.second<<"\n";
    return 0;
}

