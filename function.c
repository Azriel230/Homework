#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//В заданной строке поменять местами первое и последнее слово строки. Разделителями слов считаются пробелы.

char* Ex_1(char* str_)
{
   char strFail[] = "Fail";

   int n = 0;
   int m = 0;
   for (int i = 0; str_[i] != '\0' && str_[i] != ' '; i++) //найдем длину первого слова
      n++;

   for (int i = strlen(str_) - 1; i >= 0 && str_[i] != ' '; i--) //найдем длину последнего слова
      m++;

   int word1 = n + 1;
   int word2 = m + 1;
   char* strFirst = malloc(word1 * sizeof(char));

   char* strLast = malloc(word2 * sizeof(char));

   if (strFirst && strLast)
   {
      for (int i = 0; i < n; i++)
         strFirst[i] = str_[i];

      int c = 0;
      for (int i = strlen(str_) - m; i < strlen(str_); i++)
      {
         strLast[c] = str_[i];
         c++;
      }

      if (n == m)
      {
         for (int i = 0; i < n; i++)
            str_[i] = strLast[i];

         c = 0;
         for (int i = strlen(str_) - m; i < strlen(str_); i++)
         {
            str_[i] = strFirst[c];
            c++;
         }

      }

      if (n > m)
      {
         for (int i = n + 1; i < (strlen(str_) - m); i++)
            str_[i - (n - m)] = str_[i];

         for (int i = 0; i < m; i++)
            str_[i] = strLast[i];
         str_[m] = ' ';

         c = 0;
         for (int i = strlen(str_) - n; i < strlen(str_); i++)
         {
            str_[i] = strFirst[c];
            c++;
         }
      }

      if (n < m)
      {
         for (int i = strlen(str_) - m - 2; i > n; i--)
            str_[i + (m - n)] = str_[i];

         for (int i = 0; i < m; i++)
            str_[i] = strLast[i];
         str_[m] = ' ';

         str_[strlen(str_) - n - 1] = ' ';

         c = 0;
         for (int i = strlen(str_) - n; i < strlen(str_); i++)
         {
            str_[i] = strFirst[c];
            c++;
         }
      }
      return str_;
   }
   else
      return strFail;
}

//Написать программу согласно заданию с использованием структуры : Поля структуры(Фамилия, Имя, Отчество, Пол, Должность, Дата рождения); 
//Вывести данные об инженерах, пенсионного возраста(мужчинам больше 65 - ти лет, женщинам 60).


struct People {
   char secondName[50];
   char firstName[50];
   char patronymic[50];
   char sex[2];
   char job[50];
   int day;
   int month;
   int year;
   int age;
};


void Ex_2()
{
   int n = 0;
   printf("Number of people\n");
   scanf_s("%d", &n);

   struct People* mas = (struct People *)malloc(n * sizeof(struct People));

   for (int i = 0; i < n; i++)
   {
      printf("Enter secondName\n");
      scanf_s("%s", mas[i].secondName, 50);

      printf("Enter firstName\n");
      scanf_s("%s", mas[i].firstName, 50);

      printf("Enter patronymic\n");
      scanf_s("%s", mas[i].patronymic, 50);

      printf("Enter sex\n");
      scanf_s("%s", mas[i].sex, 2);

      printf("Enter job\n");
      scanf_s("%s", mas[i].job, 50);

      printf("Enter day of birth\n");
      scanf_s("%d", &mas[i].day);

      printf("Enter month of birth\n");
      scanf_s("%d", &mas[i].month);

      printf("Enter year of birth\n");
      scanf_s("%d", &mas[i].year);

      mas[i].age = 2021 - mas[i].year;
   }

   for (int i = 0; i < n; i++)
   {
      if (strcmp(mas[i].job, "Engineer") == 0)
      {
         if (strcmp(mas[i].sex, "M") == 0)
         {
            if (mas[i].age >= 65)
            {
               printf("%s %s %s, %s, %s, %d.%d.%d\n", mas[i].secondName, mas[i].firstName, mas[i].patronymic, mas[i].sex, mas[i].job, mas[i].day, mas[i].month, mas[i].year);
            }
         }
         else
         {
            if (mas[i].age >= 60)
            {
               printf("%s %s %s, %s, %s, %d.%d.%d\n", mas[i].secondName, mas[i].firstName, mas[i].patronymic, mas[i].sex, mas[i].job, mas[i].day, mas[i].month, mas[i].year);
            }
         }
      }
   }
}

//Дан файл f, в котором записан некий текст на русском языке. Вывести в файл g текст из f, при этом убрав каждое четвертое слово и слова, которые начинаются с буквы 'п'.

void Ex_3()
{
   FILE* f = NULL;
   fopen_s(&f, "f.txt", "r");
   if (!f)
   {
      printf("file not open");
      return;
   }

   FILE* g = NULL;
   fopen_s(&g, "g.txt", "w");
   if (!g)
   {
      printf("file not open");
      return;
   }

   int n = 0;
   int w = 0;
   char tmp[128] = "";
   fgets(&tmp, 127, f);
   for (int i = 0; i < strlen(tmp); i++)
   {
      if (tmp[i] != ' ')
      {
         while (tmp[i] != ' ')
         {
            fprintf(g, "%s", &tmp[i]);
            n++;
         }
         i += n;
         n = 0;
      }
   }
}