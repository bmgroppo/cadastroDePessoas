#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h> //necess�rio para usar setlocale

using namespace std;

//Estrutura que ser� usada para realizar cadastro
struct tipo_cadastro
{

       int cod;
       char cliente[60];
       char endereco[60];
       char tel[20];
       int vazio;

} registros[100];

//Fun��es que ser�o usadas
void cadastrar(int cod, int pos);

//Fun��o para consulta
void consultar();

//Fun��o para verificar posi��o
int verifica_pos();

//Fun��o para verificar c�digo
int verifica_cod( int cod );

//Fun��o para verificar posi��o do c�digo
int verifica_pos();

//Fun��o para excluir cadastro
void excluir();

//Come�o do programa principal
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    int op = 0, posicao, codaux, retorno;

// Enquanto op for diferente de 4 ele ficar� rodando o sistema
    while ( op != 4 ){
        printf("\n\n\t\t\t\t** Cadastro e Consulta de Clientes**\n\n\n");
        printf("MENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Sair\n\nOp��o: ");
        scanf("%d",&op);
        system("cls");
        switch ( op )
        {
            case 1: // CADASTRAR
            {
                posicao=verifica_pos();

                if ( posicao != -1 )
                {
                    printf("\nEntre com o c�digo de cadastro do Cliente: \n");
                    scanf("%d",&codaux);
					fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastrar( codaux, posicao );
                    else
                        printf("\nC�digo ja existente\n");
                }
                else
                    printf("\nN�o e possivel realizar mais cadastros!\n");

                break;
            }
            case 2: // CONSULTAR
            {
                consultar();
                break;
            }
            case 3: // EXCLUIR
            {
                excluir();
                break;
            }
            case 4: // SAIR
            {
                 printf("\n Programa de cadastro e Consulta de Clientes by Bruno Groppo e S�rgio Baumgartner - Tchau");
                 getchar();
                 break;
            }
            default :
                printf("Op��o Inv�lida");
                break;
        }
    }
  
    getchar();

    return 0;

}//Final da Main

// FUN��O CADASTRAR
void cadastrar( int cod, int pos )
{
    pos = verifica_pos();

    registros[pos].cod = cod;

    printf("\nNome do Cliente:\n");
    gets(registros[pos].cliente);

    printf("\nEndere�o:\n");
    gets(registros[pos].endereco);

    printf("\nInforme o telefone:\n");
    gets(registros[pos].tel);
    
    registros[pos].vazio = 1;

    printf("\nCadastro Realizado com Sucesso!\n\n");
    getchar();

    system("cls");

} //Final da Fun��o Cadastrar

//FUN��O CONSULTAR
void consultar( void )
{
    int cont = 0, cod, auxi;

    while ( cont <= 100 )
    {
   		printf("\nDigite 1 para consultar todos os clientes\n");
		printf("\nDigite 2 para consultar pelo c�digo do cliente\n");
    	scanf("%d",&auxi);
    	
    	system("cls");
	
		if(auxi == 1){			
      	    	if (registros[cont].vazio==1){
                	printf("\nNome do Cliente: %s\n",registros);
    	            system ("pause");	
    	            system("cls");	
                	break;
            	}
		}else if(auxi == 2){
			
			printf("\nEntre com o c�digo\n");
    		scanf("%d",&cod);

    		system("cls");
			
        	if (registros[cont].cod==cod){
      	    	if (registros[cont].vazio==1){
                	printf("\nNome do Cliente: %s\n",registros[cont].cliente);
            	    printf("\nEndere�o: %s\n",registros[cont].endereco);
        	        printf("\nTelefone:%s\n",registros[cont].tel);
    	            printf("\n");	
    	            system ("pause");	
    	            system("cls");	
                	break;
            	}
        	}
        }

        cont++;

        if ( cont > 100 )
            printf("\nC�digo n�o encontrado\n");

    }
}

//FUN��O VERIFICA POSI��O
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

//FUN��O ZERAR
void zerar( void )
{
    int cont;

    for ( cont = 0; cont <= 100; cont++ )
        registros[cont].vazio = 0;
}

//FUN��O VERIFICA C�DIGO
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

//FUN��O EXCLUIR
void excluir( void )
{
    int cod, cont = 0;
    char resp;

    printf("\nEntre com o c�digo do registro que deseja excluir\n");
    scanf("%d", &cod );

    while ( cont <= 100 )
    {

        if ( registros[cont].cod == cod )
        { // FALTOU

            if ( registros[cont].vazio == 1 )
            {
                printf("\nNome do Cliente \n%s\n", registros[cont].cliente );
                printf("\nEndere�o: \n%s\n", registros[cont].endereco );
                printf("\nTelefone:\n%s\n", registros[cont].tel );
                getchar();

                printf("\nDeseja realmente exlucir? S/N:");
                scanf("%c",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    registros[cont].vazio=0;
                    printf("\nExclus�o feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclus�o cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 100 )
            printf("\nC�digo n�o encontrado\n");

    }

    system("pause");
    system("cls");

}
