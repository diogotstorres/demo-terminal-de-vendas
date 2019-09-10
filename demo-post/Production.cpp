#include <cstdlib>
#include <iostream>

#include "Production.h"
#include "Item.h"

using namespace std;

Production::Production(int id, string t)
{
    productionID = id;
    type = t;
    status = false;//off
}


void Production::AddRestriction(Ingredient *i)
{
    restrictions.push_back(i);
}


void Production::SetStatus(bool newStatus)
{
    status = newStatus;
}


bool Production::IsOn()
{
    return status;
}

int Production::GetID()
{
    return productionID;
}
