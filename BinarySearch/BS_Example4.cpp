// █▀▀ █░░ █ ▄█ █▀█ ▄▄ ▀█▀
// ██▄ █▄▄ █ ░█ █▄█ ░░ ░█░
// Author: ELi10-T
// For more information: https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
// Good Problem


#include<bits/stdc++.h>
using namespace std;

int countOccurances(int *arr, int n, int key, bool firstIndex){
    int left = 0;
    int right = n-1;
    int ans = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] < key){
            left = mid+1;
        }
        else if(arr[mid] > key){
            right = mid-1;
        }
        else{
            ans = mid;
            if(firstIndex){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
    }
    return ans;

}

int main(){
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int first = countOccurances(arr, n, 2, true);
    int last = countOccurances(arr, n, 2, false);

    cout<<last<<" "<<first<<"\n";
    return 0;
}