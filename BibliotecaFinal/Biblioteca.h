#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
//Menu
void Msg_Menu();
void Msg_Submenu(int numero_modulo);
//Usuario
typedef struct Endereco
{

    char rua[50], complemento[30], bairro[50], cidade[50], CEP[11];
    int numero;

} TEndereco;

typedef struct Data
{

    int dia, mes, ano;

} TData;

typedef struct Usuario
{

    char nome[30], sobrenome[50], RG[10], curso[50], cpf[12], departamento[40], siape[20], matricula[20];
    TEndereco endereco;
    TData DataNascimento;
    int TipoUsuario, qtd_Livros;
    float multa;

} TUsuario;

typedef struct ModuloUsuario
{

    TUsuario Usuarios[100];
    int indice;

} TModuloUsuario;

//Livro
typedef struct Livro
{

    int edicao, quantidade, emprestados,totalemprestados;
    char titulo[50], editora[30], autor1[40], autor2[40], localPublicacao[40], isbn[20];
    TData dataPublicacao;

} TLivro;


typedef struct ModuloLivro
{

    TLivro Livros[100];
    int indice;

} TModuloLivro;

//Emprestimo

typedef struct Emprestimo
{

    char cpf[11], isbn[20];
    float multa;
    TData DataEmprestimo, DataEntrega, DataDevolucao;

} TEmprestimo;



typedef struct ModuloEmprestimo
{

    TEmprestimo Emprestimos[100];
    int indice;

} TModuloEmprestimo;





//Usuario
void LerUsuario(TUsuario *user);

void ImprimirUsuario(TUsuario user);
void ImprimirTodosUsuarios(TModuloUsuario modulo);


int PesquisarUsuario(TUsuario user, TModuloUsuario modulo);
void IniciarModuloUsuario(TModuloUsuario *modulo);
void InserirUsuario(TModuloUsuario *modulo, TUsuario user);
void AlterarUsuario(TUsuario user, TModuloUsuario* modulo);
void ExcluirUsuario(TUsuario user, TModuloUsuario* modulo);
void SubMenuModuloUsuarios(TModuloUsuario* modulo, TUsuario usuario);

//Livro
void LerLivro(TLivro* book);
void ImprimirLivro(TLivro book);

void InicializarModuloLivro(TModuloLivro *modulo);
void InserirLivro(TModuloLivro *modulo, TLivro book);
void ImprimirTodosLivros(TModuloLivro modulo);
int PesquisarLivro(TLivro book, TModuloLivro modulo);
void AlterarLivro(TLivro book, TModuloLivro* modulo,TModuloEmprestimo*MEmprestimo);
void ExcluirLivro(TLivro book, TModuloLivro* modulo);
void SubMenuModuloLivros(TModuloLivro* modulo, TLivro book,TModuloEmprestimo *MEmprestimo);

//Emprestimo
void LerEmprestimo(TEmprestimo *borrow);
void ImprimirEmprestimo(TEmprestimo borrow);

void IniciarModuloEmprestimo(TModuloEmprestimo *modulo);
int PesquisarEmprestimo(TModuloEmprestimo modulo, TEmprestimo borrow);
void AlterarEmprestimo(TModuloEmprestimo* modulo, TEmprestimo borrow);
void ExcluirEmprestimo(TModuloEmprestimo* modulo, TEmprestimo borrow);
void ImprimirTodosEmprestimos(TModuloEmprestimo modulo);
int QuantidadeDiasMes(int mes);
TData CalcularDataEntrega(TData DataEmprestimo);
void InserirEmprestimo(TModuloEmprestimo* MEmprestimo, TEmprestimo borrow, TModuloUsuario* MUsuario, TUsuario user, TModuloLivro* MLivro, TLivro book);
void BaixaEmprestimo(TEmprestimo borrow, TModuloEmprestimo *MEmprestimo, TModuloLivro *TLivro, TModuloUsuario *MUsuario);
void EfetuarPagamento(TModuloEmprestimo *MEmprestimo, TEmprestimo borrow,TModuloUsuario *MUsuario,TUsuario user);
void SubMenuModuloEmprestimos(TModuloEmprestimo* MEmprestimo, TEmprestimo borrow,TModuloUsuario *MUsuario,TUsuario user,TModuloLivro *MLivro, TLivro book );



#endif // BIBLIOTECA_H_INCLUDED
