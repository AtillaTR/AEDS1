#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct usuario
{
    char cpf[20];
    char nome[30];
    char identidade[15];
} TUsuario;

typedef struct celula
{
    TUsuario item;
    struct celula *prox;
} TCelula;

typedef struct lista
{
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
} TLista;

void FLVazia(TLista *lista)
{
    lista->primeiro=(TCelula*)malloc(sizeof(TCelula));
    lista->ultimo=lista->primeiro;
    lista->primeiro->prox=NULL;
    lista->tamanho=0;
}

void Inserir(TLista *lista,TUsuario item)
{
    lista->ultimo->prox=(TCelula*)malloc(sizeof(TCelula));
    lista->ultimo=lista->ultimo->prox;
    lista->ultimo->prox=NULL;
    lista->ultimo->item=item;
    lista->tamanho++;
}

int VerificaVazio(TLista lista)
{
    if(lista.primeiro==lista.ultimo)
        return 1;
    else
        return 0;
}

void Imprimir(TUsuario user)
{
    printf("NOME DO USUARIO:%s",user.nome);
    printf("IDENTIDADE DO USUARIO:%s",user.identidade);
    printf("CPF DO USUARIO:%s",user.cpf);
    printf("\n\n");
}

void ImprimirGeral(TLista lista)
{

    TCelula*Aux;
    Aux=lista.primeiro->prox;
    while(Aux!=NULL)
    {
        Imprimir(Aux->item);
        Aux=Aux->prox;
    }
}


TCelula*Pesquisar(TLista lista,TUsuario item)
{
    TCelula*Aux;
    Aux=lista.primeiro->prox;

    if(Aux->prox!=NULL)
        while((strcmp(Aux->item.cpf,item.cpf)!=0)&&Aux->prox!=NULL )
        {
            if(strcmp(Aux->item.cpf,item.cpf)==0)
                Aux=Aux;
            else
                Aux=Aux->prox;
        }

    return Aux;
}

int Excluir(TLista*lista,TUsuario item)
{
    if(VerificaVazio(*lista))
        return 0;

    TCelula *p,*p1;
    p=lista->primeiro->prox;
    p1=lista->primeiro;

    while(p!=NULL&&strcmp(p->item.cpf,item.cpf)!=0)
    {
        p1=p;
        p=p->prox;
    }
    if(p==NULL)
        return 0;

    if(strcmp(lista->primeiro->prox->item.cpf,p->item.cpf)==0)
        lista->primeiro->prox=p->prox;

    if(strcmp(lista->ultimo->item.cpf,p->item.cpf)==0)
    {
        lista->ultimo=p1;
        lista->ultimo->prox=NULL;
    }

    else
        p1->prox=p->prox;

    lista->tamanho--;
    free(p);
    return 1;
}

int VerificaIgualdade(TLista lista1,TLista lista2)
{
    if(lista1.tamanho==lista2.tamanho)
    {
        TCelula *Aux1,*Aux2;
        Aux1=lista1.primeiro->prox;
        Aux2=lista2.primeiro->prox;

        while((Aux1!=NULL))
        {
            if(strcmp(Aux1->item.cpf,Aux2->item.cpf)!=0)
                return 0;
            else
            {
            Aux1=Aux1->prox;
            Aux2=Aux2->prox;
            }
        }
    }
    else
        return 0;

    return 1;
}
void Intercala(TLista lista1, TLista lista2,TLista *lista3){


    TCelula *aux1=lista1.primeiro;
    TCelula *aux2=lista2.primeiro;


    while(aux1->prox!=NULL||aux2->prox!=NULL){
            if(aux1->prox!=NULL){
               Inserir(lista3,aux1->prox->item);
               aux1 = aux1->prox;
            }
        if(aux2->prox!=NULL){
            Inserir(lista3,aux2->prox->item);

        aux2 = aux2->prox;
        }

    }

free(aux1);
free(aux2);


}
void Concatena(TLista *lista1, TLista *lista2) {

    TCelula *aux1=lista2->primeiro;
   while(aux1->prox!=NULL){
    Inserir(lista1,aux1->prox->item);

    aux1=aux1->prox;
   }
   free(aux1);
}
void Mensagemsubmenu()
{
    printf("\n\n");
    printf(">>>>>>>>>>      OPCOES      <<<<<<<<<");
    printf("\n\n");
    printf("1 - ISERIR USUARIO\n");
    printf("2 - EXCLUIR USUARIO\n");
    printf("3 - PESQUISAR\n");
    printf("4 - VERIFICAR VAZIO\n");
    printf("5 - IMPRIMIR\n");
    printf("6 - SAIR\n");
    printf("\n\nOPCAO:");
}
void MensagemMenuPrincipal()
{
    printf("\n\n");
    printf(">>>>>>>>>      ESCOLHA O QUE DESEJA FAZER COM A LISTA      <<<<<<<<<<");
    printf("\n\n");
    printf("1 - LISTA 01\n");
    printf("2 - LISTA 02\n");
    printf("3 - VERIFICAR SE AS LISTAS SAO IGUAIS\n");
    printf("4 - SAIR\n");
    printf("5 - CONCATENAR\n");
    printf("6 - INTERCALAR\n");
    printf("\n\nOPCAO:");

}

