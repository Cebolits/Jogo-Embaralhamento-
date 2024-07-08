#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void embaralhar(char *texto) {
    int tamanho = strlen(texto), i, j;
    char temp;
    for (i = 0; i < tamanho; i++) {
        j = rand() % tamanho;
        temp = texto[i];
        texto[i] = texto[j];
        texto[j] = temp;
    }
}

int main() {
    FILE *arq;
    char frases[100], vetpal[10][10], *palavra, tentativa[10],vetemb[10][10];
    int escolha, count = 0, numero_aleatorio, pontos_totais = 100, pontos_ap;

    arq = fopen("arq.txt", "r");

    if (arq) {
        printf("Escolha a categoria de palavras:\n");
        printf("1 - Palavras fáceis\n");
        printf("2 - Palavras médias\n");
        printf("3 - Palavras difíceis\n");
        printf("--> ");
        scanf("%d", &escolha);

        srand(time(NULL));

        switch (escolha) {
            case 1:
                printf("\nVocê escolheu a categoria de palavras fáceis.\n");
                while (fgets(frases, sizeof(frases), arq)) {
                    palavra = strtok(frases, " \t\n"); // Divide a linha em palavras

                    while (palavra != NULL) {
                        if (strlen(palavra) == 4) {
                            strcpy(vetpal[count], palavra);
                            count++;
                        }
                        palavra = strtok(NULL, " \t\n"); // Continua dividindo a linha
                    }
                }

                if (count > 0) {
                    numero_aleatorio = rand() % count;
                    printf("Número aleatório: %d\n", numero_aleatorio); // Numero aleatorio partindo do 1
                    

                    strcpy(vetemb[numero_aleatorio],vetpal[numero_aleatorio]);
                    embaralhar(vetemb[numero_aleatorio]);
                   
                    printf("\nPalavra embaralhada: %s\n", vetemb[numero_aleatorio]);

                    while (1) {
                        printf("\nDigite quantos pontos quer apostar (ou 0 para sair): ");
                        scanf("%d", &pontos_ap);

                        if (pontos_ap == 0) {
                            printf("Você desistiu. Pontos totais: %d\n", pontos_totais);
                            break;
                        }

                        if (pontos_ap > pontos_totais) {
                            printf("Aposta inválida. Você não tem pontos suficientes.\n");
                            continue;
                        }

                        printf("\nDigite a palavra: ");
                        scanf("%s", tentativa);

                        if (strcmp(tentativa, vetpal[numero_aleatorio]) == 0) {
                           
                            printf("Parabéns! Você acertou. Pontos totais: %d\n", pontos_totais);
                            printf("\nPalavra escolhida: %s\n", vetpal[numero_aleatorio]);
                            break;
                        } else {
                            pontos_totais -= pontos_ap;
                            printf("Errado. Pontos totais: %d\n", pontos_totais);
                            
                            if (pontos_totais <= 0) {
                                printf("Você perdeu todos os pontos. Jogo encerrado.\n");
                                printf("\nPalavra escolhida: %s\n", vetpal[numero_aleatorio]);
                                break;
                            }
                        }
                    }
                } else {
                    printf("Nenhuma palavra de tamanho 4 encontrada.\n");
                }

                break;

            case 2:
                printf("\nVocê escolheu as palavras médias.\n");
                
                while (fgets(frases, sizeof(frases), arq)) {
                    palavra = strtok(frases, " \t\n"); // Divide a linha em palavras

                    while (palavra != NULL) {
                        if (strlen(palavra) == 5) {
                            strcpy(vetpal[count], palavra);
                            count++;
                        }
                        palavra = strtok(NULL, " \t\n"); // Continua dividindo a linha
                    }
                }

                if (count > 0) {
                    numero_aleatorio = rand() % count;
                    printf("Número aleatório: %d\n", numero_aleatorio); // Numero aleatorio partindo do 1
                    

                    strcpy(vetemb[numero_aleatorio],vetpal[numero_aleatorio]);
                    embaralhar(vetemb[numero_aleatorio]);

                    printf("\nPalavra embaralhada: %s\n", vetemb[numero_aleatorio]);

                    while (1) {
                        printf("\nDigite quantos pontos quer apostar (ou 0 para sair): ");
                        scanf("%d", &pontos_ap);

                        if (pontos_ap == 0) {
                            printf("Você desistiu. Pontos totais: %d\n", pontos_totais);
                            break;
                        }

                        if (pontos_ap > pontos_totais) {
                            printf("Aposta inválida. Você não tem pontos suficientes.\n");
                            continue;
                        }

                        printf("\nDigite a palavra: ");
                        scanf("%s", tentativa);

                        if (strcmp(tentativa, vetpal[numero_aleatorio]) == 0) {

                            printf("Parabéns! Você acertou. Pontos totais: %d\n", pontos_totais);
                            printf("\nPalavra escolhida: %s\n", vetpal[numero_aleatorio]);
                            break;
                        } else {
                            pontos_totais -= pontos_ap;
                            printf("Errado. Pontos totais: %d\n", pontos_totais);
                            if (pontos_totais <= 0) {
                                printf("Você perdeu todos os pontos. Jogo encerrado.\n");
                                printf("\nPalavra escolhida: %s\n", vetpal[numero_aleatorio]);
                                break;
                            }
                        }
                    }
                } else {
                    printf("Nenhuma palavra de tamanho 5 encontrada.\n");
                }

                break;
                

            case 3:
                printf("\nVocê escolheu as palavras difíceis.\n");
           
            while (fgets(frases, sizeof(frases), arq)) {
                palavra = strtok(frases, " \t\n"); // Divide a linha em palavras

                while (palavra != NULL) {
                    if (strlen(palavra) == 9) {
                        strcpy(vetpal[count], palavra);
                        count++;
                    }
                    palavra = strtok(NULL, " \t\n"); // Continua dividindo a linha
                }
            }

            if (count > 0) {
                numero_aleatorio = rand() % count;
                printf("Número aleatório: %d\n", numero_aleatorio); // Numero aleatorio partindo do 1
                

                strcpy(vetemb[numero_aleatorio],vetpal[numero_aleatorio]);
                embaralhar(vetemb[numero_aleatorio]);

                printf("\nPalavra embaralhada: %s\n", vetemb[numero_aleatorio]);

                while (1) {
                    printf("\nDigite quantos pontos quer apostar (ou 0 para sair): ");
                    scanf("%d", &pontos_ap);

                    if (pontos_ap == 0) {
                        printf("Você desistiu. Pontos totais: %d\n", pontos_totais);
                        break;
                    }

                    if (pontos_ap > pontos_totais) {
                        printf("Aposta inválida. Você não tem pontos suficientes.\n");
                        continue;
                    }

                    printf("\nDigite a palavra: ");
                    scanf("%s", tentativa);

                    if (strcmp(tentativa, vetpal[numero_aleatorio]) == 0) {

                        printf("Parabéns! Você acertou. Pontos totais: %d\n", pontos_totais);
                        printf("\nPalavra escolhida: %s\n", vetpal[numero_aleatorio]);
                        break;
                    } else {
                        pontos_totais -= pontos_ap;
                        printf("Errado. Pontos totais: %d\n", pontos_totais);
                        if (pontos_totais <= 0) {
                            printf("Você perdeu todos os pontos. Jogo encerrado.\n");
                            printf("\nPalavra escolhida: %s\n", vetpal[numero_aleatorio]);
                            break;
                        }
                    }
                }
            } else {
                printf("Nenhuma palavra de tamanho 9 encontrada.\n");
            }

            break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }

        fclose(arq);
    } else {
        printf("Não foi possível abrir o arquivo.\n");
    }

    return 0;
}
