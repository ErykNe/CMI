#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

const char* jednosci[10] = {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
const char* nascie[10] = {"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
const char* dziesiatki[10] ={"", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
const char* setki[10] = {"", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};
const char* x[7] = {"", "tysiecy", "milionow", "tysiace", "miliony", "tysiac", "milion"};

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
int main() {
    int liczba = 900000100;
    string liczbaNapis = liczbaNaSlowa(liczba);
    cout << liczbaNapis;
    return 0;
}
