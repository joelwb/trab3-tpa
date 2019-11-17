/*
Autor: Nicolas Pereira Sampaio
Deve-se descobrir se a coleção de cds da jill possui cds repetidos com a coleção de cds do jack
*/


#include <iostream>
#include <set>

using namespace std;

int main()
{
    while (true)
    {
        int qntJack;
        int qntJill;
        int qntRepetidos = 0;
        cin >> qntJack >> qntJill;
        if (qntJack + qntJill == 0)
        {
            break;
        }

        int item;
        set<int> cdsJack;
        for (int i = 0; i < qntJack; i++)
        {
            cin >> item;
            cdsJack.insert(item);
        }

        for (int i = 0; i < qntJill; i++)
        {
            cin >> item;
            if (cdsJack.find(item) != cdsJack.end())
            {
                qntRepetidos++;
            }
        }

        cout << qntRepetidos << endl;
    }
}