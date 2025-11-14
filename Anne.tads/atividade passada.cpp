#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int contCar = 0;
struct Filme {
    string titulo, genero;
    int duracao;
};

void CadastrarFilme(vector<Filme>& Filmes) {
    Filme f;

    cout << "CADASTRAR FILME\n";
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, f.titulo);
    cout << "\nGenero: ";
    getline(cin, f.genero);
    cout << "\nDuracao do filme (em minutos): ";
    cin >> f.duracao;

    Filmes.push_back(f);
}
void MostrarFilme(vector<Filme>Filmes) {
    if (Filmes.size() == 0) {
        cout << "Não há filme cadastrado\n";
        return;
    }

    cout << "FILMES\n";
    for (int i = 0; i < Filmes.size(); i++) {

        cout << "Titulo: " << Filmes[i].titulo << endl;
        cout << "Genero: " << Filmes[i].genero << endl;
        cout << "Duracao (em minutos): " << Filmes[i].duracao << endl;
        cout << endl;
    }
}


void Salvar(vector<Filme>& Filmes) {

    ofstream arquivoFilme;

    arquivoFilme.open("arquivo_filme.txt", ios::out | ios::app);

    for (int i = 0; i < Filmes.size(); i++) {
        arquivoFilme << Filmes[i].titulo << endl;
        arquivoFilme << Filmes[i].genero << endl;
        arquivoFilme << Filmes[i].duracao << endl;
    }


    cout << "Informacoes do filme salvas.\n";

    arquivoFilme.close();
}

void CarregarInfo(vector<Filme>& Filmes) {
    ifstream arquivoFilme;
    arquivoFilme.open("arquivo_filme.txt", ios::in);

    Filmes.clear();
    string inicio, fim;
    Filme f;

    while (getline(arquivoFilme, inicio)) {
            //getline pra linha inteira
        f.titulo = inicio;
        if (!getline(arquivoFilme, f.genero))
            break;

        if (!(arquivoFilme >> f.duracao))
        break;

        getline(arquivoFilme, fim);
        Filmes.push_back(f);
    }

    arquivoFilme.close();
    cout << "Informacoes carregadas\n";
}
void Menu() {
    cout << "MENU FILMES\n";
    cout << "1. Cadastrar\n";
    cout << "2. Mostrar\n";
    cout << "3. Salvar\n";
    cout << "4. Carregar informacoes\n";
    cout << "0. Sair\n";
}
int main() {

    vector<Filme>Filmes;
    int opcao;

    do {
        Menu();
        cin >> opcao;

        switch (opcao) {
        case 1:
            CadastrarFilme(Filmes);
            break;
        case 2:
            MostrarFilme(Filmes);
            break;
        case 3:
            Salvar(Filmes);
            break;
        case 4:
            CarregarInfo(Filmes);
            break;
        case 0:
            break;
        default:
            cout << "Opcao Invalida. Tente Novamente...\n";
        }

    } while (opcao != 0);

    return 0;
}
