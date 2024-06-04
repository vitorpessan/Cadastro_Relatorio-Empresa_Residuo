#ifndef RELATORIO_RESIDUOCUSTOANOEMPRESA_H
#define RELATORIO_RESIDUOCUSTOANOEMPRESA_H

void salvarResiduoCustoAnoEmpresaEmArquivo(const char *resultados) {
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

void listarResiduoCustoAno(FILE *arquivo, const char *cnpjResiduoCustoAno) {
    int ano, mes, achou = 0, anoAnterior = 0;
    char cnpjArquivo[15], qntdResiduo[50], custo[50];
    char linha[256];
    float totalQntdResiduo = 0.0, totalCusto = 0.0, totalQntdResiduoGeral = 0.0, totalCustoGeral = 0.0;
    char resultados[4096];

    // Inicializa a string de resultados
    resultados[0] = '\0';

    printf("=== Lista de Residuo e Custo por Ano ===\n");
    printf("Digite o CNPJ: ");
    scanf("%s", cnpjResiduoCustoAno);

    rewind(arquivo);  // Reinicia o ponteiro do arquivo para o início

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d;%d;%[^;];%[^;];%[^\n]", &ano, &mes, cnpjArquivo, qntdResiduo, custo);

        // Verifica se o CNPJ da linha corresponde ao CNPJ desejado
        if (strcmp(cnpjArquivo, cnpjResiduoCustoAno) == 0) {
            achou = 1;

            // Adiciona os resultados à string
            // sprintf(resultados + strlen(resultados), "| Ano: %d | Mes: %02d | Qntd de Residuo: %s | Custo: %s |\n", ano, mes, qntdResiduo, custo);
            
            if (ano != anoAnterior && anoAnterior != 0) {
                sprintf(resultados + strlen(resultados), "| Total Ano %d | Qntd de Residuo: %.2f | Custo: %.2f |\n", anoAnterior, totalQntdResiduo, totalCusto);
                totalQntdResiduo = 0.0;
                totalCusto = 0.0;
            }
            
            // Adiciona os valores convertidos às variáveis de total
            totalQntdResiduoGeral += atof(qntdResiduo); // Geral para mostrar a soma total ao final
            totalQntdResiduo += atof(qntdResiduo);
            totalCustoGeral += atof(custo); // Geral para mostrar a soma total ao final
            totalCusto += atof(custo);

            anoAnterior = ano;
        }
    }

    // Imprime o total do último ano, se houver algum
    if (anoAnterior != 0) {
        sprintf(resultados + strlen(resultados), "| Total Ano %d | Qntd de Residuo: %.2f | Custo: %.2f |\n", anoAnterior, totalQntdResiduo, totalCusto);
    }

    // Adiciona os totais ao final da string de resultados
    sprintf(resultados + strlen(resultados), "---\nTotais:\nQntd Residuo (em Toneladas):\t%.2f\nCusto (em milhares de R$):\t%.2f\n", totalQntdResiduoGeral, totalCustoGeral);

    if (!achou) printf("Nenhum resultado encontrado!\n");
    else {
        salvarResiduoCustoAnoEmpresaEmArquivo(resultados);
        printf("%s", resultados);
    }

    printf("========================================\n");

    system("pause");
}

#endif
