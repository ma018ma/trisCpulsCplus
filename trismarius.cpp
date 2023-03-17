#include <iostream>

using namespace std;

// 1 per la vittoria
// 0 per continuare la partita
// -1 per il pareggio
int isWinner(char *arr)
{
    char vuoto = '_';

    // _ _ _   _ _ _   _ _ _
    // 0 1 2  3 4 5   6 74

    for (int i = 0; i < 9; i += 3)
    {
        if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]) && arr[i] != vuoto) // ho tre x vicine
        {
            return 1; // hai vinto quindi 1
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if ((arr[i] == arr[i + 3]) && (arr[i + 3] == arr[i + 6]) && arr[i] != vuoto) // ho tre x in colonna
        {
            return 1; // hai vinto quindi 1
        }
    }
    // se li ho trovati in diagonale hai vinto =1
    if ((arr[0] == arr[4] && arr[4] == arr[8]) && arr[0] != vuoto)
    {
        return 1;
    }
    if ((arr[2] == arr[4] && arr[4] == arr[6]) && arr[2] != vuoto)
    {
        return 1;
    }
    // // se non ho trovato nulla pareggio = -1
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == vuoto)
        {
            return 0;
        }
    }
    // pareggio
    return -1;
}
int mossaTop (char *tab)
{
    int risultato = -1;
    char vuoto = '_';

    // inizializzo la tab
   // char tab[9];
    for (int i = 0; i < 9; i++)
    {
        tab[i] = vuoto;
    }


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
    return -1;
}

void stampa(char *tabella)
{
    for (int i = 0; i < 9; i++)
    {
        cout << tabella[i] << " ";
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
    char vuoto = '_';
    // inizializzo la tabella
    char tabella[9];
    for (int i = 0; i < 9; i++)
    {
        tabella[i] = vuoto;
    }
    stampa(tabella);
    bool xIsNext = true; // gestisce il turno
    while (true)         // i turni del gioco
    {
        int mossa;
        if (!xIsNext)
        {   int contatore = 0;
            mossa = rand() % 10;
            contatore ++;
            if (contatore > 0){
            mossaTop(tabella);   
            }
        }
        else
        {
            cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
            cin >> mossa;
            mossa--; // per capirci ;)

            while (tabella[mossa] != vuoto || (!(0 <= mossa && mossa < 9))) // controllo 2 condizioni (valido e vuoto)
            {
                cout << "Non puoi inserire qui" << endl;
                cout << "Giocatore " << (xIsNext ? 'X' : 'O') << " inserisci la tua mossa (1-9) ";
                cin >> mossa;
                mossa--; // per capirci ;)
            }
        }
        // se sono arrivato qui è solo perchè l'utente ha inserito un numero corretto
        xIsNext ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // se è vero metti X altrimenti metti O
        stampa(tabella);
        if (isWinner(tabella) == 1)
        {
            cout << "Hai vinto " << (xIsNext ? 'X' : 'O') << endl;
            break;
        }
        else if (isWinner(tabella) == -1)
        {
            cout << "Pareggio" << endl;
            // reset del gioco
            for (int i = 0; i < 9; i++)
            {
                tabella[i] = vuoto;
            }
            xIsNext = true;
            stampa(tabella);
        }
        else if (isWinner(tabella) == 0)
        {
            xIsNext = !xIsNext; // cambio giocatore
        }
        else
        {
            cout << "Errore nella funzione isWinner" << endl;
        }
    }
}
