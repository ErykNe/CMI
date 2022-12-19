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
        int ilosc = znajdzNajwiekszaLiczbe(0, IloscBudynkow[i]); //znajdz najwieksza liczbe
        cout << ilosc << "\n";
        for (int j = 0; j < IloscBudynkow[i]; ++j) {
            koglomerat.erase(koglomerat.begin());
        }
    }
}
int znajdzNajwiekszaLiczbe(int low, int high){
    int maxElement = *max_element(koglomerat.begin(), koglomerat.end());
    return maxElement;
}
