#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd1[2];/*determina a leitura e escrita no pipe*/
    int fd2[2];/*criei dois fd pq tanto o processo pai como o filho vão ler e escrever no pipe*/
    pid_t pid;

    if(pipe(fd1)<0) {  /*cria e verifica se os pipes foram criados */
        perror("pipe") ;
        return -1 ;
    }

    if(pipe(fd2)<0) {
        perror("pipe") ;
        return -1 ;
    }

    pid = fork();/*cria o processo filho*/

    if(pid == -1) {
        perror("fork") ;
        return -1 ;
    }

    if(pid > 0) {    /* Processo pai*/
        int num[5],  /* Números que o processo pai vai enviar para o filho*/
            soma;  /* Resultado da soma, recebido pelo filho*/
    

         num[0]=1;
               num[1]=3;
               num[2]=5;
               num[3]=7;
               num[4]=9;

                write(fd1[1], num, sizeof(num)); /* Enviando o vetor de números pro filho */

                 read(fd2[0], &soma, sizeof(soma));/*Leitura da variavel soma do processo filho*/
                printf("Soma: %d\n\n", soma);
    }else{/*Processo filho*/

        int numeros[5],  /* Números que o processo filho recebe do pai*/
            soma;/*soma que o processo filho envia para o pai*/

        read(fd1[0], numeros, sizeof(numeros) ); /* Recebeu o vetor de inteiros do pai e colocou no vetor 'numeros' */

         soma = numeros[0] + numeros[1]+ numeros[2]+ numeros[3]+ numeros[4]+2+4+6+8+10;

                write(fd2[1], &soma, sizeof(soma)); /* Envia a soma, qúe está na variável soma para o pai */
    }

}
