#include <iostream>
#include <locale.h>

using namespace std;

extern void clearScreen();

int about_section(){
    int my_option;
    cout << "Jogo da velha feito em C++ com possibilidade de 2 jogadores" << endl;
    cout << "Para jogar basta digitar o nome dos dois jogadores e as letras X e O serão " << endl;
    cout << "aleatoriamente separadas" << endl << endl;
    cout << "1 - Voltar" << endl << "2 - Sair" << endl;
    cin >> my_option;
    while (my_option < 1 || my_option > 2){
        cout << "Digite um valor válido: ";
        cin >> my_option;
    }

    clearScreen();
    return my_option;
}
