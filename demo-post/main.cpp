#include <iostream>
#include <locale>
#include <list>

#include "Interface.h"

using namespace std;

int main()
{
    int id;
    bool loop1 = true;

    Interface *interf = new Interface();
    id = interf->InputCustumerID();
    interf->ChooseProcucts(interf->UpdateRestrictions(id));

    return 0;
}


