#include <iostream>
#include <vector>

#include "Ingredient.h"
#include "Interface.h"
#include "Item.h"
#include "Product.h"
#include "Production.h"


using namespace std;

// Adiciona novo cliente
void Interface::AddCustumer(Custumer *c)
{
    custumers.push_back(c);
}

// Inicialização do "banco de dados"
Interface::Interface()
{
    vector<Ingredient*>    ingredientsBeef;
    Ingredient *soy = new Ingredient(1,"soy");
    Ingredient *dairy = new Ingredient(2,"dairy");
    Ingredient *gluten = new Ingredient(3,"gluten");
    Ingredient *sugar = new Ingredient(4,"sugar");
    ingredientsBeef.push_back(soy);
    ingredientsBeef.push_back(dairy);
    ingredientsBeef.push_back(gluten);
    ingredientsBeef.push_back(sugar);
    restrictions.push_back(soy);
    restrictions.push_back(dairy);
    restrictions.push_back(gluten);
    restrictions.push_back(sugar);

    Item *beef = new Item(1,"beef",ingredientsBeef);

    Product *DarthBacon =
        new Product(1, "Darth Bacon", 2.5);
    DarthBacon->AddItem(beef);

    //Produção com restrições
    Production * grill200 = new Production(200,"grill");
    grill200->AddRestriction(soy);
    grill200->AddRestriction(dairy);
    grill200->AddRestriction(gluten);
    grill200->AddRestriction(sugar);

    //Produção sem restrições
    Production * grill300 = new Production(300,"grill");

    store =
        new Store(1000,"California-Pasadena");
    store->AddProduct(DarthBacon);
    store->AddProduction(grill200);
    store->AddProduction(grill300);


    Custumer *custumerID2 = new Custumer(2);
    Custumer *custumerID3 = new Custumer(3);
    custumerID2->AddRestriction(dairy);
    AddCustumer(custumerID2);
    AddCustumer(custumerID3);
}


void Interface::ShowRestrictions()
{

}


// Entrada do ID do cliente, seja novo ou já registrado
int Interface::InputCustumerID()
{
    int id, i;
    cout << " --- User Recognition ---" << endl;

	bool intEntered = false;
	char input[255] ;

	while (!intEntered) {
        cout<<"\nInput your ID: ";
        cin >> input;
        string s = input;

        for (i=0; i<s.size();i++) {
            if (!isdigit(s[i])) {
                cout << "\nMust be a number (integer) ";
                intEntered = false;
                break;
            }
            else intEntered = true;
        }
        if (intEntered) {
            id = atoi(s.c_str());
            if (id==0) {
                cout << "\n0 is not allowed ";
                intEntered = false;
            }
            else intEntered = true;
        }
    }
    cout << "\nThe ID is: " << id << endl;
    return id;
}


// Verifica se o cliente não consta no banco de dados
bool Interface::IsNewCustumer(int id)
{
    for (Custumer *c: custumers) {
        if (c->GetID() == id)   return false;
    }
    return true;
}


