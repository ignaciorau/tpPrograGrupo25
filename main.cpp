#include <iostream>
#include "manager.h"
#include "menu.h"


using namespace std;

int main()
{
    Repositorio repo;
    Manager _manager(&repo);
    Menu m(_manager);

    m.manejarMenuInicio();
    return 0;
}
