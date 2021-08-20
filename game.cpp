#include <iostream>
#include <stdlib.h>
#include <string>
#include <new>
#include "player.h"

using namespace std;
extern void clearScreen();

void game(Player *p1, Player *p2);

static void initTab(char tab[3][3]){
    for (int line=0; line < 3; line++){
        for (int column=0; column < 3; column++){
            tab[line][column] = '-';
        }
    }
}


static void showTab(char tab[3][3]){
    for (int line=0; line < 3; line++){
        for (int column=0; column < 3; column++){
            cout << tab[line][column];
        }
        cout << endl;
    }

}

static void player_turn(Player *player, char tab[3][3]){
    register int line_player; register int column_player;
    cout << player->name << ", digite uma linha: ";
    cin >> line_player;
    cout << player->name << ", digite uma coluna: ";
    cin >> column_player;
    tab[line_player][column_player] = player->letter;
}

static int verifyTable(char tab[3][3]){
    for (int line=0; line < 3; line++){
        if(tab[line][0] != '-' && tab[line][0] == tab[line][1] && tab[line][0] == tab[line][2])
            return 1;

    }
    for (int column=0; column < 3; column++){
        if (tab[0][column] != '-' && tab[0][column] == tab[1][column] && tab[0][column] == tab[2][column])
            return 1;
    }
    if (tab[0][0] != '-' && tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2] || tab[0][2] != '-' && tab[0][2] == tab[1][1] && tab[0][2] == tab[2][0]){
        return 1;
    }
}

static void showResults(Player *p1, Player *p2){
    cout << p1->name << ": " << p1->score << endl;
    cout << p2->name <<": " << p2->score << endl << endl;
}

static void playAgain(Player *p1, Player *p2){
    int *esc = new int;
    cout << "Jogar novamente?" << endl << "1-Sim" << endl << "0-Não" << endl << "Escolha uma opção: ";
    cin >> *esc;
    while (*esc < 0 || *esc > 1){
        cout << "Digite um valor válido!";
        cin >> *esc;
    }
    switch(*esc){
    case 1:
        clearScreen();
        game(p1, p2);
        break;
    default:
        break;

    }
}

void game(Player *p1, Player *p2){
    register char tab[3][3];
    register int controller = 1;
    bool p1Playing;

    initTab(tab);

    for(int round=1; round < 10; round++){
        clearScreen();
        showTab(tab);
        cout << "Round: " << round << endl;
        switch (controller){
        case 1:
            player_turn(p1, tab);
            controller++;
            p1Playing = true;
            break;
        case 2:
            player_turn(p2, tab);
            controller = 1;
            p1Playing = false;
            break;

        }

        if (verifyTable(tab) == 1 && p1Playing){
                cout << p1->name << " ganhou" << endl;
                p1->score += 1;
                break;

        }
        if (verifyTable(tab) == 1 && p1Playing == false){
            cout << p2->name << " ganhou" << endl;
            p2->score += 1;
            break;
        }

    }

    showResults(p1, p2);
    playAgain(p1, p2);


}