// Adiciona restrições para clientes, se for um novo cliente, cria um novo registro
Custumer* Interface::UpdateRestrictions(int id)
{
    int i;
    int index = 0;
    bool loop = true;
    bool intEntered = false;
    int escolha = 0;
    char input[255];
    Custumer* custumer;

    for (Ingredient *i: restrictions) index++;

    bool isNewCustm = IsNewCustumer(id);
    if (isNewCustm) {
        custumer = new Custumer(id);
        AddCustumer(custumer);
    }
    else {
        for (Custumer *c: custumers) {
            if (c->GetID() == id)   custumer = c;
        }
    }


    while (loop) {
        while (!intEntered) {
            cout <<
            "\n\nSelect ingredient restrictions by their ID if you have any (one at a time): \n";

            cout <<"\n(0) - Add no more restrictions and select food ";
            for (Ingredient *i: restrictions) {
                cout <<"\n("<<i->GetID()<<") - " << i->GetName() << " ";
            }
            cout << endl;
            cout << "Option: ";
            cin >> input;

            string s = input;

            for (i=0; i<s.size();i++) {
                if (!isdigit(s[i])) {
                    cout << "\nMust be the ID number (integer) ";
                    intEntered = false;
                    break;
                }
                else intEntered = true;
            }
            if (intEntered) {
                escolha = atoi(s.c_str());
                if (escolha == 0) {
                    loop = false;
                    break;
                }
                if (!(escolha>0 && escolha<=index) ) {
                    cout << "\nSelect a value between 0 and "<<index;
                    intEntered = false;
                }
                else intEntered = true;
            }
        }//end while (!intEntered): Entrada válida
        intEntered = false;

        for (Ingredient *i: restrictions) {
            if (i->GetID() == escolha) {
                if (custumer->IsRestriction(i))
                    cout<<"\n"<<i->GetName()<<" is already registered as a restriction";
                else {
                    custumer->AddRestriction(i);
                    cout<<"\n"<<i->GetName()<<" is now registered as a restriction";
                }
            }
        }//end for
    }//end while (loop)
    return custumer; // retorna ponteiro para o o usuário ativo
}


// Asiciona o produto para o carrinho
void Interface::AddToCart(Product* p)
{
    cart.push_back(p);
}


// Interface de seleção de produtos
void Interface::ChooseProcucts(Custumer *c)
{
    int i;
    bool isAvailable;
    bool canBeProduced;
    bool loop = true;
    bool intEntered = false;
    int escolha = 0;
    char input[255];
    int cont = 0;
    int validProductions = 0;

    while (loop) {
        while (!intEntered) {
            cout <<
            "\n\nSelect items to order by their ID (one at a time): \n";

            cout <<"\n(0) - End Order ";

            // Para cada ingrediente de cada item de cada produto,
            // verifica se é compativel com a dieta do usuário.
            for (Product *p: store->menu) {
                isAvailable = true;
                for (Item *i: p->items) {

                    for (Ingredient *ingr: i->ingredients) {
                        if (c->IsRestriction(ingr)) {
                            isAvailable = false;
                            break;
                        }

                        for (Production *production: store->productions) {
                            canBeProduced = true;
                            for (Ingredient *r: production->restrictions) {

                                if (ingr->GetID() == r->GetID()) {
                                    canBeProduced = false;
                                    //cout<<"\n!!!"<<ingr->GetName();
                                    break;
                                }
                                else canBeProduced = true;
                            }
                            if (canBeProduced) validProductions++;
                        }

                    }//Ingredientes
                }//Items

                if (isAvailable && validProductions) {
                    cout <<"\n("<<p->GetID()<<") - " << p->GetName() << " ";
                    cont++; //Conta numero de produtos disponíveis
                }
            }//Produtos

            if (cont == 0){
                cout <<
                "\nUnfortunately there are no items that currently match your restrictions ";
                return;
            }
            cout << endl;
            cout << "Option: ";
            cin >> input;

            string s = input;

            for (i=0; i<s.size();i++) {
                if (!isdigit(s[i])) {
                    cout << "\nMust be the ID number (integer) ";
                    intEntered = false;
                    break;
                }
                else intEntered = true;
            }
            if (intEntered) {
                escolha = atoi(s.c_str());
                if (escolha == 0) {
                    loop = false;
                    break;
                }
                if (!(escolha>0 && escolha<=cont) ) {
                    cout << "\nSelect a value between 0 and "<<cont;
                    intEntered = false;
                }
                else intEntered = true;
            }
        }//end while (!intEntered): Entrada válida
        intEntered = false;

        for (Product *p: store->menu) {
            if (p->GetID() == escolha) {
                AddToCart(p);
                cout<<"\n"<<p->GetName()<<" is now in the cart";
            }
        }//end for


    }//end while (loop)
    cout<<"\n\nCart:\n";
    for (Product *p: cart) {
        cout<<"\n- "<<p->GetName();
    }
}


