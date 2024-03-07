/* iaed-23 - ist1106609 - project2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao Constantes */

#define MAX_NOME_CARREIRA 21

#define MAX_PARAGENS 10000
#define MAX_LIGACOES 30000
#define MAX_CARREIRAS 200

/* Definicao de Tipos de Dados */

typedef struct paragem{
    char *nome;
    double latitude, longitude;
    int idCarreiras[MAX_CARREIRAS];
    int numCarreiras;
    struct paragem *prox_p, *ant_p;
} Paragem;

typedef struct ligacao{
    int idCarreira;
    int idOrigem, idDestino;
    double custo, duracao;
    struct ligacao *prox_l, *ant_l;
} Ligacao;

typedef struct carreira{
    char *nome;
    double custoTotal;
    double duracaoTotal;
    int idLigacoes[MAX_LIGACOES];
    int numLigacoes;
    struct carreira *prox_c, *ant_c;
} Carreira;

/* Variaveis Globais */

char _buffer[BUFSIZ]; /* Buffer auxiliar. */

/* Cria uma nova lista ligada de carreiras.*/

Carreira *novaCarreira(){
    Carreira *car = malloc(sizeof(Carreira));
    if(!car) return NULL;
    car->prox_c = car->ant_c = NULL;
    return car;
}

/* Cria uma nova lista ligada de paragens.*/

Paragem *novaParagem(){
    Paragem *par = malloc(sizeof(Paragem));
    if(!par) return NULL;
    par->prox_p = par->ant_p = NULL;
    return par;
}

/* Funções para parsing do input */

/* Le espaços. Devolve 0 se chegou ao final de linha ou 1 caso contrário. */

int leEspacos() {
    int c;
    while ((c = getchar()) == ' ' || c == '\t');
    if (c == '\n') 
        return 0;
    ungetc(c, stdin);
    return 1;
}

/* Le um nome para a string que recebe como parametro. */

void leNome(char s[]) {
    int i = 0, c;
    s[0] = getchar();
    if (s[0] != '"') {
        i = 1;
        while ((c = getchar()) != ' ' && c != '\t' && c != '\n')
            s[i++] = c;
        ungetc(c, stdin);
    }
    else {
        while((c = getchar()) != '"')
            s[i++] = c;
    }
    s[i++] = '\0';
}

/* Le todo o texto até ao final de linha. */

void leAteFinalLinha(char s[]) {
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
}


/* Fnções para tratar comandos */

/* Funções para tratar as carreiras */

/* Mostra no output a carreira com indice i */

void mostraCarreira(Carreira *car) {
    int numLigacoes = car->numLigacoes;

    printf("%s ", car->nome);
    if (numLigacoes > 0) {
        printf("%s %s ", _paragens[_ligacoes[_carreiras[i].idLigacoes[0]].idOrigem].nome,
                         _paragens[_ligacoes[_carreiras[i].idLigacoes[numLigacoes-1]].idDestino].nome);
        printf("%d ", numLigacoes+1);
        printf("%.2f ", car->custoTotal);
        printf("%.2f\n", car->duracaoTotal);
    }
    else 
        printf("%d %.2f %.2f\n", 0, 0.0, 0.0);
}

/* Mostra as ligações da carreira com indice i. */

void mostraLigacoesCarreira(Carreira *car, int i, int inverso) {
    int l, numLigacoes = car->numLigacoes;
    int idLigacao;

    if (numLigacoes == 0) 
        return;
    if (inverso == 0) {
        for (l = 0; l < numLigacoes; l++) {
            idLigacao = _carreiras[i].idLigacoes[l];
            printf("%s, ", _paragens[_ligacoes[idLigacao].idOrigem].nome);
        }
        idLigacao = _carreiras[i].idLigacoes[numLigacoes-1];
        printf("%s\n", _paragens[_ligacoes[idLigacao].idDestino].nome);
    }
    else {
        for (l = numLigacoes-1; l >= 0; l--) {
            idLigacao = _carreiras[i].idLigacoes[l];
            printf("%s, ", _paragens[_ligacoes[idLigacao].idDestino].nome);
        }
        idLigacao = _carreiras[i].idLigacoes[0];
        printf("%s\n", _paragens[_ligacoes[idLigacao].idOrigem].nome);
    }
}

/* Mostra todas as carreiras. */

