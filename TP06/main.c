/*
 * main.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Merve Unlu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"
#include "rpn.h"

#define LINE_MAX 10

int main(int argc, char *argv[])
{
	/*
	 * Hesaplanmasi icin bir tanim degerini
	 * kullanicidan alir ve daha once tanimli
	 * fonksiyonlari cagirip hesaplar.
	 * Kullanici sistemden cikis yapmak icin exit yazip Enter a basmalidir.
	 */
	int continuing = 1;
	char line[LINE_MAX];
        // Alistirma 1.f
        // stack.c yazdiginiz fonksiyonlari test edin.
	/*
	struct stackNode *test = NULL;
	int tester = 0;
	tester = is_empty(test);
	if (tester == 1) printf("This stack is empty. YEET!\n");
	stack_push(&test, 5); stack_push(&test, 13); stack_push(&test, 2); stack_push(&test, 25);
	stack_print(test); 
	tester = stack_pop(&test);
	printf("%d\n", tester); 
	stack_print(test);
	stack_multi_pop(&test, 2);
	stack_print(test);
	stack_multi_pop(&test, 2);
	stack_print(test); */

        // Alistirma 2.b yi tamamladiktan sonra alttaki satiri 
        // yorumdan cikarip test yapabilirsiniz.
        // Alistirma 2.c
	
//	struct stackNode *stack = NULL;
	rpn_test_evaluate_RPN();

	/*printf("RPN Hesap Makinesi\nCikis icin exit yazip ENTER'a basin\n\n");

            // Alistirma 3   

	printf("Hesaplama isleminden cikildi.\n"); */
return 0;
}
