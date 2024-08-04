#include <stdio.h>
#include <string.h>

#define STANDARD_SIZE 50000

void inverterArray(char *inverter);

int main(){

    // leitura 
    int numFrases;
    
    scanf("%d", &numFrases);
    getchar();
    
    char frases[numFrases][STANDARD_SIZE];
    char codificado[numFrases][STANDARD_SIZE];
 
    for(int i = 0; i < numFrases; i++){
        fgets(frases[i], STANDARD_SIZE, stdin);
        
        // tirando o \n que o fgets pôe e mudo para o \0
        size_t tam = strlen(frases[i]);
        
        if(frases[i][tam - 1] == '\n'){
            frases[i][tam - 1] = '\0';
        }
    }
    
    
    // primeira parte (+3 na tabela ascii)
    for(int i = 0; i < numFrases; i++){
        int j;
        
        for(j = 0; frases[i][j] != '\0'; j++){
            
            if(frases[i][j] >= 'A' && frases[i][j] <= 'Z'){
                codificado[i][j] = frases[i][j] + 3;
                
            } else if (frases[i][j] >= 'a' && frases[i][j] <= 'z'){
                codificado[i][j] = frases[i][j] + 3;
                
            } else {
                codificado[i][j] = frases[i][j];
                
            }
            
        }
        
        codificado[i][j] = '\0';
    }
    
    // segunda parte  (invertendo tudo)
    // foi mais fácil do que eu pensei, no IF eu já tinha cantado a bola pro jão
    // fazer dessa forma que eu fiz, pensar a resolução é fácil, ruim é programar ela
    
    for(int i = 0; i < numFrases; i++){
        inverterArray(codificado[i]);
        
    }

    // terceira e ultima parte (até que enfim)
    for(int i = 0; i < numFrases; i++){
        int tam = strlen(codificado[i]);
        int meio = tam / 2;
        
        for(int j = meio; j < tam; j++){
            if(codificado[i][j] != ' '){
                codificado[i][j] -= 1;
            }
        }
    }
    
    // mostrando o resultado
    for(int i = 0; i < numFrases; i++){
        printf("%s\n", codificado[i]);
    }
    
    return 0;
}



void inverterArray(char *inverter){
    int a = 0;
    int b = strlen(inverter) - 1;  // se não fizer -1 ele pega o \0
    
    while(a < b){
        char aux = inverter[a];
        
        inverter[a] = inverter[b];
        inverter[b] = aux;
        
        a++;
        b--;
    }
}
