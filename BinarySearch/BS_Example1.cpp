// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
// Two ways to solve it:
//    :One pass: do both in the same pass
//    :Two pass: normally find the pivot and decide to do binarysearch

// This does not work for duplicates

#include<bits/stdc++.h>
using namespace std;

int findPivotPoint(int *arr, int n){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(mid < right && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(left < mid && arr[mid-1] > arr[mid]){
            return mid-1;
        }

        if(arr[left] >= arr[mid]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
}

bool binarySearch(int *arr,int left, int right, int key){
    while(left <= right){
        int mid = left+(right-left)/2;

        if(arr[mid] == key){
            return true;
        }
        else if(arr[mid] < key){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    return false;
}

int main(){
    int arr[] = {3,4,5,6,1,2};
    int n = 6;
    int point = findPivotPoint(arr, 6);
    cout<<point<<"\n";
    int key = 5;
    if(arr[0] < key && key < arr[point]){
        cout<<binarySearch(arr, 0, point, key);
    }
    else{
        cout<<binarySearch(arr, point, n, key);
    }
}   