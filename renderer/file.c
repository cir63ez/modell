#include "file.h"


int nbLettreMotLong = 0;
char* motLePlusLong;
char* motEnCours;

int caractereToNumber(FILE * f) {
    int number = 0;
    char curCaractere = '\0';
     while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        curCaractere = fgetc(f);
        number = number * 10 + atoi(curCaractere);
    }
    return number;
}

Point pointPlaneFile (FILE * f) {
    rewind(f);
    Point P;
    P.x = caractereToNumber(f);
    P.y = caractereToNumber(f);
    P.z = caractereToNumber(f);
    return P;
}


Vector vectorPlaneFile (FILE * f) {
    Vector V;
    V.x = caractereToNumber(f);
    V.y = caractereToNumber(f);
    V.z = caractereToNumber(f);
    return V;
}

int numberCaractere(FILE * f) {
    int nbCaractere = 0;
    char curCaractere = '\0';

    while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        curCaractere = fgetc(f);
        nbCaractere++;
    }
    return nbCaractere;
}

Ellipse fileToEllipse(FILE * f) {

}



int main(){
  motLePlusLong = (char *)malloc(sizeof(char));
  motEnCours = (char *)malloc(sizeof(char));
  char caractere;
  int nbLettre = 0;
  nbLettre = 0;
  FILE * f = NULL;
  f = fopen("textWiki.txt","r");
  if (f == NULL) {
    printf("Impossible de trouver le fichier\n");
    free(motLePlusLong);
    free(motEnCours);
    exit(1);
  }
  else {
    while (caractere != EOF) {
      caractere = fgetc(f);
      nbLettre = nombreLettreF(f,caractere);
      motLong(nbLettre);
    }
  }
  printf("%s\n", motLePlusLong);
  fclose(f);
  free(motLePlusLong);
  free(motEnCours);
  return 0;
}