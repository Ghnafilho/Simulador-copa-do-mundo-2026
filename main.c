#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"

// ###############################################
//               Funções Utilitárias
// ###############################################
// Função mais abstrata capaz de criar uma seleção
Selecao criar_selecao(const char *nome, char grupo){
    Selecao s = {0};
    strcpy(s.nome, nome);
    s.grupo = toupper(grupo);

    return s;
}


Jogo jogo_normal(Selecao *a, Selecao *b){
    Jogo x;
    int gols_a,gols_b;
    printf("\nJOGO %s x %s \n", a->nome, b->nome);
    printf("Digite a quantidade de gols marcados por(a) %s ", a->nome);
    scanf("%d",&gols_a);
    printf("Digite a quantidade de gols marcados por(a) %s ", b->nome);
    scanf("%d",&gols_b);
    printf("Placar final: %s %d x %d %s", a->nome, gols_a, gols_b, b->nome);
    a->gols_marcados += gols_a;
    b->gols_marcados += gols_b;
    a->gols_sofridos += gols_b;
    b->gols_sofridos += gols_a;
    if(gols_a>gols_b){
        a->vitorias +=1;
        b->derrotas +=1;
        a->pontos += 3;
    }
    if(gols_a==gols_b){
        a->empates +=1;
        b->empates +=1;
        a->pontos += 1;
        b->pontos +=1;
    }
    if(gols_a<gols_b){
        b->vitorias +=1;
        a->derrotas +=1;
        b->pontos += 3;
    }
    x.gols_mandante = gols_a;
    x.gols_visitante = gols_b;
    return x;
}


Selecao mata_mata(Selecao a, Selecao b){
    int gols_a,gols_b;
    printf("\nJOGO %s x %s \n", a.nome, b.nome);
    printf("Digite a quantidade de gols marcados por(a) %s ", a.nome);
    scanf("%d",&gols_a);
    printf("Digite a quantidade de gols marcados por(a) %s ", b.nome);
    scanf("%d",&gols_b);
    printf("Placar final: %s %d x %d %s", a.nome, gols_a, gols_b, b.nome);
    if(gols_a>gols_b){
        return a;
    }
    if(gols_a==gols_b){
        int gols_a_2, gols_b_2;
        printf("\nDigite a quantidade de gols marcados na prorrogacao por(a) %s ", a.nome);
        scanf("%d",&gols_a_2);
        printf("\nDigite a quantidade de gols marcados na prorrogacao por(a) %s ", b.nome);
        scanf("%d",&gols_b_2);
        printf("\nPlacar final: %s %d x %d %s", a.nome, gols_a+gols_a_2, gols_b+gols_b_2, b.nome);
        gols_a += gols_a_2;
        gols_b += gols_b_2;
        if(gols_a>gols_b){
            return a;
        }
        if(gols_a==gols_b){
            int gols_a_2, gols_b_2;
            printf("\nDigite a quantidade de gols marcados nos penâltis por(a) %s ", a.nome);
            scanf("%d",&gols_a_2);
            printf("\nDigite a quantidade de gols marcados nos penaltis por(a) %s ", b.nome);
            scanf("%d",&gols_b_2);
            printf("\nPlacar final: %s %d x %d %s", a.nome, gols_a_2, gols_b_2, b.nome);
            if(gols_a_2 > gols_b_2){
                return a;
            }
            if(gols_b_2 > gols_a_2){
                return b;
            }
            if(gols_a_2==gols_b_2){
                printf("Placar empatado, selecione um vencedor");
                int escolhido;
                printf("Digite 1 para %s e 2 para %s", a.nome, b.nome);
                scanf("%d", &escolhido);
                if(escolhido == 1){
                    return a;
                }
                if(escolhido == 2){
                    return b;
                }
            }
        }
        if(gols_a<gols_b){
            return b;
        }
    }
    if(gols_a<gols_b){
        return b;
    }
    Selecao c = {0}; // initializing with zero
    return c;
}

