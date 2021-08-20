#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

extern void menu();

int main(){
    setlocale(LC_ALL, "");
    menu();

    return 0;
}
