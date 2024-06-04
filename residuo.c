#ifndef RESIDUO_H
#define RESIDUO_H

void cadastraResiduoEmpresa(FILE *arquivo)
{
	int ano, mes;
	char cnpj[15];
	char qntdResiduo[5]; // Quantidade em Toneladas de KG ~ ex.: 17.83 
	char custo[7]; // Custo em milhares de reais ~ ex.: 1000.00
	char buffer[100];
    
    system("cls");
    
    printf("=== Cadastro de Residuo e Custo por Empresa ===\n");
    
    printf("Digite o ano base: ");
    scanf("%d", &ano);
    
    printf("Selecione a qual mes se refere:\n");
    printf("01 - Jan\t02 - Fev\t03 - Mar\n04 - Abr\t05 - Mai\t06 - Jun\n07 - Jul\t08 - Ago\t09 - Set\n10 - Out\t11 - Nov\t12 - Dez\nOpcao: ");
    scanf("%d", &mes);
    
    while(mes < 1 || mes > 12) {
    	printf("\nOpcao invalida! Digite novamente: ");
    	scanf("%d", &mes);
	}
	
	fflush(stdin); // Limpar o buffer no início
    
    printf("Digite o CNPJ da empresa: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%14[^\n]", cnpj);
    fflush(stdin); // Limpar o buffer
    
    printf("Digite a quantidade de residuos (em Toneladas): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%14[^\n]", qntdResiduo);
    fflush(stdin); // Limpar o buffer
    
    printf("Digite o valor estimado de custo (em milhares de Reais no formato 00.00): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%14[^\n]", custo);
    fflush(stdin); // Limpar o buffer
    
    fprintf(arquivo, "%d;%d;%s;%s;%s\n", ano, mes, cnpj, qntdResiduo, custo);
}

#endif
