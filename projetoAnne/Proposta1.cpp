#include <iostream>
#include <string>

//contadores
int contCursos = 0;
int contAlunos = 0;

using namespace std;

// Definir uma estrutura para Cursos
struct Curso {
    string nomeCurso;
    int codigo;
    int cargaH;
    int vagas;
};

// Definir uma estrutura para a Alunos
struct Aluno {
    string nomeC;
    int matricula;
    int idade;
    int codigoCurso;
};


void mostrarMenu() {
    cout << " ---------------- MENU DE OPCOES ----------------\n";
    cout << "1 - para cadastrar um curso.\n"; //nome, codigo, carga horária, vagas
    cout << "2 - para cadastrar um aluno.\n"; // N matricula, nome completo, idade
    cout << "3 - para listar cursos.\n";//  cursos cadastrados (código, nome, carga horária, vagas)
    cout << "4 - para listar alunos.\n";// nome e curso
    cout << "5 - para buscar alunos por curso.\n";// nome e curso
    cout << "6 - para exibir relatorio geral.\n";// quantos alunos em cada curso
    cout << "7 - Sair.\n\n";
    cout << "Digite sua opcao: ";
}


void cadastrarCurso(Curso vetCurso[], int &contCursos){
    //verifica se há vagas
    if(contCursos >= 10){
        cout << "Não há mais vagas disponiveis para esse curso!" << endl;
        return;
    }

    int novoCodigo;
    bool teste = false;

    do {
        cout << "Digite o codigo do curso: \n";
        cin >> novoCodigo;

        teste = false;

        for (int i = 0; i < contCursos; i++){
            //verifica se o codigo ja existe
            if(vetCurso[i].codigo == novoCodigo){
                teste = true;
                break;
            }
    }
    if(teste == true){
        cout << "Esse codigo ja existe. Tente novamente.\n";
    }
}while (teste == true);

    vetCurso[contCursos].codigo = novoCodigo;

    cout << "Digite o nome do curso: \n";
    cin.ignore();
    getline(cin, vetCurso[contCursos].nomeCurso);
    cout << "Digite a carga horaria total do curso (em horas): \n";
    cin >> vetCurso[contCursos].cargaH;
    cout << "Digite o numero de vagas do curso: ";
    cin >> vetCurso[contCursos].vagas;

    cout << "Novo curso cadastrado com sucesso!" << endl;
    contCursos ++;

}

void cadastrarAluno(Aluno vetAluno[], int &contAlunos, Curso vetCurso[], int &contCursos) {
    if(contCursos == 0){
        cout << "Nenhum curso cadastrado. Tente peimeiro a opcao 1 do menu.\n";
        return;
    }
    if (contAlunos == 40){
        cout << "Numero de vagas disponiveis atingido!\n";
        return;
    }
    cout << "Digite o nome do aluno: \n";
    cin.ignore();
    getline(cin, vetAluno[contAlunos].nomeC);
    cout << "Digite o numero de matricula: \n";
    cin >> vetAluno[contAlunos].matricula;
    cout << "Digite a idade do aluno: \n";
    cin >> vetAluno[contAlunos].idade;

    int codigoDaBusca;//variavel temporaria para guaradr o codigo digitado
    bool teste = false; //começa como falso

    do{
    cout << "Digite o codigo do curso: \n";
    cin >> codigoDaBusca;

    teste = false; //zera o teste a cada tentativa

    for(int i = 0; i < contCursos; i++){
        if (vetCurso[i].codigo == codigoDaBusca){
            teste = true;
            break;
        }
    }
    if(teste == false){
        cout << "Codigo invalido. Tente novamente";
    }

    }while (teste == false);

    vetAluno[contAlunos].codigoCurso = codigoDaBusca;

    cout << "Aluno matriculado cm sucesso!" << endl;
    contAlunos++;
}

