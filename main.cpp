#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> koglomerat;
vector<int> IloscBudynkow;
int T = 0; //ile zestawow budynkow jest
int licznik; //ilość wyburzeń

void alg();
int binarySearch(int low, int high);
int main() {
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N = 0; //ile budynkow jest w jednym
        cin >> N;
        IloscBudynkow.push_back(N);
        for (int j = 0; j < N; ++j) {
            int pietro;
            cin >> pietro;
            koglomerat.push_back(pietro);
        }
    }
    for (int pri : koglomerat) {
        cout << pri << " "; //kontrolnie
    }
    cout << T << "\n";
    cout << "\n";

    alg();


    return 0;
}
int sd = 0;
void alg(){
    for (int i = 0; i < IloscBudynkow.size(); ++i) {
        int ilosc = binarySearch(0, IloscBudynkow[i]); //znajdz najwieksza liczbe
        cout << '\n';
        cout << ilosc << "\n";

        for (int j = 0; j < IloscBudynkow[i]; ++j) {
            koglomerat.erase(koglomerat.begin());
        }
    }
}
int binarySearch(int low, int high){
    int maxElement = *max_element(koglomerat.begin(), koglomerat.end());
    return maxElement;
}
void BinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
    int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
    cout << "NIE" << "\n";
}
