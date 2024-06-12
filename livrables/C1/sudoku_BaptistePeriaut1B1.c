#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Déclaration constente
#define TAILLE 9
const int N = 3; 
const int MIN = 1;

//Nouveaux types
typedef int tGrille[TAILLE][TAILLE];

//Déclaration fonction et procédure
void chargerGrille(tGrille g);
void afficherGrille(tGrille g);
void saisir(int *valeur);
bool possible(tGrille g, int numlig, int numcol, int valeursaisie);
bool verifeGrille(tGrille g);

//Programme principale
int main(){
    //Déclaration de variable
    tGrille grille1;
    int numLigne, numColonne, valeur;

    chargerGrille(grille1);
    while (verifeGrille(grille1)==false){
        afficherGrille(grille1);
        printf("Veulliez saisir une ligne ? ");
        saisir(&numLigne);
        printf("Veulliez saisir une colonne ? ");
        saisir(&numColonne);
        numLigne=numLigne-1;
        numColonne=numColonne-1;
        if(grille1[numLigne][numColonne]!=0){
            printf("IMPOSSIBLE, la case n'est pas libre.\n");
        }
        else{
            printf("Valeur à insérer ? ");
            saisir(&valeur);
            if(possible(grille1, numLigne, numColonne, valeur)){
                grille1[numLigne][numColonne] = valeur;    
            }
        }
    }
    printf("Grille pleine, fin de partie\n");
    return EXIT_SUCCESS ;
}


//Définition des procédure et fonction
void chargerGrille(tGrille g){
    char nomFichier[30];
    FILE * f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f==NULL){
    printf("\n ERREUR sur le fichier %s\n", nomFichier);
    } else {
    fread(g, sizeof(int), TAILLE*TAILLE, f);
    }
    fclose(f);
}

void afficherGrille(tGrille g){
    int indicelig, indicecol;
    printf("   ");
    for(indicelig=1; indicelig<=TAILLE; indicelig++ ){
        if ((indicelig>1) && (indicelig%N==1)){
            printf("%4d", indicelig);
        }
        else{
            printf("%3d", indicelig);
        }
        
    }
    printf("\n");
    printf("   +---------+---------+---------+");
    printf("\n");
    for(indicelig=0; indicelig<TAILLE; indicelig++ ){
        if((indicelig>1) && (indicelig%N==0)){
            printf("   +---------+---------+---------+");
            printf("\n");
        }
        printf("%d  ", indicelig+1);
        for(indicecol=0; indicecol<TAILLE; indicecol++){
            if (indicecol%N == 0){
                printf("|");
            }
            if (g[indicelig][indicecol] == 0){
                printf(" . ");
            } else {
                printf(" %d ", g[indicelig][indicecol]);
            }   
        }

        printf("|\n");
    }
    printf("   +---------+---------+---------+");
    printf("\n");
}

void saisir(int *valeur){
    char ch[10];
    int x;
    scanf("%s", ch);
    while((sscanf(ch, "%d", &x) == 0)||(x<MIN)||(x>N*N)){
        printf("Mauvaise saisie veulliez refaire entre 1 et 9 :");
        scanf("%s", ch);
    }
    *valeur=x;
}

bool possible(tGrille g, int numlig, int numcol, int valeursaisie){
    //Déclaration variable
    int indicelig, indicecol;
    int ligTempo, colTempo;
    bool possible;
    //Initialisation variable
    possible=true;
    indicelig=0;
    indicecol=0;
    ligTempo=numlig;
    colTempo=numcol;
    //Test dans les ligne et les colonne
    do
    {
        //test ligne
        if(valeursaisie==g[numlig][indicecol]){
            printf("Il y a déjâ cette valeur sur la ligne\n");
            possible = false;
        }
        //test colonne
        else if (valeursaisie==g[indicelig][numcol]){
            printf("Il y a déjâ cette valeur sur la colonne\n");
            possible= false;
        }

        indicelig=indicelig+1;
        indicecol=indicecol+1;
    } 
    while ((valeursaisie!=g[indicelig][indicecol])&&(indicelig<TAILLE)&&(indicecol<TAILLE));
    //Test dans une blocks
    if(possible!=false){
        while (ligTempo%N!=0){
            ligTempo=ligTempo-1;
        }
        while (colTempo%N!=0){
            colTempo=colTempo-1;
        }
        do{
            do{
                if(valeursaisie==g[ligTempo][colTempo]){
                    printf("Il y a déjâ cette valeur dans le bloc\n");
                    possible= false;
                }
                colTempo=colTempo+1;
            }while (colTempo%N!=0);
            colTempo=colTempo-N;
            ligTempo=ligTempo+1;
        }while (ligTempo%N!=0);
    }
    return possible;   
}

bool verifeGrille(tGrille g){
    int indicelig, indicecol;
    bool valide;
    valide=true;
    for (indicelig=0;indicelig<TAILLE;indicelig++){
        for(indicecol=0;indicecol<TAILLE;indicecol++){
            if(g[indicelig][indicecol]==0){
                valide=false;
            }
        }
    }
    return valide;
}
