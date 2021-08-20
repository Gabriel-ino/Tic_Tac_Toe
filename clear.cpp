#include <iostream>


#ifdef __unix__
  #include <unistd.h>
  #include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
  #define OS_WINDOWS
  #include <windows.h>
#endif // __unix__

using namespace std;

void clearScreen(){
    #ifdef OS_WINDOWS
    system("cls");
    #else
    system("clear");
    #endif // OS_WINDOWS
}
