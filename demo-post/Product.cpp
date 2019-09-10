#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Item.h"
#include "Product.h"
#include "Ingredient.h"

using namespace std;

Product::Product(int id, string n, double pr)
{
    productID = id;
    name = n;
}


void Product::AddItem(Item *i){
    items.push_back(i);
}


string Product::GetName()
{
    return name;
}


int Product::GetID()
{
    return productID;
}


void Product::ShowRestrictions()
{
    int index = 1;
    vector<int> visitados;

    for(Item *x: items){
        for (Ingredient *y: x->ingredients){
            cout <<"\n("<<index<<") - " << y->GetName() << " ";
            index++;
        }
    }

}


