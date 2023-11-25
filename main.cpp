//
// Created by Eryk Nejfert on 28/11/2022.
//

#include <iostream>

void quicksort(int *array, int startOfArray, int lengthOfArray);

using namespace std;

int main(){
    int tab[] = {0,4,85,2,89,11101,355,3,97};
    quicksort(tab, 0, 9-1);
    return 0;
}
int kurwa(int *arr, int low, int high);
void quicksort(int *arr, int low, int high){
    if(low < high){
        int pi = kurwa(arr, low, high);
        quicksort(arr, low, pi - 1);
        //consider here
    }
}
int kurwa(int *arr, int low, int high){
    int pivot = arr[(low + high)/2];
    swap(arr[high], arr[pivot]);
    int b = low;
    int a = low;
    while(true){
        a++;
        if(arr[a] < pivot){
            swap(arr[b], arr[a]);
            b++;
        }
        if(arr[a] == arr[high]){
            swap(arr[high], arr[pivot]);
            b++;
            break;
        }
    }
    return pivot;
}