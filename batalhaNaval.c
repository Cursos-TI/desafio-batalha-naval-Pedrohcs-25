#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

     
    // navios [i][2][2]
    // i - quantidade de navios
    // [2] - [0] posição inicial  - [1] posição final 
    // [2] - [0] posição  v - [1] posição  h
    int navios [4][2][2] = {
        {{2,2},{2,4}},
        {{4,2},{6,2}},
        {{9,9},{7,7}},
        {{0,9},{2,7}}
    };
    int epecias3x5[3][3][5] = {
        {
            {0,0,5,0,0},
            {0,5,5,5,0},
            {5,5,5,5,5}
        },
        {
            {0,0,5,0,0},
            {0,5,5,5,0},
            {0,0,5,0,0}
        },{
            {0,0,5,0,0},
            {5,5,5,5,5},
            {0,0,5,0,0}
        },
    };
    // inserir navios
    int w = 0;
    //int d =0;
    
    while (1){
        if ((navios[w][0][0] == 0 && navios[w][0][1] == 0)&&(navios[w][1][0] == 0 && navios[w][1][1] == 0)){
            break;
        }
        if ((navios[w][0][0] > 10 || navios[w][0][1] > 10)||(navios[w][1][0] > 10  || navios[w][1][1] > 10)){
            printf ("Navio N%d não foi colocado pois passaria do limite do tabuleiro\n", (w+1));
            break;
        }

        //printf("navios[%d][0][0] %d ",w, navios[w][0][0]);
        //printf("navios[%d][0][1] %d ",w, navios[w][0][1]);
        //calculo
        int distanciaV, distanciaH,diagonal =0, invertido = 1;
        distanciaV = navios[w][1][0] - navios[w][0][0];
        distanciaH = navios[w][1][1] - navios[w][0][1];
        
       
        if (distanciaH <0)
        {
            distanciaH = distanciaH * -1;
            invertido = -1;
        }
        if (distanciaV<0){
            invertido = -1;
            distanciaV = distanciaV * -1;
        }
        
        if (distanciaH == distanciaV &&  distanciaV !=0)
        {
            diagonal=1;
        }     
        int tMeio = (distanciaH > distanciaV) ? distanciaH : distanciaV;
        int meio[tMeio][2];
        if(diagonal){
            for (int d = 0; d < distanciaH; d++)
            {   
                int calculoVertical = navios[w][0][0] + ( d +1 )* invertido;
                meio[d][0] =(calculoVertical > 0) ? calculoVertical : ( -1 * calculoVertical);
                meio[d][1] = navios[w][0][1] + ( d +1 )* invertido;
            }
        }else if (distanciaH > distanciaV && distanciaV ==0){
            for (int d = 0; d < distanciaH; d++)
            {
                meio[d][0] = (navios[w][0][0]);
                meio[d][1] = navios[w][0][1] + ( d +1 )* invertido;
            }
            
        }else if(distanciaV > distanciaH && distanciaH == 0){
            
            
            for (int  d = 0; d < distanciaV; d++)
            {
                meio[d][0] = navios[w][0][0] + ( d +1 )* invertido;
                meio[d][1] = navios[w][0][1];
            }
            
        }
        //calculo para ver se bate
        // vê se a posição do navio colide com a do anterior
        if (w>0 && ((navios[w][0][0] == navios[w-1][0][0]&& navios[w][0][1] == navios[w-1][0][1])||(navios[w][1][0] == navios[w-1][1][0]&& navios[w][1][1] == navios[w-1][1][1]))){
            break;
        }else{
            int sobreposicao = 0;
            for (short int i = 0; i < 10; i++){
                if (sobreposicao == 1)
                {   
                    printf ("Navio N%d não foi colocado pois sobreporia outro navio\n", (w+1));
                    break;
                }
                
                for (short int j = 0; j < 10; j++){
                    if ((navios[w][0][0] == i && navios[w][0][1] == j)|| (navios[w][1][0] == i && navios[w][1][1] == j)){
                        if (tabuleiro[i][j] == 0){ 
                            tabuleiro[i][j]= 3 ;
                        }else{
                            sobreposicao = 1;
                            break;
                        }
                    continue;
                    }else{
                    //int m = 0;
                    for (int m = 0; m < tMeio; m++){
                        if (meio[m][0] == i && meio[m][1] == j)
                        {
                            tabuleiro[i][j] = 3 ;
                            continue;
                        }
                    }
                    
                    }
                    
                }
                
                
            }
        }
               

        w ++;
    }

    


    // Usar habilidade
    int cordenada_de_ataque[2] = {6,5};
    int ataque_area[3][5][2];
    // centro [1][2]
    // 
    // [v-1,h-2], [v-1, h-1], [v-1,h], [v-1,h+1], [v-1,h+2] 
    // [v  ,h-2], [v , h-1], [v  ,h], [v  ,h+1], [v  ,h+2]
    // [v+1,h-2], [v+1, h-1], [v+1,h], [v+1,h+1], [v+1,h+2]
    // 
    int modificador[2];
    for (int i =0;i<3;i++){
        if (i == 0){
            modificador[0]=-1;
        }else if (i == 1){
            modificador[0]=0;
        }else{
            modificador[0]=1;
        }
        
        for (int j =0;j<5;j++){
            if (j == 0){
                modificador[1]=-2;
            }else{
                modificador[1]++;
            }
            ataque_area[i][j][0] = cordenada_de_ataque[0] + modificador[0];// v - Vertical
            ataque_area[i][j][1] = cordenada_de_ataque[1] + modificador[1];// h - Horizontal
        }
    }

    for (int v =0;v<3;v++){
        for (int h =0;h<5;h++){
        
            if ( epecias3x5[0][v][h] != 0){//cone
                tabuleiro[ataque_area[v][h][0]][ataque_area[v][h][1]] = epecias3x5[0][v][h];//cone
                //tabuleiro[i][j] = epecias3x5[1][v][h];//cruz
                //tabuleiro[i][j] = epecias3x5[2][v][h];//octaedro
            }
        }
    }
        
        
    
   
    printf("\n\n");
    //exibir tabuleiro
    for (short int i = 0; i < 10; i++){
        for (short int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilforize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
