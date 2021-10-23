#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*       ДЗ на 1-й модуль        */

void Ex_1()
{
   float a, c, x;

   printf("Vvedite parametri v takom poryadke: a c x\n");
   scanf_s("%f%f%f", &a, &c, &x);

   float L = 0;

   L = (sqrt(exp(x) - pow(cos(pow(x, 2) * pow(a, 5)), 4)) + pow(atan(a - pow(x, 5)), 4)) / (exp(1) * sqrt(fabs(a + x * pow(c, 4))));

   printf("Otvet = %f", L);
}

void Ex_2()
{
   float t, v;

   printf("Enter time\n");
   scanf_s("%f", &t);

   v = 3 * t * t - 6 * t;

   printf("Otvet = %f", v);
}

void Ex_3()
{
   float a, b, c;
   float x1, x2;

   printf("Vvedite parametri\n");
   scanf_s("%f%f%f", &a, &b, &c);

   if (a == 0)
   {
      printf("Znachenie parametra <a> ne mozhet bit = 0. Vvedite drygoe znachenie");
      return;
   }

   float d;

   d = b * b - 4 * a * c;

   if (d > 0)
   {
      x1 = (-b + sqrt(d)) / (2 * a);
      x2 = (-b - sqrt(d)) / (2 * a);

      printf("Otvet: x1 = %f, x2 = %f\n", x1, x2);
   }

   if (d == 0)
   {
      x1 = -b / (2 * a);

      printf("Otvet: x = %f", x1);
   }

   if (d < 0)
   {
      printf("Korney net");
   }
}

float Ex_4(int c, float t)
{
   switch (c)
   {
   case 48:
      return 15 * (t / 60);
   case 44:
      return 18 * (t / 60);
   case 46:
      return 16 * (t / 60);
   case 45:
      return 11 * (t / 60);
   default:
      printf("Takogo regiona net y operatora svyazi\n");
      break;
   }

   return 0;
}

void Ex_5()
{
   int sumArmstrong = 0;
   int armstrongNumber = 1000;
   int temp;
   int numberPow3;
   int tempArmstrongNumber;

   while (armstrongNumber < 9999)
   {
      sumArmstrong = 0;
      tempArmstrongNumber = armstrongNumber;

      while (tempArmstrongNumber > 0)
      {
         temp = tempArmstrongNumber % 10;
         numberPow3 = pow(temp, 4);
         sumArmstrong += numberPow3;
         tempArmstrongNumber /= 10;
      }

      if (sumArmstrong == armstrongNumber)
         printf("%d ", armstrongNumber);

      armstrongNumber += 1;
   }
}

void Ex_6()
{
   int n;

   printf("Vvedite dliny chisla\n");
   scanf_s("%d", &n);

   if (n == 0)
   {
      printf("Dlina chisla ne mozhet bit ravna 0");
      return;
   }

   int* masNumber = malloc(n * sizeof(int));

   if (!masNumber)
   {
      printf("Error!");
      return;
   }

   printf("Vvedite chislo v dvoichnoy sisteme schisleniya\n");
   
   for (int i = 0; i < n; i++)
   {
      scanf_s("%d", &masNumber[i]);
      if ((masNumber[i] != 0) || (masNumber[i] != 1))
      {
         printf("Vi ne mozhete vvodit drygie chisla krome 0 & 1");
         return;
      }
   }
   
   int num10 = 0;
   int temp = 0;
   int k = n - 1;

   for (int i = 0; i < n; i++)
   {
      if (masNumber[i] == 1)
         num10 += pow(2, k);
      k -= 1;
   }

   printf("Otvet = %d", num10);
}

void Ex_7()
{
   int i, j;

   printf("Vvedite razmer massiva i na j\n");
   scanf_s("%d%d", &i, &j);

   if ((i == 0) || (j == 0))
   {
      printf("Error!");
      return;
   }

   int* L = malloc(i * j * sizeof(int));

   if (!L)
   {
      printf("Error!");
      return;
   }

   srand(time(NULL));

   for (int n = 0; n < i * j; n++)
   {
      L[n] = rand() % 21 - 10;
      L[n] = L[n] * -3;
   }

   printf("\n");

   for (int n = 0; n < i; n++)
   {
      for (int m = 0; m < j; m++)
      {
         printf("%3d ", L[n * j + m]);
      }
      printf("\n");
   }
}

//////////////////////////////////