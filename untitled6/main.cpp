#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

const char* jednosci[10] = {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
const char* nascie[10] = {"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
const char* dziesiatki[10] ={"", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
const char* setki[10] = {"", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};
const char* x[7] = {"", "tysiecy", "milionow", "tysiace", "miliony", "tysiac", "milion"};

using namespace std;

vector<pair<string, string> > pary = {}; //para - typ danych ktory przechowuje dwie dane i tylko dwie, utworzylem z nich vector ktory przechowuje pary

int slowaNaLiczbe(string slowo);
string liczbaNaSlowa(int liczba);
void algorytm();
void RemoveWordFromLine(std::string &line, const std::string &word);

int main() {
    string s;
    cin >> s;
    int t = slowaNaLiczbe(s);
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

   /* for (pair para : pary) {
        cout << para.first << " " << para.second << " ; "; //kontrolnie pokazuje vector z danymi
    }*/

    algorytm();

    return 0;
}
int slowaNaLiczbe(string slowo) {
    if (slowo == "zero"){
        return 0;
    }
    if (slowo == "miliard"){
        return 1000000000;
    }
    if (slowo == "milion tysiac"){
        return 1001000;
    }
    int liczba = 0;
    int przechowalnia = 0;
    int err = 0;
    int kurwaZabijMnie = 0;
    while (!slowo.empty()) {
        string s;
        s = slowo.substr(0, slowo.find(' '));
        int a = 1;
        while (true) {
            if (s == "milion"){
                err += 1000000;
                RemoveWordFromLine(slowo, "milion");
                if (slowo == ""){
                    return 1000000;
                }
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s == "tysiac"){
                err += 1000;
                RemoveWordFromLine(slowo, "tysiac");
                if (slowo == ""){
                    return 1000;
                }
                RemoveWordFromLine(slowo, " ");
                break;
                cout << slowo;
            }
            if (s.find("miliard") != string::npos) {
                kurwaZabijMnie += 1000000000;
                RemoveWordFromLine(slowo, "miliard");
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s.find(x[2]) != string::npos || s.find(x[4]) != string::npos) {
                przechowalnia += a * liczba * 1000000 - liczba;
                //cout << liczba << " ";
                RemoveWordFromLine(slowo, x[2]);
                RemoveWordFromLine(slowo, x[4]);
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s.find(x[1]) != string::npos || s.find(x[3]) != string::npos) {
                if (przechowalnia != 0){
                    int temp = liczba - przechowalnia/1000000 - 1;
                    liczba += a * temp * 1000 - temp;
                } else {
                    liczba += a * liczba * 1000 - liczba;
                }
                RemoveWordFromLine(slowo, x[1]);
                RemoveWordFromLine(slowo, x[3]);
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s.find(setki[a]) != string::npos) {
                liczba += a * 100;
                //cout << liczba << " ";
                RemoveWordFromLine(slowo, setki[a]);
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s.find(dziesiatki[a]) != string::npos) {
                liczba += a * 10;
                //cout << liczba << " ";
                RemoveWordFromLine(slowo, dziesiatki[a]);
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s.find(nascie[a]) != string::npos) {
                liczba += a + 10;
                //cout << liczba << " ";
                RemoveWordFromLine(slowo, nascie[a]);
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (s.find(jednosci[a]) != string::npos && (strlen(jednosci[a]) == s.length() || strlen(jednosci[a]) == s.length() - 1)) {
                liczba += a;
                RemoveWordFromLine(slowo, jednosci[a]);
                RemoveWordFromLine(slowo, " ");
                break;
            }
            if (a == 10) {
                break;
            }
            a++;
        }
    }
    return liczba + przechowalnia + err + kurwaZabijMnie;
}
string liczbaNaSlowa(int liczba){
    string slowo = "";
    int tabelka = 1;
    int czarnaRozpaczPomozMi = 1;
    if (liczba == 0){
        return "zero";
    }
    if (liczba == 2000000000){
        return "dwa miliardy";
    }
    while (liczba != 0){
        int koncowka = liczba % 10;
        int koncowkaSprawdz = liczba % 100;
        liczba /= 10;
        switch (tabelka) {
            case 1:
                if (koncowkaSprawdz < 20 & koncowkaSprawdz > 9) {
                    if (koncowka != 0) {
                        slowo = nascie[koncowka] + slowo;
                        slowo = " " + slowo;
                        liczba /= 10;
                        tabelka++;
                        break;
                    }
                } else {
                    if (koncowka != 0) {
                        slowo = jednosci[koncowka] + slowo;
                        slowo = " " + slowo;
                    }
                    break;
                }
            case 2:
                if (koncowka != 0) {
                    slowo = dziesiatki[koncowka] + slowo;
                    slowo = " " + slowo;
                }
                break;
            case 3:
                if (koncowka != 0) {
                    slowo = setki[koncowka] + slowo;
                    slowo = " " + slowo;
                }
                break;
            case 4:
                if (koncowka != 0 || koncowkaSprawdz != 0) {
                    if (koncowka == 1 && koncowkaSprawdz < 4) {


                        slowo = x[5] + slowo;
                        slowo = " " + slowo;
                        break;

                    }
                    if (koncowka >= 5 || koncowkaSprawdz < 20 && koncowkaSprawdz > 9) {

                        slowo = x[1] + slowo;
                        slowo = " " + slowo;
                        if (koncowkaSprawdz < 20 && koncowkaSprawdz > 9) {
                            slowo = nascie[koncowka] + slowo;
                            slowo = slowo;
                            slowo = " " + slowo;
                            tabelka++;
                            liczba /= 10;
                        }else {
                            slowo = jednosci[koncowka] + slowo;
                            slowo = " " + slowo;

                        }

                        break;
                    }
                    if (koncowkaSprawdz >= 20 && koncowka > 4 || koncowka < 2){
                        slowo = x[1] + slowo;
                        slowo = " " + slowo;
                        if (koncowka == 1){
                            slowo = jednosci[koncowka] + slowo;
                            slowo = " " + slowo;
                        }
                        break;
                    }
                    if (koncowka > 1 && koncowka < 5) {

                        slowo = x[3] + slowo;
                        slowo = " " + slowo;
                        if (koncowkaSprawdz < 20 & koncowkaSprawdz > 9) {
                            slowo = nascie[koncowka] + slowo;
                            slowo = " " + slowo;
                            tabelka++;
                            break;
                        } else {
                            slowo = jednosci[koncowka] + slowo;
                            slowo = slowo;
                            slowo = " " + slowo;
                            break;
                        }

                    }

                    break;
                }
            case 5:
                if (koncowka != 0) {
                    slowo = dziesiatki[koncowka] + slowo;
                    slowo = " " + slowo;
                }
                break;
            case 6:
                if (koncowka != 0) {
                    slowo = setki[koncowka] + slowo;
                    slowo = " " + slowo;
                }
                break;
            case 7:
                if (koncowka != 0 || koncowkaSprawdz != 0) {
                    if (koncowka == 1 && koncowkaSprawdz < 4) {


                        slowo = x[6] + slowo;
                        slowo = " " + slowo;
                        break;

                    }
                    if (koncowka >= 5 || koncowkaSprawdz < 20 && koncowkaSprawdz > 9) {

                        slowo = x[2] + slowo;
                        slowo = " " + slowo;
                        if (koncowkaSprawdz < 20 && koncowkaSprawdz > 9) {
                            slowo = nascie[koncowka] + slowo;
                            slowo = slowo;
                            slowo = " " + slowo;
                            tabelka++;
                            liczba /= 10;
                        }else {
                            slowo = jednosci[koncowka] + slowo;
                            slowo = " " + slowo;

                        }

                        break;
                    }
                    if (koncowkaSprawdz >= 20 && koncowka > 4 || koncowka < 2){
                        slowo = x[2] + slowo;
                        slowo = " " + slowo;
                        if (koncowka == 1){
                            slowo = jednosci[koncowka] + slowo;
                            slowo = " " + slowo;
                        }
                        break;
                    }
                    if (koncowka > 1 && koncowka < 5) {

                        slowo = x[4] + slowo;
                        slowo = " " + slowo;
                        if (koncowkaSprawdz < 20 & koncowkaSprawdz > 9) {
                            slowo = nascie[koncowka] + slowo;
                            slowo = " " + slowo;
                            tabelka++;
                            break;
                        } else {
                            slowo = jednosci[koncowka] + slowo;
                            slowo = slowo;
                            slowo = " " + slowo;
                            break;
                        }

                    }

                    break;
                } else if (liczba % 100 != 0) {
                    slowo = x[2] + slowo;
                    slowo = " " + slowo;
                    break;
                }
            case 8:
                if (koncowka != 0) {
                    slowo = dziesiatki[koncowka] + slowo;
                    slowo = " " + slowo;
                }
                break;
            case 9:
                if (koncowka != 0) {
                    slowo = setki[koncowka] + slowo;
                    slowo = " " + slowo;
                }
                break;
            case 10:
                slowo = "miliard" + slowo;
                slowo = " " + slowo;
        }
        tabelka++;
    }
    slowo = slowo.substr(1, slowo.length() - 1);
    return slowo;
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