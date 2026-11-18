#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Ficha de um filme
struct Filme {
    string titulo;
    string genero;
    int duracao; // em minutos
};

void menu() {
    cout << "\n####### 1 - Cadastrar filme ########" << endl;
    cout << "####### 2 - Mostrar filme ########" << endl;
    cout << "####### 3 - Salvar informacoes no arquivo ########" << endl;
    cout << "####### 4 - Carregar informacoes do arquivo ########" << endl;
    cout << "####### 5 - Sair ########" << endl;
}

// Recebe o filme por referencia (&) para guardar os dados no filme original da main.
void cadastrarFilme(Filme &filme) {
    cout << "Digite o titulo do filme: " << endl;
    cin.ignore(); // descarta o enter que sobrou da opcao do menu
    getline(cin, filme.titulo);

    cout << "Digite o genero do filme: " << endl;
    getline(cin, filme.genero);

    cout << "Digite a duracao em minutos: " << endl;
    cin >> filme.duracao;

    cout << "Filme cadastrado!" << endl;
}

// So le os dados para mostrar, entao nao precisa de &.
void mostrarFilme(Filme filme) {
    if (filme.titulo == "") {
        cout << "Nenhum filme cadastrado ou carregado." << endl;
        return;
    }
    cout << "Titulo: " << filme.titulo << endl;
    cout << "Genero: " << filme.genero << endl;
    cout << "Duracao: " << filme.duracao << " minutos" << endl;
}

// Abre o arquivo para escrita. Por padrao, o ofstream apaga o conteudo anterior,
// entao cada salvamento sobrescreve o anterior.
void salvarFilme(Filme filme) {
    ofstream arquivo("filme.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para salvar." << endl;
        return;
    }

    arquivo << filme.titulo << endl;
    arquivo << filme.genero << endl;
    arquivo << filme.duracao << endl;

    arquivo.close();
    cout << "Informacoes salvas no arquivo!" << endl;
}

// Le o arquivo e guarda os dados no filme da main, por isso usa &.
void carregarFilme(Filme &filme) {
    ifstream arquivo("filme.txt");

    if (!arquivo.is_open()) {
        cout << "Arquivo nao encontrado. Salve um filme primeiro." << endl;
        return;
    }

    getline(arquivo, filme.titulo);
    getline(arquivo, filme.genero);
    arquivo >> filme.duracao;

    arquivo.close();
    cout << "Informacoes carregadas do arquivo!" << endl;
}

int main() {
    Filme meuFilme;
    meuFilme.titulo = "";
    meuFilme.genero = "";
    meuFilme.duracao = 0;

    int opcaoEscolhida = 0;

    while (opcaoEscolhida != 5) {
        menu();
        cout << "Digite a opcao desejada: " << endl;
        cin >> opcaoEscolhida;

        switch (opcaoEscolhida) {
        case 1:
            cadastrarFilme(meuFilme);
            break;

        case 2:
            mostrarFilme(meuFilme);
            break;

        case 3:
            salvarFilme(meuFilme);
            break;

        case 4:
            carregarFilme(meuFilme);
            break;

        case 5:
            cout << "Saindo do programa.." << endl;
            break;

        default:
            cout << "opcao invalida" << endl;
            break;
        }
    }

    return 0;
}