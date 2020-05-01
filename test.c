#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>
#include "libft.h"
#include "libft_bonus.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char *test_str_int[35] = {
							"2147483647",
							"	 2147483647",
							"2147483647	",
							" 2147483647	",
							"+2147483647",
							" 	+2147483647",
							"+2147483647  ",
							" 	+2147483647 	",
							"+ 2147483647",
							"+ -2147483647",
							"+-2147483647	",
							" +q2147483647	",
							"214w7483647",
							" 	+2147483648",
							"+21474836472  ",
							" 	0+2147483647 	",
							" 002147483647 	",
							" +0002147483647",
							"002147483647",
							"abcd",
							"",
							" ",
							"0",
							"-2147483648",
							"-41474836484",
							" - 2147483648",
							"	-002147483648",
							"-214748364835",
							"-2147483648wr",
							"-d83648",
							"-0",
							"-214",
							"-142",
							"18446744073709551610",
							"-5555555555555555555555"
};
int test_str_int_size = 35;

char *test_str_char[8] = {
						"test",
						"test",
						"test ",
						"TEST",
						" !123 teSt %;",
						"TEst \0tEst",
						"",
						NULL
};




void ft_tolower_toupper_test(void) {
	char test1[11] = "AbcD f12&@\0";
	char test2[11] = "AbcD f12&@\0";
	int marker = 1;

	for (int i = 0; i < 10; i++) {
		test1[i] = tolower(test1[i]);
		test2[i] = ft_tolower(test2[i]);
	}
	if (strcmp(test1, test2)) {
		marker = 0;
		printf("\tFAIL: ft_tolower \tFAILed tests. Expected %s, received %s\n", test1, test2);
	}
	for (int i = 0; i < 10; i++) {
		test1[i] = toupper(test1[i]);
		test2[i] = ft_toupper(test2[i]);
	}
	if (strcmp(test1, test2)) {
		marker = 0;
		printf("\tFAIL: ft_tolower \tFAILed tests. Expected %s, received %s\n", test1, test2);
	}

	if (marker == 1)
		printf("ft_tolower passed tests\nft_toupper passed tests\n");
}

void ft_isalpha_digit_alnum_ascii_print_test(void) {
	int alph1 = 65;		// A
	int alph2 = 122;	// z
	int dig = 48;		// 0
	int print = 38;		// &
	int not_print = 10;	// \n
	int not_ascii = 130;
	int marker = 1;

	if (!ft_isalpha(alph1) || !ft_isalpha(alph2) || ft_isalpha(dig)) {
		marker = 0;
		printf("\tFAIL: ft_isalpha \tFAILed tests\n");
	}
	if (ft_isdigit(alph1) || !ft_isdigit(dig)) {
		marker = 0;
		printf("\tFAIL: ft_digit \tFAILed tests\n");
	}
	if (!ft_isalnum(alph1) || !ft_isalnum(dig) || ft_isalnum(print) || ft_isalnum(not_print)) {
		marker = 0;
		printf("\tFAIL: ft_isalnum \tFAILed tests\n");
	}
	if (!ft_isascii(alph1) || ft_isascii(not_ascii)) {
		marker = 0;
		printf("\tFAIL: ft_isascii \tFAILed tests\n");
	}
	if (!ft_isprint(alph1) || !ft_isprint(dig) || !ft_isprint(print) || ft_isprint(not_print)) {
		marker = 0;
		printf("\tFAIL: ft_isprint \tFAILed tests\n");
	}

	if (marker == 1)
		printf("ft_isalpha passed tests\nft_isdigit passed tests\nft_isalnum passed tests\nft_isprint passed tests\nft_isascii passed tests\n");
}

void ft_atoi_test(char **arr, int arr_size) {
	int marker = 1;
	for (int i = 0; i < arr_size; i++) {
		if (ft_atoi(arr[i]) != atoi(arr[i])) {
			marker = 0;
			printf("\tFAIL ft_atoi: In row '%s' received %i, expected %i\n", arr[i], ft_atoi(arr[i]), atoi(arr[i]));
		}
	}
	if (marker == 1)
		printf("ft_atoi passed all tests\n");
}

void ft_strncmp_test(void) {
	int n = 4;
	int marker = 1;
	for (int i = 0; i < 6; i++) {
		int i1 = strncmp(test_str_char[i], test_str_char[i + 1], n);
		int i2 = ft_strncmp(test_str_char[i], test_str_char[i + 1], n);
		if ((!i1 && i2) || (i1 && !i2)) {
			marker = 0;
			printf("\tFAIL ft_strncmp: For strings '%s' & '%s' expected %i, received %i\n", test_str_char[i], test_str_char[i + 1], i1, i2);
		}
	}

	if (marker == 1)
		printf("ft_strncmp passed all tests\n");
}

void ft_strcmp_test(void) {
	int marker = 1;
	for (int i = 0; i < 6; i++) {
		int i1 = strcmp(test_str_char[i], test_str_char[i + 1]);
		int i2 = ft_strcmp(test_str_char[i], test_str_char[i + 1]);
		if ((!i1 && i2) || (i1 && !i2)) {
			marker = 0;
			printf("\tFAIL ft_strcmp: For strings '%s' & '%s' expected %i, received %i\n", test_str_char[i], test_str_char[i + 1], i1, i2);
		}
	}

	if (marker == 1)
		printf("ft_strcmp passed all tests\n");
}

