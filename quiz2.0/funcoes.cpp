#include <iostream>

#include <fstream>

#include <string>

#include <limits>




using namespace std;




struct User {

    string username;

    string password;

    string name;

};





void signUp() {

    User user;

    cout << "Digite o nome de usuário: ";

    cin >> user.username;

    cout << "Digite a senha: ";

    cin >> user.password;

    cout << "Digite o nome completo: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, user.name);




    ofstream outfile("usuarios.txt", ios::app);

    outfile << user.username << " " << user.password << " " << user.name << endl;

    outfile.close();




    cout << "Registro concluído com sucesso!\n";

}




bool login(string& loggedInUsername, string& loggedInName) {

    User user;

    cout << "Digite o nome de usuário: ";

    cin >> user.username;

    cout << "Digite a senha: ";

    cin >> user.password;




    ifstream infile("usuarios.txt");

    string username, password, name;

    while (infile >> username >> password >> name) {

        if (username == user.username && password == user.password) {

            infile.close();

            loggedInUsername = user.username;

            loggedInName = name;

         

   




            return true;

        }

    }

    infile.close();

    cout << "Nome de usuário ou senha inválidos.\n";

   

    return false;

}