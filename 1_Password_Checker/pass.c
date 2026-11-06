#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
char password[128];
int length_ok=0,upper_ok=0,lower_ok=0,digit_ok=0,punct_ok=0;
int score = 0;

printf("Enter password: ");
if (scanf("%127s", password) != 1) { return 1; }

int len = (int)strlen(password);
if (len >= 8) {
length_ok = 1;
score++;
}

for (int i = 0; i < len; i++) {
if (isupper(password[i])) { upper_ok = 1; } 
else if (islower(password[i])) { lower_ok = 1; } 
else if (isdigit(password[i])) { digit_ok = 1; } 
else if (ispunct(password[i])) { punct_ok = 1; }
}

score += (upper_ok + lower_ok + digit_ok + punct_ok);

printf("\n--- Result ---\n");
printf("Length >= 8: %d\n", length_ok);
printf("Uppercase: %d\n", upper_ok);
printf("Lowercase: %d\n", lower_ok);
printf("Digits: %d\n", digit_ok);
printf("Symbols: %d\n", punct_ok);
printf("Score: %d/5\n", score);
printf("--------------\n");

if (score <= 2) {
printf("Status: Weak\n");
} 
else if (score == 3 || score == 4) {
printf("Status: Acceptable\n");
} 
else if (score == 5) {
printf("Status: Strong\n");
}

return 0;
}