void ft_strnstr_test(void) {
	int marker = 1;
	const char *str1 = "test string";
	const char *str2 = "string";
	const char *str3 = "";

	char *ptr1 = strstr("test string", str2);
	char *ptr2 = ft_strnstr(str1, str2, 15);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strnstr: For str1 = 'test string', str2 = '%s', n = 15 expected pointer to '%s', received '%s'\n", str2, ptr1, ptr2);
	}
	ptr1 = strstr(str1, str1);
	ptr2 = ft_strnstr(str1, str1, 11);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strnstr: For str1 = '%s', str2 = '%s', n = 11 expected pointer to '%s', received '%s'\n", str1, str2, ptr1, ptr2);
	}
	ptr1 = strstr("test strin", str2);
	ptr2 = ft_strnstr(str1, str2, 10);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strnstr: For str1 = 'test strin', str2 = '%s', n = 10 expected pointer to '%s', received '%s'\n", str2, ptr1, ptr2);
	}
	ptr1 = strstr(str1, str3);
	ptr2 = ft_strnstr(str1, str3, 5);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strnstr: For str1 = '%s', str2 = '%s', n = 5 expected pointer to '%s', received '%s'\n", str1, str2, ptr1, ptr2);
	}
		ptr1 = strstr(str3, str3);
	ptr2 = ft_strnstr(str3, str3, 5);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strnstr: For str1 = '%s', str2 = '%s', n = 5 expected pointer to '%s', received '%s'\n", str1, str2, ptr1, ptr2);
	}
	ptr1 = strstr("", str2);
	ptr2 = ft_strnstr(str1, str2, 5);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strnstr: For str1 = '', str2 = '%s', n = 5 expected pointer to '%s', received '%s'\n", str2, ptr1, ptr2);
	}
	if (marker == 1)
		printf("ft_strnstr passed all tests\n");
}

void ft_strstr_test(void) {
	int marker = 1;
	const char *str1 = "test string test string";
	const char *str2 = "string";
	const char *str3 = "\tFAIL";
	const char *str4 = "";
	const char *str5 = "aaabbbaaabbb";
	const char *str6 = "abbaaab";

	char *ptr1 = strstr(str1, str2);
	char *ptr2 = ft_strstr(str1, str2);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strstr: Expected pointer to '%s', received '%s'\n", ptr1, ptr2);
	}
	ptr2 = ft_strstr(str1, str3);
	if (ptr2 != NULL) {
		marker = 0;
		printf("\tFAIL ft_strstr: Expected pointer to NULL\n");
	}
	ptr1 = strstr(str1, str4);
	ptr2 = ft_strstr(str1, str4);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strstr: Expected pointer to '%s', received '%s'\n", ptr1, ptr2);
	}
	ptr1 = strstr(str5, str6);
	ptr2 = ft_strstr(str5, str6);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strstr: Expected pointer to '%s', received '%s'\n", str5, str6);
	}
	if (marker == 1)
		printf("ft_strstr passed all tests\n");
}

void ft_strrchr_test(void) {

	int marker = 1;
	int c1 = 114;
	int c2 = 111;
	int c3 = 0;
	const char *str = "test string r";

	char *ptr1 = strrchr(str, c1);
	char *ptr2 = ft_strrchr(str, c1);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strrchr: Expected pointer to '%c', received '%c'\n", ptr1[0], ptr2[0]);
	}
	ptr2 = ft_strrchr(str, c2);
	if (ptr2 != NULL) {
		marker = 0;
		printf("\tFAIL ft_strrchr: Expected pointer to NULL\n");
	}
	ptr1 = strrchr(str, c3);
	ptr2 = ft_strrchr(str, c3);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strrchr: Expected pointer to '%c', received '%c'\n", ptr1[0], ptr2[0]);
	}

	if (marker == 1)
		printf("ft_strrchr passed all tests\n");
}

void ft_strchr_test(void) {

	int marker = 1;
	int c1 = 114;
	int c2 = 111;
	int c3 = 0;
	const char *str = "test string r";
	const char *str2 = "test string r";

	char *ptr1 = strchr(str, c1);
	char *ptr2 = ft_strchr(str, c1);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strchr: Expected pointer to '%c', received '%c'\n", ptr1[0], ptr2[0]);
	}
	ptr2 = ft_strchr(str, c2);
	if (ptr2 != NULL) {
		marker = 0;
		printf("\tFAIL ft_strchr: Expected pointer to NULL\n");
	}
	ptr1 = strchr(str, c3);
	ptr2 = ft_strchr(str2, c3);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strchr: Expected pointer to '%c', received '%c'\n", ptr1[0], ptr2[0]);
	}

	if (marker == 1)
		printf("ft_strchr passed all tests\n");
}

void ft_strlcat_test(void) {
	int marker = 1;
	char s1[25] = "first string ";
	char s2[14] = "second string";
	char s3[] = "";
	ft_strlcat(s1, s2, 20);
	if (strcmp(s1, "first string second")) {
		marker = 0;
		printf("\tFAIL ft_strlcat: For str1 = 'first string ', str2 = 'second string', n = 20	expected: 'first string second', received: '%s'\n", s1);
	}
	ft_strlcat(s1, s3, 20);
	if (strcmp(s1, "first string second")) {
		marker = 0;
		printf("\tFAIL ft_strlcat: For str1 = 'first string ', str2 = '', n = 20	expected: 'first string ', received: '%s'\n", s1);
	}
	ft_strlcat(s1, s2, 0);
	if (strcmp(s1, "first string second")) {
		marker = 0;
		printf("\tFAIL ft_strlcat: For str1 = 'first string ', str2 = 'second string', n = 0	expected: 'first string ', received: '%s'\n", s1);
	}
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	size_t r = ft_strlcat(buff, str, max);
	if (r != 42)
		printf("\tFAIL ft_strlcat: Expected len = 42, received len = %li\n", r);

	if (marker == 1)
		printf("ft_strlcat passed all tests\n");
}

void ft_strncat_test(void) {
	int marker = 1;
	int n = 6;
	char s1[40] = "first string ";
	char s2[14] = "second string";
	ft_strncat(s1, s2, n);
	if (strcmp(s1, "first string second")) {
		marker = 0;
		printf("\tFAIL ft_strncat: Expected 'first string second', received '%s'\n", s1);
	}

	if (marker == 1)
		printf("ft_strncat passed all tests\n");
}

void ft_strcat_test(void) {
	int marker = 1;
	char s1[40] = "first string ";
	char s2[14] = "second string";
	ft_strcat(s1, s2);
	if (strcmp(s1, "first string second string")) {
		marker = 0;
		printf("\tFAIL ft_strcat: Expected 'first string second string', received '%s'\n", s1);
	}

	if (marker == 1)
		printf("ft_strcat passed all tests\n");
}

