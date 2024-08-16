#include "string/string.h"
#include "forca_bruta/forca_bruta.h"
#include "kmp/kmp.h"
#include "bmh/bmh.h"
#include "bmhs/bmhs.h"

#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {

    //Definição de variáveis para análise de tempo de processamento
    struct timeval start_time, end_time;
    struct rusage start_usage, end_usage;
    long cpu_time;
    long real_time;

    //Verificação de argumentos da linha de comando
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <algoritmo> entrada.txt\n", argv[0]);
        return 1;
    }

    //Atribuição dos argumentos da linha de comando a variáveis
    char *algoritmo = argv[1];
    char *entrada = argv[2];

    //Abertura do arquivo de entrada
    FILE *input = fopen(entrada, "r");
    if (input == NULL) {
        perror("Erro ao abrir o arquivo de entrada.");
        return 1;

    }

    //Abertura ou criação do arquivo de saída
    FILE *output = fopen("output/output.txt", "w");
    
    //Leitura de dados do arquivo de entrada
    string *t = lerString(input);
    string *p = lerString(input);

    long long k;
    fscanf(input ,"%lld", &k);

    for(long long i = 0; i < k; i++){
        long long a, b;
        fscanf(input, "%lld %lld", &a, &b);

        //Criação da substring a ser analizada a partir do texto original
        t->inicio = a - 1;
        t->fim = b;

        //Início da contagem de tempo
        gettimeofday(&start_time, NULL);
        getrusage(RUSAGE_SELF, &start_usage);

        //Processamento
        if(algoritmo[0] == '1'){
            if(Kmp(t, p)){
                fprintf(output, "sim\n");
            }else{
                fprintf(output, "nao\n");
            }
        }else if(algoritmo[0] == '2'){
            if(Bmh(t, p)){
                fprintf(output, "sim\n"); 
            }    
            else {
                fprintf(output, "nao\n");
            }
        }else if(algoritmo[0] == '3'){
            if(Bmhs(t, p)){
                fprintf(output, "sim\n");
            } 
            else{
                fprintf(output, "nao\n");
            }
        }else if(algoritmo[0] == '4'){
            if(ForcaBruta(t, p)){
                fprintf(output, "sim\n");
            } 
            else{
                fprintf(output, "nao\n");
            }
        }

        //Cálculo de tempo gasto no processamento e impressão da saída
        gettimeofday(&end_time, NULL);
        getrusage(RUSAGE_SELF, &end_usage);

        cpu_time = (end_usage.ru_utime.tv_sec - start_usage.ru_utime.tv_sec) * 1000000 +
                    (end_usage.ru_utime.tv_usec - start_usage.ru_utime.tv_usec);
        real_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 +
                    (end_time.tv_usec - start_time.tv_usec);
        // printf("Tempo de CPU: %ld microssegundos\n", cpu_time);
        printf("%lld %lld %ld\n", a, b, cpu_time);
        // printf("Tempo real: %ld microssegundos\n", real_time);
    }



    //Fechamento dos arquivos de entrada e saída
    fclose(input);
    fclose(output);

    //Desalocando o padrão "p" e o texto "t"
    desalocarString(t);
    desalocarString(p);

    return 0;
}