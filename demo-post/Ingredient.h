#ifndef INGREDIENT_INCLUDED
#define INGREDIENT_INCLUDED

using namespace std;

class Ingredient
{
	private:
    int         ingredientID;
    string      name;

	public:
    Ingredient(int id, string n);
    int     GetID();
    string  GetName();
};

#endif // INGREDIENT_INCLUDED
