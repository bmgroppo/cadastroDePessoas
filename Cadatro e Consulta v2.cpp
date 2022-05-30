#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h> //necessário para usar setlocale

using namespace std;

//Estrutura que será usada para realizar cadastro
struct tipo_cadastro
{

       int cod;
       char cliente[60];
       char endereco[60];
       char tel[20];
       int vazio;

} registros[100];

//Funções que serão usadas
void cadastrar(int cod, int pos);

//Função para consulta
void consultar();

//Função para verificar posição
int verifica_pos();

//Função para verificar código
int verifica_cod( int cod );

//Função para verificar posição do código
int verifica_pos();

//Função para excluir cadastro
void excluir();

//Começo do programa principal
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    int op = 0, posicao, codaux, retorno;

// Enquanto op for diferente de 4 ele ficará¡ rodando o sistema
    while ( op != 4 ){
        printf("\n\n\t\t\t\t** Cadastro e Consulta de Clientes**\n\n\n");
        printf("MENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Sair\n\nOpção: ");
        scanf("%d",&op);
        system("cls");
        switch ( op )
        {
            case 1: // CADASTRAR
            {
                posicao=verifica_pos();

                if ( posicao != -1 )
                {
                    printf("\nEntre com o código de cadastro do Cliente: \n");
                    scanf("%d",&codaux);
					fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastrar( codaux, posicao );
                    else
                        printf("\nCódigo ja existente\n");
                }
                else
                    printf("\nNão e possivel realizar mais cadastros!\n");

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
                 printf("\n Programa de cadastro e Consulta de Clientes by Bruno Groppo e Sérgio Baumgartner - Tchau");
                 getchar();
                 break;
            }
            default :
                printf("Opção Inválida");
                break;
        }
    }
  
    getchar();

    return 0;

}//Final da Main

// FUNÇÃO CADASTRAR
void cadastrar( int cod, int pos )
{
    pos = verifica_pos();

    registros[pos].cod = cod;

    printf("\nNome do Cliente:\n");
    gets(registros[pos].cliente);

    printf("\nEndereço:\n");
    gets(registros[pos].endereco);

    printf("\nInforme o telefone:\n");
    gets(registros[pos].tel);
    
    registros[pos].vazio = 1;

    printf("\nCadastro Realizado com Sucesso!\n\n");
    getchar();

    system("cls");

} //Final da Função Cadastrar

//FUNÇÃO CONSULTAR
void consultar( void )
{
    int cont = 0, cod, auxi;

    while ( cont <= 100 )
    {
   		printf("\nDigite 1 para consultar todos os clientes\n");
		printf("\nDigite 2 para consultar pelo código do cliente\n");
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
			
			printf("\nEntre com o código\n");
    		scanf("%d",&cod);

    		system("cls");
			
        	if (registros[cont].cod==cod){
      	    	if (registros[cont].vazio==1){
                	printf("\nNome do Cliente: %s\n",registros[cont].cliente);
            	    printf("\nEndereço: %s\n",registros[cont].endereco);
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
            printf("\nCódigo não encontrado\n");

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

//FUNÇÃO VERIFICA CÓDIGO
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

    printf("\nEntre com o código do registro que deseja excluir\n");
    scanf("%d", &cod );

    while ( cont <= 100 )
    {

        if ( registros[cont].cod == cod )
        { // FALTOU

            if ( registros[cont].vazio == 1 )
            {
                printf("\nNome do Cliente \n%s\n", registros[cont].cliente );
                printf("\nEndereço: \n%s\n", registros[cont].endereco );
                printf("\nTelefone:\n%s\n", registros[cont].tel );
                getchar();

                printf("\nDeseja realmente exlucir? S/N:");
                scanf("%c",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    registros[cont].vazio=0;
                    printf("\nExclusão feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusão cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 100 )
            printf("\nCódigo não encontrado\n");

    }

    system("pause");
    system("cls");

}
