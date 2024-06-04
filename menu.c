#ifndef MENU_H
#define MENU_H

int menu()
{
	int opcaoMenu = -1;
	
	printf("=== Menu Principal ===\n");
    printf("1. Cadastrar Empresa\n");
    printf("2. Cadastrar Residuo/Empresa\n");
    printf("3. Relatorios\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    
    scanf("%d", &opcaoMenu);
	
	while (opcaoMenu < 0 || opcaoMenu > 3){
		printf("Opcao invalida!\n");
		
		system("pause");
		system("cls");
		
		printf("=== Menu Principal ===\n");
	    printf("1. Cadastrar Empresa\n");
	    printf("2. Cadastrar Residuo/Empresa\n");
	    printf("3. Relatorios\n");
	    printf("0. Sair\n");
	    printf("Escolha uma opcao: ");
	    
	    scanf("%d", &opcaoMenu);
	}
	
	return opcaoMenu;
}

#endif
