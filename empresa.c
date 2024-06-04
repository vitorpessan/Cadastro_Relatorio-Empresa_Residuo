#ifndef EMPRESA_H
#define EMPRESA_H

void cadastraEmpresa(FILE *arquivo)
{
	char nomeResponsavel[50];
	char telefoneResponsavel[15];
	char emailResponsavel[100];
    char cnpj[15];
    char razaoSocial[50];
    char nomeFantasia[50];
    char rua[100];
    char numero[5];
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[10];
    char telefone[15];
    char email[100];
    char buffer[100];
    
    system("cls");
    fflush(stdin); // Limpar o buffer no início
    
    printf("=== Cadastro de Empresa ===\n");
    
    printf("Responsavel pela empresa: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49[^\n]", nomeResponsavel);
    fflush(stdin); // Limpar o buffer
    
    printf("Telefone do responsavel: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%14[^\n]", telefoneResponsavel);
    fflush(stdin); // Limpar o buffer
    
    printf("Email do responsavel: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%99[^\n]", emailResponsavel);
    fflush(stdin); // Limpar o buffer
    
    printf("CNPJ: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%14[^\n]", cnpj);
    fflush(stdin); // Limpar o buffer
    
    printf("Razao Social: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49[^\n]", razaoSocial);
    fflush(stdin); // Limpar o buffer
    
    printf("Nome Fantasia: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49[^\n]", nomeFantasia);
    fflush(stdin); // Limpar o buffer
    
    printf("Rua: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%99[^\n]", rua);
    fflush(stdin); // Limpar o buffer
    
    printf("Numero: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%4[^\n]", numero);
    fflush(stdin); // Limpar o buffer
    
    printf("Bairro: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49[^\n]", bairro);
    fflush(stdin); // Limpar o buffer
    
    printf("Cidade: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%49[^\n]", cidade);
    fflush(stdin); // Limpar o buffer
    
    printf("Estado (UF): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%2[^\n]", estado);
    fflush(stdin); // Limpar o buffer
    
    printf("CEP: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%9[^\n]", cep);
    fflush(stdin); // Limpar o buffer
    
    printf("Telefone: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%14[^\n]", telefone);
    fflush(stdin); // Limpar o buffer
    
    printf("Email: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%99[^\n]", email);
    fflush(stdin); // Limpar o buffer
    
    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n", nomeResponsavel, telefoneResponsavel, emailResponsavel, cnpj, razaoSocial, nomeFantasia, rua, numero, bairro, cidade, estado, cep, telefone, email);
}

#endif
