#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
   srand((unsigned)time(NULL));
   int count = 1, s = 0, b = 0, num[4] = {}, n[4] = {};
   char *nickname, a;
    num[0] = rand() % 10;
   num[1] = rand() % 10;
   if (num[1] == num[0])
   {
      while (1)
         {
            num[1] = rand() % 10;
            if (num[1] != num[0])
               break;
         }
   }
   num[2] = rand() % 10; 
   if (num[2] == num[0] || num[2] == num[1])
   {
      while (1)
         {
            num[2] = rand() % 10;
            if (num[2] != num[0] && num[2] != num[1])
               break;
         }
   }
   num[3] = rand() % 10;
   if (num[3] == num[0] || num[3] == num[1] || num[3] == num[2])
   {
      while (1)
         {
            num[3] = rand() % 10;
            if (num[3] != num[0] && num[3] != num[1] && num[3] != num[2])
               break;
         }
   }

   printf ("숫자 야구 게임에 오신 것을 환영합니다!\n무작위로 정해지는 4자리 숫자를 맞춰보세요!\n게임을 시작하려면 Enter를 눌러주세요.\n");
   scanf ("%c", &a);
   printf ("이름을 입력해 주세요. : ");
   scanf ("%s", nickname);

   while(1)
      {
         printf ("첫 번째 자리를 입력해주세요. : ");
         scanf ("%d", &n[0]);
         printf ("두 번째 자리를 입력해주세요. : ");
         scanf ("%d", &n[1]);
         printf ("세 번째 자리를 입력해주세요. : ");
         scanf ("%d", &n[2]);
         printf ("네 번째 자리를 입력해주세요. : ");
         scanf ("%d", &n[3]);
         for (int i = 0; i < 4; i++)
            {
               for (int j = 0; j < 4; j++)
                  {
                     if (num[i] == n[j])
                     {
                        if (i == j)
                           s += 1;
                        else
                           b += 1;
                     }
                  }
            }
         if (s == 4)
         {
            printf ("정답입니다! %d%d%d%d입니다! %s님은 %d번 도전하셨습니다!", n[0], n[1], n[2], n[3], nickname, count);
            break;
         }
         else
         {
            printf ("스트라이크 : %d\n 볼 : %d\n", s, b);
            s = 0;
            b = 0;
            count += 1;
         }
      }
   return 0;
}