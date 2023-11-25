#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

    vector<int> rozmiaryDzieci;
    vector <pair <int, int>> butyWSklepie;


    int liczbaDzieci;
    cin >> liczbaDzieci;
    int liczbaParButow;
    cin >> liczbaParButow;
    for (int i = 0; i < liczbaDzieci; ++i) {
        int rozmiarDziecka;
        cin >> rozmiarDziecka;
        rozmiaryDzieci.push_back(rozmiarDziecka);
    }
    for (int i = 0; i < liczbaParButow; ++i) {
        pair <int, int> but;
        cin >> but.first;
        cin >> but.second;
        butyWSklepie.push_back(but);
    }
    sort(butyWSklepie.begin(), butyWSklepie.end());
    sort(rozmiaryDzieci.begin(), rozmiaryDzieci.end());

    int cenaZakupu = 0;
    for (int i = 0; i < rozmiaryDzieci.size(); ++i) {
        int rozmiar = rozmiaryDzieci[i];
        for (int j = 0; j < butyWSklepie.size(); ++j) {
            if(rozmiar == butyWSklepie[j].first){
                cenaZakupu += butyWSklepie[j].second;
                rozmiaryDzieci[i] = -1;
                butyWSklepie[j].first = -1;
                butyWSklepie[j].second = -1;
                break;
            }
            if(j == butyWSklepie.size() - 1){
                cout << "NIE";
                exit(0);
            }
        }
    }

    cout << cenaZakupu;

    return 0;
}
