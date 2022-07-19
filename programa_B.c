#include<stdio.h>

int main(){

int media,numeros[3];
FILE *gravar;

gravar=fopen("gravar.txt","r");

if (gravar != NULL){
printf("Arquivo aberto \n");
}

else{
printf("Falha ao abrir o arquivo \n");
}

for(int i=0;i<3;i++){
fscanf(gravar,"%d",&numeros[i]);
printf("%d\n",numeros[i]);
}

media=(numeros[0]+numeros[1]+numeros[2])/3;

printf("%d\n",media);

}
