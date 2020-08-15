/* ターミナルから1〜10までの2つの整数を入力し、
2つの整数の和と積の計算結果をターミナルに表示させるプログラム */

#include <stdio.h>

#define LENGTH 2 /* 入力する整数の数 */
#define MIN 1 /* 入力可能整数の最小値 */
#define MAX 10 /* 入力可能整数の最大値 */

int main(void)
{
  int n; /* カウンター */
  int num; /* 入力された数 */
  int add = 0; /* 足し算 */
  int multi = 1; /* 掛け算 */

  printf("【%d～%dまでの整数を%d個入力してください。】\n", MIN, MAX, LENGTH);
    for (n = 0; n < LENGTH; n++){
      printf("%d個目の整数を入力してください。>", n + 1);
      scanf("%d", &num);

      if (num < MIN || num > MAX) {
        printf("※ %d～%d以外の数字が入力されています。入力し直して下さい。\n\n", MIN, MAX);
        n--;
      } else {
        add += num;
        multi *= num;
      }
    }

  printf("\n----------計算結果----------\n" );
	printf("和は%dです。\n積は%dです。\n", add, multi);
	return 0;
}