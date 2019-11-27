#include "Biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Menu
void Msg_Menu()
{

    printf("\n>>>>>>>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("\n\t1. MÓDULO 1 - LIVRO");
    printf("\n\t2. MÓDULO 2 - USUÁRIO");
    printf("\n\t3. MÓDULO 3 - EMPRÉSTIMO");
    printf("\n\t4. SAIR");

}

void Msg_Submenu(int numero_modulo)
{

    char modulo[20];

    switch(numero_modulo)
    {

    case 1:
        strcpy(modulo, "USUÁRIOS");
        break;

    case 2:
        strcpy(modulo, "LIVROS");
        break;

    case 3:
        strcpy(modulo, "EMPRÉSTIMO");
        break;

    default:
        system("pause");

    }

    system("cls");
    if(strcmp(modulo,"EMPRÉSTIMO")==0)
    {
        printf("\n>>>>>>>>>>>>>>> MÓDULO DE %s: <<<<<<<<<<<<<<<\n", modulo);
        printf("\n\t1. INSERIR \n");
        printf("\t2. PESQUISAR \n");
        printf("\t3. ALTERAR \n");
        printf("\t4. EXCLUIR \n");
        printf("\t5. IMPRIMIR TODOS \n");
        printf("\t6. DAR BAIXA \n");
        printf("\t7. EFETUAR PAGAMENTO \n");
        printf("\t8. TOTAL DE MULTAS");
        printf("\t9. SAIR");
    }
    else if(strcmp(modulo,"LIVROS")==0)
    {
        printf("\n>>>>>>>>>>>>>>> MÓDULO DE %s: <<<<<<<<<<<<<<<\n", modulo);
        printf("\n\t1. INSERIR \n");
        printf("\t2. PESQUISAR \n");
        printf("\t3. ALTERAR \n");
        printf("\t4. EXCLUIR \n");
        printf("\t5. IMPRIMIR TODOS \n");
        printf("\t6. LIVRO MAIS EMPRESTADO \n");
        printf("\t7. SAIR");
    }
    else
    {
        printf("\n>>>>>>>>>>>>>>> MÓDULO DE %s: <<<<<<<<<<<<<<<\n", modulo);
        printf("\n\t1. INSERIR \n");
        printf("\t2. PESQUISAR \n");
        printf("\t3. ALTERAR \n");
        printf("\t4. EXCLUIR \n");
        printf("\t5. IMPRIMIR TODOS \n");
        printf("\t6. SAIR \n");
    }


}


//Usuario

void LerUsuario(TUsuario *user)
{

    printf("Informe o primeiro nome:\n");
    fflush(stdin);
    fgets(user->nome, 30, stdin);

    printf("\nInforme o sobrenome:\n");
    fflush(stdin);
    fgets(user->sobrenome, 50, stdin);

    printf("\nInforme o CPF:\n");
    fflush(stdin);
    fgets(user->cpf, 12, stdin);

    printf("\nInforme o RG:\n");
    fflush(stdin);
    fgets(user->RG, 10, stdin);

    printf("\nInforme o endereço: \nRua:\n");
    fflush(stdin);
    fgets(user->endereco.rua, 50, stdin);

    printf("\nNúmero:\n");
    fflush(stdin);
    scanf("%d", &user->endereco.numero);

    printf("\nComplemento:\n");
    fflush(stdin);
    fgets(user->endereco.complemento, 30, stdin);

    printf("\nBairro:\n");
    fflush(stdin);
    fgets(user->endereco.bairro, 50, stdin);

    printf("\nCidade:\n");
    fflush(stdin);
    fgets(user->endereco.cidade, 50, stdin);

    printf("\nCEP:\n");
    fflush(stdin);
    fgets(user->endereco.CEP, 11, stdin);

    printf("\nInforme a data de nascimento\nDia:\n");
    fflush(stdin);
    scanf("%d", &user->DataNascimento.dia);

    printf("\nMÊs:\n");
    fflush(stdin);
    scanf("%d", &user->DataNascimento.mes);

    printf("\nAno:\n");
    fflush(stdin);
    scanf("%d", &user->DataNascimento.ano);

    printf("\nAgora, informe o tipo de usuário:\nDigite 1 se o usuário for Professor;\nDigite 2 se o usuário for Aluno;\nDigite 3 se usuário for Funcionário:\n");
    fflush(stdin);
    scanf("%d", &user->TipoUsuario);

    if(user->TipoUsuario == 1)
    {
        printf("\nInforme o SIAPE do professor:\n");
        fflush(stdin);
        fgets(user->siape, 20, stdin);
        printf("\nInforme o departamento do professor:\n");
        fflush(stdin);
        fgets(user->departamento, 40, stdin);
    }
    else if(user->TipoUsuario == 2)
    {
        printf("\nInforme a matrícula do aluno:\n");
        fflush(stdin);
        fgets(user->matricula, 20, stdin);
        printf("\nInforme o curso do aluno:\n");
        fflush(stdin);
        fgets(user->curso, 50, stdin);
    }
    else if(user->TipoUsuario == 3)
    {
        printf("\nInforme o SIAPE do funcionário:\n");
        fflush(stdin);
        fgets(user->siape, 20, stdin);
        printf("\nInforme o departamento do funcionário:\n");
        fflush(stdin);
        fgets(user->departamento, 40, stdin);
    }

    user->multa = 0;
    user->qtd_Livros = 0;

    printf("\nLeitura de dados realizada com sucesso!\n");


}

void ImprimirUsuario(TUsuario user)
{

    printf("Nome: %s %s\n", user.nome, user.sobrenome);
    printf("CPF: %s\n", user.cpf);
    printf("RG: %s\n", user.RG);
    if(user.TipoUsuario == 1 || user.TipoUsuario == 3)
    {
        printf("Siape: %s\n", user.siape);
        printf("Departamento: %s\n", user.departamento);
    }
    else if (user.TipoUsuario == 2)
    {
        printf("Matrícula: %s\n", user.matricula);
        printf("Curso: %s\n", user.curso);
    }
    printf("Data de nascimento: %d/%d/%d\n", user.DataNascimento.dia, user.DataNascimento.mes, user.DataNascimento.ano);
    printf("Endereço:\nRua: %s\nNúmero: %d\n", user.endereco.rua, user.endereco.numero);
    printf("Complemento: %s\nBairro: %s\n", user.endereco.complemento, user.endereco.bairro);
    printf("Cidade: %s\nCEP: %s\n", user.endereco.cidade, user.endereco.CEP);
    printf("Quantidade de livros sob a custódia do usuário: %d\n", user.qtd_Livros);
    printf("Valor acumulado de multas: R$%.2f\n", user.multa);

}






int PesquisarUsuario(TUsuario user, TModuloUsuario modulo)
{

    for(int i = 0; i < modulo.indice; i++)
    {
        if(strcmp(user.cpf, modulo.Usuarios[i].cpf) == 0)
        {
            return i;
        }/* if(i == modulo.indice - 1) {
            printf("Usuário não encontrado. Tente novamente.\n");
            system("pause");
        }*/
    }
    return -1;
}

void IniciarModuloUsuario(TModuloUsuario *modulo)
{

    modulo->indice = 0;

}

void InserirUsuario(TModuloUsuario *modulo, TUsuario user)
{

    modulo->Usuarios[modulo->indice] = user;
    modulo->indice++;

    printf("Usuário cadastrado com suceso.\n");
    system("pause");

}

void ImprimirTodosUsuarios(TModuloUsuario modulo)
{

    for(int i = 0; i < modulo.indice; i++)
    {
        ImprimirUsuario(modulo.Usuarios[i]);
    }

}

void AlterarUsuario(TUsuario user, TModuloUsuario* modulo)
{

    int IndiceUser = PesquisarUsuario(user, *modulo);

    if(IndiceUser != -1)
    {
        printf("Faça as alterações:\n");
        LerUsuario(&modulo->Usuarios[IndiceUser]);
    }
    else
    {
        printf("Usuário não encontrado. Tente novamente.\n");
        system("pause");
    }

}

void ExcluirUsuario(TUsuario user, TModuloUsuario* modulo)
{

    int IndiceUser = PesquisarUsuario(user, *modulo);

    if(IndiceUser != -1)
    {
        for(int i = IndiceUser; i < modulo->indice; i++)
        {
            modulo->Usuarios[IndiceUser] = modulo->Usuarios[IndiceUser + 1];
        }
        modulo->indice--;
    }
    else
    {
        printf("Usuário não encontrado. Tente novamente.\n");
        system("pause");
    }

}

void SubMenuModuloUsuarios(TModuloUsuario* modulo, TUsuario usuario)
{

    int opcao = 0;
    int indice = 0;

    do
    {
        Msg_Submenu(1);

        printf("\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            LerUsuario(&usuario);
            InserirUsuario(modulo, usuario);
            break;

        case 2:
            printf("Informe o CPF do usuário a ser pesquisado:\n");
            fflush(stdin);
            fgets(usuario.cpf, 12, stdin);
            indice = PesquisarUsuario(usuario, *modulo);
            if(indice != -1)
            {
                ImprimirUsuario(modulo->Usuarios[indice]);
                system("pause");
            }
            else
            {
                printf("Você não possui usuários cadastrados.\n");
                system("pause");
            }
            break;

        case 3:
            printf("Informe o CPF do usuário a ser alterado:\n");
            fflush(stdin);
            fgets(usuario.cpf, 12, stdin);
            indice = PesquisarUsuario(usuario, *modulo);
            AlterarUsuario(usuario, modulo);
            system("pause");
            break;

        case 4:
            printf("Informe o CPF do usuário a ser excluído:\n");
            fflush(stdin);
            fgets(usuario.cpf, 12, stdin);
            indice = PesquisarUsuario(usuario, *modulo);
            ExcluirUsuario(usuario, modulo);
            break;

        case 5:
            ImprimirTodosUsuarios(*modulo);
            system("pause");
            break;

        case 6:
            printf("Saindo do modulo de usuários...\n");
            system("pause");
            break;

        default:
            printf("Opção inválida. Tente novamente!\n");
            system("pause");

        }

    }
    while(opcao != 6);

}



//Livro

void LerLivro(TLivro* book)
{

    printf("Informe o título do livro:\n");
    fflush(stdin);
    fgets(book->titulo, 50, stdin);

    printf("Informe a edição do livro:\n");
    fflush(stdin);
    scanf("%d", &book->edicao);

    printf("Informe o isbn do livro:\n");
    fflush(stdin);
    fgets(book->isbn, 20, stdin);

    printf("Informe o primeiro autor do livro:\n");
    fflush(stdin);
    fgets(book->autor1, 40, stdin);

    printf("Informe o segundo autor do livro:\n");
    fflush(stdin);
    fgets(book->autor2, 40, stdin);

    printf("Informe a editora do livro:\n");
    fflush(stdin);
    fgets(book->editora, 30, stdin);

    printf("Informe o local de publicação do livro:\n");
    fflush(stdin);
    fgets(book->localPublicacao, 40, stdin);

    printf("Informe a data de publicação do livro:\nDia:\n");
    fflush(stdin);
    scanf("%d", &book->dataPublicacao.dia);

    printf("Mês:\n");
    fflush(stdin);
    scanf("%d", &book->dataPublicacao.mes);

    printf("Ano:\n");
    fflush(stdin);
    scanf("%d", &book->dataPublicacao.ano);

    printf("Informe a quantidade de livros disponíveis:\n");
    fflush(stdin);
    scanf("%d", &book->quantidade);

    book->emprestados = 0;

    printf("Leitura de dados realizada com sucesso!\n");


}

void ImprimirLivro(TLivro book)
{

    printf("Título: %s\n", book.titulo);

    printf("Edição: %d\n", book.edicao);

    printf("Isbn: %s\n", book.isbn);

    printf("Primeiro autor: %s\n", book.autor1);

    printf("Segundo autor: %s\n", book.autor2);

    printf("Editora: %s\n", book.editora);

    printf("Local de publicação: %s\n", book.localPublicacao);

    printf("Data de publicação:\nDia: %d\n", book.dataPublicacao.dia);

    printf("Mês: %d\n", book.dataPublicacao.mes);

    printf("Ano: %d\n", book.dataPublicacao.ano);

    printf("Quantidade total de exemplares: %d\n", book.quantidade);

    printf("Exemplares emprestados: %d\n\n", book.emprestados);

}





void InicializarModuloLivro(TModuloLivro *modulo)
{

    modulo->indice = 0;

}

void InserirLivro(TModuloLivro *modulo, TLivro book)
{

    modulo->Livros[modulo->indice] = book;
    modulo->indice++;

    printf("Livro cadastrado com sucesso!\n");
    system("pause");

}

void ImprimirTodosLivros(TModuloLivro modulo)
{

    for(int i = 0; i < modulo.indice; i++)
    {
        ImprimirLivro(modulo.Livros[i]);
    }

}

int PesquisarLivro(TLivro book, TModuloLivro modulo)
{

    for(int i = 0; i < modulo.indice; i++)
    {
        if(strcmp(book.isbn, modulo.Livros[i].isbn) == 0)
        {
            return i;
        } /*if(i == modulo.indice - 1) {
            printf("Livro não encontrado. Tente novamente.\n");
            system("pause");
        }*/
    }
    return -1;
}

void AlterarLivro(TLivro book, TModuloLivro* MLivros,TModuloEmprestimo *MEmprestimo)
{

    int IndiceLivro = PesquisarLivro(book, *MLivros);
    char isbn[14];

    strcpy(isbn,MLivros->Livros[IndiceLivro].isbn);




    if(IndiceLivro == -1)
    {
        printf("Faça as alterações:\n");
        LerLivro(&MLivros->Livros[IndiceLivro]);
        for(int i=0; i<MEmprestimo->indice; i++)
        {
            if(strcmp(MEmprestimo->Emprestimos[i].isbn,isbn)==0)
            {
                strcpy(MEmprestimo->Emprestimos[i].isbn,MLivros->Livros[IndiceLivro].isbn);
            }
        }
    }
    else
    {
        printf("Livro não encontrado. Tente novamente.\n");
        system("pause");
    }

}

void ExcluirLivro(TLivro book, TModuloLivro* modulo)
{
    int i=0;
    int IndiceLivro = PesquisarLivro(book, *modulo);

    if(IndiceLivro != -1)
    {
        for( i = IndiceLivro; i < modulo->indice; i++)
        {
            modulo->Livros[IndiceLivro] = modulo->Livros[IndiceLivro + 1];
        }
        modulo->indice--;

        printf("Livro excluído com sucesso.\n");
        system("pause");
    }
    else
    {
        printf("Livro não encontrado. Tente novamente.\n");
        system("pause");
    }

}
void MaisEmprestado(TModuloLivro *modulo)
{
    int Emprestado=modulo->Livros[0].totalemprestados;
    char isbn[14];
    for(int i=0; i<modulo->indice; i++)
    {
        if(Emprestado<modulo->Livros[i].totalemprestados)
        {
            Emprestado=modulo->Livros[i].totalemprestados;
            fflush(stdin);
            strcpy(isbn,modulo->Livros[i].isbn);
        }
    }
    printf("O livro mais emprestado e %s",isbn);
    system("pause");
}
void SubMenuModuloLivros(TModuloLivro* modulo, TLivro book,TModuloEmprestimo *MEmpretimo)
{

    int opcao = 0;
    int indice = 0;

    do
    {
        Msg_Submenu(2);

        printf("\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            LerLivro(&book);
            InserirLivro(modulo, book);
            break;

        case 2:
            printf("Informe o isbn do livro a ser pesquisado: \n");
            fflush(stdin);
            fgets(book.isbn, 20, stdin);
            indice = PesquisarLivro(book, *modulo);
            if(indice != -1)
            {
                ImprimirLivro(modulo->Livros[indice]);
                system("pause");
            }
            else
            {
                printf("Você não possui livros cadastrados.\n");
                system("pause");
            }
            break;

        case 3:
            printf("Informe o isbn do livro a ser alterado: \n");
            fflush(stdin);
            fgets(book.isbn, 20, stdin);
            indice = PesquisarLivro(book, *modulo);
            AlterarLivro(book, modulo,MEmpretimo);
            break;

        case 4:
            printf("Informe o isbn do livro a ser excluído: \n");
            fflush(stdin);
            fgets(book.isbn, 20, stdin);
            indice = PesquisarLivro(book, *modulo);
            ExcluirLivro(book, modulo);
            break;

        case 5:
            ImprimirTodosLivros(*modulo);
            system("pause");
            break;


        case 6:
            MaisEmprestado(modulo);
            system("pause");
            break;
        case 7:
            printf("Saindo do modulo de livros...\n");
            system("pause");
            break;

        default:
            printf("Opção inválida. Tente novamente!\n");
            system("pause");

        }

    }
    while(opcao != 7);

}



//Emprestimo

void LerEmprestimo(TEmprestimo *borrow)
{

    printf("Informe o CPF do usuário que fará o empréstimo:\n");
    fflush(stdin);
    fgets(borrow->cpf, 11, stdin);

    printf("Informe o ISBN do livro que será emprestado:\n");
    fflush(stdin);
    fgets(borrow->isbn, 20, stdin);

    printf("Informe a data do empréstimo:\nDia:\n");
    fflush(stdin);
    scanf("%d", &borrow->DataEmprestimo.dia);

    printf("Mês:\n");
    fflush(stdin);
    scanf("%d", &borrow->DataEmprestimo.mes);

    printf("Ano:\n");
    fflush(stdin);
    scanf("%d", &borrow->DataEmprestimo.ano);

    borrow->multa = 0;
    borrow->DataEntrega.dia = 0;
    borrow->DataEntrega.mes = 0;
    borrow->DataEntrega.ano = 0;
    borrow->DataDevolucao.dia = 0;
    borrow->DataDevolucao.mes = 0;
    borrow->DataDevolucao.ano = 0;

    printf("Dados lidos com sucesso!\n");

}

void ImprimirEmprestimo(TEmprestimo borrow)
{

    printf("CPF do usuário: %s\n", borrow.cpf);
    printf("ISBN do livro: %s\n", borrow.isbn);
    printf("Data do empréstimo: %d/%d/%d\n", borrow.DataEmprestimo.dia, borrow.DataEmprestimo.mes, borrow.DataEmprestimo.ano);
    printf("Data prevista para entrega: %d/%d/%d\n", borrow.DataEntrega.dia, borrow.DataEntrega.mes, borrow.DataEntrega.ano);
    printf("Data de devolução: %d/%d/%d\n", borrow.DataDevolucao.dia, borrow.DataDevolucao.mes, borrow.DataDevolucao.ano);

}






void IniciarModuloEmprestimo(TModuloEmprestimo *modulo)
{

    modulo->indice = 0;

}

int PesquisarEmprestimo(TModuloEmprestimo modulo, TEmprestimo borrow)
{

    for(int i = 0; i < modulo.indice; i++)
    {
        if((strcmp(modulo.Emprestimos[i].cpf, borrow.cpf) == 0) &&
                (strcmp(modulo.Emprestimos[i].isbn, borrow.isbn) == 0) &&
                (modulo.Emprestimos[i].DataEmprestimo.dia == borrow.DataEmprestimo.dia) &&
                (modulo.Emprestimos[i].DataEmprestimo.mes == borrow.DataEmprestimo.mes) &&
                (modulo.Emprestimos[i].DataEmprestimo.ano == borrow.DataEmprestimo.ano))
        {
            return i;
        }/* if(i == modulo.indice - 1) {
            printf("Empréstimo não encontrado. Tente novamente.\n");
            system("pause");
        }*/
    }
    return -1;
}

void AlterarEmprestimo(TModuloEmprestimo* modulo, TEmprestimo borrow)
{

    int IndiceEmprestimo = PesquisarEmprestimo(*modulo, borrow);

    if(IndiceEmprestimo != -1)
    {
        printf("Faça as alterações:\n");
        LerEmprestimo(&modulo->Emprestimos[IndiceEmprestimo]);
    }
    else
    {
        printf("Emprestimo não encontrado. Tente novamente.\n");
        system("pause");
    }

}

void ExcluirEmprestimo(TModuloEmprestimo* modulo, TEmprestimo borrow)
{

    int IndiceEmprestimo = PesquisarEmprestimo(*modulo, borrow);

    if(IndiceEmprestimo != -1)
    {
        for(int i = IndiceEmprestimo; i < modulo->indice; i++)
        {
            modulo->Emprestimos[i] = modulo->Emprestimos[i + 1];
        }
        modulo->indice--;
    }
    else
    {
        printf("Empréstimo não encontrado. Tente novamente.\n");
        system("pause");
    }

}

void ImprimirTodosEmprestimos(TModuloEmprestimo modulo)
{

    for(int i = 0; i < modulo.indice; i++)
    {
        ImprimirEmprestimo(modulo.Emprestimos[i]);
    }

}


int QuantidadeDiasMes(int mes)
{

    int dias = 0;

    switch(mes)
    {

    case 1:
        dias = 31;
        break;

    case 2:
        dias = 28;
        break;

    case 3:
        dias = 31;
        break;

    case 4:
        dias = 30;
        break;

    case 5:
        dias = 31;
        break;

    case 6:
        dias = 30;
        break;

    case 7:
        dias = 31;
        break;

    case 8:
        dias = 31;
        break;

    case 9:
        dias = 30;
        break;

    case 10:
        dias = 31;
        break;

    case 11:
        dias = 30;
        break;

    case 12:
        dias = 31;
        break;

    default:
        printf("Erro ao calcular o número de dias do mês. Tente novamente.\n");
        system("pause");

    }

    return dias;
}

TData CalcularDataEntrega(TData DataEmprestimo)
{

    TData DataEntrega;
    DataEntrega.dia=0;
    int DiasMes = QuantidadeDiasMes(DataEmprestimo.mes);

    if(DataEmprestimo.mes == 12 && DataEmprestimo.dia >= 18)
    {
        DataEntrega.ano = DataEmprestimo.ano + 1;
        DataEntrega.mes = 1;
        DataEntrega.dia = 14 - (31 - DataEmprestimo.dia);
    }
    else if(DiasMes - DataEmprestimo.dia < 14)
    {
        DataEntrega.ano = DataEmprestimo.ano;
        DataEntrega.mes = DataEmprestimo.mes + 1;
        DataEntrega.dia = 14 - (DiasMes - DataEmprestimo.dia);
    }
    else
    {
        DataEntrega.ano = DataEmprestimo.ano;
        DataEntrega.mes = DataEmprestimo.mes;
        DataEntrega.dia = DataEntrega.dia + 14;
    }

    return DataEntrega;
}

void InserirEmprestimo(TModuloEmprestimo* MEmprestimo, TEmprestimo borrow, TModuloUsuario* MUsuario, TUsuario user, TModuloLivro* MLivro, TLivro book)
{

    int IndiceUsuario;//PesquisarUsuario(user, *MUsuario);
    int IndiceLivro;//PesquisarLivro(book, *MLivro);
    strcpy(user.cpf,borrow.cpf);
    strcpy(book.isbn,borrow.isbn);
    IndiceUsuario = PesquisarUsuario(user, *MUsuario);
    IndiceLivro = PesquisarLivro(book, *MLivro);

    user=MUsuario->Usuarios[IndiceUsuario];
    book=MLivro->Livros[IndiceLivro];

    if(IndiceUsuario == -1)
    {
        printf("Este usuário ainda não foi cadastrado no sistema. Cadastre-o e tente novamente.\n");
        system("pause");
    }
    else if(IndiceLivro == -1)
    {
        printf("Este livro ainda não foi cadastrado no sistema. Cadastre-o e tente novamente.\n");
        system("pause");
    }
    else
    {
        int LivrosDisponiveis = (MLivro->Livros[IndiceLivro].quantidade - MLivro->Livros[IndiceLivro].emprestados);

        if(LivrosDisponiveis > (MLivro->Livros[IndiceLivro].quantidade / 10))
        {

            system("PAUSE");
            if(user.TipoUsuario == 1)
            {
                if(user.qtd_Livros < 5&&user.multa==0)
                {
                    borrow.DataEntrega = CalcularDataEntrega(borrow.DataEmprestimo);
                    MLivro->Livros[IndiceLivro].emprestados++;
                    MLivro->Livros[IndiceLivro].totalemprestados++;
                    MEmprestimo->Emprestimos[MEmprestimo->indice] = borrow;
                    MEmprestimo->indice++;
                    MUsuario->Usuarios[IndiceUsuario].qtd_Livros++;
                    printf("Empréstimo realizado com sucesso!\n");
                    system("PAUSE");
                }
                else
                {
                    printf("Não é possível realizar o empréstimo. O usuário já atingiu o limite de livros emprestados.\n");
                    system("PAUSE");
                }
            }
            else if(user.TipoUsuario == 2 || user.TipoUsuario == 3)
            {
                if(user.qtd_Livros < 3&&user.multa==0)
                {
                    borrow.DataEntrega = CalcularDataEntrega(borrow.DataEmprestimo);
                    MLivro->Livros[IndiceLivro].emprestados++;
                    MLivro->Livros[IndiceLivro].totalemprestados++;
                    MEmprestimo->Emprestimos[MEmprestimo->indice] = borrow;
                    MEmprestimo->indice++;
                    MUsuario->Usuarios[IndiceUsuario].qtd_Livros++;
                    printf("Empréstimo realizado com sucesso!\n");
                    printf("A data de entrega esta prevista para? \n %d/%d/%d",borrow.DataEntrega.dia,borrow.DataEntrega.mes,borrow.DataEntrega.ano);
                    system("PAUSE");
                }
                else
                {
                    printf("Não é possível realizar o empréstimo. O usuário já atingiu o limite de livros emprestados.\n");
                    system("PAUSE");
                }
            }

            system("PAUSE");
        }
        else
        {
            printf("Não foi possível realizar o empréstimo, pois a biblioteca não possui exemplares suficentes.\n");
            system("PAUSE");
        }
    }
}

void BaixaEmprestimo(TEmprestimo borrow, TModuloEmprestimo *MEmprestimo, TModuloLivro *TLivro, TModuloUsuario *MUsuario)
{

    int dias = 0;
    int multa = 0;
    int opcao = 0;

    TUsuario usuario;


    int IndiceEmprestimo = PesquisarEmprestimo(*MEmprestimo, borrow);

    strcpy(usuario.cpf, MEmprestimo->Emprestimos[IndiceEmprestimo].cpf);
    int IndiceUsuario = PesquisarUsuario(usuario, *MUsuario);

    printf("Informe a data de devolução do livro:\nDia:\n");
    fflush(stdin);
    scanf("%d",&MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.dia);

    printf("\nMês:\n");
    fflush(stdin);
    scanf("%d",&MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.mes);

    printf("\nAno:\n");
    fflush(stdin);
    scanf("%d",&MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.ano);

    if(MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.ano > MEmprestimo->Emprestimos[IndiceEmprestimo].DataEntrega.ano)
    {
        if(MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.mes > MEmprestimo->Emprestimos[IndiceEmprestimo].DataEntrega.mes)
        {

            for(int i = MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.mes; i > 0; i--)
            {
                dias = dias + QuantidadeDiasMes(i);
            }

            for(int i = 12; i > MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes; i--)
            {
                dias = dias + QuantidadeDiasMes(i);
            }
            dias = dias + (QuantidadeDiasMes(MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes) - MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.dia);

        }
        else
        {

            for(int i = MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.mes; i > 0; i--)
            {
                dias = dias + QuantidadeDiasMes(i);
            }

            for(int i = 12; i > MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes; i--)
            {
                dias = dias + QuantidadeDiasMes(i);
            }
            dias = dias + (QuantidadeDiasMes(MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes) - MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.dia);

        }

    }
    else
    {
        if(MEmprestimo->Emprestimos[IndiceEmprestimo].DataDevolucao.mes > MEmprestimo->Emprestimos[IndiceEmprestimo].DataEntrega.mes)
        {

            for(int i = 12; i > MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes; i--)
            {
                dias = dias + QuantidadeDiasMes(i);
            }
            dias = dias + (QuantidadeDiasMes(MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes) - MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.dia);

        }
        else
        {

            dias = dias + (QuantidadeDiasMes(MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.mes) - MEmprestimo->Emprestimos[IndiceEmprestimo].DataEmprestimo.dia);

        }

    }

    multa = dias * 2;
    MEmprestimo->Emprestimos[IndiceEmprestimo].multa=multa;
    MUsuario->Usuarios[IndiceUsuario].multa=multa;
    if(multa > 0)
    {
        printf("A multa por este empréstimo é de R$%.2f. O usuário deseja pagar a multa agora?\nSe sim, digite 1, se não, digite 2:\n",MUsuario->Usuarios[IndiceUsuario].multa);
        fflush(stdin);
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            printf("Multa paga com sucesso!\n");
            system("pause");
        }
        else if (opcao == 2)
        {
            MUsuario->Usuarios[IndiceUsuario].multa = MUsuario->Usuarios[IndiceUsuario].multa + multa;
        }
    }

}
void EfetuarPagamento(TModuloEmprestimo *MEmprestimo, TEmprestimo borrow,TModuloUsuario *MUsuario,TUsuario user)
{
    int IndiceEmprestimo=0,IndiceUsuario=0;

    IndiceEmprestimo=PesquisarEmprestimo(*MEmprestimo,borrow);

    IndiceUsuario=PesquisarUsuario(user,*MUsuario);
    if(IndiceEmprestimo!=-1)
    {
        MEmprestimo->Emprestimos[IndiceEmprestimo].multa=0.0;
        MUsuario->Usuarios[IndiceUsuario].multa=0.0;
        printf("Pagamento realizado com sucesso");
    }
    else
    {
        printf("O usuario que desejou nao foi encontrado");
    }




}
void TotaldasMultas(TModuloEmprestimo *MEmprestimo)
{
    float totalmulta=0.0;
    int quant=0;


    for(int i=0; i<MEmprestimo->indice; i++)
    {
        if(MEmprestimo->Emprestimos[i].multa>0)
        {
            totalmulta=totalmulta+MEmprestimo->Emprestimos[i].multa;

            quant++;

        }
    }
    printf("O total das multas sao R$%.2f\n e a quantidade de livros relacionados %d",totalmulta,quant);
}
//void LivrosemComum(TModuloEmprestimo *MEmprestimo,char usuario1[],char usuario2[]){
//char isbns1[14];
//int cont=0;
//for(int i=0;i<MEmprestimo->indice;i++){
//      strcpy(isbns1,MEmprestimo->Emprestimos[i].isbn);
//    for(int j=0;j<=14;j++){
// if(usuario1==MEmprestimo->Emprestimos[j].cpf){
//   if(strcmp(isbns1,MEmprestimo->Emprestimos[j].isbn)==0){
//     cont++;
//}
//}


