// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information : https://www.geeksforgeeks.org/the-ubiquitous-binary-search-set-1/
// It is the optimal algorithm for a sorted array 


#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int n, int key){
    int left = 0;
    int right = n-1;      // REMEMBER: do not start with right = n && left < right; you might miss the case where 
                          // they might be equal exactly. 
    while(left <= right){
        int i = left + (right-left)/2;
        if(key == arr[i]){
            return true;
        }
        else if(key < arr[i]){
            right = i-1;
        }
        else{
            left = i+1;
        }
    }

    return false;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    cout<<binarySearch(arr, 7, 100);
}