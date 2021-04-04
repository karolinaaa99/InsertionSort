#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void init(int tab[], int n) //funkcja zapełniająca tablicę tab o rozmiarze n losowymi licbami
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 100 + 1; //zapelniam tablice liczbami losowymi z przedzialu <1, 100>
	}
}

void print(int tab[], int n) //funkcja do wyświetlenia danych z tablicy
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
}

void sort(int tab[], int n) //sortowanie przez proste wstawianie, insertionsort
{
	// ZADEKLAROWANIE ZMIENNEJ POMOCNICZEJ NA PRZECHOWYWANIE WARTOSCI AKTUALNEJ CYFRY
		int x, k;
	// PETLA PRZECHODZACA PO INDEKSACH OD 1 DO 'N' TABLICY CYFR
	for (int i = 1; i < n; i++)
	{
		// ZMIENNEJ POMOCNICZEJ PRZYPISUJEMY WARTOSC CYFRY O AKTUALNYM INDEKSIE
			x = tab[i];
		// SZUKAMY MIEJSCA WSROD POPRZEDZAJACYCH AKTUALNY INDEKS CYFR W KTORYM KOLEJNA Z CYFR BEDZIE WIEKSZA OD TEJ O AKTUALNYM INDEKSIE I TUZ ZA NIA WSTAWIAMY DANA CYFRE
			for (k = i - 1; k >= 0; k--)
			{
				if (x < tab[k])
				{
					tab[k + 1] = tab[k];
				}
				else
					break;
			}
		tab[k + 1] = x;
	}

}


int main()
{
	cout << "InsertionSort" << endl;
	cout << "***************" << endl;

	int n;
	clock_t poczatek;
	clock_t koniec;
	double wynik;

	srand(time(NULL));
	cout << endl;

	poczatek = clock();

	cout << "Podaj ile liczb chcesz posortowac n = ";
	cin >> n;
	cout << endl;

	int* tab = new int[n];

	//zapelniam tablice
	init(tab, n);

	cout << "Zawartosc tablicy przed sortowaniem:"<<endl;
	print(tab, n);
	cout << endl;

	//wywoluje algorytm sortowania przez proste wstawianie, insertionsort
	sort(tab, n);
	cout << endl;

	cout << "Zawartosc tablicy po sortowaniu:" << endl;
	print(tab, n);
	cout << endl;

	koniec = clock();
	wynik = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << endl;

	cout << "Czas dzialania sortowania przez proste wstawianie: "<<wynik<<" sek"<<endl;


	return 0;
}