#include <iostream>
#include <fstream>

using namespace std;

int main(){

    fstream meuArquivo;

    //variáveis ques erão gravadas no arquivo binário
    int x = 25;
    float vet[] = {18.5, 546.8, 9587.0, 543.6};

    //abrir/criar arquivo binario para gravação
    meuArquivo.open("arquivo.bin", ios::out | ios::binary);

    //acessar oarquivo e gravar as informações
    if(meuArquivo.is_open() == true){
        meuArquivo.write((char*) &x, sizeof(x)); //grava x
        meuArquivo.write((char*) &vet, sizeof(vet));//grava vet
        meuArquivo.close();

        cout << "Deu certo!" << endl;
    }
    else{
        cout <<"Erro no acesso ao 'arquivo.bin'\n";
    }
    return 0;
}
