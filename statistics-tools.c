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
float sum(float array[], size_t size); // sommatoria

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

   printf("Media aritmetica: %.2f\nMedia geometrica: %.2f\n", arit_mean(dataArr, mod), geom_mean(dataArr, mod));
   printf("Media quadratica: %.2f\nMedia armonica: %.2f\n", quad_mean(dataArr, mod), harm_mean(dataArr, mod));
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
   float mean=1;
   for(size_t i=0; i<size; i++)
   {
      mean *= array[i];
   }
   return pow(mean, 1.0/size);
}

float quad_mean(float array[], size_t size)
{
   float square_arr[size];
   for(size_t i=0; i<size; i++)
   {
      square_arr[i] = array[i]*array[i];
   }
   return sqrt( sum(square_arr, size)/size );
}

float harm_mean(float array[], size_t size)
{
   float reverse_array[size];
   for(size_t i=0; i<size; i++)
   {
      reverse_array[i] = 1/array[i];
   }
   return size / sum(reverse_array, size);
}

float sum(float array[], size_t size)
{
   float result=0;
   for(size_t i=0; i<size; i++)
   {
      result += array[i];
   }
   return result;
}