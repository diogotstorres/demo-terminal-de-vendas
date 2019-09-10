#include <cstdlib>
#include <iostream>

#include "Custumer.h"
#include "Item.h"

using namespace std;

Custumer::Custumer(int id)
{
    custumerID = id;
}


void Custumer::AddRestriction(Ingredient * i){
    restrictions.push_back(i);
}


int Custumer::GetID()
{
    return custumerID;
}


bool Custumer::IsRestriction(Ingredient *i){
    for (Ingredient *r: restrictions) {
        if (i->GetID() == r->GetID())
            return true;
    }
    return false;
}


