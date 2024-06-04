#ifndef RELATORIO_EMPRESASCADASTRADAS_H
#define RELATORIO_EMPRESASCADASTRADAS_H

void lerEmpresasCadastradas(FILE *arquivo, char *resultados) {
    char linha[256];

    printf("==========================================================================================\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nomeResponsavel[50], telefoneResponsavel[15], emailResponsavel[50];
        char cnpj[15], razaoSocial[50], nomeFantasia[50];
        char rua[50], numero[10], bairro[50], cidade[50], estado[3], cep[10];
        char telefone[15], email[50];

        sscanf(linha, "%49[^;];%14[^;];%49[^;];%14[^;];%49[^;];%49[^;];%49[^;];%9[^;];%49[^;];%49[^;];%2[^;];%9[^;];%14[^;];%49[^\n]",
               nomeResponsavel, telefoneResponsavel, emailResponsavel,
               cnpj, razaoSocial, nomeFantasia,
               rua, numero, bairro, cidade,
               estado, cep, telefone, email);

        sprintf(resultados, "%s|\033[31m %-30s\033[0m |\033[31m %-30s\033[0m |\033[31m %-30s\033[0m \n", resultados, "Responsavel", "Telefone Responsavel", "Email Responsavel");
        sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, nomeResponsavel, telefoneResponsavel, emailResponsavel);
        sprintf(resultados, "%s|\033[31m %-30s\033[0m |\033[31m %-30s\033[0m |\033[31m %-30s\033[0m \n", resultados, "CNPJ", "Razao Social", "Nome Fantasia");
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, cnpj, razaoSocial, nomeFantasia);
		sprintf(resultados, "%s|\033[31m %-30s\033[0m |\033[31m %-30s\033[0m |\033[31m %-30s\033[0m \n", resultados, "Logradouro", "Numero", "Bairro");
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, rua, numero, bairro);
		sprintf(resultados, "%s|\033[31m %-30s\033[0m |\033[31m %-30s\033[0m |\033[31m %-30s\033[0m \n", resultados, "Cidade", "Estado", "CEP");
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, cidade, estado, cep);
		sprintf(resultados, "%s|\033[31m %-30s\033[0m |\033[31m %-30s\033[0m |\033[31m %-30s\033[0m \n", resultados, "Telefone", "Email", "");
		sprintf(resultados, "%s| %-30s | %-30s \n", resultados, telefone, email);
		sprintf(resultados, "%s==========================================================================================\n", resultados);
    }
}

void lerEmpresasCadastradasPB(FILE *arquivo, char *resultados) {
    char linha[256];

	sprintf(resultados, "%s==========================================================================================\n", resultados);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nomeResponsavel[50], telefoneResponsavel[15], emailResponsavel[50];
        char cnpj[15], razaoSocial[50], nomeFantasia[50];
        char rua[50], numero[10], bairro[50], cidade[50], estado[3], cep[10];
        char telefone[15], email[50];

        sscanf(linha, "%49[^;];%14[^;];%49[^;];%14[^;];%49[^;];%49[^;];%49[^;];%9[^;];%49[^;];%49[^;];%2[^;];%9[^;];%14[^;];%49[^\n]",
               nomeResponsavel, telefoneResponsavel, emailResponsavel,
               cnpj, razaoSocial, nomeFantasia,
               rua, numero, bairro, cidade,
               estado, cep, telefone, email);

        sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, "Responsavel", "Telefone Responsavel", "Email Responsavel");
        sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, nomeResponsavel, telefoneResponsavel, emailResponsavel);
        sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, "CNPJ", "Razao Social", "Nome Fantasia");
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, cnpj, razaoSocial, nomeFantasia);
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, "Logradouro", "Numero", "Bairro");
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, rua, numero, bairro);
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, "Cidade", "Estado", "CEP");
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, cidade, estado, cep);
		sprintf(resultados, "%s| %-30s | %-30s | %-30s \n", resultados, "Telefone", "Email", "");
		sprintf(resultados, "%s| %-30s | %-30s \n", resultados, telefone, email);
		sprintf(resultados, "%s==========================================================================================\n", resultados);
    }
}

void empresasCadastradas(FILE *arquivo) {
    system("cls");

    printf("=== Empresas Cadastradas ===\n");

    char salvar;
    printf("Deseja salvar os resultados em um arquivo de texto? (S/N): ");
    scanf(" %c", &salvar);

    if (salvar == 'S' || salvar == 's') {
        char caminho[100], nomeArquivo[50], resultados[4096] = "";
        FILE *arquivoSaida;
        printf("Digite o nome do arquivo para salvar os resultados (sem extensao): ");
        scanf("%s", nomeArquivo);

        sprintf(caminho, "./Relatorios/%s.txt", nomeArquivo);

        lerEmpresasCadastradasPB(arquivo, resultados);

        arquivoSaida = fopen(caminho, "w");
        if (arquivoSaida == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return;
        }

        // Salvar os dados no arquivo de saída
        fprintf(arquivoSaida, "%s", resultados);

        fclose(arquivoSaida);

        printf("Resultados salvos em Relatorios/%s.txt\n", nomeArquivo);
        printf("%s", resultados);
        system("pause");
    } else {
        char resultados[4096] = ""; 
        lerEmpresasCadastradas(arquivo, resultados);
        printf("%s", resultados);
        system("pause");
    }
}

#endif
