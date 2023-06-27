// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/


#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int n){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left+ (right-left)/2;
        if(arr[mid] == mid){
            return mid;
        }
        else if(arr[mid] < mid){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {-100,-10, -5, -3, -4, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<binarySearch(arr, n)<<"\n";
}