// ##############################################################
//                    REPESCAGENS -- TODO
// ##############################################################
RepescagemMundo mundo_rep(Selecao a,Selecao b,Selecao c){
    RepescagemMundo x;
    x.selecoes_repescagem_mundo[0] = a;
    x.selecoes_repescagem_mundo[1] = b;
    x.selecoes_repescagem_mundo[2] = c;
    return x;
}
RepescagemEuro euro_rep(Selecao a,Selecao b,Selecao c,Selecao d){
    RepescagemEuro x;
    x.selecoes_repescagem_euro[0] = a;
    x.selecoes_repescagem_euro[1] = b;
    x.selecoes_repescagem_euro[2] = c;
    x.selecoes_repescagem_euro[3] = d;
    return x;
}
Selecao rep_mundo_jogos(RepescagemMundo x){
    Selecao um;
    // a = 0 b = 1 c = 2
    um = mata_mata(x.selecoes_repescagem_mundo[1], x.selecoes_repescagem_mundo[2]);
    return mata_mata(um, x.selecoes_repescagem_mundo[0]);
}
Selecao rep_euro_jogos(RepescagemEuro x){
    Selecao um;
    Selecao dois;
    // a = 0 b = 1 c = 2 d = 3
    um = mata_mata(x.selecoes_repescagem_euro[0], x.selecoes_repescagem_euro[1]);
    dois = mata_mata(x.selecoes_repescagem_euro[2], x.selecoes_repescagem_euro[3]);
    return mata_mata(um, dois);
}
Grupo cria_grupo(Selecao a,Selecao b,Selecao c,Selecao d){
    Grupo x;
    x.selecoes[0] = a;
    x.selecoes[1] = b;
    x.selecoes[2] = c;
    x.selecoes[3] = d;
    return x;
}


int compara(Selecao x, Selecao y, Jogo confronto_xy){

    if (x.pontos > y.pontos) return 1;
    if (x.pontos < y.pontos) return 0;

    if (confronto_xy.gols_mandante > confronto_xy.gols_visitante) return 1;
    if (confronto_xy.gols_mandante < confronto_xy.gols_visitante) return 0;


    int saldo_x = x.gols_marcados - x.gols_sofridos;
    int saldo_y = y.gols_marcados - y.gols_sofridos;

    if (saldo_x > saldo_y) return 1;
    if (saldo_x < saldo_y) return 0;


    if (x.gols_marcados > y.gols_marcados) return 1;
    if (x.gols_marcados < y.gols_marcados) return 0;

    // 5. Empate total → escolha manual
    printf("Empate TOTAL entre %s e %s!\n", x.nome, y.nome);
    printf("Digite 1 para %s ficar na frente ou 2 para %s: ",
           x.nome, y.nome);

    int escolha;
    scanf("%d", &escolha);

    return (escolha == 1);
}
int compara_sem_confronto(Selecao x, Selecao y){

    if (x.pontos > y.pontos) return 1;
    if (x.pontos < y.pontos) return 0;


    int saldo_x = x.gols_marcados - x.gols_sofridos;
    int saldo_y = y.gols_marcados - y.gols_sofridos;

    if (saldo_x > saldo_y) return 1;
    if (saldo_x < saldo_y) return 0;


    if (x.gols_marcados > y.gols_marcados) return 1;
    if (x.gols_marcados < y.gols_marcados) return 0;

    // 5. Empate total → escolha manual
    printf("Empate TOTAL entre %s e %s!\n", x.nome, y.nome);
    printf("Digite 1 para %s ficar na frente ou 2 para %s: ",
           x.nome, y.nome);

    int escolha;
    scanf("%d", &escolha);

    return (escolha == 1);
}



