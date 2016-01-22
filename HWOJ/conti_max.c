#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int Continumax(char** pOutputstr,  char* inputstr)
{
	int len = strlen(inputstr);
	//pOutputstr = (char **)malloc(sizeof(char*));
	int counter = 0;
	int max = 0;
	int pre_max = 0;
	char *max_start = NULL;
    char *tmp;
	while (counter <= len) {
		if (inputstr[counter] >= '0' && inputstr[counter] <= '9') {
			if (max == 0) max_start = inputstr + counter;
			max++;
		}
		else {
			if (max >= pre_max) {
				pre_max = max;
                tmp = (char*)malloc((max+1)*sizeof(char));
				for (int i=0; i < max; ++i) {
					tmp[i] = *max_start;
                    max_start++;
				}
				tmp[max] = '\0';
			}
            max_start = NULL;
			max = 0;
		}
		counter++;
	}
	*pOutputstr = (char*)malloc((max+1)*sizeof(char));
    strcpy(*pOutputstr, tmp);
    free(tmp);
	return pre_max;
}

int main() {
    char tmp[] = "abcd12345ed125ss123058789";
    char tmp2[] = "";
    char tmp3[] = "1234567891010101";
    char tmp4[] = "adbasdfqwepyuga;slkdf";
    char tmp5[] = "ad1234;s5678";
    char *out;
    char *out2;
    char *out3;
    char *out4;
    char *out5;

    unsigned int max = Continumax(&out, tmp);
    unsigned int max2 = Continumax(&out2, tmp2);
    unsigned int max3 = Continumax(&out3, tmp3);
    unsigned int max4 = Continumax(&out4, tmp4);
    unsigned int max5 = Continumax(&out5, tmp5);
    printf("%s::%u\n", out, max);
    printf("%s::%u\n", out2, max2);
    printf("%s::%u\n", out3, max3);
    printf("%s::%u\n", out4, max4);
    printf("%s::%u\n", out5, max5);
}
