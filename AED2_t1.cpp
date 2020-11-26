//Simple implementation of a map/dictionary data structure in c++

#include <iostream>
#include <map>
#include <string>

using std::cin, 
      std::cout, 
      std::string, 
      std::map;

int main()
{

    string comando;
    string nome, tel;

    //create a map that stores strings indexed by strings
    map<string, string> m;
    map<string, string>::iterator it;

    cin >> comando;
    while (comando != "0"){

        cin >> nome;
        
        if (comando == "P")
        {
            /* pesquisar por um contato */
            it = m.find(nome);
            if (it != m.end())
            {
                cout << "Contatinho encontrado: telefone " << m[nome] << "\n";
            }
            else
            {
                cout << "Contatinho nao encontrado\n";
            }
            
        }
        
        else if (comando == "R")
        {
            it = m.find(nome);
            if (it != m.end())
            {
                m.erase (it);
            }
            else 
            {
                cout << "Operacao invalida: contatinho nao encontrado\n";
            }
        }
        
        if (comando == "I")
        {
            cin >> tel;

            it = m.find(nome);
            if (it != m.end())
            {
                cout << "Contatinho ja inserido\n";
            }
            else 
            {
                m[nome] = tel;
            }
        }

        else if (comando == "A")
        {
            cin >> tel;

            it = m.find(nome);
            if (it != m.end())
            {
                m[nome] = tel;;
            }
            else
            {
            cout << "Operacao invalida: contatinho nao encontrado\n";
            }
        }
        
        /* 
        cout << "cmd - " << comando << "\n";
        cout << "nome - " << nome << "\n";
        cout << "tel - " << tel << "\n";
        */
        cin >> comando;
    }
    
    return 0;
}