Grupo simula_grupo(Grupo a){
    Jogo rodada_1 = jogo_normal(&a.selecoes[0], &a.selecoes[1]); // a vs b
    Jogo rodada_2 = jogo_normal(&a.selecoes[2], &a.selecoes[3]); // c vs d
    Jogo rodada_3 = jogo_normal(&a.selecoes[0], &a.selecoes[2]); // a vs c
    Jogo rodada_4 = jogo_normal(&a.selecoes[1], &a.selecoes[3]); // b vs d
    Jogo rodada_5 = jogo_normal(&a.selecoes[0], &a.selecoes[3]); // a vs d
    Jogo rodada_6 = jogo_normal(&a.selecoes[2], &a.selecoes[1]); // c vs b
    Grupo copia = a;
    Selecao temp;
    int comparados[6];
    comparados[0] = compara(a.selecoes[0], a.selecoes[1], rodada_1);
    comparados[1] = compara(a.selecoes[2], a.selecoes[3], rodada_2);
    comparados[2] = compara(a.selecoes[0], a.selecoes[2], rodada_3);
    comparados[3] = compara(a.selecoes[1], a.selecoes[3], rodada_4);
    comparados[4] = compara(a.selecoes[0], a.selecoes[3], rodada_5);
    comparados[5] = compara(a.selecoes[1], a.selecoes[2], rodada_6);

    // calcula os empates
    // colinha: a = 0; b = 1; c = 2; d = 3;
    // empate entre as 4 seleções (A, B, C e D)
    if(a.selecoes[0].pontos == a.selecoes[1].pontos && a.selecoes[0].pontos == a.selecoes[2].pontos && a.selecoes[0].pontos == a.selecoes[3].pontos){
        comparados[0] = compara_sem_confronto(a.selecoes[0], a.selecoes[1]);
        comparados[1] = compara_sem_confronto(a.selecoes[2], a.selecoes[3]);
        comparados[2] = compara_sem_confronto(a.selecoes[0], a.selecoes[2]);
        comparados[3] = compara_sem_confronto(a.selecoes[1], a.selecoes[3]);
        comparados[4] = compara_sem_confronto(a.selecoes[0], a.selecoes[3]);
        comparados[5] = compara_sem_confronto(a.selecoes[1], a.selecoes[2]);
    }
    // empate entre 3 seleções: A, B e C
    if(a.selecoes[0].pontos == a.selecoes[1].pontos && a.selecoes[0].pontos == a.selecoes[2].pontos){
        comparados[0] = compara_sem_confronto(a.selecoes[0], a.selecoes[1]);
        comparados[2] = compara_sem_confronto(a.selecoes[0], a.selecoes[2]);
        comparados[5] = compara_sem_confronto(a.selecoes[1], a.selecoes[2]);
    }
    // empate entre 3 seleções: A, B e D
    if(a.selecoes[0].pontos == a.selecoes[1].pontos && a.selecoes[0].pontos == a.selecoes[3].pontos){
        comparados[0] = compara_sem_confronto(a.selecoes[0], a.selecoes[1]);
        comparados[4] = compara_sem_confronto(a.selecoes[0], a.selecoes[3]);
        comparados[3] = compara_sem_confronto(a.selecoes[1], a.selecoes[3]);
    }
    // empate entre 3 seleções: A, C e D
    if(a.selecoes[0].pontos == a.selecoes[3].pontos && a.selecoes[0].pontos == a.selecoes[2].pontos){
        comparados[4] = compara_sem_confronto(a.selecoes[0], a.selecoes[3]);
        comparados[2] = compara_sem_confronto(a.selecoes[0], a.selecoes[2]);
        comparados[1] = compara_sem_confronto(a.selecoes[2], a.selecoes[3]);
    }
    // empate entre 3 seleções: B, C e D
    if(a.selecoes[3].pontos == a.selecoes[1].pontos && a.selecoes[3].pontos == a.selecoes[2].pontos){
        comparados[5] = compara_sem_confronto(a.selecoes[1], a.selecoes[2]);
        comparados[3] = compara_sem_confronto(a.selecoes[1], a.selecoes[3]);
        comparados[1] = compara_sem_confronto(a.selecoes[2], a.selecoes[3]);
    }

    int trocado = 0;
    int caso_final = 0;
    if(comparados[0] == 1 && comparados[2] == 1 && comparados[4] == 1){
        //Primeiro é a seleção a
        trocado = 1;
    }
    if(comparados[0] == 0 && comparados[3] == 1 && comparados[5] == 1){
        //primeiro é a seleção b
        temp = a.selecoes[0];
        a.selecoes[0] = a.selecoes[1];
        a.selecoes[1] = temp;
        trocado = 2;
    }
    if(comparados[1] == 1 && comparados[2] == 0 && comparados[5] == 0){
        //primeiro é a seleção c
        temp = a.selecoes[0];
        a.selecoes[0] = a.selecoes[2];
        a.selecoes[2] = temp;
        trocado = 3;
    }
    if(comparados[1] == 0 && comparados[3] == 0 && comparados[4] == 0){
        //primeiro é a seleção d
        temp = a.selecoes[0];
        a.selecoes[0] = a.selecoes[3];
        a.selecoes[3] = temp;
        trocado = 4;
    }

    //Primeiros e últimos é mais fácil a implementação
    if(comparados[0] != 1 && comparados[2] != 1 && comparados[4] != 1){
        // Último é a seleção a
        switch (trocado)
        {
        case 2: 
            temp = a.selecoes[3];
            a.selecoes[3] = a.selecoes[1];
            a.selecoes[1] = temp;
            
            a.selecoes[1] = copia.selecoes[2]; 
            a.selecoes[2] = copia.selecoes[3]; 
            caso_final = 1;
            break;
            
        case 3: 
            temp = a.selecoes[3];
            a.selecoes[3] = a.selecoes[2];
            a.selecoes[2] = temp;
            caso_final = 3;
            break;
            
        case 4: 
            caso_final = 5;
            break;
            
        default:
            break;
        }
    }
    if(comparados[0] != 0 && comparados[3] != 1 && comparados[5] != 1){
        //ultimo é a seleção b
        temp = a.selecoes[3];
        a.selecoes[3] = a.selecoes[1];
        a.selecoes[1] = temp;
        switch (trocado)
        {
        case 1:
            caso_final = 1;
            a.selecoes[1] = copia.selecoes[2];
            a.selecoes[2] = copia.selecoes[3];
            break;
        case 3:
            caso_final = 4;
            a.selecoes[1] = copia.selecoes[0];
            a.selecoes[2] = copia.selecoes[3];
            break;
        case 4:
            caso_final = 2;
            break;
        default:
            break;
        }
    }
    if(comparados[1] != 1 && comparados[2] != 0 && comparados[5] != 0){
        //ultimo é a seleção c
        temp = a.selecoes[3];
        a.selecoes[3] = a.selecoes[2];
        a.selecoes[2] = temp;
        switch (trocado)
        {
        case 1: 
            caso_final = 3;
            break;
        case 2:
            caso_final = 4;
            break;
        case 4:
            caso_final = 0;
            a.selecoes[1] = copia.selecoes[0];
            a.selecoes[2] = copia.selecoes[1];
            break;
        default:
            break;
        }
    }
    if(comparados[1] != 0 && comparados[3] != 0 && comparados[4] != 0){
        //ultimo é a seleção d
        switch (trocado)
        {
        case 1:
            caso_final = 5;
            break;
        case 2:
            caso_final = 2;
            break;
        case 3:
            caso_final = 0;
            a.selecoes[1] = copia.selecoes[0];
            a.selecoes[2] = copia.selecoes[1];
            break;
        default:
            break;
        }
    }
    if(comparados[caso_final]==0){
        temp = a.selecoes[2];
        a.selecoes[2] = a.selecoes[1];
        a.selecoes[1] = temp;
    }
    return a;
}

