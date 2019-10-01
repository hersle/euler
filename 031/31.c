#include <stdio.h>

int main()
{
    int GOAL = 200;

    int combos = 0;
    int a, b, c, d, e, f, g, h;
    int sa, sb, sc, sd, se, sf, sg, sh;
    for (a = 0; a <= GOAL / 1; a++) {
        sa = a;
        for (b = 0; b <= (GOAL - sa) / 2; b++) {
            sb = sa + b * 2;
            for (c = 0; c <= (GOAL - sb) / 5; c++) {
                sc = sb + c * 5;
                for (d = 0; d <= (GOAL - sc) / 10; d++) {
                    sd = sc + d * 10;
                    for (e = 0; e <= (GOAL - sd) / 20; e++) {
                        se = sd + e * 20;
                        for (f = 0; f <= (GOAL - se) / 50; f++) {
                            sf = se + f * 50;
                            for (g = 0; g <= (GOAL - sf) / 100; g++) {
                                sg = sf + g * 100;
                                for (h = 0; h <= (GOAL - sg) / 200; h++) {
                                    sh = sg + h * 200;
                                    if (sh == GOAL) {
                                        combos++;
                                        printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Combos: %d\n", combos);
    return 0;
}
