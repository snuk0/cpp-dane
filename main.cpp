#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct uczen
{
        string numer, imie, nazwisko, pesel, adres;
};

class klasa
{
                vector <uczen> spis;
        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);
};

void klasa::wypisz()
{
        for (auto it : spis)
        {
                cout << it.numer << " "
                         << it.imie << " "
                         << it.nazwisko << " "
                         << it.pesel << " "
                         << it.adres << "\n";
        }
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open("b.txt");
        string imie = imie;
        string nazwisko = nazwisko;
        for (auto it : spis)
        {
                char x = '#'-1;
                plik <<
                         " { \n" << "   " << x << "numer" << x << ":" << x << it.numer << x << "\n"
                                 << "   " << x << "imie" << x << ":" << x << it.imie << x << "\n"
                                 << "   " << x << "nazwisko" << x << ":" << x << it.nazwisko << x << "\n"
                                 << "   " << x << "pesel" << x << ":" << x << it.pesel << x << "\n"
                                 << "   " << x << "imie" << x << ":" << x << it.adres << x << "\n}";

                    plik << ",";
                plik << "\n";

        }
        plik.close();
}

void klasa::wczytajZPliku(const char *nazwa)
{
        string napis;
        fstream plik2("a.txt", ios::in);
        getline(plik2, napis);

        while(napis != "")
        {
                vector <string> v;
                string x = "";
                for(int i = 0; i <= napis.size(); i++)
                {
                        if(i == napis.size())
                                v.push_back(x);
                        else
                        {
                                if(napis[i] == ' ' && x != " ")
                                {
                                        v.push_back(x);
                                        x = "";
                                }
                                else if(napis[i] != ' ')
                                        x.push_back(napis[i]);
                        }
                }

                uczen wprowadz;
                wprowadz.numer = v[0];
                wprowadz.imie = v[1];
                wprowadz.nazwisko = v[2];
                wprowadz.pesel = v[3];
                wprowadz.adres = v[4];
                spis.push_back(wprowadz);

                cout << "\n";
                getline(plik2, napis);
        }
        plik2.close();

}

int main(int argc, char** argv) {
        klasa TI;
        TI.wczytajZPliku("a.txt");
        TI.wypisz();
        TI.zapiszDoPliku("b.txt");
        return 0;
}
