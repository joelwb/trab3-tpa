/*
Autor: Nicolas Pereira Sampaio
Deve-se descobrir se é possível colocar o trem em ordem de acordo com a chegada
*/


#include <iostream>
#include <stack>
using namespace std;

int main()
{
    while (true)
    {
        int qntVagao, valor;
        stack<int> pilha;
        cin >> qntVagao;
        if (qntVagao == 0)
            break;
        while (true)
        {
            while (!pilha.empty())
            {
                pilha.pop();
            }
            int comp = 0;
            for (int i = 0; i < qntVagao; i++)
            {
                cin >> valor;
                if (valor == 0)
                    break;

                while (comp < qntVagao && comp != valor)
                {
                    if (!pilha.empty() && pilha.top() == valor)
                    {
                        break;
                    }
                    comp++;
                    pilha.push(comp);
                }
                if (pilha.top() == valor)
                {
                    pilha.pop();
                }
            }
            if (valor == 0)
            {
                printf("\n");
                break;
            }
            if (pilha.empty())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}