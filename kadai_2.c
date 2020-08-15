/* ターミナルから1〜10までの2つの整数を入力し、
2つの整数の和と積の計算結果をターミナルに表示させるプログラム */

#include<stdio.h>

#define LENGTH 2 /* 入力する整数の数 */
#define MIN 1 /* 入力可能整数の最小値 */
#define MAX 10 /* 入力可能整数の最大値 */

/* 関数の宣言 */
void inp_num(int *num_p); // ターミナルから入力を受け付ける
void cal_result(int *num_p);  // 計算と結果を出力する関数

int main(void)
{
  int num_arr[LENGTH] = {}; // 入力された整数を格納する配列

	inp_num(num_arr);
	cal_result(num_arr);

	return 0;
}

// ターミナルから入力を受け付けて配列を作る
void inp_num(int *num_p) {
	int tmpNum; // 入力値を一時格納する変数
  int n; /* カウンター */

	printf("【%d～%dまでの整数を%d個入力してください。】\n", MIN, MAX, LENGTH);
	for(n = 0; n < LENGTH; n++){
		printf("%d個目の整数を入力してください。>", n + 1);
		scanf("%d", &tmpNum);

    if (tmpNum < MIN || tmpNum > MAX) {
      printf("※ %d～%d以外の数字が入力されています。入力し直して下さい。\n\n", MIN, MAX);
      n--;
    } else {
      num_p[n] = tmpNum;
    }
  }
}

// 計算して結果を出力
void cal_result(int *num_p) {
  int add = 0; /* 足し算 */
  int multi = 1; /* 掛け算 */
  int n; /* カウンター */

  for(n = 0; n < LENGTH; n++) {
    add += num_p[n];
    multi *= num_p[n];
  }

  printf("\n----------計算結果----------\n" );
	printf("和は%dです。\n", add);
	printf("積は%dです。\n", multi);
}