#ifndef PRODUCT_INCLUDED
#define PRODUCT_INCLUDED

#include "Item.h"
#include "Ingredient.h"

using namespace std;

class Product
{
	private:
	int                 productID;
    string              name;
    double              price;


    public:
    vector<Item*>       items;
    Product(int id, string n, double pr);
    string  GetName();
    int     GetID();
    void    AddItem(Item *i);
    void    ShowRestrictions();
};

#endif // PRODUCT_INCLUDED

