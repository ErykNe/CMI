#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> koglomerat;
vector<int> IloscBudynkow;
int T = 0;

void alg();

int znajdzNajwiekszaLiczbe(int low, int high);
int sprawdzOptymalnosc(int low, int high);

int main() {
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N = 0;
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
void alg(){
    for (int i = 0; i < IloscBudynkow.size(); ++i) {
       int a = sprawdzOptymalnosc(0, IloscBudynkow[i]);
        if (a == -1){
            cout << "NIE" << "\n";
            for (int j = 0; j < IloscBudynkow[i]; ++j) {
                koglomerat.erase(koglomerat.begin());
            }
            continue;
        }
        int ilosc = znajdzNajwiekszaLiczbe(0, IloscBudynkow[i]);
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
int sprawdzOptymalnosc(int low, int high) {
    for(int i = high - 1; i > low; i--){
        int a = koglomerat[i];
        if(a == 0){
            if(koglomerat[i + 1] != 0 && koglomerat[i - 1] != 0 && i + 1 < high){
                return -1;
                break;
            }
        }
    }
    int maxElement = *max_element(koglomerat.begin(), koglomerat.begin() + high);
    vector<int>::iterator i = max_element(koglomerat.begin(), koglomerat.begin() + high);
    int indexMaxElement = std::distance(koglomerat.begin(), i);
    int secondLargest = 0;
    for (int i = 0; i < high; i++) {
        if (koglomerat[i] != koglomerat[indexMaxElement]) {
            if (secondLargest == -1) {
                secondLargest = i;
            }
            else if (koglomerat[i] > koglomerat[secondLargest]) {
                secondLargest = i;
            }
        }
    }
    int secondSecondLargest = 0;
    for (int i = high - 1; i >= 0; i--) {
        if (koglomerat[i] != koglomerat[indexMaxElement]) {
            if (secondSecondLargest == -1) {
                secondSecondLargest = i;
            }
            else if (koglomerat[i] > koglomerat[secondSecondLargest]) {
                secondSecondLargest = i;
            }
        }
    }
    if (abs(indexMaxElement - secondLargest) > 1){
        return -1;
    }
    else if (abs(indexMaxElement - secondSecondLargest) > 1){
        return -1;
    } else {
        return 0;
    }
}
