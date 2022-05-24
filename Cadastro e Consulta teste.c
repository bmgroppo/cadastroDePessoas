#include <stdio.h>
#include <stdlib.h>

//Estrutura que sera usada para realizar cadastro
struct tipo_cadastro
{

       int cod;
       char cliente[60];
       char endereco[60];
       int tel;
       //int anofab;
       //float precovenda;
       //float precocusto;
       //char produtora[60];
       int vazio;

} registros[100];

//Funçoes que serao usadas
void cadastrar(int cod, int pos);

//Funçao para consulta
void consultar( void );

//Funçao para exibir relatorio
//int relatorio( void );

//Função para verificar posição
int verifica_pos( void );

//Função para verificar codigo
int verifica_cod( int cod );

//Função para verificar posição do codigo
int verifica_pos( void );

//Função para excluir cadastro
void excluir( void );

//Começo do programa principal
int main( void )
{
    int op = 0, posicao, codaux, retorno;

    while ( op != 5 )
    {
        printf("\n\n\t\t\t\t** Cadastro e Consulta de Clientes**\n\n\n");
        printf("MENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Relatorio\n5 - Sair\n\nOpcao: ");
        scanf("%d",&op);
        system("cls");
        switch ( op )
        {
            case 1: // CADASTRAR
            {

                posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com o codigo de cadastro do Cliente: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastrar( codaux, posicao );
                    else
                        printf("\nCodigo ja existente\n");

                }
                else
                    printf("\nNao e possivel realizar mais cadastros!\n");

                break;

            }
            case 2: // CONSULTAR
            {
                consultar();
                break;
            }
            case 3:
            {
                excluir();
                break;
            }
            case 4:
            {
                system("cls");
                printf("Opcao indisponivel");
                break;
            } // FALTOU
            case 5:
            {
                 printf("\n Programa de cadastro e Consulta de Clientes by Bruno Groppo - Tchau");
                 getchar();
                 break;
            }
            default :
                printf("Opcao Invalida");
                break;
        }
    }
  

    getchar();

    return 0;

}//Final da Main

// FUNÇAO CADASTRAR
void cadastrar( int cod, int pos )
{
    pos = verifica_pos();

    registros[pos].cod = cod;

    //printf("\nProdutora:\n");
    //gets(registros[pos].produtora);

    printf("\nNome do Cliente:\n");
    gets(registros[pos].cliente);

    printf("\nEndereco:\n");
    gets(registros[pos].endereco);

    
    /*printf("\nAno de Fabricacao:\n");
    while ( ( registros[pos].anofab  < 1910 ) || ( registros[pos].anofab > 2020 ) )
    {
        scanf("%d",&registros[pos].anofab);
        if ( ( registros[pos].anofab < 1910 ) || ( registros[pos].anofab > 2020 ) )
            printf("Ano invalido, digite ano entre 1910 e 2020:");
    }

    printf("\nPreco de custo:\n");
    while ( registros[pos].precocusto <= 0 )
    {
               scanf("%f", &registros[pos].precocusto );
               if ( registros[pos].precocusto <= 0 )
                printf("Valor invalido, digite um valor acima de 0:");
    }

    registros[pos].precovenda=registros[pos].precocusto+(registros[pos].precocusto/2);
*/
    printf("\nInforme o telefone:");
    scanf("%d", &registros[pos].tel );
    registros[pos].vazio = 1;

    printf("\nCadastro Realizado com Sucesso!\n\n");
    getchar();
    system("pause");

    system("cls");

} //Final da Função Cadastrar

//FUNÇÃO CONSULTAR
void consultar( void )
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);

    system("cls");

    while ( cont <= 100 )
    {

        if (registros[cont].cod==cod)
        {
            if (registros[cont].vazio==1)
            {

                //printf("\nProdutora: \n%s\n",registros[cont].produtora);
                printf("\nNome do Cliente: \n%s\n",registros[cont].cliente);
                printf("\nEndereco: \n%s\n",registros[cont].endereco);
                //printf("\nAno de fabricacao: \n%d\n",registros[cont].anofab);
                //printf("\nPreco de venda: \nR$%.2f\n",registros[cont].precovenda);
                printf("\nTelefone:\n%d\n",registros[cont].tel);
                printf("\n");

                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 100 )
            printf("\nCodigo nao encontrado\n");

    }
}

//FUNÇÃO VERIFICA POSIÇÃO
int verifica_pos( void )
{
    int cont = 0;

    while ( cont <= 100 )
    {

        if ( registros[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

}

//FUNÇÃO ZERAR
void zerar( void )
{
    int cont;

    for ( cont = 0; cont <= 100; cont++ )
        registros[cont].vazio = 0;
}

//FUNÇÃO VERIFICA CODIGO
int verifica_cod( int cod )
{
    int cont = 0;

    while ( cont <= 100 )
    {
        if ( registros[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

}

//FUNÇÃO EXCLUIR
void excluir( void )
{
    int cod, cont = 0;
    char resp;

    printf("\nEntre com o codigo do registro que deseja excluir\n");
    scanf("%d", &cod );

    while ( cont <= 100 )
    {

        if ( registros[cont].cod == cod )
        { // FALTOU

            if ( registros[cont].vazio == 1 )
            {

                //printf("\nProdutora: \n%s\n", registros[cont].produtora );
                printf("\nNome do Cliente \n%s\n", registros[cont].cliente );
                printf("\nEndereco: \n%s\n", registros[cont].endereco );
                //printf("\nAno de fabricacao: \n%d\n", registros[cont].anofab );
                //printf("\nPreco de venda: \nR$%.2f\n", registros[cont].precovenda );
                printf("\nTelefone:\n%d\n", registros[cont].tel );
                getchar();

                printf("\nDeseja realmente exlucir? S/N:");
                scanf("%c",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    registros[cont].vazio=0;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 100 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}