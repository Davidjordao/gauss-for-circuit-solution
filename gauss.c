#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

float **p,*v,*i;//-----------------------FLAG

void escalona(float linhas, float colunas)
{
  int i=0,y,z,a,b;
  float *t,*aux,mult=0;
  aux=(float*)malloc(linhas*sizeof(float));
  t=(float*)malloc(colunas*sizeof(float));
  for(i=0;i<linhas;i++)
  {//elemento na posição 0,0 ...vai zerar todos os elementos abaixo dele
    for(y=i+1;y<linhas;y++)
    {
        mult = p[y][i]/p[i][i];
        for(a=0;a<colunas;a++)
        {
            t[a]=0;
            t[a]=mult*p[i][a];
        }
        for(b=0;b<colunas;b++)
        {
            p[y][b]=t[b]-p[y][b];
        }
    aux[y]=mult*v[y];
    v[y]=aux[y]-v[y];
    }
  }
    printf("\n\n\n\n");
    free(aux);//--------------------FLAG
    free(t);
}

void resultado(float linhas, float colunas)//------------------FLAG
{//begin to work in linear system resolution
    i=(float*)malloc(colunas*sizeof(float));
    int x,y,trade=0;
        for(x=0;x<linhas;x++)
        {
            trade=linhas-x;
            i[x]=p[trade][trade];
        }   
        for(y=0;y<colunas;y++)
        {   
            printf("%f  aaaa \n",i[x]);
        }
    free(i);
}//-------------------------------------------------

void imprime (float linhas, float colunas)
{
    int y,i;
    for(i=0;i<linhas;i++){
        for(y=0;y<colunas;y++){
        printf("%f ",p[i][y]);
    }
    printf(" | %f |",v[i]);
    printf("\n");
    }
}
void criaMatriz(float linhas, float colunas)
{
    int i;
    if (linhas == colunas)
    {
        v=(float*)malloc(linhas*sizeof(float));
        p=(float*)malloc(linhas*sizeof(float));
        if (p==NULL)
            {
                printf("Memoria Cheia\n");
                exit(1);
            }
        for (i=0;i<linhas;i++)
            {
                p[i]=(float*)malloc(colunas*sizeof(float));
            }
    }
}

void preenchimento (float linhas,float colunas)
{
    int y,i;
    for(i=0;i<linhas;i++)
    {
        for(y=0;y<colunas;y++)
        {
         printf("Posicao [%d][%d]",i,y);
         scanf("%f",&p[i][y]);   
        }
        printf("entre com a solução %d :",i+1);
        scanf("%f",&v[i]);
    }
    system("clear");
}
void main()
{
    int i;
    float linhas=0, colunas=0;
    printf("Entre com numero de equações : \n");
    scanf("%f",&linhas);
    printf("Entre com numero de icognitas : \n");
    scanf("%f",&colunas);
    criaMatriz(linhas,colunas);
    preenchimento(linhas,colunas);
    imprime(linhas,colunas);
    escalona(linhas,colunas);
    imprime(linhas,colunas);
    resultado(linhas,colunas);//------------------------FLAG    
    free(p);
    free(v);//----------------------FLAG
    system("pause");
}
