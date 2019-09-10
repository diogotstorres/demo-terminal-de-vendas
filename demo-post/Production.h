#ifndef PRODUCTION_INCLUDED
#define PRODUCTION_INCLUDED

#include <vector>

#include "Ingredient.h"

using namespace std;

class Production
{
	private:

    int                     productionID;
    bool                    status;
    string                  type;

	public:
    vector<Ingredient*>     restrictions;
    Production(int id, string t);
    void AddRestriction(Ingredient *i);
    void SetStatus(bool newStatus);
    bool IsOn();
    int GetID();
};

#endif // PRODUCTION_INCLUDED

