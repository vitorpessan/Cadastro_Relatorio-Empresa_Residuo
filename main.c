// Bibliotecas do C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arquivos Externos
#include "menu.c"
#include "login.c"
#include "empresa.c"
#include "residuo.c"
#include "relatorio_menu.c"
#include "relatorio_empresasCadastradas.c"
#include "relatorio_ResiduoCustoMesEmpresa.c"
#include "relatorio_ResiduoCustoAnoEmpresa.c"

int main()
{
	FILE *arquivo;
	char opcaoCadastraEmpresa = 'N', opcaoCadastraResiduo = 'N';
	int sair = 0, sairRelatorio = 0;
	
	if (login()) 
	{		
		while (!sair)
		{
			system("cls");
			
			switch(menu()) {
				case 1: // Cadastro Empresa					
					do {
						arquivo = fopen("empresas.txt", "a");
					
						if(arquivo == NULL) {
							printf("Erro ao abrir o arquivo!\n");
							opcaoCadastraEmpresa = 'n';
							return 1;
						}
						
						cadastraEmpresa(arquivo);						
						fclose(arquivo);
						
						printf("Deseja cadastrar outra empresa? (S/N): ");
						scanf("%c", &opcaoCadastraEmpresa);
					} while(opcaoCadastraEmpresa == 'S' || opcaoCadastraEmpresa == 's');
					
					break;
					
				case 2: // Cadastro Residuo/Empresa
					do {
						arquivo = fopen("residuo_empresa.txt", "a");
					
						if(arquivo == NULL) {
							printf("Erro ao abrir o arquivo!\n");
							opcaoCadastraResiduo = 'n';
							return 1;
						}
						
						cadastraResiduoEmpresa(arquivo);						
						fclose(arquivo);
						
						printf("Deseja inserir outro registro? (S/N): ");
						scanf("%c", &opcaoCadastraResiduo);
					} while(opcaoCadastraResiduo == 'S' || opcaoCadastraResiduo == 's');
					
					break;
					
				case 3: // Relatorios
					while(!sairRelatorio)
					{
						system("cls");
						
						switch(menuRelatorio()) {
							case 1: // Lista de empresas cadastradas							
								arquivo = fopen("empresas.txt", "r");
						
								if(arquivo == NULL) {
									printf("Erro ao abrir o arquivo!\n");
									return 1;
								}
								
								empresasCadastradas(arquivo);								
								fclose(arquivo);
								
								break;
							
							case 2: // Analise mensal de Residuo e Custo por empresa com total anual
								arquivo = fopen("residuo_empresa.txt", "r");
						
								if(arquivo == NULL) {
									printf("Erro ao abrir o arquivo!\n");
									return 1;
								}
								
								system("cls");
								
								char cnpjResiduoCustoMes[15];
								
								listarResiduoCustoMesAMes(arquivo, cnpjResiduoCustoMes);
								fclose(arquivo);
								
								break;
								
							case 3: // Analise anual de Residuo e Custo por empresa
								arquivo = fopen("residuo_empresa.txt", "r");
						
								if(arquivo == NULL) {
									printf("Erro ao abrir o arquivo!\n");
									return 1;
								}
								
								system("cls");
								
								char cnpjResiduoCustoAno[15];
								
								listarResiduoCustoAno(arquivo, cnpjResiduoCustoAno);
								fclose(arquivo);
								
								break;
								
							case 0: // Sair
								sairRelatorio = 1;
								break;
								
							default: // Caso algo dê errado
								printf("Algo deu errado. O programa sera encerrado...");
								sairRelatorio = 1;
								
								break;
						}
					}
					
					sairRelatorio = 0; // Para liberar o menu de relatorios novamente
					
					break;
					
				case 0: // Sair
					printf("Ate mais!");
					sair = 1;
					
					break;
					
				default: // Caso algo dê errado
					printf("Algo deu errado. O programa sera encerrado...");
					sair = 1;
					
					break;
			}
		}
	}
	
	return 0;
}
