#include <iostream>
using namespace std;

class Mavericks{
    private:
        int num;
        Mavericks* prox;
        Mavericks* ant;
    public:
        Mavericks(int num = 0) : num(num), prox(nullptr), ant(nullptr){}
    
        void setNum(int num){
            this->num = num;
        }
        int getNum(){
            return this->num;
        }
        void setProx(Mavericks* prox){
            this->prox = prox;
        }
        Mavericks* getProx(){
            return this->prox;
        }
        void setAnt(Mavericks* ant){
            this->ant = ant;
        }
        Mavericks* getAnt(){
            return this->ant;
        }
};

void VoltarMenu(){
    int opc;
    cout << endl;
    cout << "Deseja voltar ao menu principal? " << endl << "[ 1 ]- Sim | [ 2 ] - Não: ";
    cin >> opc;
    while (opc != 1 && opc != 2){
        cout << "Opção inválida!" << endl << "Selecione uma opção válida: ";
        cin >> opc;
    }
    if (opc == 1) {
        system("clear");
    }else{
        cout << "Fechando..." << endl;
        exit(0);
    }
    
}

void Menu(){
    cout << endl;
    cout << "Escolha uma das opções do menu: " << endl;
    cout << "[ 0 ] - Listar elementos da lista" << endl;
    cout << "[ 1 ] - Inserir um elemento na lista" << endl;
    cout << "[ 2 ] - Verificar se a lista está vazia" << endl;
    cout << "[ 3 ] - Buscar um elemento da lista" << endl;
    cout << "[ 4 ] - Remover um elemento da lista" << endl;
    cout << "[ 5 ] - Liberar a lista" << endl;
    cout << "[ 6 ] - Sair" << endl;
    cout << ":";
}

