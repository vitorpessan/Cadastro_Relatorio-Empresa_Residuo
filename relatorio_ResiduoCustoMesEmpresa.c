#ifndef RELATORIO_RESIDUOCUSTOMESEMPRESA_H
#define RELATORIO_RESIDUOCUSTOMESEMPRESA_H

void salvarResiduoCustoMesEmpresaEmArquivo(const char *resultados) {
    char opcaoSalvar;

    printf("Deseja salvar os resultados em um arquivo de texto? (S/N): ");
    scanf(" %c", &opcaoSalvar);

    if (opcaoSalvar == 'S' || opcaoSalvar == 's') {
        char nomeArquivo[50];
        FILE *arquivoSaida;

        printf("Digite o nome do arquivo para salvar os resultados (sem extensao): ");
        scanf("%s", nomeArquivo);

        char caminho[100]; 
        sprintf(caminho, "./Relatorios/%s.txt", nomeArquivo);

        arquivoSaida = fopen(caminho, "w");
        
        if (arquivoSaida == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return;
        }

        fprintf(arquivoSaida, "%s", resultados);

        fclose(arquivoSaida);

        printf("Resultados salvos em Relatorios/%s.txt\n", nomeArquivo);
    }
}

void listarResiduoCustoMesAMes(FILE *arquivo, const char *cnpjResiduoCustoMes) {
    int ano, mes, achou = 0;
    float totalQntdResiduo = 0.0, totalCusto = 0.0;
    char cnpjArquivo[15], qntdResiduo[50], custo[50], linha[256], resultados[1024], buffer[20];
    resultados[0] = '\0'; 

    printf("=== Lista de Residuo e Custo Mes a Mes ===\n");
    printf("Digite o CNPJ: ");
    scanf("%s", cnpjResiduoCustoMes);

    rewind(arquivo);  // Reinicia o ponteiro do arquivo para o início

	sprintf(resultados + strlen(resultados), "CNPJ: %s\n---\n", cnpjResiduoCustoMes);
	
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d;%d;%[^;];%[^;];%[^\n]", &ano, &mes, cnpjArquivo, qntdResiduo, custo);

        // Verifica se o CNPJ da linha corresponde ao CNPJ desejado
        if (strcmp(cnpjArquivo, cnpjResiduoCustoMes) == 0) {
            achou = 1;
            sprintf(resultados + strlen(resultados), "| Ano: %d | Mes: %02d | Qntd de Residuo: %s | Custo: %s |\n", ano, mes, qntdResiduo, custo);
            
            // Adiciona os valores convertidos às variáveis de total
	        totalQntdResiduo += atof(qntdResiduo);
	        totalCusto += atof(custo);
        }
    }
    
    sprintf(resultados + strlen(resultados), "---\nTotais:\nQntd Residuo (em Toneladas):\t%.2f\nCusto (em milhares de R$):\t%.2f\n", totalQntdResiduo, totalCusto);

	if(!achou) printf("Nenhum resultado encontrado!\n");
	else {
		salvarResiduoCustoMesEmpresaEmArquivo(resultados);
		printf("%s", resultados);
	}
    
	printf("========================================\n");
    
    system("pause");
}

#endif
