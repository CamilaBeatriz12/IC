#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//funçao do mdc
int gcd(int a, int b){

  if(b == 0){
    return a;
  }

  return gcd(b, a % b);
}

int main(){
    clock_t Ticks[2];
    Ticks[0] = clock();

    //declaração de variáveis
    int p_n, q_n, n,retorno;
    int i,j,x,y, contador = 0;
    int x0 = 7;
    int q = 1,mdc = 1;
    int vetor[4];
    float matriz[1][5];
    double Tempo;

    FILE *arquivo;
    arquivo = fopen("Experimento.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao criar arquivo \n");
    }

    for(i = 0; i < 10; i++){ //ERRO: eu não sei o que tem de erro pq ele não consegue pegar os 10 primeiros primeiros primos e fazer a conta, mas números menores dá certo
      fscanf(arquivo, "%d\n", &vetor[i]);
      printf("%d\n", vetor[i]);
    }

    fclose(arquivo);

    for(j = 0; j < 9; j++){// ERRO: não faz a conta corretamente com números maiores
      p_n = vetor[j];
      printf("O valor de p_n e: %d\n", p_n);

      q_n = vetor[j+1];
      printf("O valor de q_n e: %d\n", q_n);

      n = p_n *q_n;

      //funçao pra achar o x0 aleatoriamente
     /*srand(100); //constante

      for(i = 0; i < 1; i++){ //for

        x0 = rand() % n;

        printf("%d \n", x0); //ir apenas até o numero maximo n
      }*/

      x = x0;
      y = x0;
      mdc = 1;
      q = 1;
      contador = 0;

      while(mdc == 1 && contador < n){
        x = (x * x + 1) % n; //função específica

        y = (y * y + 1) % n; //função específica
        y = (y * y + 1) % n; //função específica

        printf("X: %d \n", x);
        printf("Y: %d \n", y);

        q = ((y - x) * q) % n;

        printf("Valor de Q: %d \n", q);

        if(q < 0){
          q = q + n;
        }

        mdc = gcd(q, n);

        printf("GCD: %d \n", mdc);

        contador++;
      }

      printf("iteracoes: %d \n", contador);

      if(mdc > 1 && mdc < n){
        retorno = 1;
        printf("Numero fatorado com sucesso: %d \n", retorno);
      }
      else{
        retorno = 0;
        printf("Nao foi possivel fatorar o numero: %d \n", retorno);
      }

      Ticks[1] = clock();
      Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
      printf("Tempo gasto: %g ms. \n", Tempo);

      matriz[0][0] = p_n;
      matriz[0][1] = n;
      matriz[0][2] = Tempo;
      matriz[0][3] = contador;
      matriz[0][4] = retorno;

      printf("%.0f\t", matriz[0][0]);
      printf("%.0f\t", matriz[0][1]);
      printf("%.0f\t", matriz[0][2]);
      printf("%.0f\t", matriz[0][3]);
      printf("%.0f\n", matriz[0][4]);

      FILE *arq;
      arq = fopen("C:\\Users\\Usuario\\Documents\\IC\\Experimento.txt", "a"); // abri dnv o arquivo pra poder escrever logo abaixo dos primos, usei abertura "a", pois fica visível tanto os primos quanto a matriz dos resultados
                                                                              // mas é possível usar a abertura "w", mas acaba apagando os primos
      if(arq == NULL){
          printf("Erro ao criar arquivo \n");
      }

      fprintf(arq, "\n%.0f\t", matriz[0][0]); //o "\n" é só pra ficar organizado no arquivo
      fprintf(arq, "%.0f\t", matriz[0][1]);
      fprintf(arq, "%.0f\t", matriz[0][2]);
      fprintf(arq, "%.0f\t", matriz[0][3]);
      fprintf(arq, "%.0f\n", matriz[0][4]);

      fclose(arq);

      printf("GCD: %d \n", mdc);
    }

    return 0;
}
