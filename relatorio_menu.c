#ifndef RELATORIO_MENU_H
#define RELATORIO_MENU_H

int menuRelatorio()
{
	int opcaoRelatorio = -1;
	
	printf("=== Relatorios Disponiveis ===\n");
    printf("1. Lista de empresas cadastradas\n");
    printf("2. Analise mensal de Residuo e Custo por empresa com total anual\n");
    printf("3. Analise anual de Residuo e Custo por empresa\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    
    scanf("%d", &opcaoRelatorio);
	
	while (opcaoRelatorio < 0 || opcaoRelatorio > 7){
		printf("Opcao invalida!\n");
		
		system("pause");
		system("cls");
		
		printf("=== Relatorios Disponiveis ===\n");
		printf("1. Lista de empresas cadastradas\n");
	    printf("2. Analise mensal de Residuo e Custo por empresa com total anual\n");
	    printf("3. Analise anual de Residuo e Custo por empresa\n");
	    printf("0. Sair\n");
	    printf("Escolha uma opcao: ");
	    
	    scanf("%d", &opcaoRelatorio);
	}
	
	return opcaoRelatorio;
}

#endif
