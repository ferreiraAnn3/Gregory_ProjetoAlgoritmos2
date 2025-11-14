#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct cpu{
    char fabricante[70];
    char modelo[70];
    float valor;

};


void gravar(cpu vet[]){
    fstream cpuArquivo;
    cpuArquivo.open("cpuArquivo.bin", ios::out | ios ::binary);
    if(cpuArquivo.is_open()){
        for(int i=0; i<3; i++){
        cpuArquivo.write((char*) &vet[i].fabricante, sizeof(vet[i].fabricante));
        cpuArquivo.write((char*) &vet[i].modelo, sizeof(vet[i].modelo));
        cpuArquivo.write((char*) &vet[i].valor, sizeof(vet[i].valor));
            }
    }

}


void preencher(cpu vet[]){

    strcpy(vet[0].fabricante, "Intel");
    strcpy(vet[1].fabricante, "AMD");
    strcpy(vet[2].fabricante, "AMD");

    strcpy(vet[0].modelo, "Intel Core i3-12100");
    strcpy(vet[1].modelo, "Ryzen 5 5600");
    strcpy(vet[2].modelo, "Ryzen 9 7950X");

    vet[0].valor = 850;
    vet[1].valor = 900;
    vet[2].valor = 4.000;
}

void mostrar(cpu vet[], int n){
    for(int i=0; i<n; i++){
        cout << "Fabricante; " << vet[i].fabricante << endl;
        cout << "Modelo; " << vet[i].modelo<< endl;
        cout << "Valor; " << vet[i].valor << endl << endl;
    }
}

void carregar(cpu vet[]){
    fstream cpuArquivo;
    cpuArquivo.open("cpuArquivo", ios::in | ios::binary);
    if(cpuArquivo.is_open()){
        cpuArquivo.read((char *) &vet, sizeof(cpu)*3);
    }

    cout << "Informações carregadas";
}

void menu(){
    cout << "\n....Menu...." << endl;
    cout << "1- para preencher as informacoes" << endl;
    cout << "2- para mostrar" << endl;
    cout << "3- para gravar" << endl;
    cout << "4- para carregar" << endl;
    cout << "5- para sair" << endl;
    cout << "Digite a sua opcao: ";

}

int main(){
    cpu vet[3];
    int opcao;

    do{
        menu();
        cin >> opcao;

    switch(opcao){
    case 1:
        preencher(vet);
        break;
    case 2:
        mostrar(vet, 3);
        break;

    case 3:
        gravar(vet);
        break;

    case 4:
        carregar(vet);
        break;

    case 5:
        cout << "Voce saiu do programa" << endl;

        }
    }while (opcao !=0);

        return 0;
}
