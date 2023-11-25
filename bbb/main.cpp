#include <iostream>

using namespace std;

int iloczyn(int a, int b){
    int iloczyn = 0;
    while (b > 0) {
        if (b % 2 != 0) {
            iloczyn += a;
        }
        a <<= 1; //przesunięcie bitowe
        b >>= 1;
    }
    return iloczyn;
    //mnożenie rosyjskich chłopów
}
string DuuuzeLiczby(string a, string b){
    string wynik = "";
    int wPamieci = 0;
    int sum = 0;
    if (a.length() != b.length()){
        if (a.length() > b.length()) {
            for (int j = b.length(); j <= a.length() - 1; ++j) {
                b.insert(0, "0");
            }
        } else{
            for (int j = a.length(); j <= b.length() - 1; ++j) {
                a.insert(0, "0");
            }
        }
    }
    for (int i = 1; i <= a.length(); ++i) {
        int x = (int)a[a.length() - i] - '0';
        int y = (int)b[a.length() - i] - '0';
        sum = x + y + wPamieci;
        if (sum >= 10){
            wPamieci = 1;
            sum = sum % 10;
            wynik = to_string(sum) + wynik;
        } else{
            wynik = to_string(sum) + wynik;
        }
    }
    if(wPamieci != 0){
        wynik = to_string(wPamieci) + wynik;
    }
    return wynik;
};
void przemnóżDuużeLiczby (string a, string b){ //z.d
    // Algorytm Karacuby
}
int pow(int a, int n){
    int sum = a;
    int skladnik = a;
    if (n == 0){
        return 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < a; ++j) {
            skladnik += sum;
        }
        sum = skladnik;
    }
    return skladnik; //unikamy mnożenia, bo jest too expensive
}
int main() {
    cout << iloczyn(12, 12) << endl;
    cout << pow(3, 3) << endl;
    string gowno = "a";
    cout << DuuuzeLiczby("1", "22") << endl;
    return 0;
}
