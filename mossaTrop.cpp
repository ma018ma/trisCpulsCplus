#include <iostream>

using namespace std;

void stampa(char *tab)
{
    for (int i = 0; i < 9; i++)
    {
        cout << tab[i] << " ";
        if (i == 2 || i == 5 || i == 8) // alla fine di ogni riga (3x3) vai a capo
        {
            cout << endl;
        }
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    int risultato = -1;
    char vuoto = '_';

    // inizializzo la tab
    char tab[9];
    for (int i = 0; i < 9; i++)
    {
        tab[i] = vuoto;
    }
    stampa(tab);



    tab[0] = 'X';
    tab[3] = 'X';
    tab[6] = 'O';

    stampa(tab);

    // QUI LAVORO

    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};
        // prima riga orizzontale
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][2];// posizione 2 per non perdere
        }
    }

    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = c == b && a == vuoto && c == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][0];// posizione 0 per non perdere
        }
    }
        for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i][0]];
        char b = tab[combinazioni[i][1]];
        char c = tab[combinazioni[i][2]];

        bool condizione = a == c && b == vuoto && c == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][1];// posizione 1 per non perdere
        }
    }// seconda riga orizzontale
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i+1][0]];
        char b = tab[combinazioni[i+1][1]];
        char c = tab[combinazioni[i+1][2]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i+1][2];// posizione 5 per non perdere
        }
    }
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i+1][0]];
        char b = tab[combinazioni[i+1][1]];
        char c = tab[combinazioni[i+1][2]];

        bool condizione = b == c && a == vuoto && b == 'X';

        if (condizione)
        {
            risultato = combinazioni[i+1][0];// posizione 3 per non perdere
        }
    }
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i+1][0]];
        char b = tab[combinazioni[i+1][1]];
        char c = tab[combinazioni[i+1][2]];

        bool condizione = a == c && b == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i+1][1];// posizione 4 per non perdere
        }
    }
    //terza riga orizzontale
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i+2][0]];
        char b = tab[combinazioni[i+2][1]];
        char c = tab[combinazioni[i+2][2]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i+2][2];// posizione 8 per non perdere
        }
    }
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i+2][0]];
        char b = tab[combinazioni[i+2][1]];
        char c = tab[combinazioni[i+2][2]];

        bool condizione = b == c && a == vuoto && b == 'X';

        if (condizione)
        {
            risultato = combinazioni[i+2][0];// posizione 6 per non perdere
        }
    }
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[i+2][0]];
        char b = tab[combinazioni[i+2][1]];
        char c = tab[combinazioni[i+2][2]];

        bool condizione = a == c && b == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i+2][1];// posizione 7 per non perdere
        }
    }
    //prima riga verticale
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[0][i]];
        char b = tab[combinazioni[1][i+3]];
        char c = tab[combinazioni[2][i+3]];

        bool condizione = b == c && a == vuoto && b == 'X';

        if (condizione)
        {
            risultato = combinazioni[b][i];// posizione 0 per non perdere
        }
    }
    //seconda riga verticale
    for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[0][i]];
        char b = tab[combinazioni[1][i+3]];
        char c = tab[combinazioni[2][i+3]];

        bool condizione = a == c && b == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[a][i+3];// posizione 3 per non perdere
        }
    }
    //terza riga verticale
        for (int i = 0; i < 8; i++)
    {
        char a = tab[combinazioni[0][i]];
        char b = tab[combinazioni[1][i+3]];
        char c = tab[combinazioni[2][i+3]];

        bool condizione = a == b && c == vuoto && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[a][i+3];// posizione 6 per non perdere
        }
    }
    //diagonale 0-4-8
    
    //diagonale 2-4-6


    cout << "risultato ottenuto: " << risultato << " | risultato atteso: 1" << endl;
}