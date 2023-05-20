#include <iostream>
#include<iomanip>
#include<windows.h>
#define colo 10
#define p 0
#define righe 2
#define alu 1

using namespace std;


void queque(int registro[][10], int r, int c, int prcs, int durata)//inserisco un solo processo nuovo in coda
{
    int i, x;

    for (x = 0; x < c; x++)
    {
        if (registro[1][x] == 0)
        {
            registro[0][x] = prcs;
            registro[1][x] = durata;
            break;
        }



    }

}

void ordina(int coda[][10], int r, int c)//ordino tutti i processi maggiori di zero
{
    int i, x, app;

    i = 0;
    while (i < c)
    {
        x = 0;
        while (x < c - 1)
        {
            if ((coda[1][x] > coda[1][x + 1]) && (coda[1][x] > 0))
            {
                app = coda[1][x];
                coda[1][x] = coda[1][x + 1];
                coda[1][x + 1] = app;

                app = coda[0][x];
                coda[0][x] = coda[0][x + 1];
                coda[0][x + 1] = app;
            }
            x++;
        }
        i++;
    }
}

void visualizza(int coda[][10], int r, int c)
{
    int x;
    cout << "Processo numero" << "   Tempo stimato" << endl;

    for (x = 0; x < c; x++)
    {
        cout << coda[0][x] << setw(18) << coda[1][x] << endl;
    }
}

int fetch(int coda[][10], int r, int c)//individuo il primo processo maggiore di zero e ne raccolgo l'istruction pointer da passare alla cpu
{
    int i, x, pos;

    i = 0;
    while (i <= c)
    {
        if (coda[0][i] > 0)
        {
            pos = i;
            break;
        }
        i++;
    }

    return pos;
}

void exe(int coda[][10], int r, int c, int cp[][1], int ri, int co)//acquisisco il primo valore della coda ordinata e gli sottraggo un secondo
{                                                                 //posso usare la funzione fetch per raccogliere l'indice del processo e caricare                            
    int i, pos;                                                   //la cpu direttamente in quella funzione(POCHE MODIFICHE IN MAIN E VOID EXE)

    for (i = 0; i < c; i++)
    {
        if (coda[1][i] > 0)
        {
            cp[0][0] = coda[0][i];
            cp[1][0] = coda[1][i];
            pos = cp[1][0];
            pos--;
            coda[1][i] = pos;
            break;
        }
    }

}



int main()
{
    int coda[2][10], cpu[2][1];
    int i, x, tempo, sce, posizione;
    int pn = 1000;

    srand(time(NULL));

    for (i = 0; i < righe; i++)
    {
        for (x = 0; x < colo; x++)
        {
            coda[i][x] = 0;
        }
    }

    do
    {
        cout << "1. Step into" << endl;
        cout << "0. Arresta il sistema" << endl;
        cin >> sce;

        tempo = rand() % 20;
        queque(coda, righe, colo, pn, tempo);
        //visualizza(coda, righe, colo);
        pn++;
        ordina(coda, righe, colo);
        visualizza(coda, righe, colo);
        //posizione=fetch(coda, righe, colo);
        exe(coda, righe, colo, cpu, righe, alu);


    } while (sce != 0);


    return 0;
}


