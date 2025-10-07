#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int> &arr,int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(vector<int> &arr, int d){
    int n = arr.size();
    if (n==0) return;
    d%=n;
    if (d==0) return;

    reverseArray(arr,0,n-d-1);
    reverseArray(arr,n-d,n-1);
    reverseArray(arr,0,n-1);
}



int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int d = 2;
    cout<<"Original Array: ";
    rotateArray(arr,d);
    cout<<"Clockwise Rotated Array: ";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}