void listarCursos(Curso vetCurso[], int contCursos) {
    if(contCursos == 0){
        cout << "Nao ha cursos cadastrados, tente a opcao 1 do menu\n";
        return;
    }
    for(int i=0; i<contCursos; i++){
        cout << "CURSOS\n";
        cout << "Codigo: " << i+1 << endl;
        cout << "Nome: " << vetCurso[i].nomeCurso << endl;
        cout << "Carga horaria: " << vetCurso[i].cargaH << " horas" << endl;
        cout << "Vagas: " << vetCurso[i].vagas << endl;
    }
}

string buscarNomeCursos(Curso vetCurso[], int contCursos, int codigoCurso){
    for(int i = 0; i <contCursos; i++){
        if(vetCurso[i].codigo == codigoCurso){
            return vetCurso[i].nomeCurso;
        }

    }return "Curso nao encontrado";
}

void listarAlunos(Aluno vetAluno[], int contAlunos, Curso vetCurso[], int contCursos) {
     if(contAlunos == 0){
        cout << "Nao ha alunos cadastrados, tente a opcao 2 do menu.\n";
        return;
    }

    for (int i = 0; i < contAlunos; i++){
    int codigoCurso = vetAluno[i].codigoCurso;

    //vetCurso é a caixa, contCurso é o postit, codigoCurso é o que está no postit
    string nomeCurso = buscarNomeCursos(vetCurso, contCursos, codigoCurso);
    cout << "Curso: " << nomeCurso << endl;
    cout << "Aluno: " << vetAluno[i].nomeC << endl;
    }
}

void buscarAlunosPorCurso(Aluno vetAluno[], int contAlunos, Curso vetCurso[], int contCursos){
    if(contAlunos == 0){
        cout << "Nao ha alunos cadastrados, tente a opcao 2 do menu.\n";
        return;
    }

    int codigoDigitado;
    cout << "Digite o codigo do curso: \n";
    cin >> codigoDigitado;

    bool achou = false;
    for(int i = 0; i < contAlunos; i++){
    if(codigoDigitado == vetAluno[i].codigoCurso){
        cout << vetAluno[i].nomeC << endl;
        achou = true;

       }
    }
     if (achou ==false){
        cout << "Nenhum aluno encontrado. Tente novamente\n";
       }
}



void relatorioGeral(Aluno vetAluno[], int contAlunos, Curso vetCurso[], int contCursos){
    if(contCursos == 0){
        cout << "Nenhum curso cadastrado, tente a opcao 1 do menu\n";
        return;
    }

    cout << "RELATORIO\n";
    //este loop percorre por cada curso cadastrado
    for(int i = 0; i < contCursos; i++){
        int cont=0;
        //este loop percorre por cada aluno caddastrado
        for(int j = 0; j<contAlunos; j++){
            //essa condicao compara se o codigo do curso é igual ao codigo do aluno
            if(vetCurso[i].codigo == vetAluno[j].codigoCurso){
                cont++;
            }
        }
        cout << "Curso: " << vetCurso[i].nomeCurso << endl;
        cout << "Codigo: " << vetCurso[i].codigo << endl;
        cout << "Alunos matriculados: " << cont << endl;
    }
}

int main() {
    Curso esteCurso;
    Aluno esteAluno;

    Aluno vetAluno[40];
    Curso vetCurso[10];

    int opcao;

   do{

    mostrarMenu();
    cin >> opcao;

    switch(opcao){

    case 1:
        cadastrarCurso(vetCurso, contCursos);
        break;
    case 2:
        cadastrarAluno(vetAluno, contAlunos, vetCurso, contCursos);
        break;
    case 3:
        listarCursos(vetCurso, contCursos);
        break;
    case 4:
        listarAlunos(vetAluno,contAlunos, vetCurso, contCursos);
        break;
    case 5:
        buscarAlunosPorCurso(vetAluno, contAlunos, vetCurso, contCursos);
        break;
    case 6:
        relatorioGeral(vetAluno, contAlunos, vetCurso, contCursos);
        break;
    case 7:
        cout << "Voce saiu do sistema." << endl;
        break;

    default:
        cout<< "Opcao inexistente, tente novamente!\n"<< endl;

    }

   }while (opcao != 7);

    return 0;
}
