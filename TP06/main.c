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

int main(int argc, char *argv[]) {
	/*
	 * Hesaplanmasi icin bir tanim degerini
	 * kullanicidan alir ve daha once tanimli
	 * fonksiyonlari cagirip hesaplar.
	 * Kullanici sistemden cikis yapmak icin exit yazip Enter a basmalidir.
	 */
	int continuing = 1;
	char line[LINE_MAX];
	double res = 0;
        // Alistirma 1.f
        // stack.c yazdiginiz fonksiyonlari test edin.

	/*  HATALAR:
		1) Alistirma 1'in testlerini yorum icine almazsam Alistirma 2 hic calismiyor. 
		Hata vermiyor ama direkt programi kapatiyor, cok garip.

		2) Cok uzun bir islem girersem bazen islemi yapip sonucu dogru bastigi halde 
		*** stack smashing detected ***: <unknown> terminated Aborted (core dumped)
		hatasi veriyor. Ornek:  34*2+7*5-2/5+ veya 64*2+7*5-2/5+2*8-  sonuclar 51.50
		ve 179.00. Hatayi hemen vermiyor, bu islemlerden sonra exit yazinca veriyor.
	*/

	/*
	struct stackNode *test = NULL;
	int tester = 0;
	tester = is_empty(test);
	if (tester == 1) printf("This stack empty, YEET!\n");
	stack_push(&test, 5); stack_push(&test, 13); stack_push(&test, 2); stack_push(&test, 25);
	stack_print(test); 
	tester = stack_pop(&test);
	printf("%d\n", tester); 
	stack_print(test);
	stack_multi_pop(&test, 2);
	stack_print(test);
	stack_multi_pop(&test, 2);
	stack_print(test); 
	stack_free(&test); */

    // Alistirma 2.b yi tamamladiktan sonra alttaki satiri 
	// yorumdan cikarip test yapabilirsiniz.
	// Alistirma 2.c
	
	rpn_test_evaluate_RPN();
	struct stackNode *stack = NULL;

	printf("\nRPN Calculator\nTo exit, write exit and press ENTER");
    // Alistirma 3   
	while (1 == 1) {
		printf("\nEnter the equation: ");
		scanf("%s", line);
		if (!strcmp(line, "exit")) {
			printf("Exiting the calculator...\n");
			break; 
		}
		else {
			res = evaluate_RPN(line, &stack);
			printf("The result of this equation is %.2lf\n", res);
		}
	}
	stack_free(&stack);

	return 0;
}
