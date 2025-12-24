#ifndef UTILS_H
#define UTILS_H

typedef struct Selecao
{
    char nome[100];
    int pontos;
    int vitorias;
    int derrotas;
    int empates;
    int gols_marcados;
    int gols_sofridos;
    char grupo;

} Selecao;

typedef struct Jogo
{
    int gols_mandante;
    int gols_visitante;
} Jogo;

typedef struct Grupo{
    Selecao selecoes[4]; // array of teams
}Grupo;

typedef struct RepescagemEuro{
    Selecao selecoes_repescagem_euro[4];
}RepescagemEuro;

typedef struct RepescagemMundo{
    Selecao selecoes_repescagem_mundo[3];
}RepescagemMundo;

typedef struct TerceirosPassados
{
   Selecao classificadas[8];
   char grupos[8];    
}TerceirosPassados;

Selecao criar_selecao(const char *nome, char grupo);
Jogo jogo_normal(Selecao *a, Selecao *b);
Selecao mata_mata(Selecao a, Selecao b); // why not passing by pointer here too?
Grupo cria_grupo(Selecao a, Selecao b, Selecao c, Selecao d);
TerceirosPassados melhores_terceiros(Selecao a, Selecao b, Selecao c, Selecao d , 
    Selecao e, Selecao f, Selecao g, Selecao h, 
    Selecao i, Selecao j, Selecao k, Selecao l
);

extern const char tabela[495][8];
extern const char *nomes_times[12][4];

#endif