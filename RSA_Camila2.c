#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//funcao que gera o maior divisor comum
long int gcd(long int a, long int b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}



//funcao para criptografar
long int Criptografar(long int b, long int n, long int e){


    FILE *arquivo;
    arquivo = fopen("Criptografado.txt", "w");


    if(arquivo==NULL){
        printf("Erro ao criar arquivo! \n");
    }

    printf("Mensagem a ser encriptada: %ld \n", b);
    fprintf(arquivo, "Mensagem a ser encriptada: %ld \n", b);


    //para criptografar tem o segulong inte passo: (b ^ e) % n;
    //long int c = (pow(b , e));

    long int c = 1;

    for(int i=1; i<=e ; i++){
        c = (c * b) % n;
        //printf("i: %d \n", i);

    }

    //c = fmod(c , n); //funcao para divisao, com o % n da para realizar o calculo

    if(c < 0){
        c = c + n;
    }

    printf("Mensagem criptografada: %ld \n", c);
    fprintf(arquivo, "Mensagem criptografada: %ld \n", c);

    fclose(arquivo);

    return c;
}

//funcao para descriptografar
long int Descriptografar(long int c, long int n, long int d) {



    //long int C; //variavel para receber o q tem no arquivo criptografado

    long int b = 1;

    for(int i=1; i<=d; i++){
       b = (c * b) % n;
    }

    //b = fmod(b, n);

    if(b < 0){
        b = b + n;
    }

    printf("Mensagem Decriptada: %ld \n", b);



    FILE *arquivo1;
    FILE *arquivo2;

    arquivo1 = fopen("Criptografado.txt", "r");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir arquivo \n");
    } else {
        arquivo2 = fopen("Descriptografado.txt", "w");

        if (arquivo2 == NULL) {
            printf("Erro ao abrir arquivo \n");
        }

        // fscanf(arquivo1, "%lf \n", &C);
        // printf("%lf \n", C);
        //
        // long int D = (pow(C , d)); //variavel para descriptografar, com o mesmo jeito q criptografar so q agr com o d
        //
        // D = fmod(D , n);

        //printf("Mensagem decriptada: %ld \n", b);
        //fprintf(arquivo2, "Mensagem decriptada: %lf \n", D);
    }

    fclose(arquivo1);
    fclose(arquivo2);

    return b;

}

long int main() {

    long int c, BLOCO;

    //chave publica para criptografar apenas
    long int p = 1223; //constante pequena
    long int q = 1987; //constante pequena
    long int n; //mutilplicacao de p e q
    long int phi;
    long int e; //numero long inteiro comecando do 2...Nao pode ter divisor comum com phi



    //chave privada para descriptografar
    //long int k = 2; //long inteiro qualquer para o calculo de d
    long int d; //inverso do e mod phi

    long int b = 1070777; //bloco usado


    n = p*q;

    printf("n: %ld \n", n);

    phi = (p-1)*(q-1);
    printf("phi: %ld \n", phi);

    //para achar o melhor e nas condicoes ja descritas
    //while(e<phi){
      //  if(gcd(e,phi) == 1){
        //    break;
        //}
        //else{
          //  e++;
        //}
    //}
    //printf("e: %ld \n", e);

    for (int e = 2; e<phi ; ++e) {
        if(gcd(e,phi) == 1){
            return e;
        }
        else{
            e++;
        }
    }

    // d é o inverso mod phi de e, entao: d*e = 1(mod phi)...
    // com as primeiras aulas, sabemos q passando o e dividindo temos q o d = 1 + um k*phi
    // d = (1 + (k*phi))/e;
    //
    // printf("d: %ld\n");

    d = 1051235;

    c = Criptografar(b, n, e);
    BLOCO  = Descriptografar(c, n, d);

    return 0;
}
