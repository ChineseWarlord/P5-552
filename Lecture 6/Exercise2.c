#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    float answer = 0;
    int k = 0;
    int n = 0;
    float LORT = 0;
    // int x = (n - k);

    for (n = 0; n < 50; n++) {
        printf("n = %d\n", n);
        for (k = 0; k < 50; k++) {
            printf("k = %d\n", k);
            //answer += (1 / 8 * exp(-k * 1 / 8) * (n - k));

            LORT += ((exp(-k * 1 / 8) * 1 / 8 * (n - k)) * 1 / 8);
            //printf("LORT = %f\n", LORT);
            //printf("answer = %f\n", answer);
        }

        // float test = exp(-k * 1 / 8);
        // printf("test = %f\n", test);
    }
    //printf("Final Answer: %f\n", answer);
    printf("Final Answer: %f\n", LORT);

    return 0;
}
