#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct usuario
{
    char cpf[15];
    char nome[30];
    char identidade[15];
} TUsuario;

typedef struct celula
{
    TUsuario item;
    struct celula *prox;
} TCelula;



typedef  struct fila
{
    TCelula *Frente;
    TCelula *Tras;
    int tamanho;
} TFila;

void FFVazia(TFila *fila)
{
    fila->Frente=(TCelula*)malloc(sizeof(TCelula));
    fila->Tras=fila->Frente;
    fila->Frente->prox=NULL;
    fila->tamanho=0;
}

int FilaVazia(TFila fila)
{
    return(fila.Frente==fila.Tras);
}

void Enfileirar(TFila *fila, TUsuario item)
{
    fila->Tras->prox=(TCelula*)malloc(sizeof(TCelula));
    fila->Tras=fila->Tras->prox;
    fila->Tras->prox=NULL;
    fila->Tras->item=item;
    fila->tamanho++;
}

void Desenfileirar(TFila *fila,TUsuario *item)
{
    TCelula*Aux;

    if(!FilaVazia(*fila))
    {
        Aux=fila->Frente->prox;
        *item=Aux->item;
        fila->Frente->prox=Aux->prox;
        free(Aux);

        if(fila->Frente->prox==NULL)
            fila->Tras=fila->Frente;
    }
    fila->tamanho--;
}


typedef struct
{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha)
{
    Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha)
{
    return (Pilha.topo == Pilha.fundo);
}

