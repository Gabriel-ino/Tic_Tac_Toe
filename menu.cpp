#include <iostream>
#include <locale.h>
#include <string>
#include <time.h>

#include "player.h"

using namespace std;

extern void game(Player *p1, Player *p2);
extern int about_section();
void menu();


static void config_letter_player(Player *p1, Player *p2){
    int choice_letter = rand() % 2;
    char opt[2] = {'X', 'O'};

    p1->letter = opt[choice_letter];

    switch(p1->letter){
    case 'X':
        p2->letter = 'O';
        break;
    case 'O':
        p2->letter = 'X';
    }

}

static void choose_option(int *option, Player *player, Player *player2){
    cout << "Olá, " << player->name << " e " << player2->name <<"!" << endl << "Escolham uma opção:" << endl;
    cout << "1 - Jogar" << endl << "2 - Sobre" << endl << "3 - Sair" << endl;

    cin >> *option;

    while (*option < 1 || *option > 3){
        cout << "Digite uma opção válida!";
        cin >> *option;
    }
}

static void run_option(int *option, Player *player, Player *player2){
    switch(*option){
    case 1:
        //Jogar
        game(player, player2);
        break;
    case 2:
        if (about_section() == 1)
            menu();
        break;
    default:
        break;
    }
    cout << "Até logo! ";
}

void menu(){
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "");
    Player *player = new Player;
    Player *player2 = new Player;

    cout << "Olá player 1, digite seu nome: ";
    cin >> player->name;

    cout << "Olá player 2, digite seu nome: ";
    cin >> player2->name;

    config_letter_player(player, player2);

    int *option = new int;

    choose_option(option, player, player2);
    run_option(option, player, player2);


}
