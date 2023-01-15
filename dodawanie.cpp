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
    return liczba + przechowalnia + err;
}
string liczbaNaSlowa(int liczba){
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
string jednosci[10] = {"", " jeden", " dwa", " trzy", " cztery", " piec", " szesc", " siedem", " osiem", " dziewiec"};
string nascie[10] = {"dziesiec", " jedenascie", " dwanascie", " trzynascie", " czternascie", " pietnascie", " szesnascie", " siedemnascie", " osiemnascie", " dziewietnascie"};
string dziesiatki[10] ={"", " dziesiec", " dwadziescia", " trzydziesci", " czterdziesci", " piecdziesiat", " szescdziesiat", " siedemdziesiat", " osiemdziesiat", " dziewiecdziesiat"};
string setki[10] = {"", " sto", " dwiescie", " trzysta", " czterysta", " piecset", " szescset", " siedemset", " osiemset", " dziewiecset"};
string duze[8] = {"", " tysiac", " tysiace", " tysiecy", " milion", " milionow", " miliony"," miliard."};

string      slownie = " ";
long long        liczba;
int     koncowka;
int     rzad = 0;
int     j = 0;
long long elo;
cout<<1000000 %10;

do{

cin>>liczba;
 

if (liczba==0) slownie="zero";
while (liczba > 1000)
{
liczba= liczba / 1000;
if (liczba > 1 && liczba < 5) slownie = duze[2] + slownie;
if (liczba >= 5) slownie = duze[3] + slownie;
if (koncowka%10 != 0) slownie =jednosci[koncowka] + slownie;
    
}



while (liczba>0)
{
koncowka=(liczba%10);
liczba/=10; //liczba = liczba / 10
if ((j==0)&&(liczba%100!=0 || koncowka!=0)) slownie=duze[rzad]+slownie;
if ((j==0)&&(liczba%10!=1)) slownie=jednosci[koncowka]+slownie;
if ((j==0)&&(liczba%10==1))

{
slownie=nascie[koncowka];
liczba/=10;
j+=2;
continue;
}
if (j==1) slownie=dziesiatki[koncowka]+slownie;
if (j==2)
{
slownie=setki[koncowka]+slownie;
j=-1;
rzad++;
}
j++;
}
cout<<slownie;

   rzad = 0;
   j = 0;
   slownie = " ";

}while(liczba > 0);

return 0;
}


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