void Empilha(TPilha *Pilha,TUsuario x)
{
    TCelula *Aux;
    Aux = (TCelula*) malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilha(TPilha *Pilha, TUsuario *Item)
{
    TCelula *q;
    if (Vazia(*Pilha))
    {
        printf("Erro: lista vazia\n");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}

int Tamanho(TPilha Pilha)
{
    return (Pilha.tamanho);
}
void Imprimir(TUsuario user)
{
    printf("\n\n");
    printf("NOME DO USUARIO:%s",user.nome);
    printf("\nIDENTIDADE DO USUARIO:%s",user.identidade);
    printf("\nCPF DO USUARIO:%s",user.cpf);
    printf("\n\n");
}

void ImprimirGeral(TPilha p)
{
    TUsuario item;
    TPilha Aux;
    FPVazia(&Aux);

    while(!Vazia(p))
    {
        Desempilha(&p,&item);
        Empilha(&Aux,item);
    }
    while(!Vazia(Aux))
    {
        Desempilha(&Aux,&item);
        Imprimir(item);
        Empilha(&p,item);
    }
    free(Aux.fundo);
}

TUsuario Pesquisar(TPilha p,TUsuario item)
{
    TUsuario aux,retorno;
    TPilha paux;
    FPVazia(&paux);

    while(!Vazia(p))
    {
        Desempilha(&p,&aux);
        if(strcmp(aux.cpf,item.cpf)==0)
            retorno=aux;

        Empilha(&paux,aux);
    }
    while(!Vazia(paux))
    {
        Desempilha(&paux,&item);
        Empilha(&p,item);
    }
    free(paux.fundo);
    return retorno;
}

int VerificarExiste(TPilha p,TUsuario item)
{
    TUsuario aux;
    int retorno=0;
    TPilha paux;
    FPVazia(&paux);

    while(!Vazia(p))
    {
        Desempilha(&p,&aux);
        if(strcmp(aux.cpf,item.cpf)==0)
            retorno=1;

        Empilha(&paux,aux);
    }
    while(!Vazia(paux))
    {
        Desempilha(&paux,&item);
        Empilha(&p,item);
    }
    free(paux.fundo);
    return retorno;
}

void Excluir(TPilha *p,TUsuario item)
{
    TUsuario aux;
    TPilha pilhaaux;
    FPVazia(&pilhaaux);

    while(!Vazia(*p))
    {
        Desempilha(p,&aux);
        if(strcmp(aux.cpf,item.cpf)!=0)
            Empilha(&pilhaaux,aux);
    }
    while(!Vazia(pilhaaux))
    {
        Desempilha(&pilhaaux,&aux);
        Empilha(p,aux);
    }
}

void InverteComFila(TPilha *pilha)
{
    TUsuario item;
    TFila faux;
    FFVazia(&faux);

    while(!Vazia(*pilha))
    {
        Desempilha(pilha,&item);
        Enfileirar(&faux,item);
    }

    while(!FilaVazia(faux))
    {
        Desenfileirar(&faux,&item);
        Empilha(pilha,item);
    }
    free(faux.Frente);
}

void InvertecomduasPilhas(TPilha *pilha)
{
    TUsuario item;
    TPilha pilha1,pilha2;
    FPVazia(&pilha1);
    FPVazia(&pilha2);

    while(!Vazia(*pilha))
    {
        Desempilha(pilha,&item);
        Empilha(&pilha1,item);
    }

    while(!Vazia(pilha1))
    {
        Desempilha(&pilha1,&item);
        Empilha(&pilha2,item);
    }
    while(!Vazia(pilha2))
    {
        Desempilha(&pilha2,&item);
        Empilha(pilha,item);
    }
    free(pilha1.fundo);
    free(pilha2.fundo);
}

void InverteComUmaPilha(TPilha *pilha)
{
    int contador=(pilha->tamanho)-1;
    int contador2;
    TUsuario item1,item2;
    TPilha pilha1;
    FPVazia(&pilha1);

    while(contador>0)
    {
        contador2=(pilha->tamanho)-1;
        Desempilha(pilha,&item1);
        while(!Vazia(*pilha))
        {
            Desempilha(pilha,&item2);
            Empilha(&pilha1,item2);
        }

        while(!Vazia(pilha1))
        {
            if(Vazia(*pilha))
            {
                while((contador2-contador)>0)
                {
                    Desempilha(&pilha1,&item2);
                    Empilha(pilha,item2);
                    contador2--;
                }
                Empilha(pilha,item1);
            }
            Desempilha(&pilha1,&item2);
            Empilha(pilha,item2);
        }
        contador--;
    }
    free(pilha1.fundo);
}

int VerificarIgualdade(TPilha pilha1,TPilha pilha2)
{
    int retorno=1;
    TUsuario item,item1;
    TPilha aux1,aux2;
    FPVazia(&aux1);
    FPVazia(&aux2);

    if(pilha1.tamanho=pilha2.tamanho)
    {
        while(!Vazia(pilha1))
        {
            Desempilha(&pilha1,&item);
            Empilha(&aux1,item);
            Desempilha(&pilha2,&item);
            Empilha(&aux2,item);
        }
        while(!Vazia(aux1))
        {
            Desempilha(&aux1,&item);
            Desempilha(&aux2,&item1);

            if(strcmp(item.cpf,item1.cpf)!=0)
                retorno=0;

            Empilha(&pilha1,item);
            Empilha(&pilha2,item1);
        }
        free(pilha1.fundo);
        free(pilha2.fundo);
    }
    else
        return 0;

    return retorno;
}

void Intercalar(TPilha pilha1,TPilha pilha2,TPilha *pilha3)
{
    TUsuario item;
    TPilha aux1,aux2;
    FPVazia(&aux1);
    FPVazia(&aux2);

    while(!Vazia(pilha1)||!Vazia(pilha2))
    {
        if(!Vazia(pilha1))
        {
            Desempilha(&pilha1,&item);
            Empilha(&aux1,item);
        }

        if(!Vazia(pilha2))
        {
            Desempilha(&pilha2,&item);
            Empilha(&aux2,item);
        }
    }

    while(!Vazia(aux1)||!Vazia(aux2))
    {
        if(!Vazia(aux1))
        {
            Desempilha(&aux1,&item);
            Empilha(&pilha1,item);
            Empilha(pilha3,item);
        }
        if(!Vazia(aux2))
        {
            Desempilha(&aux2,&item);
            Empilha(&pilha2,item);
            Empilha(pilha3,item);
        }
    }
    free(aux1.fundo);
    free(aux2.fundo);
}

void libera(TPilha *pilha)
{
    TUsuario item;

    while(!Vazia(*pilha))
      Desempilha(pilha,&item);

    free(pilha->fundo);
}

void InserirUsuario(TUsuario *user)
{
    printf("\n\n>>>NOME:");
    fgets(user->nome,30,stdin);
    fflush(stdin);
    printf("\n\n>>>CPF:");
    fgets(user->cpf,15,stdin);
    fflush(stdin);
    printf("\n\n>>>ID:");
    fgets(user->identidade,15,stdin);
    fflush(stdin);
    printf("\n\n");
}

void MensagemMenu()
{
    printf("\n\n>>>>>>>>>>     ESCOLHA UMA OPCAO        <<<<<<<<<<\n\n");
    printf("1 - PILHA 01\n");
    printf("2 - PILHA 02\n");
    printf("3 - INTERCALAR \n");
    printf("4 - VERIFICAR SE AS PILHAS SAO IGUAIS\n");
    printf("5 - SAIR\n\n");
    printf("OPCAO:");
}

void Mensagemsubmenu()
{
    printf("\n\n");
    printf(">>>>>>>>>>     ESCOLHA UMA DAS OPCOES      <<<<<<<<<<");
    printf("\n\n");
    printf("1 - ISERIR USUARIO\n");
    printf("2 - EXCLUIR USUARIO\n");
    printf("3 - PESQUISAR\n");
    printf("4 - VERIFICAR VAZIO\n");
    printf("5 - IMPRIMIR\n");
    printf("6 - INVERTER PILHA UTILIZANDO UMA FILA\n");
    printf("7 - INVERTER PILHA UTILIZANDO DUAS PILHAS\n");
    printf("8 - INVERTER PILHA UTILIZANDO UMA PILHA\n");
    printf("9 - VERIFICAR SE ELEMENTO ESTA CADASTRADO\n");
    printf("0 - SAIR\n");
    printf("\n\nOPCAO:");
}


int main()
{
    TPilha pilha1,pilha2;
    FPVazia(&pilha1);
    FPVazia(&pilha2);
    TUsuario user;
    int opcao;

    while(opcao!=5)
    {
        system("cls");

        MensagemMenu();
        scanf("%d",&opcao);
        fflush(stdin);

        switch(opcao)
        {
        case 1:
            while(opcao!=0)
            {
                system("cls");
                printf("\n\n>>>>>>>>>>>>>>>     OPERACOES PILHA 01       <<<<<<<<<<<<<<<\n\n");
                Mensagemsubmenu();
                scanf("%d",&opcao);
                fflush(stdin);

                switch(opcao)
                {
                case 1:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>     INSERIR OS DADOS DO USUARIO      <<<<<<<<<<<<<<\n\n");
                    InserirUsuario(&user);
                    Empilha(&pilha1,user);
                    system("Pause");
                    break;

                case 2:
                    system("cls");
                    printf("\n\N>>>>>>>>>>>>>>>>     FORNECA O CPF DO USUARIO PARA EXCLUIR      <<<<<<<<<<<<<<<<\n\n");
                    printf("\nCPF: ");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    Excluir(&pilha1,user);
                    system("Pause");
                    break;

                case 3:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>>     FORNECA O CPF DO USUARIO PARA VERIFICACAO     <<<<<<<<<<<<<<<");
                    printf("\n>>>CPF: ");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);

                    if(!Vazia(pilha1))
                    {
                        if(VerificarExiste(pilha1,user)==1)
                        {
                            system("cls");
                            printf("\n\n>>>>>>>>>>>>>>>     DADOS DO USUARIO PESQUISADO     <<<<<<<<<<<<<<<\n\n");
                            Imprimir(Pesquisar(pilha1,user));
                        }
                        else
                            printf("\n\n>>>>O USUARIO NAO ESTA CADASTRADO<<<<\n\n");
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");

                    system("Pause");
                    break;

                case 4:
                    system("cls");
                    if(!Vazia(pilha1))
                        printf("\n\n>>>>A PILHA NAO ESTA VAZIA<<<<\n\n");
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");
                    system("Pause");
                    break;

                case 5:
                    system("cls");
                    if(!Vazia(pilha1))
                    {
                        printf("\n\n>>>>>>>>>>>>     DADOS DOS USUARIOS      <<<<<<<<<<<<<\n\n");
                        ImprimirGeral(pilha1);
                    }
                    else
                        printf("\n\nA PILHA ESTA VAZIA\n\n");
                    system("Pause");
                    break;

                case 6:
                    system("cls");
                    if(!Vazia(pilha1))
                    {
                        printf("\n\n>>>>>>>>>>>>>>>     PILHA INVERTIDA COM UMA FILA     <<<<<<<<<<<<<<<\n\n");
                        InverteComFila(&pilha1);
                        ImprimirGeral(pilha1);
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");
                    system("Pause");
                    break;

                case 7:
                    system("cls");
                    if(!Vazia(pilha1))
                    {
                        printf("\n\n>>>>>>>>>>>>>     PILHA INVERTIDA COM DUAS PILHAS      <<<<<<<<<<<<<<<\n\n");
                        InvertecomduasPilhas(&pilha1);
                        ImprimirGeral(pilha1);
                    }
                    else
                        printf("\n\nA PILHA ESTA VAZIA\n\n");
                    system("Pause");
                    break;

                case 8:
                    system("cls");
                    if(!Vazia(pilha1))
                    {
                        printf("\n\n>>>>>>>>>>>>     PILHA INVERTIDA COM UMA PILHA        <<<<<<<<<<<<\n\n");
                        InverteComUmaPilha(&pilha1);
                        ImprimirGeral(pilha1);
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");

                    system("Pause");
                    break;

                case 9:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>>     FORNECA O CPF DO USUARIO PARA EXCLUIR       <<<<<<<<<<<<<<<\n\n");
                    printf("\nCPF: ");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    if(VerificarExiste(pilha1,user)==1)
                        printf("\n\n>>>>USUARIO CADASTRADO<<<<\n\n");
                    else
                        printf("\n\n>>>>O USUARIO NAO ESTA CADASTRADO<<<<\n\n");
                    system("Pause");
                    break;

                case 0:
                    system("cls");
                    printf("\n\n>>>>RETORNANDO AO MENU PRINCIPAL<<<<\n\n");
                    break;

                default:
                    system("cls");
                    printf("\n\n>>>>OPCAO INVALIDA<<<<\n\n");
                    system("Pause");
                    break;
                }
            }
            break;


        case 2:
            while(opcao!=0)
            {
                system("cls");
                printf("\n\n>>>>>>>>>>>>>>>     OPERACOES PILHA 02       <<<<<<<<<<<<<<<\n\n");
                Mensagemsubmenu();
                scanf("%d",&opcao);
                fflush(stdin);

                switch(opcao)
                {
                case 1:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>     INSIRA OS DADOS DO USUARIO      <<<<<<<<<<<<<<<\n\n");
                    InserirUsuario(&user);
                    Empilha(&pilha2,user);
                    system("Pause");
                    break;

                case 2:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>     FORNECA O CPF DO USUARIO PARA EXCLUIR     <<<<<<<<<<<<<<<<\n\n");
                    printf("\nCPF: ");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    Excluir(&pilha2,user);
                    system("Pause");
                    break;

                case 3:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>     FORNECA O CPF DO USUARIO PARA VERIFICACAO      <<<<<<<<<<<<<<<\n\n");
                    printf("\nCPF: ");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);

                    if(!Vazia(pilha2))
                    {
                        if(VerificarExiste(pilha2,user)==1)
                        {
                            system("cls");
                            printf("\n\n>>>>>>>>>>>>>>     DADOS DO USUARIO     <<<<<<<<<<<<<<<\n\n");
                            Imprimir(Pesquisar(pilha2,user));
                        }
                        else
                            printf("\n\n>>>>O USUARIO NAO ESTA CADASTRADO<<<<\n\n");
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");

                    system("Pause");
                    break;

                case 4:
                    system("cls");
                    if(!Vazia(pilha2))
                        printf("\n\n>>>>A PILHA NAO ESTA VAZIA<<<<\n\n");
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");
                    system("Pause");
                    break;

                case 5:
                    system("cls");
                    if(!Vazia(pilha2))
                    {
                        printf("\n\n>>>>>>>>>>>>>>>>>     DADOS DOS USUARIOS CADASTRADOS      <<<<<<<<<<<<<<<<\n\n");
                        ImprimirGeral(pilha2);
                    }
                    else
                        printf("\n\nA PILHA ESTA VAZIA\n\n");
                    system("Pause");
                    break;

                case 6:
                    system("cls");
                    if(!Vazia(pilha2))
                    {
                        printf("\n\n>>>>>>>>>>>>>>>>>>     PILHA INVERTIDA COM UMA FILA     <<<<<<<<<<<<<<\n\n");
                        InverteComFila(&pilha2);
                        ImprimirGeral(pilha2);
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");
                    system("Pause");
                    break;

                case 7:
                    system("cls");
                    if(!Vazia(pilha2))
                    {
                        printf("\n\n>>>>>>>>>>>>>>>     PILHA INVERTIDA COM DUAS PILHAS      <<<<<<<<<<<<<<<\n\n");
                        InvertecomduasPilhas(&pilha2);
                        ImprimirGeral(pilha2);
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");
                    system("Pause");
                    break;

                case 8:
                    system("cls");
                    if(!Vazia(pilha2))
                    {
                        printf("\n\n>>>>>>>>>>>>>    PILHA INVERTIDA COM UMA PILHA        <<<<<<<<<<<<<\n\n");
                        InverteComUmaPilha(&pilha2);
                        ImprimirGeral(pilha2);
                    }
                    else
                        printf("\n\n>>>>A PILHA ESTA VAZIA<<<<\n\n");

                    system("Pause");
                    break;

                case 9:
                    system("cls");
                    printf("\n\n>>>>>>>>>>>>>>     FORNECA O CPF DO USUARIO PARA EXCLUIR       <<<<<<<<<<<\n\n");
                    printf("\nCPF: ");
                    fgets(user.cpf,20,stdin);
                    fflush(stdin);
                    if(VerificarExiste(pilha2,user)==1)
                        printf("\n\n>>>>USUARIO CADASTRADO<<<<\n\n");
                    else
                        printf("\n\n>>>>O USUARIO NAO ESTA CADASTRADO<<<\n\n");
                    system("Pause");
                    break;

                case 0:
                    system("cls");
                    printf("\n\n>>>>RETORNANDO AO MENU PRINCIPAL<<<<\n\n");
                    break;

                default:
                    system("cls");
                    printf("\n\n>>>>OPCAO INVALIDA.ESCOLHA UMA OPCAO VALIDA<<<<\n\n");
                    system("Pause");
                    break;
                }
            }
            break;

            case 3:
            system("cls");
            TPilha Auxpilha;
            FPVazia(&Auxpilha);

            if(!Vazia(pilha1)||!Vazia(pilha2))
            {
                printf("\n\n>>>>>>>>>>>>>>>>        FILA INTERCALADA        <<<<<<<<<<<<<<\n\n");
                Intercalar(pilha1,pilha2,&Auxpilha);
                ImprimirGeral(Auxpilha);
            }else
                printf("\n\n>>>>AMBAS AS PILHAS ESTAO VAZIAS<<<<\n\n");

            libera(&Auxpilha);
            system("Pause");
            break;

            case 4:
            system("cls");
            if(!Vazia(pilha1)||!Vazia(pilha2))
            {
                if(VerificarIgualdade(pilha1,pilha2))
                    printf("\n\n>>>>AS PILHAS SAO IGUAIS<<<<\n\n");
                else
                    printf("\n\n>>>>AS PILHAS NAO SAO IGUAIS<<<<\n\n");
            }
            else
                printf("\n\n>>>>AMBAS AS PILHAS ESTAO VAZIAS<<<<\n\n");

            system("Pause");
            break;
        }
    }
    return 0;
}
