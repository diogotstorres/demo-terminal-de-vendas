#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED

#include "Store.h"
#include "Custumer.h"
#include "Ingredient.h"
#include "Product.h"

using namespace std;

class Interface
{
	private:
    vector<Custumer*>       custumers;
    vector<Ingredient*>     restrictions;
    vector<Product*>        cart;
    Store                   *store;

	public:
    Interface();
    void ShowRestrictions();
    void Login();
    int  InputCustumerID();
    void AddCustumer(Custumer *c);
    bool IsNewCustumer(int id);
    Custumer* UpdateRestrictions(int id);
    void ChooseProcucts(Custumer *c);
    void AddToCart(Product* p);
};

#endif // INTERFACE_INCLUDED
