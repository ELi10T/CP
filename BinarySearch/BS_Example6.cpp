// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int n){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left+(right-left)/2;
        if((mid > 0 && arr[mid] > arr[mid-1]) && (mid < n-1 && arr[mid] > arr[mid+1])){
            return mid;
        }
        else if(arr[mid] < arr[mid-1]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {120, 100, 80, 20, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = binarySearch(arr, n);
    if(i != -1){
        cout<<arr[i]<<"\n";
    }
    else{
        if(arr[0] > arr[1]){
            cout<<arr[0]<<"\n";
        }
        else{
            cout<<arr[n-1]<<"\n";
        }
    }
}