/*
Nao sei como faco pra inserir as questoes aqui e fazer elas funcionarem no codigo, portanto elas estao todas no arquivo biblioteca.c junto com as demais.
Esse aquivo e somente para facilitar a vizualizacao das questoes

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

*/