void InserirDadosUser(TUsuario *user)
{
    printf("\n\nDIGITE O NOME:");
    fgets(user->nome,30,stdin);
    fflush(stdin);
    printf("\n\nDIGITE O CPF:");
    fgets(user->cpf,20,stdin);
    fflush(stdin);
    printf("\n\nDIGITE O ID:");
    fgets(user->identidade,15,stdin);
    fflush(stdin);
}


int main()
{
    int opcao=0;
    TUsuario user;
    TLista lista1;
    TLista lista2;
    TLista lista3;
    FLVazia(&lista1);
    FLVazia(&lista2);
    FLVazia(&lista3);

    while(opcao!=4)
    {
        MensagemMenuPrincipal();
        scanf("%d",&opcao);
        fflush(stdin);
        system("cls");

        switch(opcao)
        {
        case 1:
            while(opcao!=6)
            {
                printf("\n                          >>>>>>>       OPERACOES LISTA 01       <<<<<<<\n");
                Mensagemsubmenu();
                scanf("%d",&opcao);
                fflush(stdin);

                switch(opcao)
                {
                case 1:
                    system("cls");
                    InserirDadosUser(&user);
                    Inserir(&lista1,user);
                    break;

                case 2:
                    system("cls");
                    printf("\n\n>>>>>>>>>>  DIGITE O CPF DO USUARIO QUE DESEJA EXCLUIR   <<<<<<<<<<");
                    printf("\nCPF:");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    int retorno=Excluir(&lista1,user);

                    if(retorno==0)
                        printf("\n\n>>>>O USUARIO NAO EXISTE<<<<\n\n");
                    else
                        printf("\n>>>>USUARIO EXCLUIDO COM SUCESSO<<<<\n");

                    system("Pause");
                    break;

                case 3:
                    system("cls");
                    printf("\n\n>>>>>>>>>>  DIGITE O CPF DO USUARIO QUE DESEJA ENCONTRAR   <<<<<<<<<<");
                    printf("\nCPF:");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    TCelula *c=Pesquisar(lista1,user);
                    if(c!=NULL)
                        Imprimir(c->item);
                    else
                        printf(">>>>O USUARIO NAO EXISTE<<<<");

                    system("Pause");
                    break;

                case 4:
                    system("cls");
                    int r=VerificaVazio(lista1);

                    if(r==1)
                        printf("\n\n>>>>LISTA VAZIA<<<<\n\n");
                    else
                        printf("\n\n>>>>A LISTA NAO ESTA VAZIA<<<<\n\n");

                    system("Pause");
                    break;

                case 5:
                    system("cls");
                    if(VerificaVazio(lista1))
                        printf("\n\n>>>>A LISTA ESTA VAZIA.NAO EXISTE ELEMENTOS PARA IMPRIMIR<<<<\n\n");
                    else
                        printf("\n\n>>>>>>>>>      LISTA       <<<<<<<<<\n\n");

                    ImprimirGeral(lista1);
                    system("Pause");
                    break;

                case 6:
                    system("cls");
                    printf("\n\n\n\n\n\n>>>>>>>>>>>>>     SAINDO DO SUBMENU      <<<<<<<<<<<<<<\n\n\n");
                    system("Pause");
                    break;

                default:
                    system("cls");
                    printf("\n\n>>>>A OPCAO ESCOLHIDA E INVALIDA.\nESCOLHA UMA OPCAO VALIDA<<<<\n\n");
                }
                system("cls");
            }

            break;

        case 2:
            while(opcao!=6)
            {
                printf("\n                          >>>>>>>       OPERACOES LISTA 02       <<<<<<<\n");
                Mensagemsubmenu();
                scanf("%d",&opcao);
                fflush(stdin);

                switch(opcao)
                {
                case 1:
                    system("cls");
                    InserirDadosUser(&user);
                    Inserir(&lista2,user);
                    break;

                case 2:
                    system("cls");
                    printf("\n\n>>>>>>>>>>  DIGITE O CPF DO USUARIO QUE DESEJA EXCLUIR   <<<<<<<<<<");
                    printf("\nCPF:");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    int retorno=Excluir(&lista2,user);

                    if(retorno==0)
                        printf("\n\n>>>>O USUARIO NAO EXISTE<<<<\n\n");
                    else
                        printf("\n>>>>USUARIO EXCLUIDO COM SUCESSO<<<<\n");

                    system("Pause");
                    break;

                case 3:
                    system("cls");
                    printf("\n\n>>>>>>>>>>  DIGITE O CPF DO USUARIO QUE DESEJA ENCONTRAR   <<<<<<<<<<");
                    printf("\nCPF:");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    TCelula *c=Pesquisar(lista2,user);
                    if(c!=NULL)
                        Imprimir(c->item);
                    else
                        printf(">>>>O USUARIO NAO EXISTE<<<<");

                    system("Pause");
                    break;

                case 4:
                    system("cls");
                    int r=VerificaVazio(lista2);

                    if(r==1)
                        printf("\n\n>>>>LISTA VAZIA<<<<\n\n");
                    else
                        printf("\n\n>>>>A LISTA NAO ESTA VAZIA<<<<\n\n");

                    system("Pause");
                    break;

                case 5:
                    system("cls");
                    if(VerificaVazio(lista2))
                        printf("\n\n>>>>A LISTA ESTA VAZIA.NAO EXISTE ELEMENTOS PARA IMPRIMIR<<<<\n\n");
                    else
                        printf("\n\n>>>>>>>>>>      LISTA DE DE ELEMENTOS       <<<<<<<<<<\n\n");

                    ImprimirGeral(lista2);
                    system("Pause");
                    break;


                case 6:
                    system("cls");
                    printf("\n\n\n\n\n\n>>>>>>>>>>     SAINDO DO SUBMENU      <<<<<<<<<<\n\n\n");
                    system("Pause");
                    break;

                default:
                    system("cls");
                    printf("\n\n>>>>A OPCAO ESCOLHIDA E INVALIDA.<<<<\n>>>>ESCOLHA UMA OPCAO VALIDA<<<<\n\n");
                }
                system("cls");
            }
                break;



            case 3:
                system("cls");

                if(VerificaVazio(lista1)&&VerificaVazio(lista2))
                    printf("\n\n>>>>AMBAS AS LISTA ESTAO VAZIAS<<<<<\n\n");
                else
                {
                    int res=(VerificaIgualdade(lista1,lista2));

                    if(res==1)
                        printf("\n\n>>>>AS LISTA SAO IGUAIS<<<<\n\n");
                    else
                        printf("\n\n>>>>AS LISTAS SAO DIFERENTES<<<<\n\n");
                }
                system("Pause");
                break;

            case 4:
                system("cls");
                printf("\n\n\n\n\n\n>>>>>>>>>>     SAINDO DO PROGRAMA      <<<<<<<<<<\n\n");
                system("Pause");
                break;
            case 5:
                system("cls");
                if(VerificaVazio(lista1)&&VerificaVazio(lista2))
                    printf("\n\n>>>>AMBAS AS LISTA ESTAO VAZIAS<<<<<\n\n");
                else
                {
                    Concatena(&lista1,&lista2);

                    ImprimirGeral(lista1);
                }
                system("Pause");
                break;
            case 6:
                system("cls");
                if(VerificaVazio(lista1)&&VerificaVazio(lista2))
                    printf("\n\n>>>>AMBAS AS LISTA ESTAO VAZIAS<<<<<\n\n");
                else
                {
                    Intercala(lista1,lista2,&lista3);

                    ImprimirGeral(lista3);
                }
                system("Pause");
                break;

            default:
                system("cls");
                printf("\n\n>>>>>>A OPCAO ESCOLHIDA E INVALIDA.<<<<<<\n>>>>>ESCOLHA UMA OPCAO VALIDA<<<<<<\n\n");
            }
            system("cls");
        }
    return 0;
}
