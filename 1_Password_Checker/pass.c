#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[128];
    int len, upper = 0, lower = 0, digit = 0, punct = 0, score = 0;

    printf("Enter password: ");
    if (scanf("%127s", password) != 1) return 1;

    len = (int)strlen(password);
    if (len >= 8) score++;

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) upper = 1;
        else if (islower(password[i])) lower = 1;
        else if (isdigit(password[i])) digit = 1;
        else if (ispunct(password[i])) punct = 1;
    }

    score += (upper + lower + digit + punct);

    printf("Length: %d\n", len >= 8);
    printf("Uppercase: %d\n", upper);
    printf("Lowercase: %d\n", lower);
    printf("Digits: %d\n", digit);
    printf("Punctuation: %d\n", punct);
    printf("Final Score: %d/5\n", score);

    return 0;
}
