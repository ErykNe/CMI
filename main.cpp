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
    if (T < 1 || T > 50){
        exit(1);
    }
    for (int i = 0; i < T; ++i) {
        int N = 0;
        cin >> N;
        if (N > 100000){
            exit(1);
        }
        IloscBudynkow.push_back(N);
        for (int j = 0; j < N; ++j) {
            int pietro;
            cin >> pietro;
            if (pietro < 0 || pietro > 500000000){
                exit(1);
            }
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
        if (ilosc == 0){
            cout << "NIE" << "\n";
        } else {
            cout << ilosc << "\n";
        }
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
    for(int j = high - j; j > low; j--){
        int a = koglomerat[j];
        if(a == 0){
            if(koglomerat[j + 1] != 0 && koglomerat[j - 1] != 0 && j + 1 < high){
                return -1;
                break;
            }
        }
    }
    int maxElement = *max_element(koglomerat.begin(), koglomerat.begin() + high);
    vector<int>::iterator i = max_element(koglomerat.begin(), koglomerat.begin() + high);
    int indexMaxElement = distance(koglomerat.begin(), i);

    for (int k = indexMaxElement - 1; k > low + 1; --k) {
        if (koglomerat[k - 1] > koglomerat[k] || koglomerat[k] > koglomerat[k + 1]){
            return -1;
            break;
        }
    }
    for (int k = indexMaxElement + 1; k < high - 1; ++k) {
        if (koglomerat[k - 1] < koglomerat[k] || koglomerat[k]  < koglomerat[k + 1]){
            return -1;
            break;
        }
    }
    return 0;
}
