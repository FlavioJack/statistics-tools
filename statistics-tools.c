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


float arit_mean(float *array);


int main(void)
{
   size_t len; 
   puts("Inserisci il numero di elementi: ");
   scanf("%zu", &len); // inserisco la dimensione dell'array
   float elements[len]; 
   puts("Inserisci i valori di cui vuoi calcolare la media: ");
   for(size_t i=0; i<len; i++)
   {
      scanf("%f", &elements[i]);
   }

   printf("La media e': %.2f\n", arit_mean(elements));
}


float arit_mean(float *array)
{
   size_t size = sizeof(array)/sizeof(array[0]);
   float mean=0;
   for(size_t i=0; i<size; i++)
   {
      mean += array[i]; 
   }
   return mean;
}