void ft_strncpy_test(void) {
	int marker = 1;
	char s1_1[5] = {0};
	char s1_2[5] = {0};
	char s2_1[10] = {0};
	char s2_2[10] = {0};
	char s3_1[20] = {0};
	char s3_2[20] = {0};
	char *str = "proverka strncpy";

	strncpy(s1_1, str, 8);						// dst < n, dst < src, n < src
	ft_strncpy(s1_2, str, 8);
	if (memcmp(s1_1, s1_2, 5)) {
		marker = 0;
		printf("\tFAIL ft_strncpy: For dst size = 5, n = 8 expected '%s', received '%s'\n", s1_1, s1_2);
	}
	memset(s1_1, 0, 5);
	memset(s1_2, 0, 5);

	strncpy(s1_1, str, 20);						// dst < n, dst < src, n > src
	ft_strncpy(s1_2, str, 20);
	if (memcmp(s1_1, s1_2, 5)) {
		marker = 0;
		printf("\tFAIL ft_strncpy: For dst size = 5, n = 20 expected '%s', received '%s'\n", s1_1, s1_2);
	}
	memset(s1_1, 0, 5);
	memset(s1_2, 0, 5);

	strncpy(s3_1, str, 25);						// dst < n, dst > src, n > src
	ft_strncpy(s3_2, str, 25);
	if (memcmp(s3_1, s3_2, 25)) {
		marker = 0;
		printf("\tFAIL ft_strncpy: For dst size = 20, n = 25 expected '%s', received '%s'\n", s3_1, s3_2);
	}
	memset(s3_1, 0, 20);
	memset(s3_2, 0, 20);

	strncpy(s2_1, str, 8);						// dst > n, dst < src, n < src
	ft_strncpy(s2_2, str, 8);
	if (memcmp(s2_1, s2_2, 8)) {
		marker = 0;
		printf("\tFAIL ft_strncpy: For dst size = 10, n = 8 expected '%s', received '%s'\n", s2_1, s2_2);
	}
	memset(s2_1, 0, 10);
	memset(s2_2, 0, 10);

	strncpy(s3_1, str, 8);						// dst > n, dst > src, n < src
	ft_strncpy(s3_2, str, 8);
	if (memcmp(s3_1, s3_2, 8)) {
		marker = 0;
		printf("\tFAIL ft_strncpy: For dst size = 20, n = 8 expected '%s', received '%s'\n", s3_1, s3_2);
	}
	memset(s3_1, 0, 20);
	memset(s3_2, 0, 20);

	strncpy(s3_1, str, 18);						// dst > n, dst > src, n > src
	ft_strncpy(s3_2, str, 18);
	if (memcmp(s3_1, s3_2, 18)) {
		marker = 0;
		printf("\tFAIL ft_strncpy: For dst size = 20, n = 18 expected '%s', received '%s'\n", s3_1, s3_2);
	}
	memset(s3_1, 0, 20);
	memset(s3_2, 0, 20);

	if (marker == 1)
		printf("ft_strncpy passed all tests\n");
}

void ft_strcpy_test(void) {
	int marker = 1;
	const char *str = "test string";
	char *s = (char *)calloc(strlen(str) + 1, 1);
	ft_strcpy(s, str);
	if (strcmp(s, str)) {
		marker = 0;
			printf("\tFAIL ft_strcpy: Expected '%s', received '%s'\n", str, s);
	}
	if (marker == 1)
		printf("ft_strcpy passed all tests\n");
	free(s);
}

void ft_strdup_test(void) {
	int marker = 1;
	const char *str = "test string";
	char *s = ft_strdup(str);
	if (strcmp(s, str)) {
		marker = 0;
			printf("\tFAIL ft_strdup: Expected '%s', received '%s'\n", str, s);
	}
	if (marker == 1)
		printf("ft_strdup passed all tests\n");
	free(s);
}
void ft_strlen_test(void) {
	int marker = 1;
	for (int i = 0; test_str_char[i]; i++) {
		int i1 = ft_strlen(test_str_char[i]);
		int i2 = strlen(test_str_char[i]);
		if (i1 != i2) {
			marker = 0;
			printf("\tFAIL ft_strlen: Expected '%i', received '%i'\n", i1, i2);
		}
	}
	if (marker == 1)
		printf("ft_strlen passed all tests\n");
}

void ft_memcmp_test(void) {
	int marker = 1;
	const char *str1 = "test string";
	const char *str2 = "test String";

	int i1 = memcmp(str1, str2, 10);
	int i2 = ft_memcmp(str1, str2, 10);
	if (i1 != i2) {
		marker = 0;
		printf("\tFAIL ft_memcmp: Expected '%i', received '%i'\n", i1, i2);
	}
	i1 = memcmp(str1, str2, 5);
	i2 = ft_memcmp(str1, str2, 5);
	if (i1 != i2) {
		marker = 0;
		printf("\tFAIL ft_memcmp: Expected '%i', received '%i'\n", i1, i2);
	}

	if (marker == 1)
		printf("ft_memcmp passed all tests\n");
}

void ft_memchr_test(void) {
	int marker = 1;
	int c = 103;
	const char *str = "test string";

	char *ptr1 = memchr(str, c, 11);
	char *ptr2 = ft_memchr(str, c, 11);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_memchr: Expected pointer to '%c', received '%c'\n", ptr1[0], ptr2[0]);
	}
	ptr1 = memchr(str, c, 5);
	ptr2 = ft_memchr(str, c, 5);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_memchr: Expected pointer to NULL");
	}

	if (marker == 1)
		printf("ft_memchr passed all tests\n");
}

void ft_memmove_test(void) {
	int marker = 1;
	char src1[10]="123456789\0";
	char src2[10]="123456789\0";

	   memmove(&src1[2], &src1[4], 5);
	ft_memmove(&src2[2], &src2[4], 5);
	if (strcmp(src1, src2)) {
		marker = 0;
		printf("\tFAIL ft_memmove: Expected '%s', received '%s'\n", src1, src2);
	}

	   memmove(&src1[4], &src1[2], 5);
	ft_memmove(&src2[4], &src2[2], 5);
	if (strcmp(src1, src2)) {
		marker = 0;
		printf("\tFAIL ft_memmove: Expected '%s', received '%s'\n", src1, src2);
	}

	if (marker == 1)
		printf("ft_memmove passed all tests\n");
}

