#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include <vector>

#include "Ingredient.h"

using namespace std;

class Item
{
	private:
    int                     itemId;
    string                  name;

	public:
    vector<Ingredient*>     ingredients;
    Item(int id, string n, vector<Ingredient*> ing);
};

#endif // ITEM_INCLUDED

