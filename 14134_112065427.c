#include <stdio.h>
#include <string.h>

int mask[24] = {
	0x000001, 0x000002, 0x000004, 0x000008,
	0x000010, 0x000020, 0x000040, 0x000080,
	0x000100, 0x000200, 0x000400, 0x000800,
	0x001000, 0x002000, 0x004000, 0x008000,
	0x010000, 0x020000, 0x040000, 0x080000,
	0x100000, 0x200000, 0x400000, 0x800000
};

int main(void) {
	char set[21];
	scanf(" %s", set);

	int length = strlen(set);
	int lim = 1 << length; //Create the possible moves

	for(int i = 0; i < lim; i++){
		for(int j = 0; j < length; j++){
			if((i & mask[j]) != 0){
				printf("%c", set[j]);//If true, refer to the corresponding real value
			}
		}
		if(i > 0) printf("\n");
	}
  return 0;
