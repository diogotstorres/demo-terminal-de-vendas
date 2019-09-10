#include <cstdlib>
#include <iostream>

#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient(int id, string n)
{
    ingredientID = id;
    name = n;
}


int  Ingredient::GetID()
{
    return ingredientID;
}


string  Ingredient::GetName()
{
    return name;
}