int main()
{
    Mavericks *inicio = nullptr, *temp = nullptr, *ajuda = nullptr, *ultimo = nullptr;
    int opcao, num, i = 0, opm, cont, opc;
    
    while (1){
        if (i == 0){
            temp = new Mavericks;
            inicio = temp;
            cout << "Digite o " << i + 1 << "° número: ";
            cin >> num; 
            temp->setNum(num);
            temp->setProx(nullptr);
            temp->setAnt(nullptr);
            ajuda = temp;
            ultimo = temp;
            i++;
        }else{
            cout << "Deseja continuar?" << endl << "[ 1 ] - Sim | [ 2 ] - Não: ";
            cin >> opcao;
            if (opcao == 2){
                break;
            }
            temp = new Mavericks;
            ajuda->setProx(temp);
            cout << "Digite o " << i + 1 << "° número: ";
            cin >> num;
            temp->setNum(num);
            temp->setProx(nullptr);
            temp->setAnt(ajuda);
            ajuda = temp;
            ultimo = temp;
            i++;
        }
    }
    
    system("clear");
    
    do{
        Menu();
        cin >> opm; 
        switch(opm){
            case 0:
                system("clear");
                cout << "LISTAGEM DOS ELEMENTOS DA LISTA!" << endl;
                if (inicio == nullptr){
                    cout << "A lista está vazia!" << endl;
                    cout << endl;
                    VoltarMenu();
                    break;
                }
                cout << "[ 1 ] - Do início ao fim" << endl << "[ 2 ] - Do fim ao início" << endl;
                cin >> opc;
                while (opc!=1 && opc!=2){
                    cout << "Opção inválida!" << endl << "Digite uma opção válida: ";
                    cin >> opc;
                }
                if (opc == 1){
                    cout << "Listagem dos itens da lista do início ao fim: " << endl;
                    ajuda = inicio;
                    while (ajuda != nullptr){
                        cout << ajuda->getNum();
                        ajuda = ajuda->getProx();
                        cout << endl;
                    }
                }else if(opc == 2){
                    cout << endl;
                    cout << "Listagem dos itens da lista do fim ao início: " << endl;
                    ajuda = ultimo;
                    while (ajuda != nullptr){
                        cout << ajuda->getNum();
                        ajuda = ajuda->getAnt();
                        cout << endl;
                    }
                }
                VoltarMenu();
                break;
            case 1:
                system("clear");
                cout << "INSERIR UM ELEMENTO NA LISTA" << endl;
                while (1){
                    cout << "Digite o próximo número: ";
                    cin >> num;
                    Mavericks *novonum = new Mavericks(num);
                    if (inicio == nullptr){
                        inicio = novonum;
                        ultimo = novonum;
                    }else{
                        novonum->setAnt(ultimo);
                        ultimo->setProx(novonum);
                        ultimo = novonum;
                    }
                    cout << "Deseja continuar?" << endl << "[ 1 ] - Sim | [ 2 ] - Não: ";
                    cin >> opcao;
                    if (opcao == 2){
                        break;
                    }
                }
                VoltarMenu();
                break;
            case 2:
                system("clear");
                cout << "VERIFICAR SE A LISTA ESTÁ VAZIA" << endl;;
                if (inicio == nullptr){
                    cout << "A lista ESTÁ vazia!";
                }else{
                    cout << "A lista NÃO está vazia!" << endl << "Selecione a opção [ 0 ] no menu principal para exibir a lista!" << endl;
                }
                VoltarMenu();
                break;
            case 3:
                cont = 0;
                system("clear");
                cont = 0;
                cout << "BUSCAR UM ELEMENTO NA LISTA" << endl;
                cout << "Digite um número para verificar se ele está na lista: ";
                cin >> opc;
                ajuda = inicio;
                while (ajuda != nullptr){
                    if (ajuda->getNum() == opc){
                        cont = 1;
                    }
                    ajuda = ajuda->getProx();
                }
                if (cont == 1){
                    cout << "Número " << opc << " está na lista!" << endl;
                }else{
                    cout << "Número " << opc << " NÃO está na lista!" << endl;
                }
                VoltarMenu();
                break;
            case 4:
                system("clear");
                cout << "REMOVER UM ITEM DA LISTA!" << endl;
                // verifica se o item está na lista;
                cout << "Qual número você deseja remover da lista: ";
                cin >> opc;
                ajuda = inicio;
                cont = 0;
                while (ajuda != nullptr){
                    if (ajuda->getNum() == opc){
                        cont = 1;
                        break;
                    }
                    ajuda = ajuda->getProx();
                }
                if (cont == 1){
                    if (ajuda == inicio) { 
                        inicio = ajuda->getProx();
                        if (inicio != nullptr) {
                            inicio->setAnt(nullptr);
                        } else { // quer dizer que a lista tem apenas um item, já que o proximo ao excluido é nulo, a lista é zerada
                            ultimo = nullptr; 
                        }
                    } else if (ajuda == ultimo) { 
                        ultimo = ajuda->getAnt();
                        if (ultimo != nullptr) {
                            ultimo->setProx(nullptr);
                        } else { //quer dizer que o anterior ao excluido é nulo, ou seja, está tentando excluir o item inicial que nao tem anteriror, lista é zerada
                            inicio = nullptr; 
                        }
                    } else {
                        // o anterior ao item excluido tem seu próximo setado como próximo do item excluido
                        ajuda->getAnt()->setProx(ajuda->getProx());
                        ajuda->getProx()->setAnt(ajuda->getAnt());
                        // o próximo item do item anterior ao excluido é setado como próximo do excluido
                    }
                    delete ajuda; // deleta o ajuda, item que o usuário quer deletar.
                    cout << "Número " << opc << " removido da lista!" << endl;
                } else {
                    cout << "O número " << opc << " não está na lista!" << endl;
                }
                VoltarMenu();
                break;
            case 5:
                system("clear");
                ajuda = inicio;
                while (ajuda != nullptr){
                    ajuda->setProx(nullptr);
                    ajuda->setAnt(nullptr);
                    ajuda = ajuda->getProx();
                }
                inicio = nullptr;
                cout << "Lista limpa!" << endl;
                VoltarMenu();
                break;
            case 6:
                cout << "Saindo...";
                i = 77;
                break;
            default:
                system("clear");
                cout << "Opção inválida!";
                break;
        }
    }while(i!=77);
    
    return 0;
}