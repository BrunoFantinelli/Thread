#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


 int vec[10];
 int vec2[10];
 int tam = 0;
 float divi;
void *function(void *param)
{
    char url[]="teste.txt";
    char ch;
    int j = 0;
    int i = 0;
    FILE *arq;
    arq = fopen(url, "r");
    while( (ch=fgetc(arq))!= ';' ){
        vec[tam] = ch - 48;
        vec2[tam] = vec[tam];
        printf("Thread #1 --> %d \n", vec[tam]);
        tam++;
    }

}

void *function2(void *param)
{
    int i;
    int j;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {

            if(vec[i] < vec[j])
            {
                int temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            }

        }
    }
    for(i = 0; i < tam; i++)
    {

     printf("Thread #2 --> Ordenado: %d\n", vec[i]);
    }


}

void *function3(void *param)
{
    int i;
    int soma = 0;
    int multiplacao ;
    float media = 0.00;
    for (i = 0; i < tam; i++)
    {
        soma += vec2[i];
        multiplacao *= vec2[i];

    }
    divi = tam;
    media = soma/divi;
    printf("Thread #3 --> Soma: %d\n", soma);
    printf("Thread #3 --> Multiplicacao: %d\n", multiplacao);
    printf("Thread #3 --> Media: %.2f\n", media);






}

int main(void)
{
       pthread_t threads[3];
       pthread_create(&threads[1], NULL, function, NULL);
       pthread_join(threads[1], NULL);
       pthread_create(&threads[2], NULL, function2, NULL);
       pthread_create(&threads[3], NULL, function3, NULL);
       pthread_join(threads[3], NULL);
       pthread_join(threads[2], NULL);




       return 0;
}
