#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> koglomerat;
vector<int> IloscBudynkow;
int T = 0; //ile zestawow budynkow jest
int licznik; //ilość wyburzeń

void alg();

int znajdzNajwiekszaLiczbe(int low, int high);
int binarySearch(int l, int r, int x);

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
    alg();
    return 0;
}
int sd = 0;
void alg(){
    for (int i = 0; i < IloscBudynkow.size(); ++i) {
        //algorytm
        //jezeli znalazlo 0 w środku tego - Cout << "NIE" << "\n";
        //continue;
        int a = binarySearch(0, IloscBudynkow[i], 0);
        int centrum = 0 + (IloscBudynkow[i] - 0) / 2;
        if (a <= centrum){

        }
        if(a > centrum){

        }
        cout << a << "\n";
        int ilosc = znajdzNajwiekszaLiczbe(0, IloscBudynkow[i]); //znajdz najwieksza liczbe
        cout << ilosc << "\n";
        for (int j = 0; j < IloscBudynkow[i]; ++j) {
            koglomerat.erase(koglomerat.begin());
        }
    }
}
int znajdzNajwiekszaLiczbe(int low, int high){
    int maxElement = *max_element(koglomerat.begin(), koglomerat.begin() + high);
    return maxElement;
}
int binarySearch(int low, int high, int szukana) {
    if (high >= low) {
        int centrum = low + (high - low) / 2;


        if (koglomerat[centrum] == szukana){
            return centrum;
        }
`       else if (koglomerat[centrum] > szukana){
            return binarySearch(low, centrum - 1, 0);
        }
        else if (koglomerat[centrum] < szukana){
            return binarySearch(centrum + 1, high, 0);
        }
    }

    // We reach here when element is not
    // present in array
    return -1;
}
