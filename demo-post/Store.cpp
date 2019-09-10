#include <cstdlib>
#include <iostream>
#include <vector>

#include "Store.h"
#include "Product.h"
#include "Production.h"

using namespace std;

Store::Store(int id, string n)
{
    storeID = id;
    name = n;
}

void Store::AddProduct(Product *p){
    menu.push_back(p);
}

void Store::AddProduction(Production *p){
    productions.push_back(p);
}


