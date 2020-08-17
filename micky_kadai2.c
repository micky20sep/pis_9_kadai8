#include<stdio.h>

#define LENGTH 2 /* 入力する整数の数 */
#define MIN_NUM 1 /* 入力可能整数の最小値 */
#define MAX_NUM 10 /* 入力可能整数の最大値 */
#define MAX_BUF 1024 /* おそらくUNIX系 stdinの最大文字数 */

int cal_result(int *a){
	printf("\n----------計算結果----------\n" );
	int s = 0;
	int p = 1;
	for(int i=0; i<LENGTH; i++){
		s += a[i];
		p *= a[i];
	}
	printf("和は%dです。\n", s);
	printf("積は%dです。\n", p);

	return 0;
}

int main(void){
	int x, y, a[LENGTH];
	int err = 0;
	int z;
	char buf[MAX_BUF];
	printf("【%d～%dまでの整数を%dつ入力してください。】\n", MIN_NUM, MAX_NUM, LENGTH);

	for (int i = 0; i < LENGTH; i++) {
		printf("%dコ目の整数を入力してください。＞", i+1);
		/* なんとなくi - 1したくないのでdo while */
		do{
			z = scanf("%d", &a[i]);
			/* err 0=false or 1=0以外=true のif else */
			if(MIN_NUM<=a[i] && a[i]<=MAX_NUM){
				err = 0;
				/* 以下、Kahorinさん発見?のerr3パターン+α対策 */
				/* 数字を1つずつ入力させるために読み捨てる */
				fgets(buf, MAX_BUF, stdin);
		  }	else {
				if(z==0){
					printf("※ 数字以外を入力しないでください。＞" );
					scanf("%*s");
					err = 1;
				} else if(a[i]<MIN_NUM || MAX_NUM<a[i]){
					printf("※ %d～%d以外の数字が入力されています。再入力してください。＞", MIN_NUM, MAX_NUM);
					err = 1;
				} else {
					/* その他のデバッグが面倒なので、とりあえずelseに放り込む? */
					printf("※ 真面目にやってください。＞" );
					err = 1;
				}
			}
		} while(err);
	}

	cal_result(a);
	return 0;
}
