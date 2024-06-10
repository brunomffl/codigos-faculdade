#include <iostream>
#include <vector>
using namespace std;

void MenuPrincipal() {
    int opcaoF;
    cout << endl;
    cout << "Deseja voltar ao menu principal" << endl;
    cout << "1) Sim " << endl << "2) Não" << endl;
    cin >> opcaoF;
    if (opcaoF != 1 && opcaoF != 2) {
        while (opcaoF != 1 && opcaoF != 2) {
            cout << "Opção inválida!" << endl;
            cout << "Selecione uma opção válida: ";
            cin >> opcaoF;
        }
    }
    if (opcaoF == 1) {
        system("clear");
    } else {
        cout << "Fechando..." << endl;
        exit(0);
    }
}

class Autor {
private:
    string nome;
    string nacionalidade;
    int anoNascimento;
public:
    void setNome(string nome) {
        this->nome = nome;
    }
    string getNome() {
        return this->nome;
    }
    void setNacionalidade(string nacionalidade) {
        this->nacionalidade = nacionalidade;
    }
    string getNacionalidade() {
        return this->nacionalidade;
    }
    void setAnoNascimento(int anoNascimento) {
        this->anoNascimento = anoNascimento;
    }
    int getAnoNascimento() {
        return this->anoNascimento;
    }
};

class Livro {
private:
    string titulo;
    Autor autor;
    string genero;
    int anoPublicacao;
public:
    void setTitulo(string titulo) {
        this->titulo = titulo;
    }
    string getTitulo() {
        return this->titulo;
    }
    void setAutor(Autor autor) {
        this->autor = autor;
    }
    Autor getAutor() {
        return this->autor;
    }
    void setGenero(string genero) {
        this->genero = genero;
    }
    string getGenero() {
        return this->genero;
    }
    void setAnoPublicacao(int anoPublicacao) {
        this->anoPublicacao = anoPublicacao;
    }
    int getAnoPublicacao() {
        return this->anoPublicacao;
    }
};

class Colecao {
private:
    string NomeColecao;
    vector<Livro> livros;
public:
    void setNomeColecao(string NomeColecao) {
        this->NomeColecao = NomeColecao;
    }
    string getNomeColecao() {
        return this->NomeColecao;
    }
    void AdicionarLivro(Livro livro) {
        livros.push_back(livro);
    }
    void RemoverLivro(string titulo) {
        for (auto cont = livros.begin(); cont != livros.end(); ++cont) {
            if (cont->getTitulo() == titulo) {
                livros.erase(cont);
                break;
            }
        }
    }
    void ListarLivros() {
        for (auto cont : livros) {
            cout << "Título: " << cont.getTitulo() << endl;
            cout << "Autor: " << cont.getAutor().getNome() << endl;
            cout << "Gênero: " << cont.getGenero() << endl;
            cout << "Publicação: " << cont.getAnoPublicacao() << endl << endl;
        }
    }
    
    void ListarTitulos(){
        for (auto titulos : livros){
            cout << "Título: " << titulos.getTitulo() << endl;
        }
    }
};

class DispositivoLeitura {
private:
    vector<Colecao> colecoes;
    vector<Livro> LivrosLidos;
public:
    void AdicionarColecao(Colecao colecao) {
        colecoes.push_back(colecao);
    }
    void AdicionarLivroLido(Livro livro) {
        LivrosLidos.push_back(livro);
    }
    void ListarLivrosLidos() {
        if (LivrosLidos.empty()) {
            cout << "Nenhum livro lido foi cadastrado neste dispositivo!";
        } else {
            for (auto cont2 : LivrosLidos) {
                cout << "Título: " << cont2.getTitulo() << endl;
                cout << "Autor: " << cont2.getAutor().getNome() << endl;
                cout << "Gênero: " << cont2.getGenero() << endl;
                cout << "Publicação: " << cont2.getAnoPublicacao() << endl;
                cout << endl;
            }
        }
    }
    void ListarLivrosDisp(){
        for (auto titulos : colecoes){
            titulos.ListarTitulos();
        }
    }
    
    void MostrarColecoes() {
        for (auto colecao : colecoes) {
            cout << "Coleção: " << colecao.getNomeColecao() << endl;
            cout << "Livros na coleção: " << endl;
            colecao.ListarLivros();
        }
    }
};

