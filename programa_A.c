#include <stdio.h>

int main(){

int numeros[3];
FILE *gravar;


gravar=fopen("gravar.txt","w");

if(gravar!=NULL){
printf("Arquivo criado \n");

}else{
printf("Arquivo não criado \n");
}

for(int i =0; i<3; i++){

printf("digite um numero \n");
scanf("%d",&numeros[i]);

fprintf(gravar,"%d \n",numeros[i]);

}
fclose(gravar);

}