void ft_memccpy_test(void) {
	int marker = 1;
	int n1 = 10;
	int n2 = 5;
	int c = 114;
	char *str = "test string";
	char *dst1 = (char *)malloc(15);
	char *dst2 = (char *)malloc(15);

	ft_memccpy(dst1, str, c, n1);
	ft_memccpy(dst2, str, c, n2);

	for (int i = 0; str[i] != c ; i++) {
		if (dst1[i] != str[i]) {
			marker = 0;
			printf("\tFAIL ft_memccpy: For %i - %c is not equal %c\n", i, dst1[i], str[i]);
		}
	}
	if (ft_memccpy(dst2, str, c, n2) != NULL) {
		marker = 0;
		printf("\tFAIL ft_memccpy: Expected NULL\n");
	}
	if (marker == 1)
		printf("ft_memccpy passed all tests\n");
	free(dst1);	free(dst2);
}

void ft_memcpy_test(void) {
	int marker = 1;
	int n = 10;
	char *str = "test string";
	char *dst = (char *)malloc(15);

	ft_memcpy(dst, str, n);
	for (int i = 0; i < n; i++) {
		if (dst[i] != str[i]) {
			marker = 0;
			printf("\tFAIL ft_memcpy: For %i - %c is not equal %c\n", i, dst[i], str[i]);
		}
	}
	// void *n1 = (void*)0;
	// void *n2 = (void*)0;
	// if (memcmp(memcpy(n1, n2, 3), ft_memcpy(n1, n2, 3), 3))
	// 	printf("\tFAIL ft_memcpy: memcpy does not behave well with NULL as both params with size\n");

	if (marker == 1)
		printf("ft_memcpy passed all tests\n");
	free(dst);
}

void ft_bzero_test(void) {
	int n = 5;
	int marker = 1;
	char *str = (char *)malloc(n);

	ft_bzero(str, n);
	for (int i = 0; i < n; i++) {
		if (str[i] != 0) {
			marker = 0;
			printf("\tFAIL ft_bzero: str[%i] is not equal '0'", i);
		}
	}

	if (marker == 1)
		printf("ft_bzero passed all tests\n");
	free(str);
}

void ft_memset_test(void) {
	int n = 8;
	int c = 50;
	int marker = 1;
	char *str1 = ft_strnew(n);
	char *str2 = ft_strnew(n);
	int *arr1 = (int *)malloc(n * sizeof(int));
	int *arr2 = (int *)malloc(n * sizeof(int));

	ft_memset(str1, c, n * sizeof(char));
	memset(str2, c, n * sizeof(char));
	ft_memset(arr1, c, n * sizeof(int));
	memset(arr2, c, n * sizeof(int));
	for (int i = 0; i < n; i++) {
		if (str1[i] != str2[i]) {
			marker = 0;
			printf("\tFAIL ft_memset: For i = '%i' str1[i] = %c is not equal str2[i] = %c\n", i, str1[i], str2[i]);
		}
		if (arr1[i] != arr2[i]) {
			marker = 0;
			printf("\tFAIL ft_memset: For i = '%i' arr1[i] = %i is not equal arr2[i] = %i\n", i, arr1[i], arr2[i]);
		}
	}

	if (marker == 1)
		printf("ft_memset passed all tests\n");
	free(str1); free(str2); free(arr1); free(arr2);
}

void ft_memdel_test(void) {
	char *ptr = (char *)malloc(5);
	int marker = 1;

	strcpy(ptr, "test\0");
	ft_memdel((void *)&ptr);
	if (ptr != NULL) {
		printf("\tFAIL ft_memdel_test: pointer didn't set to NULL\n");
		marker = 0;
	}
	if (marker == 1)
		printf("ft_memdel set pointer to NULL. *** Check valgrind.log ***\n");
	free(ptr);
}

void ft_strnew_test(void) {
	int marker = 1;
	size_t size = sizeof(int) * 15;

	char *str = ft_strnew(size);
	for (int i = 0, n = size; i < n; i++) {
		if (str[i] != 0) {
			marker = 0;
			printf("\tFAIL ft_strnew_test: for i = %i str[i] != 0\n", i);
		}
	}
	if (marker == 1)
		printf("ft_strnew_test passed all tests\n");
	free(str);
}

void ft_strdel_test(void) {
	char *str = (char *)malloc(5);
	int marker = 1;

	strcpy(str, "test\0");
	ft_strdel(&str);
	if (str != NULL) {
		printf("\tFAIL ft_strdel_test: pointer didn't set to NULL\n");
		marker = 0;
	}
	if (marker == 1)
		printf("ft_strdel set pointer to NULL. *** Check valgrind.log ***\n");
	free(str);
}

void ft_strclr_test(void) {
	ft_strclr(NULL);

	int marker = 1;
	char *str = (char *)malloc(5);
	strcpy(str, "test\0");
	ft_strclr(str);
	for (int i = 0; i < 5; i++) {
		if (str[i] != '\0') {
			marker = 0;
			printf("\tFAIL ft_strclr_test: for i = %i str[i] != 0\n", i);
		}
	}
	if (marker == 1)
		printf("ft_strclr passed all tests\n");
	free(str);
}

void test_func1(char *c) {
	*c += 1;
}

void ft_striter_test(void) {
	ft_striter(NULL, test_func1);

	char *str = (char *)malloc(5);
	int marker = 1;
	strcpy(str, "abcd\0");
	ft_striter(str, test_func1);

	if (strcmp(str, "bcde\0")) {
		marker = 0;
		printf("\tFAIL ft_striter: expected: 'bcde', received: %s\n", str);
	}

	if (marker == 1)
		printf("ft_striter passed all tests\n");
	free(str);
}


void test_func2(unsigned int i, char *c) {
	*c += i;
}

