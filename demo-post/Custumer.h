#ifndef CUSTUMER_INCLUDED
#define CUSTUMER_INCLUDED

#include <vector>

#include "Ingredient.h"

using namespace std;

class Custumer
{
	private:
    int                     custumerID;
    vector<Ingredient*>     restrictions;

    public:
    Custumer(int id);
    void AddRestriction(Ingredient *i);
    int GetID();
    bool IsRestriction(Ingredient *i);
};

#endif // CUSTUMER_INCLUDED
