#include <stdio.h>
#include <string.h>

void cadastrar(int codigo[], char nome[][15], int *total) {
    if (*total == 5) {
        printf("\nCadastro cheio!\n");
        return;
    }
    printf("\nDigite o codigo: ");
    scanf("%d", &codigo[*total]);
    getchar();
    printf("Digite o nome: ");
    fgets(nome[*total], 15, stdin);
    (*total)++;
    printf("\nCadastro realizado com sucesso!\n");
}

void consultar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;

    printf("\nDigite o codigo para consulta: ");
    scanf("%d", &busca);

    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            printf("\nCodigo: %d\n", codigo[i]);
            printf("Nome: %s", nome[i]);
            return;
        }
    }

    printf("\nCodigo nao encontrado!\n");
}

void listar(int codigo[], char nome[][15], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum registro cadastrado!\n");
        return;
    }

    printf("\n===== LISTA DE REGISTROS =====\n");

    for (i = 0; i < total; i++) {
        printf("\nCodigo: %d\n", codigo[i]);
        printf("Nome: %s", nome[i]);
    }
}

void alterar(int codigo[], char nome[][15], int total) {
    int busca;
    int i;

    printf("\nDigite o codigo que sera alterado: ");
    scanf("%d", &busca);

    for (i = 0; i < total; i++) {
        if (codigo[i] == busca) {
            printf("Digite o novo codigo: ");
            scanf("%d", &codigo[i]);
            getchar();
            printf("Digite o novo nome: ");
            fgets(nome[i], 15, stdin);
            printf("\nRegistro alterado com sucesso!\n");
            return;
        }
    }

    printf("\nCodigo nao encontrado!\n");
}

void excluir(int codigo[], char nome[][15], int *total) {
    int busca;
    int i, j;

    printf("\nDigite o codigo que sera excluido: ");
    scanf("%d", &busca);

    for (i = 0; i < *total; i++) {
        if (codigo[i] == busca) {
            for (j = i; j < *total - 1; j++) {
                codigo[j] = codigo[j + 1];
                strcpy(nome[j], nome[j + 1]);
            }
            (*total)--;
            printf("\nRegistro excluido com sucesso!\n");
            return;
        }
    }

    printf("\nCodigo nao encontrado!\n");
}

int main(void) {
    int codigo[5];
    char nome[5][15];
    int total = 0;
    int opcao;
    do {
        printf("\n\n===== MENU =====");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar(codigo, nome, &total);
                break;
            case 2:
                consultar(codigo, nome, total);
                break;
            case 3:
                listar(codigo, nome, total);
                break;
            case 4:
                alterar(codigo, nome, total);
                break;
            case 5:
                excluir(codigo, nome, &total);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}
