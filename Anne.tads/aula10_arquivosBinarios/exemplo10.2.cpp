#include <iostream>
#include <fstream>

using namespace std;

int main(){

    fstream meuArquivo;

    //variáveis ques erão gravadas no arquivo binário
    int anne;
    float ferreira[4];

    //abrir/criar arquivo binario para leitura
    meuArquivo.open("arquivo.bin", ios::in | ios::binary);

    //acessar oarquivo e ler as informações
    if(meuArquivo.is_open() == true){
        meuArquivo.read((char*) &anne, sizeof(anne)); //grava anne
        meuArquivo.read((char*) &ferreira, sizeof(ferreira));//grava ferreira
        meuArquivo.close();

        cout << "Deu certo!" << endl;
    }
    else{
        cout <<"Erro no acesso ao 'arquivo.bin'\n";
    }

    //exibir as informações lidas (as das variaveis)
    cout << "A = " << anne << endl;

    cout << "Numeros do vetor 'ferreira': ";
    for(int i=0; i<4; i++){
        cout << ferreira[i] << " ";
    }

    cout << endl;

    return 0;
}