void listaCarreiras(Carreira *car) {
    while ((car = car->prox_c) != NULL)
        mostraCarreira(car);
}

/* Procura uma carreira por nome.
   Devolve a carreira ou -1 se não existe. */

int encontraCarreira(Carreira *car, char nomeCarreira[]) {
    while ((car = car->prox_c) != NULL)
        if (strcmp(car->nome, nomeCarreira) == 0)
            return car;
    return -1;
}

/* Procura se uma paragem existe numa carreira.
   Se existir, devolve o indice da primeira ligação que usa
   a paragem. Caso contrário, devolve -1. */

int encontraParagemCarreira(Carreira *car, int idCarreira, int idParagem) {
    int numLigacoes = _carreiras[idCarreira].numLigacoes;
    int i, idLigacao;

    for (i = 0; i < numLigacoes; i++) {
        idLigacao = _carreiras[idCarreira].idLigacoes[i];
        if (_ligacoes[idLigacao].idOrigem == idParagem)
            return i;
    }
    idLigacao = _carreiras[idCarreira].idLigacoes[numLigacoes-1];
    if (_ligacoes[idLigacao].idDestino == idParagem)
        return numLigacoes;
    return -1;
}

/* Cria uma carreira nova. */

void criaCarreira(Carreira *car, char nomeCarreira[]) {
    Carreira *nova = malloc(sizeof(Carreira));
    nova->custoTotal = 0.0;
    nova->duracaoTotal = 0.0;
    nova->numLigacoes = 0;
    nova->nome = malloc(sizeof(nomeCarreira));
    strcpy(nova->nome, nomeCarreira);
    nova->prox_c = NULL;
    nova->ant_c = car->ant_c;
    car->ant_c->prox_c = nova;
    car->ant_c = nova;
}

/* Verifica se a string é um prefixo de tamanho pelo menos 3 da
   palavra inverso. */

int verificaInversoOk(char s[]) {
    char inv[] = "inverso";
    int size = strlen(s), i;

    if (size < 3 || size > 7)
        return 0;
    for (i = 0; i < size; i++)
        if (inv[i] != s[i])
            return 0;
    return 1;
}

/* Função para tratar do comando 'c'. */

void carreiras(Carreira *car) {
    char s[BUFSIZ];
    int index, fimLinha = leEspacos();
    
    if (!fimLinha) {
        listaCarreiras(car);
        return;
    }

    leNome(s);
    index = encontraCarreira(car, s);
    fimLinha = leEspacos();
    if (!fimLinha) {
        if (index == -1)
            criaCarreira(car, s);
        else
            mostraLigacoesCarreira(car, index, 0);
    }
    else {
        leNome(_buffer);
        if (verificaInversoOk(_buffer))
            mostraLigacoesCarreira(car, index, 1);
        else
            printf("incorrect sort option.\n");
        leAteFinalLinha(_buffer);
    }
}

/* Funções para tratar as paragens */

/* Mostra uma paragem. */

void mostraParagem(Paragem *par) {
    printf("%s: %16.12f %16.12f %d\n", par->nome, par->latitude, par->longitude, par->numCarreiras);
}

/* Mostra todas as paragens. */

void listaParagens(Paragem *par) {
    while ((par = par->prox_p) != NULL)
        mostraParagem(par);
}

/* Verifica se existe uma paragem com um determinado nome.
   Se existir devolve a paragem. Caso contrário, devolve -1. */

int encontraParagem(Paragem *par, char nomeParagem[]) {
    while ((par = par->prox_p) != NULL){
        if (strcmp(nomeParagem, par->nome) == 0)
            return par;
    }
    return -1;
}

/* Cria uma nova paragem. */

void criaParagem(Paragem *par, char nomeParagem[], double latitude, double longitude) {
    Paragem *nova = malloc(sizeof(Paragem));
    if(!nova) return;
    nova->latitude = latitude;
    nova->longitude = longitude;
    nova->numCarreiras = 0;
    nova->nome = malloc(sizeof(char) * (strlen(nomeParagem) + 1));
    strcpy(nova->nome, nomeParagem);
    nova->prox_p = NULL;
    nova->ant_p = par->ant_p;
    par->ant_p->prox_p = nova;
    par->ant_p = nova;
}

/* Função para tratar o comando 'p'. */

