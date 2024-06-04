#ifndef LOGIN_H
#define LOGIN_H

struct Usuario {
	char usuario[50];
	char senha[50];
};

int login()
{
	char usuario[50], senha[50];
	struct Usuario admin = {"admin", "123"};
	int logado = 0;	
	
	while(!logado) {
		printf("=== GreenFinger ===\n");
		
		printf("Nome de usuario: ");
		scanf("%s", usuario);
		
		printf("Senha: ");
		scanf("%s", senha);
		
		if ((strcmp(usuario, admin.usuario) == 0) && (strcmp(senha, admin.senha) == 0)) {
			logado = 1;
			
			printf("\nBoas vindas, %s.\n\n", usuario);
			
			system("pause");
			system("cls");
		} else {
			logado = 0;
			
			printf("\nUsuario ou senha invalidos. Tente novamente!\n\n");
			
			while (getchar() != '\n');
			
			system("pause");
			system("cls");
		}	
	}
	
	return logado;
}

#endif