int main() {
    Autor autor1, autor2, autor3,autor4,autor5,autor6;
    Livro livro1, livro2, livro3,livro4,livro5,livro6;
    Colecao colecao1, colecao2, colecao3, colecao4;
    DispositivoLeitura dispositivo1, dispositivo2;
    int opcao, opcaoE, opcao2, opcao3, opcaoF = 1;
    autor1.setNome("Victor Hugo");
    autor1.setNacionalidade("Francês");
    autor1.setAnoNascimento(1802);
    autor2.setNome("Gabriel García Márquez");
    autor2.setNacionalidade("Colombiano");
    autor2.setAnoNascimento(1927);
    autor3.setNome("Fiodor Dostoiévski");
    autor3.setNacionalidade("Russo");
    autor3.setAnoNascimento(1821);
    autor4.setNome("Antoine de Saint-Exupéry");
    autor4.setNacionalidade("Francês");
    autor4.setAnoNascimento(1900);
    autor5.setNome("Machado de Assis");
    autor5.setNacionalidade("Brasileiro");
    autor5.setAnoNascimento(1839);
    autor6.setNome("JK Rowling");
    autor6.setNacionalidade("Britânica");
    autor6.setAnoNascimento(1965);
    livro1.setTitulo("Os miseráveis");
    livro1.setAutor(autor1);
    livro1.setGenero("Romance");
    livro1.setAnoPublicacao(1862);
    livro2.setTitulo("Cem Anos de Solidão");
    livro2.setAutor(autor2);
    livro2.setGenero("Ficção épica");
    livro2.setAnoPublicacao(1967);
    livro3.setTitulo("Crime e Castigo");
    livro3.setAutor(autor3);
    livro3.setGenero("Crime Policial");
    livro3.setAnoPublicacao(1866);
    livro4.setTitulo("O Pequeno Príncipe");
    livro4.setAutor(autor4);
    livro4.setGenero("Fantasia");
    livro4.setAnoPublicacao(1943);
    livro5.setTitulo("Dom Casmurro");
    livro5.setAutor(autor5);
    livro5.setAnoPublicacao(1899);
    livro5.setGenero("Romance");
    livro6.setTitulo("Harry Potter e a Pedra Filososfal");
    livro6.setAutor(autor6);
    livro6.setAnoPublicacao(1997);
    livro6.setGenero("Ficção");
    colecao1.setNomeColecao("Livros de Ficção");
    colecao1.AdicionarLivro(livro2);
    colecao1.AdicionarLivro(livro6);
    colecao2.setNomeColecao("Livros de Romance");
    colecao2.AdicionarLivro(livro1);
    colecao2.AdicionarLivro(livro5);
    colecao3.setNomeColecao("Livros de Fantasia");
    colecao3.AdicionarLivro(livro4);
    colecao4.setNomeColecao("Livros de Crime");
    colecao4.AdicionarLivro(livro3);
    dispositivo1.AdicionarColecao(colecao1);
    dispositivo1.AdicionarColecao(colecao3);
    dispositivo2.AdicionarColecao(colecao2);
    dispositivo2.AdicionarColecao(colecao4);
    dispositivo1.AdicionarLivroLido(livro2);
    dispositivo2.AdicionarLivroLido(livro3);
    dispositivo1.AdicionarLivroLido(livro6);
    dispositivo2.AdicionarLivroLido(livro1);

    do {
        cout << "Selecione um dispositivo de leitura: " << endl;
        cout << "1) Dispositivo 1" << endl;
        cout << "2) Dispositivo 2" << endl;
        cin >> opcao;
        if (opcao != 1 && opcao != 2) {
            while (opcao != 1 && opcao != 2) {
                cout << "Opção inválida!" << endl;
                cout << "Digite uma opção válida: ";
                cin >> opcao;
                cout << endl;
            }
        }

        cout << endl;

        if (opcao == 1) {
            cout << "Dispositivo 1 selecionado!" << endl;
            cout << "1) Exibir coleções deste dispositivo" << endl;
            cout << "2) Exibir livros lidos neste dispositivo" << endl;
            cout << "3) Exibir TODOS os livros do dispositivo" << endl;
            cin >> opcao2;
            if (opcao2 != 1 && opcao2 != 2 && opcao2 != 3) {
                while (opcao2 != 1 && opcao2 != 2 && opcao2 != 3) {
                    cout << "Opção inválida!" << endl;
                    cout << "Selecione uma opção válida: ";
                    cin >> opcao2;
                }
            }

            cout << endl;

            if (opcao2 == 1) {
                cout << "Exibindo coleções do dispositivo 1: " << endl;
                dispositivo1.MostrarColecoes();
                MenuPrincipal();
            }else if (opcao2 == 2) {
                cout << "Exibindo livros lidos no dispositivo 1:" << endl;
                dispositivo1.ListarLivrosLidos();
                MenuPrincipal();
            }else{
                cout << "Exibindo todos os livros cadastrados neste dispositivo: " << endl;
                dispositivo1.ListarLivrosDisp();
                MenuPrincipal();
            }
        } else {
            cout << "Dispositivo 2 selecionado!" << endl;
            cout << "1) Exibir coleções deste dispositivo" << endl;
            cout << "2) Exibir livros lidos neste dispositivo" << endl;
            cout << "3) Exibir TODOS os livros deste dispositivo" << endl;
            cin >> opcao2;
            if (opcao2 != 1 && opcao2 != 2 && opcao2 != 3) {
                while (opcao2 != 1 && opcao2 != 2 && opcao2 != 3) {
                    cout << "Opção inválida!" << endl;
                    cout << "Digite uma opção válida: ";
                    cin >> opcao2;
                }
            }

            cout << endl;

            if (opcao2 == 1) {
                cout << "Exibindo coleções do dispositivo 2: " << endl;
                dispositivo2.MostrarColecoes();
                MenuPrincipal();
            } else if (opcao2 == 2) {
                cout << "Exibindo livros lidos no dispositivo 2: " << endl;
                dispositivo2.ListarLivrosLidos();
                cout << endl;
                MenuPrincipal();
            }else{
                cout << "Exibindo todos os livros cadastrados neste dispositivo: " << endl;
                dispositivo2.ListarLivrosDisp();
                MenuPrincipal();
            }
        }
    } while (opcaoF == 1);

    return 0;
}