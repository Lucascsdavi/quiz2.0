#include <iostream>

#include <fstream>

#include <string>

#include <limits>

#include "Funcoes.cpp"




using namespace std;

struct Pergunta {

    string texto;

    string opcoes[4];

    int resposta;

};





int main() {

    int choice;

    bool loggedIn = false;

    string loggedInUsername, loggedInName;




    do {

        cout << "Escolha uma opção:\n";

        cout << "1. Registrar (Sign Up)\n";

        cout << "2. Entrar (Login)\n";

        cout << "3. Sair\n";

        cout << "Digite sua escolha: ";




        while (!(cin >> choice)) {

            cout << "Opção inválida. Tente novamente.\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }




        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do teclado




        switch (choice) {

            case 1:

                signUp();

                break;

            case 2:

                loggedIn = login(loggedInUsername, loggedInName);

           

                break;

            case 3:

                cout << "Encerrando o programa.\n";

                break;

            default:

                cout << "Opção inválida. Tente novamente.\n";

                break;

        }




        if (loggedIn) {

            cout << "Login bem-sucedido!\n";

            cout << "Usuário logado: " << loggedInName << " (" << loggedInUsername << ")\n";

            loggedIn = false;

             Pergunta pergunta;

           

            // Definindo a pergunta e as opções

            pergunta.texto = "teu pai é gay?";

            pergunta.opcoes[0] = "A) sim";

            pergunta.opcoes[1] = "B) nao";

            pergunta.opcoes[2] = "C) com certeza";

            pergunta.opcoes[3] = "D) claro";

           

            // Definindo a resposta correta

            pergunta.resposta = 1;

           

            // Exibindo a pergunta e as opções

            cout << pergunta.texto << endl;

            for (int i = 0; i < 4; i++) {

                cout << pergunta.opcoes[i] << endl;

            }

       

        }




        cout << endl;

    } while (choice != 3);




    return 0;

}