#include <iostream>
#include <vector>
//ANDAKDBADA
using namespace std;

vector<int> koglomerat;
vector<int> IloscBudynkow;
int T = 0; //ile zestawow budynkow jest
int licznik; //ilość wyburzeń

void alg();
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
    
}