void ft_striteri_test(void) {
	ft_striteri(NULL, test_func2);

	char *str = (char *)malloc(5);
	int marker = 1;
	strcpy(str, "abcd\0");
	ft_striteri(str, test_func2);
	if (strcmp(str, "aceg\0")) {
		marker = 0;
		printf("\tFAIL ft_striteri: expected: 'aceg', received: %s\n", str);
	}

	if (marker == 1)
		printf("ft_striteri passed all tests\n");
	free(str);
}

char test_func3(char c) {
	c -= 32;
	return (c);
}

void ft_strmap_test(void)
{
	int marker = 1;
	char *str = ft_strmap(test_str_char[0], test_func3);
	char *str_null = ft_strmap(NULL, test_func3);

	if (strcmp(str, "TEST")) {
		marker = 0;
		printf("\tFAIL ft_strmap: expected: 'TEST', received: %s\n", str);
	}
	if (str_null != NULL) {
		marker = 0;
		printf("\tFAIL ft_strmap: expected: 'NULL', received: %s\n", str_null);
	}
	if (marker == 1)
		printf("ft_strmap passed all tests\n");
	free(str);
}

char test_func4(unsigned int i, char c) {
	c += i;
	return (c);
}

void ft_strmapi_test(void)
{
	int marker = 1;
	char *str = ft_strmapi(test_str_char[0], test_func4);
	char *str_null = ft_strmapi(NULL, test_func4);

	if (strcmp(str, "tfuw")) {
		marker = 0;
		printf("\tFAIL ft_strmapi: expected: 'tfuw', received: %s\n", str);
	}
	if (str_null != NULL) {
		marker = 0;
		printf("\tFAIL ft_strmapi: expected: 'NULL', received: %s\n", str_null);
	}
	if (marker == 1)
		printf("ft_strmapi passed all tests\n");
	free(str);
}

void ft_strequ_test(void) {
	int marker = 1;
	// if (ft_strequ(NULL, NULL) != 1) {
	// 	marker = 0;
	// 	printf("\tFAIL ft_strequ: for 'NULL' & 'NULL' expected '1'\n");
	// }
	// if (ft_strequ(NULL, "test") != 0) {
	// 	marker = 0;
	// 	printf("\tFAIL ft_strequ: for 'NULL' & 'test' expected '0'\n");
	// }
	if (ft_strequ("test", "test") != 1) {
		marker = 0;
		printf("\tFAIL ft_strequ: for 'test' & 'test' expected '1'\n");
	}
	if (ft_strequ("test", "test ") != 0) {
		marker = 0;
		printf("\tFAIL ft_strequ: for 'test' & 'test ' expected '0'\n");
	}

	if (marker == 1)
		printf("ft_strequ passed all tests\n");
}

void ft_strnequ_test(void) {
	int marker = 1;

	if (ft_strnequ("test", "tesT", 3) != 1) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for 'test' & 'tesT' & n = 3 expected '1'\n");
	}
	if (ft_strnequ("test", "tesT", 4) != 0) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for 'test' & 'tesT' & n = 4 expected '0'\n");
	}
	if (ft_strnequ("test", "test", 5) != 1) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for 'test' & 'test' & n = 5 expected '1'\n");
	}
	if (ft_strnequ("tests", "test", 6) != 0) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for 'tests' & 'test' & n = 6 expected '0'\n");
	}
	if (ft_strnequ("", "test", 6) != 0) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for '' & 'test' & n = 6 expected '0'\n");
	}
	if (ft_strnequ("test", "", 6) != 0) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for 'test' & '' & n = 6 expected '0'\n");
	}
	if (ft_strnequ("", "", 6) != 1) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for '' & '' & n = 6 expected '1'\n");
	}
	if (ft_strnequ("", "", 0) != 1) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for '' & '' & n = 0 expected '1'\n");
	}
	if (ft_strnequ("test", "voda", 0) != 1) {
		marker = 0;
		printf("\tFAIL ft_strnequ: for 'test' & 'voda' & n = 0 expected '1'\n");
	}

	if (marker == 1)
		printf("ft_strnequ passed all tests\n");
}

void ft_substr_test(void) {
	char *strnull = ft_substr(NULL, 0, 5);
	char *strerr = ft_substr("test text", 5, 5);
	char *str = ft_substr("test text", 2, 5);
	int marker = 1;
	if (strnull != NULL) {
		marker = 0;
		printf("\tFAIL ft_substr: for ('NULL', 0, 5) expected 'NULL', received '%s'\n", strnull);
	}
	if (strerr != NULL) {
		marker = 0;
		printf("\tFAIL ft_substr: for ('test text', 5, 5) expected 'NULL', received '%s'\n", strerr);
	}
	if (strcmp(str, "st te")) {
		marker = 0;
		printf("\tFAIL ft_substr: for ('test text', 2, 5) expected 'st te', received '%s'\n", str);
	}

	if (marker == 1)
		printf("ft_substr passed all tests\n");
	free(str);
	free(strerr);
	free(strnull);
}

void ft_strjoin_test(void) {
	int marker = 1;

	char *str = ft_strjoin("hello ", "world");
	// ft_strjoin("hello", NULL);
	if (strcmp("hello world", str)) {
		marker = 0;
		printf("\tFAIL ft_strjoin: for ('hello ', 'world') expected 'hello world', received '%s'\n", str);
	}

	if (marker == 1)
		printf("ft_strjoin passed all tests\n");
	free(str);
}

