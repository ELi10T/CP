// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

// Find the min number which is greater than the given number in the sorted array. 

// Two types of solns: [1,2,3,4,5,6] - x = 3, ans = 4;
//                     [1,2,4,5,6] - x = 3, ans = 4;
#include<bits/stdc++.h>
using namespace std;

int findCeil(int *arr, int n, int key){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left+(right-left)/2;
        if(arr[mid] < key){
            left = mid+1;
        }
        else if(arr[mid] == key){
            left = mid+1;
        }
        else{
            if((mid == 0 && arr[mid] > key) || arr[mid-1] <= key){
                return mid;
            }
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
    int n = sizeof(arr)/sizeof(arr[0]);

    int i = findCeil(arr, n, 12);
    cout<<i<<"\n";
}