void paragens(Paragem *par) {
    char *s;
    int i, fimLinha = leEspacos();
    
    if (!fimLinha) {
        listaParagens(par);
        return;
    }
    leNome(s);
    fimLinha = leEspacos();
    if (!fimLinha) {
        if ((i = encontraParagem(par, s)) == -1)
            printf("%s: no such stop.\n", s);
        else   
            printf("%16.12f %16.12f\n", par->latitude, par->longitude);
    }
    else {
        double latitude, longitude;
        if(scanf("%lf%lf", &latitude, &longitude) < 1){}
        if (encontraParagem(par, s) == -1)
            criaParagem(par, s, latitude, longitude);
        else
            printf("%s: stop already exists.\n", s);
        leAteFinalLinha(_buffer);
    }
}

/* Funções para tratar as Ligações */

/* Adiciona uma nova ligação. */

void criaLigacao(int idCarreira, int idParagemOrigem, int idParagemDestino,
                 double custo, double duracao) {
    _ligacoes[_numLigacoes].idCarreira = idCarreira;
    _ligacoes[_numLigacoes].idOrigem = idParagemOrigem;
    _ligacoes[_numLigacoes].idDestino = idParagemDestino;
    _ligacoes[_numLigacoes].custo = custo;
    _ligacoes[_numLigacoes].duracao = duracao;
    _numLigacoes++;
}

/* Acrescenta uma nova ligação no fim de uma carreira. */

void acrescentaLigacaoFim(int idCarreira, int idLigacao) {
    int numLigacoesCarreira = _carreiras[idCarreira].numLigacoes;

    _carreiras[idCarreira].idLigacoes[numLigacoesCarreira] = idLigacao;
    _carreiras[idCarreira].custoTotal += _ligacoes[idLigacao].custo;
    _carreiras[idCarreira].duracaoTotal += _ligacoes[idLigacao].duracao;
    _carreiras[idCarreira].numLigacoes++;
}

/* Acrescenta uma nova ligação no início de uma carreira. */

void acrescentaLigacaoInicio(int idCarreira, int idLigacao) {
    int numLigacoesCarreira = _carreiras[idCarreira].numLigacoes;
    int i;

    for (i = numLigacoesCarreira-1; i >= 0; i--)
        _carreiras[idCarreira].idLigacoes[i+1] = _carreiras[idCarreira].idLigacoes[i];

    _carreiras[idCarreira].idLigacoes[0] = idLigacao;
    _carreiras[idCarreira].custoTotal += _ligacoes[idLigacao].custo;
    _carreiras[idCarreira].duracaoTotal += _ligacoes[idLigacao].duracao;
    _carreiras[idCarreira].numLigacoes++;
}

/* Adiciona que existe uma nova carreira associada a uma paragem. */

void adicionaCarreiraParagem(int idParagem, int idCarreira) {
    _paragens[idParagem].idCarreiras[_paragens[idParagem].numCarreiras] = idCarreira;
    _paragens[idParagem].numCarreiras++;
}


/* Adiciona primeira ligacao da carreira. */

void adicionaPrimeiraLigacao(int idCarreira, int idParagemOrigem, int idParagemDestino,
                     double custo, double duracao) {
    adicionaCarreiraParagem(idParagemOrigem, idCarreira);
    if (idParagemOrigem != idParagemDestino)
        adicionaCarreiraParagem(idParagemDestino, idCarreira);
    criaLigacao(idCarreira, idParagemOrigem, idParagemDestino, custo, duracao);
    acrescentaLigacaoFim(idCarreira, _numLigacoes-1);  
}


/* Adiciona uma nova ligação a uma carreira. */

void adicionaLigacao(int idCarreira, int idParagemOrigem, int idParagemDestino,
                     double custo, double duracao) {
    int numLigacoesCarreira = _carreiras[idCarreira].numLigacoes;
    
    if (numLigacoesCarreira == 0) 
        adicionaPrimeiraLigacao(idCarreira, idParagemOrigem, idParagemDestino,
				custo, duracao);
    else {
        int idPrimeiraLigacao = _carreiras[idCarreira].idLigacoes[0];
        int idUltimaLigacao = _carreiras[idCarreira].idLigacoes[numLigacoesCarreira-1];
        if (idParagemOrigem == _ligacoes[idUltimaLigacao].idDestino) {
            if (encontraParagemCarreira(idCarreira, idParagemDestino) == -1)
                adicionaCarreiraParagem(idParagemDestino, idCarreira);
            criaLigacao(idCarreira, idParagemOrigem, idParagemDestino, custo, duracao);
            acrescentaLigacaoFim(idCarreira, _numLigacoes-1);
        }
        else if (idParagemDestino == _ligacoes[idPrimeiraLigacao].idOrigem) {
            if (encontraParagemCarreira(idCarreira, idParagemOrigem) == -1)
                adicionaCarreiraParagem(idParagemOrigem, idCarreira);
            criaLigacao(idCarreira, idParagemOrigem, idParagemDestino, custo, duracao);
            acrescentaLigacaoInicio(idCarreira, _numLigacoes-1);
        }
        else 
            printf("link cannot be associated with bus line.\n");
    }
}