void ft_strtrim_test(void) {
	int marker = 1;

	char *str1 = ft_strtrim("#$!#hello world@##@!", "!@#$");
	char *str2 = ft_strtrim("hello world", "!@#$");
	char *str3 = ft_strtrim("", "!@#$");
	char *str4 = ft_strtrim("#@!$!@#!", "!@#$");
	if (strcmp("hello world", str1)) {
		marker = 0;
		printf("\tFAIL ft_strtrim: for ('#$!#hello world@##@!') expected 'hello world', received '%s'\n", str1);
	}
	if (strcmp("hello world", str2)) {
		marker = 0;
		printf("\tFAIL ft_strtrim: for ('hello world') expected 'hello world', received '%s'\n", str2);
	}
	if (strcmp("", str3)) {
		marker = 0;
		printf("\tFAIL ft_strtrim: for blank sting\n");
	}
	if (strcmp("", str4)) {
		marker = 0;
		printf("\tFAIL ft_strtrim: for blank sting\n");
	}

	if (marker == 1)
		printf("ft_strtrim passed all tests\n");
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

void ft_split_test(void) {
	int marker = 1;
	char **ptr1 = ft_split("** coronavirus*will*kill* us*all**", '*');
	char *ptr2[5] = {" coronavirus","will","kill"," us","all"};
	for (int i = 0; ptr1[i] && ptr2[i]; i++) {
		if (strcmp(ptr1[i], ptr2[i])) {
			marker = 0;
			printf("\tFAIL ft_split: for i = %i expected '%s', received '%s'\n", i, ptr2[i], ptr1[i]);
		}
	}
	if (marker == 1)
		printf("ft_split passed all tests\n");
	for (int i = 0; ptr1[i]; i++)
		free(ptr1[i]);
	free(ptr1);
}

void ft_itoa_test(void) {
	int marker = 1;
	int arr_size = 13;
	int arr_i[13] = {-2147483648, -2000000000, -178, -100, -12, -1, 0, 1, +15, +100, 15231, 1500000000, 2147483647};
	char *arr_s[13] = {"-2147483648","-2000000000","-178","-100","-12","-1","0","1","15","100","15231","1500000000", "2147483647"};
	for (int i = 0; i < arr_size; i++) {
		char *str = ft_itoa(arr_i[i]);
		if (strcmp(str, arr_s[i])) {
			marker = 0;
			printf("\tFAIL ft_itoa: for i = %i expected '%s', received '%s'\n", i, arr_s[i], str);
		}
		free(str);
	}

	if (marker == 1)
		printf("ft_itoa passed all tests\n");
}

void ft_putstr_test(void) {
	char *str = NULL;
	ft_putstr(str);
	ft_putstr("ft_putstr passed all tests\n");
}

void ft_putendl_test(void) {
	char *str = NULL;
	ft_putendl(str);
	ft_putendl("ft_putendl passed all tests");
}

void ft_putnbr_test(void) {
	int arr_i[7] = {-2147483648, -100, -1, 0, 1, +100, 2147483647};
	printf("ft_putnbr passed all tests if next 2 strings is equal\n");
	for (int i = 0; i < 7; i++)
		printf("%i, ", arr_i[i]);
	printf("\n");
	for (int i = 0; i < 7; i++) {
		ft_putnbr(arr_i[i]);
		ft_putstr(", ");
	}
	ft_putstr("\n");
}

void ft_lstnew_test(void) {
	int		marker = 1;
	void	*ptr;
	t_list	*list;

	ptr = NULL;;
	list = ft_lstnew(ptr);
	if (list->content != NULL) {
		marker = 0;
		printf("\tFAIL ft_lstnew: for content = NULL\n");
	}
	free(list);
	int i = 15;
	list = ft_lstnew(&i);
	i = 10;
	if (*(int *)(list->content) != i) {
		marker = 0;
		printf("\tFAIL ft_lstnew: for content int i = 15\n");
		printf("\tExpected i = '%i', received i = '%i'\n", i, *((int *)(list->content)));
	}
	free(list);

	char *s = "test string";
	char *s2 = "test string";
	list = ft_lstnew(s);
	s = "TEST STRING";
	if (strcmp ((char *)(list->content), s2)) {
		marker = 0;
		printf("\tFAIL ft_lstnew: for content s = 'test string'\n");
		printf("\tExpected s = '%s, received s = '%s'\n", s2, (char *)(list->content));
	}
	free(list);

	if (marker == 1)
		printf("ft_lstnew passed all tests\n");
}

void del_test(void *ptr) {
	free(ptr);
}

void ft_lstadd_front_test(void) {
	int marker = 1;

	int i1 = 15;
	int i2 = 50;
	t_list *list;
	t_list *list_add;

	list = ft_lstnew(&i1);
	list_add = ft_lstnew(&i2);
	ft_lstadd_front(&list, list_add);
	if (*((int *)(list->content)) != 50) {
		marker = 0;
		printf("\tFAIL ft_lstadd_front: test failed. Expected list->content = 50, received %i\n", *((int *)(list->content)));
	}
	del_test(list);

	list = NULL;
	list_add = ft_lstnew(&i2);
	ft_lstadd_front(&list, list_add);
	if (*((int *)(list->content)) != 50) {
		marker = 0;
		printf("\tFAIL ft_lstadd_front: test failed. Expected list->content = 50, received %i\n", *((int *)(list->content)));
	}
	del_test(list);

	if (marker == 1)
		printf("ft_lstadd_front passed all tests\n");
}

void ft_lstsize_test(void) {
	t_list *list = NULL;
	int marker = 1;

	if (ft_lstsize(list) != 0) {
		marker = 0;
		printf("\tFAIL ft_lstsize: didn't work, when list point at NULL\n");
	}
	t_list *node1 = ft_lstnew(&marker);
	t_list *node2 = ft_lstnew(&marker);
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);

	if (ft_lstsize(list) != 2) {
		marker = 0;
		printf("\tFAIL ft_lstsize: didn't work. Expected size = 2, recieved size = %i\n", ft_lstsize(list));
	}

	if (marker == 1)
		printf("ft_lstsize passed all tests\n");
}

void ft_lstlast_test(void) {
	t_list *list = NULL;
	int marker = 1;

	if (list != NULL) {
		marker = 0;
		printf("\tFAIL ft_lstlast: didn't work, when list point at NULL\n");
	}

	int last = 10;
	int scnd = 5;
	int frst = 1;
	t_list *node1 = ft_lstnew(&last);
	t_list *node2 = ft_lstnew(&scnd);
	t_list *node3 = ft_lstnew(&frst);
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);

	t_list *last_node = ft_lstlast(list);
	if (*(int *)(last_node->content) != 10) {
		marker = 0;
		printf("\tFAIL ft_lstlast: Expected last_node->content = 15, recieved  = %i\n", *(int *)(last_node->content));
	}

	if (marker == 1)
		printf("ft_lstlast passed all tests\n");
}

