#include <iostream>
#include <locale>
#include <list>

#include "Interface.h"

using namespace std;

int main()
{
    int id;
    bool loop1 = true;

    Interface *interf = new Interface();
    id = interf->InputCustumerID();
    interf->ChooseProcucts(interf->UpdateRestrictions(id));

    return 0;
}


//    ListaLocalidades * lista = new ListaLocalidades();
//    lista->criarListaLocalidades();
//
//    int escolha1 = 0;
//    bool loop1 = true;
//    bool loopU = false;
//    bool loopBD = false;
//
//    while (loop1){
//
//        cout << endl;
//        cout << "********** Escolha o modo **********" << endl;
//        cout << endl;
//        cout << "(1): Usuário final" << endl;
//        cout << "(2): Gerenciador Banco de Dados" << endl;
//        cout << "(3): Sair" << endl;
//        cout << endl;
//        cout << "Opção: ";
//        cin >> escolha1;
//
//        switch(escolha1) {
//        case 1:
//            loopU = true;
//            loop1 = false;
//            break;
//        case 2:
//            loopBD = true;
//            loop1 = false;
//            break;
//        case 3:
//            exit(1);
//        default:
//            cout << "Opção inválida." << endl;
//            continue;
//        }
//    }
//
//     while (loopU){
//        int escolha2 = 0;
//
//        cout << endl;
//        cout << "********** Menu Consulta pelo Usuário **********" << endl;
//        cout << endl;
//        cout << "(1): Consultar lista" << endl;
//        cout << "(2): Sair" << endl;
//        cout << endl;
//        cout << "Opção: ";
//        cin >> escolha2;
//
//        switch(escolha2) {
//        case 1:
//            lista->consultaLista();
//            continue;
//        case 2:
//            exit(1);
//        default:
//            cout << "Opção inválida." << endl;
//            continue;
//        }
//     }
//
//
//    while (loopBD){
//        int escolha3 = 0;
//
//        cout << endl;
//        cout << "********** Menu Edição de Localidades **********" << endl;
//        cout << endl;
//        cout << "(1): Consultar lista" << endl;
//        cout << "(2): Inserir nova localidade" << endl;
//        cout << "(3): Excluir localidade" << endl;
//        cout << "(4): Sair" << endl;
//        cout << endl;
//        cout << "Opção: ";
//        cin >> escolha3;
//
//        switch(escolha3) {
//        case 1:
//            lista->consultaLista();
//            continue;
//        case 2:
//            lista->inserirLocalidade();
//            continue;
//        case 3:
//            lista->excluirLocalidade();
//            continue;
//        case 4:
//            exit(1);
//        default:
//            cout << "Opção inválida." << endl;
//            continue;
//        }
//    }
//
//    return 0;
//}
//
//
