#ifndef STORE_INCLUDED
#define STORE_INCLUDED

#include "Product.h"
#include "Production.h"

using namespace std;

class Store
{
	private:
    int                     storeID;
    string                  name;

    public:
    vector<Product*>        menu;
    vector<Production*>     productions;
    Store(int id, string n);
    void AddProduct(Product *p);
    void AddProduction(Production *p);
    void AvailableProducts();
};

#endif // STORE_INCLUDED

