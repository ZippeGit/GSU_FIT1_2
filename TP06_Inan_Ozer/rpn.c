/*
 * rpn.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Merve Unlu
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include"rpn.h"
#include"stack.h"

/*
 * Verilen iki sayi uzerinde, verilen islemi uygular.
 * Ornek: op1 = 1 op2 = 3 operation= +
 *        sonuc: 1+3 = 4
 * Ornek: op1 = 8 op2 = -3 operation = *
 *        sonuc: 8 * -3 = -24
 * Verilen operation eger istenen 4 islem(*,+,/,-) karakterinde degilse
 * hata mesaji gosterip fonksiyondan cikar.
 */
double compute_operation(double op1, double op2, char operation) {
    /* Alistirma 2.a: op1 ve op2'yi operation ile verilen '+', '-', '*', '/'
     * islemlerini uygulayip geri donduren fonksiyonu yazin. */
    double result = 0;

    switch (operation) {
        case '+':
            result = op1 + op2;
            break;

        case '-':
            result = op2 - op1;
            break;

        case '*':
            result = op1 * op2;
            break;

        case '/':
            result = op2 / op1;
            break;
        
        default:
            printf("Please enter one of the allowed operations...\n");
            break;
    }

    /*
     * Hint: switch-case kullanabilirsiniz.
     */
    return result;
}

/*
 * Verilen expr parametresindeki sayilari, yine
 * expr icindeki islemler ile hesaplayip,
 * yigit icerisine kaydedecek.
 */
double evaluate_RPN(char *expr, struct stackNode **top) {


    double retval = 0.;
   // Alistirma 2.b
	// Kullanilacak degisken atamalarini yapin
    int i = 0;
    double op1, op2;
    /*  Ifadenin sonuna kadar elemanlari gezecek  bir dongu kurunuz
     *   ifadenin sonuna gelip gelmedigini ('\0') ile kontrol edebilirsiniz */
    // Hint: kontrol icin her dongu sirasinda yigit icerigini ekrana basabilirsiniz
    //      boylece yigitdaki degisimleri gorebilirsiniz.
        /*  Eger eleman islenen (operand) ise yigita ekleyiniz (push)
         * Hint: isdigit fonksyiyonunu kontrol icin kullanabilirsiniz . */

	    /* Eger eleman bir islem ise yigittan iki deger cekiniz (pop)*/

            // Bu iki deger ile istenen islemi compute_operation()
            // fonksiyonuna verip donus degeri yigita ekleyin (push).
    while (expr[i] != '\0') {

        if (!isdigit(expr[i])) {
            op1 = stack_pop(top);
            op2 = stack_pop(top);
            retval = compute_operation(op1, op2, expr[i]);
            stack_push(top, retval);
        }

        else {
            stack_push(top, expr[i] - '0');
        }

        stack_print(*top);

        i++;
    }

    //  yigitta kalan eleman sonuc degeridir.
    // retval degiskenini sonuc degerini pop ile alarak guncelleyin.
    retval = stack_pop(top);

	// yigit bos degilse kontrol edin,
	// bu durumda compute_operation fonksiyonu hatali olabilir.
	// bununla ilgili mesaj ekrana yazilsin.
    if(!is_empty(*top)) {
        printf("There are still elements in the stack...\n");
    }

    return retval;
}


void rpn_test_evaluate_RPN(){
	/* Test */
    struct stackNode *stack = NULL;
    printf("Testing equation 13+2-\n");
	assert(evaluate_RPN("13+2-", &stack) == 2.0);
    printf("\nTesting equation 62+5*84/-\n");
	assert(evaluate_RPN("62+5*84/-", &stack) == 38.0);
    stack_free(&stack);
	printf("\nThe tests are successful.\n");
}