void ft_lstadd_back_test(void) {
		int marker = 1;

	int i1 = 15;
	int i2 = 50;
	t_list *list;
	t_list *list_add;

	list = ft_lstnew(&i1);
	list_add = ft_lstnew(&i2);
	ft_lstadd_back(&list, list_add);
	if (*((int *)(list->content)) != 15 || *(int *)(list->next->content) != 50) {
		marker = 0;
		printf("\tFAIL ft_lstadd_back: test failed. Expected list->content = 15, list->next->content = 50\
		received list->content = %i, list->next->content = %i\n", *((int *)(list->content)), *(int *)(list->next->content));
	}
	del_test(list);

	list = NULL;
	list_add = ft_lstnew(&i2);
	ft_lstadd_back(&list, list_add);
	if (*((int *)(list->content)) != 50) {
		marker = 0;
		printf("\tFAIL ft_lstadd_back: test failed. Expected list->content = 15, %i\n", *(int *)(list->content));
	}
	del_test(list);

	if (marker == 1)
		printf("ft_lstadd_back passed all tests\n");
}

void ft_lstdelone_test(void) {
	int marker = 1;

	int *i = (int *)malloc(sizeof(int));
	t_list *list = ft_lstnew(i);

	ft_lstdelone(list, del_test);
	// if (list->next != NULL) {
	// 	marker = 0;
	// 	printf("\tFAIL ft_lstdelone: pointer didn't set to NULL\n");
	// }

	if (marker == 1)
		printf("ft_lstdelone set pointer list to NULL. *** Check valgrind.log ***\n");
}

void ft_lstclear_test(void) {
	int marker = 1;

	int *i1 = (int *)malloc(sizeof(int));
	int *i2 = (int *)malloc(sizeof(int));
	int *i3 = (int *)malloc(sizeof(int));
	t_list *list = ft_lstnew(i1);
	list->next = ft_lstnew(i2);
	list->next->next = ft_lstnew(i3);


	ft_lstclear(&list, del_test);
	if (list != NULL) {
		marker = 0;
		printf("\tFAIL ft_lstclear: pointer didn't set to NULL\n");
	}

	if (marker == 1)
		printf("ft_lstclear set pointer list to NULL. *** Check valgrind.log ***\n");
}

void f_test(void *content) {
	*(int *)content += 35;
}

void del_test2(void *ptr) {
	*(int *)ptr = 0;
}

void ft_lstiter_test(void) {
	int marker = 1;

	int i1 = 15;
	int i2 = 20;
	int i3 = 25;
	t_list *list;

	list = ft_lstnew(&i1);
	list->next = ft_lstnew(&i2);
	list->next->next = ft_lstnew(&i3);
	ft_lstiter(list, f_test);
	if (*((int *)(list->content)) != 50 || *((int *)(list->next->content)) != 55 || *((int *)(list->next->next->content)) != 60) {
		marker = 0;
		printf("\tFAIL ft_lstiter: test failed\n");
	}
	ft_lstclear(&list, del_test2);

	if (marker == 1)
		printf("ft_lstiter passed all tests\n");
}

void *f_test1(void *list) {
	*(int *)list += 35;
	return (list);
}

void ft_lstmap_test(void) {
	int marker = 1;

	int i1 = 15;
	t_list *list;
	list = ft_lstnew(&i1);
	list->next = ft_lstnew(&i1);
	list->next->next = ft_lstnew(&i1);

	t_list *list_new = ft_lstmap(list, f_test1, del_test2);
	if (*((int *)(list_new->content)) != 50 || *((int *)(list_new->next->content)) != 50 || *((int *)(list_new->next->next->content)) != 50) {
		marker = 0;
		printf("\tFAIL ft_lstmap: test failed\n");
	}
	// if (*((int *)(list->content)) != 15 || *((int *)(list->next->content)) != 15 || *((int *)(list->next->next->content)) != 15) {
	// 	marker = 0;
	// 	printf("\tFAIL ft_lstmap: you changed the source list\n");
	// }

	ft_lstclear(&list_new, del_test);
	ft_lstclear(&list, del_test);

	if (marker == 1)
		printf("ft_lstmap passed all tests\n");
}

void ft_islower_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((islower(i) == 0 && ft_islower(i) > 0) || (islower(i) > 0 && ft_islower(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_islower: for i = %i expected %i, received %i\n", i, islower(i), ft_islower(i));
		}
	}

	if (marker == 1)
		printf("ft_islower passed all tests\n");
}

void ft_isupper_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((isupper(i) == 0 && ft_isupper(i) > 0) || (isupper(i) > 0 && ft_isupper(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_isupper: for i = %i expected %i, received %i\n", i, isupper(i), ft_isupper(i));
		}
	}

	if (marker == 1)
		printf("ft_isupper passed all tests\n");
}

void ft_isblank_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((isblank(i) == 0 && ft_isblank(i) > 0) || (isblank(i) > 0 && ft_isblank(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_isblank: for i = %i expected %i, received %i\n", i, isblank(i), ft_isblank(i));
		}
	}

	if (marker == 1)
		printf("ft_blank passed all tests\n");
}

void ft_iscntrl_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((iscntrl(i) == 0 && ft_iscntrl(i) > 0) || (iscntrl(i) > 0 && ft_iscntrl(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_iscntrl: for i = %i expected %i, received %i\n", i, iscntrl(i), ft_iscntrl(i));
		}
	}

	if (marker == 1)
		printf("ft_iscntrl passed all tests\n");
}

void ft_isgraph_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((isgraph(i) == 0 && ft_isgraph(i) > 0) || (isgraph(i) > 0 && ft_isgraph(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_iscntrl: for i = %i expected %i, received %i\n", i, isgraph(i), ft_isgraph(i));
		}
	}

	if (marker == 1)
		printf("ft_isgraph passed all tests\n");
}


void ft_isspace_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((isspace(i) == 0 && ft_isspace(i) > 0) || (isspace(i) > 0 && ft_isspace(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_isspace: for i = %i expected %i, received %i\n", i, isspace(i), ft_isspace(i));
		}
	}

	if (marker == 1)
		printf("ft_isspace passed all tests\n");
}

