#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int key;
} Registry;

typedef struct Nodo {
    Registry reg;
    struct Nodo *pLeft;
    struct Nodo *pRight;
}Nodo;

//Funções de "Inserção"
int insert (Nodo **ppSource, Registry reg);
void listTree (Nodo *pSource);
void cleanTree (Nodo *pSource);

//balancing
int balancing(Nodo **ppSource);
int balancingLeft (Nodo **ppSource);
int balancingRight (Nodo **ppSource);
void RSE (Nodo **ppSource);
void RSD (Nodo **ppSource);
int FB (Nodo *pSource);
int height (Nodo *pSource);
int verificationAVL (Nodo *pSource);

int main () {
    int i, nNodos, random;
    Nodo *pSource = NULL;
    Registry reg;

    printf("Digite o numero de nodos: ");
    scanf("%d", &nNodos);
    getchar();
    
    srand(time(0));

    for (i=0; i < nNodos; i++){
        random = rand() % 100;
        reg.key = random;
        insert(&pSource, reg);
    }

    printf("\n");
    listTree(pSource);
    printf("\n");

    if(verificationAVL(pSource)) {
        printf("\nA arvore eh AVL!\n");
    } else {
        printf("\nA arvore nao eh AVL!\n");
    }

    cleanTree(pSource);

    return 0;
}

void cleanTree (Nodo *pSource) {
    if (pSource == NULL) {
        return;
    }

    cleanTree(pSource -> pLeft);
    cleanTree(pSource -> pRight);

    free(pSource);
}

void listTree (Nodo *pSource) {
    if (pSource != NULL) {
        printf("%d(", pSource -> reg.key);
        listTree(pSource -> pLeft);
        listTree(pSource -> pRight);
        printf(")");
    }
}

int insert (Nodo **ppSource, Registry nReg) {
    if (*ppSource == NULL) {
        *ppSource = (Nodo*)malloc(sizeof(Nodo));
        (*ppSource) -> reg = nReg;
        (*ppSource) -> pLeft = NULL;
        (*ppSource) -> pRight = NULL;

        return 1;
    } else if ( nReg.key < (*ppSource) -> reg.key ) {
        if (insert( &(*ppSource) -> pLeft, nReg )){
            if (balancing(ppSource)) {
                return 0;
            } else {
                return 1;
            }
        }
    } else if (nReg.key > (*ppSource) -> reg.key) {
        if (insert (&(*ppSource) -> pRight, nReg)) {
            if (balancing(ppSource)) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        return 0;
    }
    return 0;
}

//-----------------------FUNÇÕES DE balancing-----------------------//

int FB(Nodo *pSource) {
    if (pSource == NULL) {
        return 0;
    }

    return height(pSource -> pLeft) - height(pSource -> pRight);
}

int height(Nodo *pSource) {
    int iLeft, iRight;

    if (pSource == NULL) {
        return 0;
    }

    iLeft = height(pSource -> pLeft);
    iRight = height(pSource -> pRight);

    if (iLeft > iRight){
        return iLeft + 1;
    } else {
        return iRight + 1;
    }
}

int balancing(Nodo **ppSource) {
    int fb = FB(*ppSource);

    if (fb > 1) {
        return balancingLeft(ppSource);
    }
    else if (fb < -1){
        return balancingRight(ppSource);
    } else {
        return 0;
    }
}

int balancingLeft(Nodo **ppSource) {
    int FBL = FB( (*ppSource) -> pLeft );

    if (FBL >= 0) {
        RSD(ppSource);
        return 1;
    } else if (FBL < 0) { // Rotação dupla para a Direita
        RSE ( &((*ppSource) -> pLeft) );
        RSD (ppSource);
        return 1;
    }
    return 0;
}


int balancingRight (Nodo **ppSource) {
    int FBR = FB( (*ppSource) -> pRight );
    
    if (FBR <= 0) {
        RSE (ppSource);
        return 1;
    } else if (FBR > 0) { // ROTAÇÃO DUPLA PARA ESQUERDA
        RSD ( &((*ppSource) -> pRight) );
        RSE (ppSource);
        return 1;
    }
    return 0;
}

void RSE (Nodo** ppSource) { // ROTAÇÃO SIMPLES PARA DIREITA
    Nodo *pAux;

    pAux = (*ppSource) -> pRight;
    (*ppSource)->pRight = pAux -> pLeft;
    pAux -> pLeft = (*ppSource);
    (*ppSource) = pAux;
}

void RSD (Nodo **ppSource) { //ROTAÇÃO SIMPLES ESQUERDA
    Nodo *pAux;

    pAux = (*ppSource) -> pLeft;
    (*ppSource) -> pLeft = pAux -> pRight;
    pAux -> pRight = (*ppSource);
    (*ppSource) = pAux;
}

int verificationAVL (Nodo *pSource) { //VERIFICAÇÃO SE É AVL
    int fb;
    fb = FB (pSource);

    if (pSource == NULL) {
        return 1;
    }

    if (!verificationAVL(pSource -> pLeft)) {
        return 0;
    }

    if (!verificationAVL(pSource -> pRight)) {
        return 0;
    }

    if ((fb > 1) || (fb < -1)) {
        return 0;
    } else {
        return 1;
    }
}