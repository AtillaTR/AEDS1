#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include <locale.h>


int main()
{

    setlocale(LC_ALL, "Portuguese");

    TUsuario usuario;
    TLivro livro;
    TEmprestimo emprestimo;

    TModuloUsuario moduloUsuario;
    TModuloLivro moduloLivro;
    TModuloEmprestimo moduloEmprestimo;

    InicializarModuloLivro(&moduloLivro);
    IniciarModuloEmprestimo(&moduloEmprestimo);
    IniciarModuloUsuario(&moduloUsuario);

    int opcao = 0;

    do
    {
        system("cls");

        Msg_Menu();
        printf("\n\nDigite uma opção: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:
            SubMenuModuloLivros(&moduloLivro, livro,&moduloEmprestimo);
            break;

        case 2:
            SubMenuModuloUsuarios(&moduloUsuario, usuario);
            break;

        case 3:
            SubMenuModuloEmprestimos(&moduloEmprestimo, emprestimo,&moduloUsuario, usuario,&moduloLivro, livro);
            break;

        case 4:
            printf("Saindo do programa...\n");
            system("pause");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            system("pause");
        }

    }
    while(opcao != 4);

    return 0;
}