//}
//for(int i=0;i<MEmprestimo->indice;i++){
//      for(int j=0;j<=14;j++){
//if(strcmp(isbns1[i][j],isbns2[i][j]==0))
//}
//  }

//}
//}
void SubMenuModuloEmprestimos(TModuloEmprestimo* MEmprestimo, TEmprestimo borrow,TModuloUsuario *MUsuario,TUsuario user,TModuloLivro *MLivro, TLivro book )
{

    int opcao = 0,indice=0;

    do
    {
        Msg_Submenu(3);

        printf("\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:


            LerEmprestimo(&borrow);
            InserirEmprestimo(MEmprestimo,borrow,MUsuario,user,MLivro,book);


            break;

        case 2:
            printf("Informe o emprestimo que deseja pesquisar: \n");
            printf("Informe o CPF : \n");
            fflush(stdin);
            fgets(borrow.cpf,11,stdin);
            printf("Informe o ISBN: \n");
            fflush(stdin);
            fgets(borrow.isbn,20,stdin);
            printf("Informe a Data: \n");
            printf("Dia \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.dia);
            printf("Mes \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.mes);
            printf("Ano \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.ano);


            indice=PesquisarEmprestimo(*MEmprestimo,borrow);
            if(indice != -1)
            {
                ImprimirEmprestimo(MEmprestimo->Emprestimos[indice]);
                system("pause");
            }
            else
            {
                printf("Você não possui emprestimos.\n");
                system("pause");
            }

            break;

        case 3:
            printf("Informe o emprestimo que deseja pesquisar: \n");
            printf("Informe o CPF : \n");
            fflush(stdin);
            fgets(borrow.cpf,11,stdin);
            printf("Informe o ISBN: \n");
            fflush(stdin);
            fgets(borrow.isbn,20,stdin);
            printf("Informe a Data: \n");
            printf("Dia \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.dia);
            printf("Mes \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.mes);
            printf("Ano \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.ano);


            indice=PesquisarEmprestimo(*MEmprestimo,borrow);
            if(indice!=-1)
            {
                AlterarEmprestimo(MEmprestimo,borrow);
            }
            break;

        case 4:
            printf("Informe o emprestimo que deseja pesquisar: \n");
            printf("Informe o CPF : \n");
            fflush(stdin);
            fgets(borrow.cpf,11,stdin);
            printf("Informe o ISBN: \n");
            fflush(stdin);
            fgets(borrow.isbn,20,stdin);
            printf("Informe a Data: \n");
            printf("Dia \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.dia);
            printf("Mes \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.mes);
            printf("Ano \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.ano);


            indice=PesquisarEmprestimo(*MEmprestimo,borrow);
            if(indice!=-1)
            {
                ExcluirEmprestimo(MEmprestimo,borrow);
            }

            break;

        case 5:
            ImprimirTodosEmprestimos(*MEmprestimo);
            system("pause");
            break;

        case 6:
            printf("Informe o CPF : \n");
            fflush(stdin);
            fgets(borrow.cpf,11,stdin);
            printf("Informe o ISBN: \n");
            fflush(stdin);
            fgets(borrow.isbn,20,stdin);
            printf("Informe a Data: \n");
            printf("Dia \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.dia);
            printf("Mes \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.mes);
            printf("Ano \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.ano);

            BaixaEmprestimo(borrow,MEmprestimo,MLivro,MUsuario);
            system("pause");
            break;
        case 7:
            printf("Informe o CPF : \n");
            fflush(stdin);
            fgets(borrow.cpf,11,stdin);
            printf("Informe o ISBN: \n");
            fflush(stdin);
            fgets(borrow.isbn,20,stdin);
            printf("Informe a Data: \n");
            printf("Dia \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.dia);
            printf("Mes \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.mes);
            printf("Ano \n");
            fflush(stdin);
            scanf("%d",&borrow.DataEmprestimo.ano);
            strcpy(user.cpf,borrow.cpf);
            EfetuarPagamento(MEmprestimo,borrow,MUsuario,user);
            system("pause");

            break;
        case 8:
            TotaldasMultas(MEmprestimo);
            system("pause");

            break;
        case 9:
            printf("Saindo do modulo de emprestimos");
            system("pause");
            break;
        default:
            printf("Opção inválida. Tente novamente!\n");
            system("pause");

        }

    }
    while(opcao != 9);

}







