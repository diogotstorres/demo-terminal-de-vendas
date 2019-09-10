#include <cstdlib>
#include <iostream>
#include <vector>

#include "Item.h"
#include "Ingredient.h"

using namespace std;

Item::Item(int id, string n, vector<Ingredient*> ing)
{
    itemId = id;
    name = n;
    ingredients = ing;
}


