//zamiana liczby na slowa
//Tomasz Lubinski (c)2019
//www.algorytm.org

#include <stdio.h>
#include <string.h>

const char* jednosci[10] = {"", " jeden", " dwa", " trzy", " cztery", " piec", " szesc", " siedem", " osiem", " dziewiec"};
const char* nascie[10] = {"dziesiec", " jedenascie", " dwanascie", " trzynascie", " czternascie", " pietnascie", " szesnascie", " siedemnascie", " osiemnascie", " dziewietnascie"};
const char* dziesiatki[10] ={"", " dziesiec", " dwadziescia", " trzydziesci", " czterdziesci", " piecdziesiat", " szescdziesiat", " siedemdziesiat", " osiemdziesiat", " dziewiecdziesiat"};
const char* setki[10] = {"", " sto", " dwiescie", " trzysta", " czterysta", " piecset", " szescset", " siedemset", " osiemset", " dziewiecset"};
const char* x[7] = {"", " tys.", " mln.", " mld.", " bln.", " bld.", " try."};

//Dodaje stringa add z przodu stringa str
void prepend(char *str, const char *add)
{
   char tmp[1024];
   strcpy(tmp, str); //skopiuj wartosc str do bufora tymczasowego
   strcpy(str, add); //skopiuj add do str
   strcat(str, tmp); //dodaj dotychczasowa wartosc str z bufora tymczasowego
}

int main()
{
char      slownie[1024];
long long liczba;
int     koncowka;
int     rzad = 0;
int     j = 0;
int     minus = 0;

printf("Podaj liczbe do zamiany na slowa\n");
scanf("%lld",&liczba);

if (liczba<0)
{
        minus=1;
        liczba=-liczba;
}

slownie[0] = 0;
if (liczba==0) strcat(slownie, "zero");

while (liczba>0)
{
        koncowka=(liczba%10);
        liczba/=10;
        if ((j==0)&&(liczba%100!=0 || koncowka!=0)) prepend(slownie, x[rzad]);
        if ((j==0)&&(liczba%10!=1)) prepend(slownie, jednosci[koncowka]);
        if ((j==0)&&(liczba%10==1))
        {
                prepend(slownie, nascie[koncowka]);
                liczba/=10;
                j+=2;
                continue;
        }
        if (j==1) prepend(slownie, dziesiatki[koncowka]);
        if (j==2)
        {
                prepend(slownie, setki[koncowka]);
                j=-1;
                rzad++;
        }
        j++;
}

if (minus==1) prepend(slownie, "minus");

printf("\nOdpowiedz:\n");
printf("%s", slownie);

}

