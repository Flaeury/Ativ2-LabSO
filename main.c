#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int numeroProcessos;
    
    printf("Digite o número de processos que deseja criar: ");
    scanf("%d", &numeroProcessos);

    // Laço que verifica se o número de processos é válido
    if (numeroProcessos <= 0) { 
        fprintf(stderr, "O número de processos deve ser maior que zero.\n");
        return EXIT_FAILURE;
    }

    // Laço que cria os processos filhos
    for (int i = 0; i < numeroProcessos; i++) { 
        pid_t pid = fork();

        if (pid < 0) {
            printf("Erro ao criar processo filho");
            return EXIT_FAILURE;

        } else if (pid == 0) {
            execl("./hello", "./hello", NULL);
            return EXIT_FAILURE;
        }
    }
    // Laço que espera pelos processos filhos
    for (int i = 0; i < numeroProcessos; i++) { 
        wait(NULL);
    }

    printf("Processos finalizados.\n");

    return EXIT_SUCCESS;
}
