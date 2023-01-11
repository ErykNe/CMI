#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

const char* jednosci[10] = {"", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
const char* nascie[10] = {"dziesiec", " jedenascie", " dwanascie", " trzynascie", " czternascie", " pietnascie", " szesnascie", " siedemnascie", " osiemnascie", " dziewietnascie"};
const char* dziesiatki[10] ={"", " dziesiec", " dwadziescia", " trzydziesci", " czterdziesci", " piecdziesiat", " szescdziesiat", " siedemdziesiat", " osiemdziesiat", " dziewiecdziesiat"};
const char* setki[10] = {"", " sto", " dwiescie", " trzysta", " czterysta", " piecset", " szescset", " siedemset", " osiemset", " dziewiecset"};
const char* x[7] = {"", " tysiecy", " milionow", " tysiace", " miliony", " tysiac", " milion"};

using namespace std;

vector<pair<string, string> > pary = {}; //para - typ danych ktory przechowuje dwie dane i tylko dwie, utworzylem z nich vector ktory przechowuje pary

int slowaNaLiczbe(string slowo);
string liczbaNaSlowa(int liczba);
void algorytm();
void RemoveWordFromLine(std::string &line, const std::string &word);

int main() {
    int t = 0; //narazie int, dopóki nie mamy konwertera
    cin >> t;
    for (int i = 0; i < t; ++i) {


        string liczba;
        getline(std::cin >> std::ws, liczba);
        string liczba2;
        getline(std::cin >> std::ws, liczba2);
        pair<string, string> para;
        para.first = liczba;
        para.second = liczba2;

        pary.push_back(para); //dodaje pare do vectora
    }

    for (pair para : pary) {
        cout << para.first << " " << para.second << " ; "; //kontrolnie pokazuje vector z danymi
    }

    algorytm();

    return 0;
}
int slowaNaLiczbe(string slowo) {
    int liczba = 0;
    int a = 1;
    string s = slowo.substr(0, 10);
    while (true) {
        if (slowo.find(jednosci[a]) != string::npos) {
            liczba += a;
            RemoveWordFromLine(slowo, jednosci[a]);
            break;
        }
        if (a == 10) {
            break;
        }
        a++;
    }
    int b = 10;
    while (true) {
        if (slowo.find(nascie[b / 10]) != string::npos) {
            liczba += b;
            break;
        }
        if (b == 110) {
            break;
        }
        b += 10;
    }
    int c = 100;
    while (true) {
        if (slowo.find(nascie[b / 100]) != string::npos) {
            liczba += c;
            break;
        }
        if (c == 1100) {
            break;
        }
        c += 100;
    }
        int d = 1000;

        if (slowo.find(nascie[1]) != string::npos && slowo.find(nascie[3]) != string::npos &&
            slowo.find(nascie[5]) != string::npos) {
            int a = 1;
            while (true) {
                if (s.find(jednosci[a]) != string::npos) {
                    d *= a;
                    liczba += d;
                    break;
                }
                if (a == 11) {
                    liczba += d;
                }
                a++;
            }
        }

        return liczba;

}
string liczbaNaSlowa(int liczba){



}
void algorytm(){
    for (pair para : pary) {
        int liczba = slowaNaLiczbe(para.first);
        int liczba2 = slowaNaLiczbe(para.second);
        string sumaNapis = liczbaNaSlowa(liczba + liczba2);
        cout << sumaNapis << "\n";
    }
}
void RemoveWordFromLine(std::string &line, const std::string &word){
    auto n = line.find(word);
    if (n != std::string::npos)
    {
        line.erase(n, word.length());
    }
}
