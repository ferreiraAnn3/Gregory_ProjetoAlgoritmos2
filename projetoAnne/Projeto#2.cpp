#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int contCursos = 0;
int contAlunos = 0;
int contDados = 0;

// structs
struct Curso {
    char nomeCurso[50];
    int codigo;
    int cargaH;
    int vagas;
};

struct Aluno {
    char nomeC[100];
    int matricula;
    int idade;
    int codigoCurso;
};

struct Dados {
    double rg;
    double cpf;
    double telefone;
    int matricula;
};

void mostrarMenu() {
    cout << "\n--------- MENU ---------\n";
    cout << "1 - Cadastrar curso\n";
    cout << "2 - Cadastrar aluno\n"
;
    cout << "3 - Listar cursos\n";
    cout << "4 - Listar alunos\n";
    cout << "5 - Buscar alunos por curso\n";
    cout << "6 - Cadastrar dados pessoais\n";
    cout << "7 - Listar dados pessoais\n";
    cout << "8 - Relatorio geral\n";
    cout << "9 - Salvar informacoes\n";
    cout << "10 - Carregar informacoes\n";
    cout << "11 - Sair\n";
    cout << "Escolha sua opcao: ";
}

// Funções de salvar e carregar dados
void salvarDados(const Curso vetCurso[], int contCursos, const Aluno vetAluno[], int contAlunos, const Dados vetDados[], int contDados)
{
    fstream arquivo("Dados.bin", ios::binary | ios::out);
    if (!arquivo) {
        cout << "Erro ao abrir arquivo para salvar.\n";
        return;
    }

    arquivo.write((char*)&contCursos, sizeof(int));
    arquivo.write((char*)&contAlunos, sizeof(int));
    arquivo.write((char*)&contDados, sizeof(int));

    arquivo.write((char*)vetCurso, contCursos * sizeof(Curso));
    arquivo.write((char*)vetAluno, contAlunos * sizeof(Aluno));
    arquivo.write((char*)vetDados, contDados * sizeof(Dados));

    arquivo.close();
    cout << "Dados salvos.\n";
}

void carregarDados(Curso vetCurso[], int &contCursos, Aluno vetAluno[], int &contAlunos,Dados vetDados[], int &contDados)
{
    fstream arquivo("Dados.bin", ios::binary | ios::in);
    if (!arquivo) {
        cout << "Nenhum arquivo encontrado para carregar.\n";
        return;
    }

    arquivo.read((char*)&contCursos, sizeof(int));
    arquivo.read((char*)&contAlunos, sizeof(int));
    arquivo.read((char*)&contDados, sizeof(int));

    arquivo.read((char*)vetCurso, contCursos * sizeof(Curso));
    arquivo.read((char*)vetAluno, contAlunos * sizeof(Aluno));
    arquivo.read((char*)vetDados, contDados * sizeof(Dados));

    arquivo.close();
    cout << "Dados carregados.\n";
}

// Cadastro de curso
void cadastrarCurso(Curso vetCurso[], int &contCursos) {
    if (contCursos >= 10) {
        cout << "Limite máximo de cursos atingido!\n";
        return;
    }

    int novoCodigo;
    bool existe;

    do {
        cout << "Digite o codigo do curso: ";
        cin >> novoCodigo;

        existe = false;
        for (int i = 0; i < contCursos; i++) {
            if (vetCurso[i].codigo == novoCodigo) {
                existe = true;
                cout << "Esse codigo ja existe.\n";
                break;
            }
        }
    } while (existe);

    vetCurso[contCursos].codigo = novoCodigo;

    cout << "Digite o nome do curso: ";
    cin.ignore();
    cin.getline(vetCurso[contCursos].nomeCurso, 50);

    cout << "Digite a carga horaria: ";
    cin >> vetCurso[contCursos].cargaH;

    cout << "Digite o numero de vagas: ";
    cin >> vetCurso[contCursos].vagas;

    contCursos++;
    cout << "Curso cadastrado com sucesso!\n";
}

// Cadastro de aluno
void cadastrarAluno(Aluno vetAluno[], int &contAlunos, Curso vetCurso[], int contCursos) {
    if (contCursos == 0) {
        cout << "Nenhum curso cadastrado!\n";
        return;
    }
    if (contAlunos >= 40) {
        cout << "Limite de alunos atingido!\n";
        return;
    }

    cout << "Nome do aluno: ";
    cin.ignore();
    cin.getline(vetAluno[contAlunos].nomeC, 100);

    cout << "Matricula: ";
    cin >> vetAluno[contAlunos].matricula;

    cout << "Idade: ";
    cin >> vetAluno[contAlunos].idade;

    int codigo;
    bool existe;

    do {
        cout << "Codigo do curso: ";
        cin >> codigo;

        existe = false;
        for (int i = 0; i < contCursos; i++) {
            if (vetCurso[i].codigo == codigo) {
                existe = true;
                break;
            }
        }

        if (!existe)
            cout << "Codigo nao encontrado.\n";

    } while (!existe);

    vetAluno[contAlunos].codigoCurso = codigo;
    contAlunos++;
    cout << "Aluno cadastrado com sucesso!\n";
}

