#include <stdio.h>

int my_print_alpha ( void ) {
    for (int i = 'a'; i <= 'z'; ++i) {
        putchar(i);
    }
    return 0;
}

int my_print_revalpha ( void ) {
    for (int i = 'z'; i >= 'a'; --i) {
        putchar(i);
    }
    return 0;
}

int my_print_digits ( void ) {
    for (int i = '0'; i <= '9'; ++i) {
        putchar(i);
    }
    return 0;
}

int my_isneg ( int n ) {
    if (n < 0) {
        putchar('N');
        return 0;
    }
    putchar('P');
    return 0;
}

int my_print_comb ( void ) {
    int a, b, c;

    for (int a = '0'; a <= '9'; ++a) {
        for (int b = '0'; b <= '9'; ++b) {
            for (int c = '0'; c <= '9'; ++c) {
                if (a < b && b < c) {
                    putchar(a);
                    putchar(b);
                    putchar(c);
                    if (a == '7')
                        return 0;
                    putchar(',');
                    putchar(' ');
                }
            }
        }
    }
    return 0;
}

int my_put_nbr ( int nb ) {
    if (nb < 0) {
        putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        putchar(nb + 48);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        putchar(nb % 10 + 48);
    }
    return (0);
}