/* Le nome de carreira e paragens de uma ligacao. */

void leNomesComando(char nomeCarreira[], char nomeOrigem[], char nomeDestino[]) {
    leEspacos();
    leNome(nomeCarreira);
    leEspacos();
    leNome(nomeOrigem);
    leEspacos();
    leNome(nomeDestino);
}

/* Função para tratar o comando 'l'. */

void ligacoes() {
    char nomeCarreira[MAX_NOME_CARREIRA], nomeOrigem[MAX_NOME_PARAGEM], nomeDestino[MAX_NOME_PARAGEM];
    double custo, duracao;
    int indexCarreira, indexOrigem, indexDestino;

    leNomesComando(nomeCarreira, nomeOrigem, nomeDestino);
    if(scanf("%lf%lf", &custo, &duracao) < 1){}
    leAteFinalLinha(_buffer);

    indexCarreira = encontraCarreira(nomeCarreira);
    if (indexCarreira == -1)
        printf("%s: no such line.\n", nomeCarreira);
    else {
        indexOrigem = encontraParagem(nomeOrigem);
        if (indexOrigem == -1) 
	    printf("%s: no such stop.\n", nomeOrigem);
	else {
	    indexDestino = encontraParagem(nomeDestino);
	    if (indexDestino == -1)
	        printf("%s: no such stop.\n", nomeDestino);
	    else if (custo < 0.0 || duracao < 0.0)
	            printf("negative cost or duration.\n");
		else 
		    adicionaLigacao(indexCarreira, indexOrigem, indexDestino, custo, duracao);
	}
    }
}

/* Funções para tratar as interseções */

/* Aplica Bubble Sort a um vector de identificadores de carreiras. */

void ordenaCarreiras(int idCarreiras[], int numCarreiras) {
    int i, j, houveTroca = 1;
    for (i = 0; houveTroca && i < numCarreiras-1; i++) {
        houveTroca = 0;
	for (j = 0; j < numCarreiras-1-i; j++) {
	    if (strcmp(_carreiras[idCarreiras[j]].nome, _carreiras[idCarreiras[j+1]].nome) > 0) {
	        int aux = idCarreiras[j];
	        idCarreiras[j] = idCarreiras[j+1];
		idCarreiras[j+1] = aux;
		houveTroca = 1;
	    }
	}
    }
}

/* Função para tratar o comando 'i'. */

void intersecoes() {
    int i, c, idCarreira, numCarreiras;

    leAteFinalLinha(_buffer);

    for (i = 0; i < _numParagens; i++) {
        numCarreiras = _paragens[i].numCarreiras;
        if (numCarreiras > 1) {
            printf("%s %d:", _paragens[i].nome, numCarreiras);
            ordenaCarreiras(_paragens[i].idCarreiras, numCarreiras);
            for (c = 0; c < numCarreiras; c++) {
                idCarreira = _paragens[i].idCarreiras[c];
                printf(" %s", _carreiras[idCarreira].nome);
            }
            printf("\n");
        }
    }
}


/* Função MAIN */

int main() {
    Paragem *par = novaParagem();
    Carreira *car = novaCarreira();
    Ligacao *lig = novaLigacao();
    int c;

    do {
        c = getchar();
        switch(c) {
            case 'c':
                carreiras(car);
                break;
            case 'p':
                paragens(par);
                break;
            case 'l':
                ligacoes(lig);
                break;
            case 'i':
                intersecoes();
                break;
	        case 'q':
	            break;
            default:
	            /* Ignorar linhas em branco */
	            if (c == ' ' || c == '\t' || c == '\n') break;
        }
    } while (c != 'q');
    return 0;
}
