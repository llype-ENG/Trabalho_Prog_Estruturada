
#include "remove.h"
#include<stdio.h>
#include<math.h>//Para funções matemáticas, como pow e round.
#include<string.h>//Para manipulação de strings, como strlen e strcmp.
#include<stdlib.h>//Para conversão e alocação de memória, como strtol
#include<locale.h>//foi usada para definir o padrão de localização.

//O código principal, que executa o processo de decodificação da mensagem hexadecimal.
int main() {
    char mensagens[101];//Armazena a mensagem hexadecimal 
    char hex[3];//para armazenar dois caracteres da mensagem hexadecimal por vez.
    int i, j, b, msg, n, verificacao, x = 1, numeroscasos;//Valor b usadoo para ajustar o cálculo da função func_val / msg= Número de mensagens que o usuário deseja decodificar.
    char continuar;// variavel para o programa continuar rodando caso o usuario queira
    char final[] = "00";// Indica o final da mensagem.
    long int resultado; // O valor decimal correspondente ao hexadecimal convertido.
    char mensagem_decodificada[2][101]; //Armazena até 2 mensagens decodificadas, com tamanho máximo de 100 caracteres.
    do {
        printf("Quantas mensagens deseja decodigicar?: ");
        scanf("%d", &msg);
        
        for(n=0;n<msg;n++){
            printf("\nDigite o valor de b: ");
            scanf("%d", &b);

            printf("Digite a mensagem que deseja decodificar: ");
            scanf("%100s", mensagens);
        
            int indice = 0; 
            for(i = 0; i < strlen(mensagens); i += 2) {//Processa a mensagem hexadecimal em blocos de 2 caracteres por vez (cada bloco de 2 caracteres hexadecimais representa um byte)./
                x = i / 2 + 1;
                verificacao = func_val(x, b);//O valor de (verificacao) é obtido a partir da função func_val e determina se o caractere deve ser decodificado ou não.
                if(verificacao != 0) {
                    hex[0] = mensagens[i];//Armazena os dois caracteres hexadecimais para serem convertidos.
                    hex[1] = mensagens[i + 1];
                    hex[2] = '\0';
                    if(strcmp(hex, final) == 0) {//// Verifica se chegou ao final da mensagem.
                        break;
                    }
                    resultado = strtol(hex, NULL, 16);//Converte os dois caracteres hexadecimais em um valor inteiro.
                    mensagem_decodificada[n][indice++] = (char) resultado; //Armazena o caractere decodificado na string.
                }
            }
            mensagem_decodificada[n][indice] = '\0'; // Termina a string com valor nulo
        
        }

         system("cls");// Limpa a tela com (system("cls")) e, em seguida, imprime todas as mensagens decodificadas.
        for(n=0;n<msg;n++){
            printf("%s\n", mensagem_decodificada[n]);
        }
        
        printf("\nDeseja decodificar novamente outra mensagem (s/n)?: ");
        scanf(" %c", &continuar);

     } while(continuar == 's' || continuar == 'S');

    return 0;
}