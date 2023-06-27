#include <iostream>
#include <time.h>

 

#define CLEAR_COMMAND "CLS"

 

using namespace std;

 

int mostrarMenu();
void definirPerguntas();
void jogarRonda();

 

struct perguntas{
    int correta;
    string pergunta,resposta1,resposta2,resposta3;
}p[5];

 

int main(){
    definirPerguntas();
    while(true){
        int decisaoMenu = mostrarMenu();
        if(decisaoMenu == 0){
            return 0;
        }
    }
}
int mostrarMenu(){
    int estado = system("clear");
    if(estado == -1){
        mostrarMenu();
    }
    int decisao = 0;
    cout<<"Menu:"<<endl;
    cout<<"1) Jogar Ronda"<<endl;
    cout<<"2) Sair"<<endl;
    cin>>decisao;
    switch(decisao){
        case 1:
        estado = system("CLS");
        if(estado == -1){
            mostrarMenu();
        }
        jogarRonda();
        break;
        case 2:
        return 0;
        break;
        default:
        mostrarMenu();
        break;
    }
    return 0;
}
void definirPerguntas(){
    p[0].pergunta = "Em que ano chegou o homem á lua?";
    p[0].resposta1 = "1) 1969";
    p[0].resposta2 = "2) 1978";
    p[0].resposta3 = "3) 1965";
    p[0].correta = 1;

    p[1].pergunta = "Como era conhecida a Primeira Guerra Mundial antes de se estabelecer a Segunda?";
    p[1].resposta1 = "1) A Guerra Mundial.";
    p[1].resposta2 = "2) A Grande Guerra.";
    p[1].resposta3 = "3) Nenhuma das anteriores.";
    p[1].correta = 2;

    p[2].pergunta = "Que país está entre  o Peru e a Colombia?";
    p[2].resposta1 = "1) Mexico.";
    p[2].resposta2 = "2) Venezuela.";
    p[2].resposta3 = "3) Equador.";
    p[2].correta = 3;

    p[3].pergunta = "Qual país do mundo tem a maior população?";
    p[3].resposta1 = "1) China.";
    p[3].resposta2 = "2) Russia.";
    p[3].resposta3 = "3) Japão.";
    p[3].correta = 1;

    p[4].pergunta = "Quem era o Pelé?";
    p[4].resposta1 = "1) Jogador de basket.";
    p[4].resposta2 = "2) Jogador de futebol.";
    p[4].resposta3 = "3) Jogador de tennis.";
    p[4].correta = 2;
}
void jogarRonda(){
    int pontuacao = 0;
    srand((unsigned)time(0));
    int id, idA[5];
    bool rep = false;
    for(int i = 0; i < 5;i++){
        do{
            rep = false;
            id = rand()%(4-0+1)+0;
            for(int j = 0; j < i; j++){
                if(id == idA[j]){
                    rep = true;
                }
            }
        }while(rep);

 

        idA[i] = id;
        int resposta;
        cout<<p[id].pergunta<<endl;
        cout<<p[id].resposta1<<endl;
        cout<<p[id].resposta2<<endl;
        cout<<p[id].resposta3<<endl;
        cin>>resposta;
        if(resposta == p[id].correta){
            cout<<"Correto"<<endl;
            pontuacao += 10;
        }else{
            cout<<"Incorreto"<<endl;
            cout<<"A resposta correta é a: "<<p[id].correta<<endl;
        }
        char decisao;
        cout<<"Deseja continuar s/n"<<endl;
        cin>>decisao;
        if(decisao != 's'){
            cout<<"A tua pontuacao é  "<<pontuacao<<"/"<<(i+1)*10<<endl;
            return;
        }
        int estado = system("CLS");
        if(estado == -1){
            jogarRonda();
        }
    }
    cout<<"A Tua pontuacao é "<<pontuacao<<"/50"<<endl;
    return;

}