TerceirosPassados melhores_terceiros(Selecao a, Selecao b, Selecao c, Selecao d,
                                      Selecao e, Selecao f, Selecao g,Selecao h,
                                      Selecao i, Selecao j, Selecao k, Selecao l){

    Selecao terceiros[12] = {a,b,c,d,e,f,g,h,i,j,k,l};

    // Ordenação por "compara_sem_confronto"
    for(int in = 0; in < 12; in++){
        for(int jo = in + 1; jo < 12; jo++){
            int compara = compara_sem_confronto(terceiros[in], terceiros[jo]);

            // Se o segundo é melhor, troca
            if(compara == 0){
                Selecao tmp = terceiros[in];
                terceiros[in] = terceiros[jo];
                terceiros[jo] = tmp;
            }
        }
    }

    TerceirosPassados resp;

    // Pega os 8 melhores após ordenar
    for(int x = 0; x < 8; x++){
        resp.classificadas[x] = terceiros[x];       // salva seleções
        resp.grupos[x] = toupper(terceiros[x].grupo);  // salva o grupo
    }

    return resp;
}
TerceirosPassados ordena2(TerceirosPassados x, const char y[]){
    TerceirosPassados copia = x;
    for(int in = 0; in < 8; in++){
        for(int jo = 0; jo < 8; jo++){
            if(x.grupos[in] == y[jo]){
                copia.classificadas[jo] = x.classificadas[in];
            }
        }
    }
    return copia;
}