void ft_isxdigit_test(void) {
	int marker = 1;
	for (int i = -200; i < 257; i++) {
		if ((isxdigit(i) == 0 && ft_isxdigit(i) > 0) || (isxdigit(i) > 0 && ft_isxdigit(i) == 0))
		{
			marker = 0;
			printf("\tFAIL ft_isxdigit: for i = %i expected %i, received %i\n", i, isxdigit(i), ft_isxdigit(i));
		}
	}

	if (marker == 1)
		printf("ft_isxdigit passed all tests\n");
}

void ft_strcasecmp_test(void) {
	int marker = 1;
	int i;
	char *s1 = "test";
	char *s2 = "test ";
	char *s3 = "TEST";
	char *s4 = "";

	i = ft_strcasecmp(s1, s1);
	if (i != 0)
	{
		marker = 0;
		printf("\tFAIL ft_strcasecmp: for s1 '%s' and s2 '%s', expected 0, received %i\n", s1, s1, ft_strcasecmp(s1, s1));
	}

	i = ft_strcasecmp(s1, s2);
	if (i == 0)
	{
		marker = 0;
		printf("\tFAIL ft_strcasecmp: for s1 '%s' and s2 '%s', expected NOT 0, received %i\n", s1, s2, ft_strcasecmp(s1, s2));
	}

	i = ft_strcasecmp(s1, s3);
	if (i != 0)
	{
		marker = 0;
		printf("\tFAIL ft_strcasecmp: for s1 '%s' and s2 '%s', expected 0, received %i\n", s1, s3, ft_strcasecmp(s1, s3));
	}

	i = ft_strcasecmp(s1, s4);
	if (i == 0)
	{
		marker = 1;
		printf("\tFAIL ft_strcasecmp: for s1 '%s' and s2 '%s', expected NOT 0, received %i\n", s1, s4, ft_strcasecmp(s1, s4));
	}

	if (marker == 1)
		printf("ft_strcasecmp passed all tests\n");
}

void ft_strncasecmp_test(void) {
	int marker = 1;
	int i;
	char *s1 = "test";
	char *s2 = "test ";
	char *s3 = "TESTooo";

	i = ft_strncasecmp(s1, s2, 4);
	if (i != 0)
	{
		marker = 0;
		printf("\tFAIL ft_strncasecmp: for s1 '%s' and s2 '%s' and n = 4, expected 0, received %i\n", s1, s2, ft_strncasecmp(s1, s2, 4));
	}

	i = ft_strncasecmp(s1, s3, 4);
	if (i != 0)
	{
		marker = 0;
		printf("\tFAIL ft_strncasecmp: for s1 '%s' and s2 '%s' and n = 4, expected 0, received %i\n", s1, s3, ft_strncasecmp(s1, s3, 4));
	}

	if (marker == 1)
		printf("ft_strncasecmp passed all tests\n");
}

void ft_strcasestr_test(void) {
	int marker = 1;
	const char *str1 = "test string test string";
	const char *str2 = "string";
	const char *str3 = "\tFAIL";
	const char *str4 = "";
	const char *str5 = "aaabbbaaabbb";
	const char *str6 = "abbaaab";

	char *ptr1 = strstr(str1, str2);
	char *ptr2 = ft_strcasestr(str1, "StrIng");
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strcasestr(1): Expected pointer to '%s', received '%s'\n", ptr1, ptr2);
	}
	ptr2 = ft_strcasestr(str1, str3);
	if (ptr2 != NULL) {
		marker = 0;
		printf("\tFAIL ft_strcasestr(2): Expected pointer to NULL\n");
	}
	ptr1 = strstr(str1, str4);
	ptr2 = ft_strcasestr(str1, str4);
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strcasestr(3): Expected pointer to '%s', received '%s'\n", ptr1, ptr2);
	}
	ptr1 = strstr(str5, str6);
	ptr2 = ft_strcasestr(str5, "aBbaaAb");
	if (ptr1 != ptr2) {
		marker = 0;
		printf("\tFAIL ft_strcasestr(4): Expected pointer to '%s', received '%s'\n", str5, str6);
	}
	if (marker == 1)
		printf("ft_strcasestr passed all tests\n");
}

int main(void) {
	ft_tolower_toupper_test();
	ft_isalpha_digit_alnum_ascii_print_test();
	ft_atoi_test(test_str_int, test_str_int_size);
	ft_strncmp_test();
	ft_strcmp_test();
	ft_strnstr_test();
	ft_strstr_test();
	ft_strrchr_test();
	ft_strchr_test();
	ft_strlcat_test();
	ft_strncat_test();
	ft_strcat_test();
	ft_strncpy_test();
	ft_strcpy_test();
	ft_strdup_test();
	ft_strlen_test();
	ft_memcmp_test();
	ft_memchr_test();
	ft_memmove_test();
	ft_memccpy_test();
	ft_memcpy_test();
	ft_memset_test();
	ft_bzero_test();
	ft_memdel_test();
	ft_strnew_test();
	ft_strdel_test();
	ft_strclr_test();
	ft_striter_test();
	ft_striteri_test();
	ft_strmap_test();
	ft_strmapi_test();
	ft_strequ_test();
	ft_strnequ_test();
	ft_substr_test();
	ft_strjoin_test();
	ft_strtrim_test();
	ft_split_test();
	ft_itoa_test();
	ft_putstr_test();
	ft_putendl_test();
	ft_putnbr_test();
	ft_lstnew_test();
	ft_lstadd_front_test();
	ft_lstsize_test();
	ft_lstlast_test();
	ft_lstadd_back_test();
	ft_lstdelone_test();
	ft_lstclear_test();
	ft_lstiter_test();
	// ft_lstmap_test();
	ft_islower_test();
	ft_isupper_test();
	ft_isblank_test();
	ft_iscntrl_test();
	ft_isspace_test();
	ft_isxdigit_test();
	ft_strcasecmp_test();
	ft_strncasecmp_test();
	ft_strcasestr_test();
}