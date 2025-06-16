/*
data una serie di dati, fornire gli strumenti statistici:

- indici dispersione (varianza, CV, ...)
- indici di posizione (medie, moda, mediana, quartili, ...)
- indici di correlazione tra le variabili o indipendenza (chi-quadrato, ...)

FLUSSO
1) Si richiede di inserire una serie di dati con possibilita di aggiungerne altre.
2) Una volta ottenuta la serie di dati si propongono gli strumenti e si scelgono quelli desiderati;
   Si possono scegliere anche piu strumenti, nel senso che il programma mostrera' contemporaneamente piu' risultati diversi,
   ad esempio la media aritmetica e la varianza, o la varianza ed il coeff. di correlazione di Pearson. 
3) Salvo i dati ottenuti.
*/

#include <stdio.h>
#include <math.h>


float arit_mean(float array[], size_t size); // media aritmetica
float geom_mean(float array[], size_t size); // media geometrica
float quad_mean(float array[], size_t size); // media quadratica
float harm_mean(float array[], size_t size); // media armonica


int main(void)
{
   puts("Inserisci il numero delle modalita'");
   int mod; 
   scanf("%d", &mod);
   
   puts("Inserisci i dati:");
   float dataArr[mod];
   for(size_t i=0; i<mod; i++)
   { 
      scanf("%f", &dataArr[i]);
   }

   puts("Scegli la funzione: 1-Media aritmetica, 2-Media geometrica, 3-Media Quadratica, 4-Media armonica\n");

   int ch; scanf("%d", &ch);
   switch(ch)
   {
      case 1:
         printf("La media aritmetica e': %f\n",arit_mean(dataArr, mod));
         break;
      case 2:
         printf("La media geometrica e': %f\n",geom_mean(dataArr, mod));
         break;
      default:
         break;
   }
}


float arit_mean(float array[], size_t size)
{
   float mean=0;
   for(size_t i=0; i<size; i++)
   {
      mean += array[i]; 
   }
   return mean/size;
}

float geom_mean(float array[], size_t size)
{
   float arg=1;
   for(size_t i=0; i<size; i++)
   {
      arg *= array[i];
   }
   return pow(arg, 1.0/size);
}