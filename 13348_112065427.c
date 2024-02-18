/*
4 3
000
110
110
110

4 3
000
000
000
000
*/

#include <stdio.h>


int main(void) {
	int h, w;
	scanf("%d %d", &h, &w);

	char arr[h][w];
	for(int i = 0; i < h; i++){
		scanf(" %s", arr[i]);
	}

	// for(int i = 0; i < h; i++){
	// 	for(int j = 0; j < w; j++){
	// 		printf("%c", arr[i][j]);
	// 	}
	// 	printf("\n");
	// }

	long long int ways[h][w];
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i == 0 && j == 0) ways[i][j] = 1;
			else if(j == 0 && arr[i][0] == '0') {
				ways[i][0] = ways[i-1][0];
			}
			else if(i == 0 && arr[0][j] == '0') {
				ways[0][j] = ways[0][j-1];
			}
			else if(arr[i][j] == '0'){
				ways[i][j] = 0;
				if(arr[i-1][j-1] == '0') ways[i][j] += ways[i-1][j-1];
				if(arr[i-1][j] == '0') ways[i][j] += ways[i-1][j];
				if(arr[i][j-1] == '0') ways[i][j] += ways[i][j-1];
			}
			else ways[i][j] = 0;
		}
	}

	// for(int i = 0; i < h; i++){
	// 	for(int j = 0; j < w; j++){
	// 		printf("%lld ", ways[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%lld\n", ways[h-1][w-1]);

  return 0;
}
