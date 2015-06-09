 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 #        .---.         .-----------
 #       /     \  __  /    ------
 #      / /     \(  )/    -----   (`-')  _ _(`-')              <-. (`-')_
 #     //////    '\/ `   ---      ( OO).-/( (OO ).->     .->      \( OO) )     .->
 #    //// / //  :   : ---      (,------. \    .'_ (`-')----. ,--./ ,--/  ,--.'  ,-.
 #   // /   /  / `\/ '--         |  .---' '`'-..__)( OO).-. ' |   \ |  | (`-')'.'  /
 #  //          //..\\          (|  '--.  |  |  ' |( _) | | | |  . '|  |)(OO \    /
 # ============UU====UU====      |  .--'  |  |  / : \|  |)| | |  |\    |  |  /   /)
 #             '//||\\`          |  `---. |  '-'  /  '  '-' ' |  | \   |  `-/   /`
 #               ''``            `------' `------'    `-----' `--'  `--'    `--'
 # ######################################################################################
 #
 # Author: edony - edonyzpc@gmail.com
 #
 # twitter : @edonyzpc
 #
 # Last modified: 2015-06-09 16:40
 #
 # Filename: temper.c
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include <stdio.h>

float C2F(float celsius) {
    return 1.8 * celsius + 32;
}

void StepTemp(float start, float end, float step) {
    float tmp_temp = start;
    printf("Celsius          Fahrenheit\n");
    printf("-------          ----------\n");
    while (tmp_temp <= end) {
        printf("%.6f        %.6f\n", tmp_temp, C2F(tmp_temp));
        tmp_temp += step;
    }
}

int main() {
    float start, end, step;
    const float low_limit = 0;
    const float up_limit = 50000;
    printf("Please given in a lower limit, limit >= %f: ", low_limit);
    scanf("%f", &start);
    while (start < low_limit) scanf("%f", &start);

    printf("Please given in a higher limit, %f > limit <= %f: ", start, up_limit);
    scanf("%f", &end);
    while (end <= start || end > up_limit) {
        printf("wrong end %f\n", end);
        scanf("%f", &end);
    }

    float step_limit = end - start;
    printf("Please given in a step, %f < limit <= %f: ", low_limit, step_limit);
    scanf("%f", &step);
    while (step < 0 || step > up_limit) {
        scanf("%f", &step);
    }
    StepTemp(start, end, step);
    return 0;
}
