// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
// Finding the majority element

#include<bits/stdc++.h>
using namespace std;

int binarySearchFirstOccurrence(int *arr, int n, int key){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if((mid == 0 && arr[mid] == key) || (arr[mid] == key && arr[mid-1] < key)){
            return mid;
        }
        else if(arr[mid] < key){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

bool findMajority(int *arr, int n, int key){
    int i = binarySearchFirstOccurrence(arr, n, key);
    
    if(i == -1){
        return false;
    }
    
    if(arr[i+n/2] == key){
        return true;
    } 
    return false;
}

int main(){
    int arr[] = { 1, 2, 3, 3, 3, 3, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    cout<<findMajority(arr, n , x);

    return 0;
}   