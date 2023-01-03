#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

const char* jednosci[10] = {"", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
const char* nascie[10] = {"dziesiec", " jedenascie", " dwanascie", " trzynascie", " czternascie", " pietnascie", " szesnascie", " siedemnascie", " osiemnascie", " dziewietnascie"};
const char* dziesiatki[10] ={"", " dziesiec", " dwadziescia", " trzydziesci", " czterdziesci", " piecdziesiat", " szescdziesiat", " siedemdziesiat", " osiemdziesiat", " dziewiecdziesiat"};
const char* setki[10] = {"", " sto", " dwiescie", " trzysta", " czterysta", " piecset", " szescset", " siedemset", " osiemset", " dziewiecset"};
const char* x[7] = {"", " tys.", " mln.", " mld.", " bln.", " bld.", " try."};

using namespace std;

vector<pair<string, string>> pary = {}; //para - typ danych ktory przechowuje dwie dane i tylko dwie, utworzylem z nich vector ktory przechowuje pary

int main() {
    int t = 0; //narazie int, dopóki nie mamy konwertera
    cin >> t;
    for (int i = 0; i < t; ++i) {

        string liczba;
        cin >> liczba;
        string liczba2;
        cin >> liczba2;
        pair<string, string> para;
        para.first = liczba;
        para.second = liczba2;

        pary.push_back(para); //dodaje pare do vectora
    }

    for (pair para : pary) {
        cout << para.first << " " << para.second << " ; "; //kontrolnie pokazuje vector z danymi
    }
    return 0;
}