TerceirosPassados ordena(TerceirosPassados x, const char y[]){
    int contador = 0;
    for(int in = 0; in < 8; in++){
        for(int jo = 0; jo< 8; jo++){
        if(x.grupos[in] == y[jo]){
            contador ++;
        }
    }
    }
    if(contador == 8){
        return ordena2(x, y);
    }

        return x;


}
TerceirosPassados ordena3(TerceirosPassados x, const char y[495][8]){
    for(int i = 0; i<495; i++ ){
        x = ordena(x,y[i]);
    }
    return x;
}
// ##################################################
//              MAIN LOOP
// ##################################################
int main(){

    // #################################################################
    //                     Cria-se as seleções
    // #################################################################
    Grupo grupos_copa[12];

    for(int i = 0; i < 12; ++i){ // grupo
        char letra_grupo = 'A' + i;
        for(int j = 0; j < 4; ++j) // times por grupo
        {
            grupos_copa[i].selecoes[j] = criar_selecao(nomes_times[i][j], letra_grupo);
        }
    }

    // ##################################################################
    // Repescagens euro e mundo
    // Faz a repescagem dos jogos e adiciona os membros faltantes na array grupos_copa
    // 'R' de repescagem
    // ##################################################################
    RepescagemEuro po_4 = {
        { 
        criar_selecao("Dinamarca", 'R'), criar_selecao("Macedonia do Norte", 'R'), 
        criar_selecao("Republica Tcheca", 'R'), criar_selecao("Irlanda", 'R') 
        }
    };
    grupos_copa[0].selecoes[3] = rep_euro_jogos(po_4);
    grupos_copa[0].selecoes[3].grupo = 'A';

    RepescagemEuro po_3 = {
        { 
        criar_selecao("Turquia", 'R'), criar_selecao("Romenia", 'R'), 
        criar_selecao("Eslovaquia", 'R'), criar_selecao("Kosovo", 'R') 
        }
    };
    grupos_copa[3].selecoes[3] = rep_euro_jogos(po_3);
    grupos_copa[3].selecoes[3].grupo = 'D';
    
    RepescagemEuro po_2 = {
        { 
            criar_selecao("Ucrania", 'R'), criar_selecao("Suecia", 'R'), 
            criar_selecao("Polonia", 'R'), criar_selecao("Albania", 'R') 
        }
    };
    grupos_copa[5].selecoes[2] = rep_euro_jogos(po_2);
    grupos_copa[5].selecoes[2].grupo = 'F';
    
    RepescagemEuro po_1 = {
        { 
            criar_selecao("Italia", 'R'), criar_selecao("Irlanda do Norte", 'R'), 
            criar_selecao("Pais de Gales", 'R'), criar_selecao("Bosnia", 'R') 
        }
    };
    grupos_copa[1].selecoes[1] = rep_euro_jogos(po_1);
    grupos_copa[1].selecoes[1].grupo = 'B';

    RepescagemMundo rep_a = {
        { 
            criar_selecao("Iraque", 'R'), criar_selecao("Bolivia", 'R'), 
            criar_selecao("Suriname", 'R') 
        }
    };
    grupos_copa[8].selecoes[2] = rep_mundo_jogos(rep_a);
    grupos_copa[8].selecoes[2].grupo = 'I';


    RepescagemMundo rep_b = {
        { 
            criar_selecao("Congo", 'R'), criar_selecao("Jamaica", 'R'), 
            criar_selecao("Nova Caledonia", 'R') 
        }
    };
    grupos_copa[10].selecoes[1] = rep_mundo_jogos(rep_b);
    grupos_copa[10].selecoes[1].grupo = 'K';

    // ######################################################
    // Exibição dos grupos
    // ######################################################

    // Itera 12x, printando cada grupo
    for (int i = 0; i < 12; i++) {
        char letra = 'A' + i; // Gera 'A', 'B', 'C' até 'L'

        // Print inicial: Nomes das seleções no grupo
        printf("\nGrupo %c: \n%s\n%s\n%s\n%s",
            letra,
            grupos_copa[i].selecoes[0].nome,
            grupos_copa[i].selecoes[1].nome,
            grupos_copa[i].selecoes[2].nome,
            grupos_copa[i].selecoes[3].nome);

        // Simulação do grupo (atualizando o estado das seleções no array)
        grupos_copa[i] = simula_grupo(grupos_copa[i]);

        // Print final: Nomes e Pontuação após os jogos
        printf("\nGrupo %c: \n%s %d\n%s %d\n%s %d\n%s %d\n",
            letra,
            grupos_copa[i].selecoes[0].nome, grupos_copa[i].selecoes[0].pontos,
            grupos_copa[i].selecoes[1].nome, grupos_copa[i].selecoes[1].pontos,
            grupos_copa[i].selecoes[2].nome, grupos_copa[i].selecoes[2].pontos,
            grupos_copa[i].selecoes[3].nome, grupos_copa[i].selecoes[3].pontos);
    }

    // ############################################################
    // CÁLCULO DOS MELHORES TERCEIROS
    // ############################################################

    // No modelo novo, passamos o terceiro colocado de cada grupo (índice 2)
    TerceirosPassados passaram = melhores_terceiros(
        grupos_copa[0].selecoes[2],  grupos_copa[1].selecoes[2],  grupos_copa[2].selecoes[2],
        grupos_copa[3].selecoes[2],  grupos_copa[4].selecoes[2],  grupos_copa[5].selecoes[2],
        grupos_copa[6].selecoes[2],  grupos_copa[7].selecoes[2],  grupos_copa[8].selecoes[2],
        grupos_copa[9].selecoes[2],  grupos_copa[10].selecoes[2], grupos_copa[11].selecoes[2]
    );
    passaram = ordena3(passaram, tabela);
    
    // ------------------------------------------------------------
    // PRÉ-OITAVAS
    // ------------------------------------------------------------
    printf("\n--- PRE-OITAVAS ---\n");
    // Cria uma array de seleções da pré oitavas
    Selecao pre[16];

    printf("Pre-Oitavas 1\n");
    pre[0]  = mata_mata(grupos_copa[4].selecoes[0],  passaram.classificadas[3]); // E1 x 3rd
    pre[1]  = mata_mata(grupos_copa[8].selecoes[0],  passaram.classificadas[5]); // I1 x 3rd

    printf("Pre-Oitavas 2\n");
    pre[2]  = mata_mata(grupos_copa[0].selecoes[1],  grupos_copa[1].selecoes[1]); // A2 x B2
    pre[3]  = mata_mata(grupos_copa[5].selecoes[0],  grupos_copa[2].selecoes[1]); // F1 x C2

    printf("Pre-Oitavas 3\n");
    pre[4]  = mata_mata(grupos_copa[10].selecoes[1], grupos_copa[11].selecoes[1]); // K2 x L2
    pre[5]  = mata_mata(grupos_copa[7].selecoes[0],  grupos_copa[9].selecoes[1]); // H1 x J2

    printf("Pre-Oitavas 4\n");
    pre[6]  = mata_mata(grupos_copa[3].selecoes[0],  passaram.classificadas[2]); // D1 x 3rd
    pre[7]  = mata_mata(grupos_copa[6].selecoes[0],  passaram.classificadas[4]); // G1 x 3rd

    printf("Pre-Oitavas 5\n");
    pre[8]  = mata_mata(grupos_copa[2].selecoes[0],  grupos_copa[5].selecoes[1]); // C1 x F2
    pre[9]  = mata_mata(grupos_copa[4].selecoes[1],  grupos_copa[8].selecoes[1]); // E2 x I2

    printf("Pre-Oitavas 6\n");
    pre[10] = mata_mata(grupos_copa[0].selecoes[0],  passaram.classificadas[0]); // A1 x 3rd
    pre[11] = mata_mata(grupos_copa[11].selecoes[0], passaram.classificadas[7]); // L1 x 3rd

    printf("Pre-Oitavas 7\n");
    pre[12] = mata_mata(grupos_copa[9].selecoes[0],  grupos_copa[7].selecoes[1]); // J1 x H2
    pre[13] = mata_mata(grupos_copa[3].selecoes[1],  grupos_copa[6].selecoes[1]); // D2 x G2

    printf("Pre-Oitavas 8\n");
    pre[14] = mata_mata(grupos_copa[1].selecoes[0],  passaram.classificadas[1]); // B1 x 3rd
    pre[15] = mata_mata(grupos_copa[10].selecoes[0], passaram.classificadas[6]); // K1 x 3rd

    // ------------------------------------------------------------
    // OITAVAS
    // ------------------------------------------------------------
    printf("\n--- OITAVAS ---\n");
    // Mesma lógica das pré oitavas
    Selecao oit[8];

    printf("Oitavas 1\n");
    oit[0] = mata_mata(pre[0], pre[1]);

    printf("Oitavas 2\n");
    oit[1] = mata_mata(pre[2], pre[3]);

    printf("Oitavas 3\n");
    oit[2] = mata_mata(pre[4], pre[5]);

    printf("Oitavas 4\n");
    oit[3] = mata_mata(pre[6], pre[7]);

    printf("Oitavas 5\n");
    oit[4] = mata_mata(pre[8], pre[9]);

    printf("Oitavas 6\n");
    oit[5] = mata_mata(pre[10], pre[11]);

    printf("Oitavas 7\n");
    oit[6] = mata_mata(pre[12], pre[13]);

    printf("Oitavas 8\n");
    oit[7] = mata_mata(pre[14], pre[15]);


    // ------------------------------------------------------------
    // QUARTAS
    // ------------------------------------------------------------
    printf("\n--- QUARTAS ---\n");

    Selecao qua[4];

    printf("Quartas 1\n");
    qua[0] = mata_mata(oit[0], oit[1]);

    printf("Quartas 2\n");
    qua[1] = mata_mata(oit[2], oit[3]);

    printf("Quartas 3\n");
    qua[2] = mata_mata(oit[4], oit[5]);

    printf("Quartas 4\n");
    qua[3] = mata_mata(oit[6], oit[7]);


    // ------------------------------------------------------------
    // SEMIFINAIS
    // ------------------------------------------------------------
    printf("\n--- SEMIFINAIS ---\n");
    
    Selecao semi[2];

    printf("Semifinal 1\n");
    semi[0] = mata_mata(qua[0], qua[1]);

    printf("Semifinal 2\n");
    semi[1] = mata_mata(qua[2], qua[3]);


    // ------------------------------------------------------------
    // FINAL
    // ------------------------------------------------------------
    printf("\n--- FINAL ---\n");

    printf("Final\n");
    Selecao final1 = mata_mata(semi[0], semi[1]);

        printf("%s",final1.nome);
    }
