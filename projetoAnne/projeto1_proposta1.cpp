#include <iostream>
#include <string>

// Variável global para controlar a posição no array
int pos = 0;

#define N 50

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


void cadastrarCurso(Curso *c) {
    cout << "Digite o nome do curso: \n";
    cin.ignore();
    getline(cin, c->nomeCurso);
    cout << "Digite o codigo do curso: \n";
    cin >> c->codigo;
    cout << "Digite a carga horaria total do curso (em horas): \n";
    cin >> c->cargaH;
    cout << "Digite o numero de vagas do curso: ";
    cin >> c->vagas;
}

void cadastrarAluno(Aluno *a) {
    cout << "Digite o nome do aluno: \n";
    cin.ignore();
    getline(cin, a->nomeC);
    cout << "Digite o numero de matricula: \n";
    cin >> a->matricula;
    cout << "Digite a idade do aluno: \n";
    cin >> a->idade;
}

void listarCursos(Curso vetCurso[]) {
    for(int i=0; i<=pos; i++){
        cout << "Codigo: " << i+1 << endl;
        cout << "Nome: " << vetCurso[i].nomeCurso << endl;
        cout << "Carga horaria: " << vetCurso[i].cargaH << endl;
        cout << "Vagas: " << vetCurso[i].vagas << endl;
    }
}

void listarAlunos(Aluno vetAluno[], Curso vetCurso[]) {
    for(int i=0; i<=pos; i++){
        cout << "Nome: " << vetAluno[i].nomeC << endl;
        cout << "Curso: " << vetCurso[i].nomeCurso<< endl;
    }
}

void adicionarCurso(Curso vetCurso[], Curso c){
    if(pos < N){
        vetCurso[pos++] = c;
    }
    else{
        cout << "Cheio";
    }

}
void adicionarAluno (Aluno vetAluno[], Aluno a){
    if(pos < N){
        vetAluno[pos++] = a;
    }
    else{
        cout << "Cheio";
    }

}



int main() {
    Curso esteCurso;
    Aluno esteAluno;


    int opcao;

    Aluno vetAluno[40];
    Curso vetCurso[10];

    mostrarMenu();
    cin >> opcao;
    while (opcao != 7) {
        switch(opcao) {
            case 1:
                cadastrarCurso(&esteCurso);
               // adicionarCurso(esteCurso);
                break;
            case 2:
                cadastrarAluno(&esteAluno);
                break;
            case 3:
                listarCursos(vetCurso);
                break;
            case 4:
                //listarAlunos(vetAluno);

            default:
                cout << "Opcao invalida. Digite novamente...\n";
                break;
        }
        mostrarMenu();
        cin >> opcao;
    }

    return 0;
}