// Cadastro de dados pessoais
void cadastrarDados(Aluno vetAluno[], int contAlunos, Dados vetDados[], int &contDados) {
    if (contAlunos == 0) {
        cout << "Nenhum aluno cadastrado!\n";
        return;
    }

    if (contDados >= 40) {
        cout << "Limite de dados atingido!\n";
        return;
    }

    int nMatricula;
    cout << "Digite a matricula do aluno: ";
    cin >> nMatricula;

    int indiceAluno = -1;
    for (int i = 0; i < contAlunos; i++) {
        if (vetAluno[i].matricula == nMatricula) {
            indiceAluno = i;
            break;
        }
    }

    if (indiceAluno == -1) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    cout << "Digite o RG: ";
    cin >> vetDados[contDados].rg;
    cout << "Digite o CPF: ";
    cin >> vetDados[contDados].cpf;
    cout << "Digite o telefone: ";
    cin >> vetDados[contDados].telefone;

vetDados[contDados].matricula = nMatricula;
        contDados++;

    cout << "Dados cadastrados com sucesso!\n";
}

// Listar cursos
void listarCursos(Curso vetCurso[], int contCursos) {
    if (contCursos == 0) {
        cout << "Nenhum curso cadastrado.\n";
        return;
    }

    for (int i = 0; i < contCursos; i++) {
        cout << "\nCurso: " << vetCurso[i].nomeCurso << endl;
        cout << "Codigo: " << vetCurso[i].codigo << endl;
        cout << "Carga horaria: " << vetCurso[i].cargaH << endl;
        cout << "Vagas: " << vetCurso[i].vagas << endl;
    }
}

// Buscar nome do curso por código
string buscarNomeCursos(Curso vetCurso[], int contCursos, int codigoCurso) {
    for (int i = 0; i < contCursos; i++) {
        if (vetCurso[i].codigo == codigoCurso)
            return vetCurso[i].nomeCurso;
    }
    return "Curso nao encontrado";
}

// Listar alunos
void listarAlunos(Aluno vetAluno[], int contAlunos, Curso vetCurso[], int contCursos) {
    if (contAlunos == 0) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    for (int i = 0; i < contAlunos; i++) {
        cout << "\nAluno: " << vetAluno[i].nomeC << endl;
        cout << "Matricula: " << vetAluno[i].matricula << endl;
        cout << "Idade: " << vetAluno[i].idade << endl;
        cout << "Curso: " << buscarNomeCursos(vetCurso, contCursos, vetAluno[i].codigoCurso) << endl;
    }
}

// Listar dados pessoais
void listarDados(Aluno vetAluno[], int contAlunos, Dados vetDados[], int contDados) {
    if (contDados == 0) {
        cout << "Nenhum dado cadastrado!\n";
        return;
    }

    for (int i = 0; i < contDados; i++) {

        char nome[100] = "Aluno nao encontrado";

    for (int j = 0; j < contAlunos; j++) {
            if (vetAluno[j].matricula == vetDados[i].matricula) {
                strcpy(nome, vetAluno[j].nomeC);
                break;
            }
        }

        cout << "\nAluno: " << nome << endl;
        cout << "RG: " << vetDados[i].rg << endl;
        cout << "CPF: " << vetDados[i].cpf << endl;
        cout << "Telefone: " << vetDados[i].telefone << endl;
    }
}

// Buscar alunos por curso
void buscarAlunosPorCurso(Aluno vetAluno[], int contAlunos, Curso vetCurso[], int contCursos) {
    if (contAlunos == 0) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    int codigo;
    cout << "Digite o codigo do curso: ";
    cin >> codigo;

    bool achou = false;
    for (int i = 0; i < contAlunos; i++) {
        if (vetAluno[i].codigoCurso == codigo) {
            cout << vetAluno[i].nomeC << endl;
            achou = true;
        }
    }

    if (!achou)
        cout << "Nenhum aluno encontrado neste curso.\n";
}

// Relatorio geral
void relatorioGeral(Aluno vetAluno[], int contAlunos, Curso vetCurso[], int contCursos) {
    if (contCursos == 0) {
        cout << "Nenhum curso cadastrado.\n";
        return;
    }

    cout << "---- RELATORIO GERAL ----\n";

    for (int i = 0; i < contCursos; i++) {
        int qtd = 0;
        for (int j = 0; j < contAlunos; j++) {
            if (vetAluno[j].codigoCurso == vetCurso[i].codigo)
                qtd++;
        }
        cout << "\nCurso: " << vetCurso[i].nomeCurso << endl;
        cout << "Codigo: " << vetCurso[i].codigo << endl;
        cout << "Alunos matriculados: " << qtd << endl;
    }
}

// Main
int main() {
    Curso vetCurso[10];
    Aluno vetAluno[40];
    Dados vetDados[40];

    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
        case 1: cadastrarCurso(vetCurso, contCursos);
        break;
        case 2: cadastrarAluno(vetAluno, contAlunos, vetCurso, contCursos);
        break;
        case 3: listarCursos(vetCurso, contCursos);
        break;
        case 4: listarAlunos(vetAluno, contAlunos, vetCurso, contCursos);
        break;
        case 5: buscarAlunosPorCurso(vetAluno, contAlunos, vetCurso, contCursos);
        break;
        case 6: cadastrarDados(vetAluno, contAlunos, vetDados, contDados);
        break;
        case 7: listarDados(vetAluno, contAlunos, vetDados, contDados);
        break;
        case 8: relatorioGeral(vetAluno, contAlunos, vetCurso, contCursos);
        break;
        case 9: salvarDados(vetCurso, contCursos, vetAluno, contAlunos, vetDados, contDados);
        break;
        case 10: carregarDados(vetCurso, contCursos, vetAluno, contAlunos, vetDados, contDados);
        break;
        case 11: cout << "Saindo...\n";
        break;
        default: cout << "Opcao invalida!\n";
        break;
        }

    } while (opcao != 11);

    return 0;
}
