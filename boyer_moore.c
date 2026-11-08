#include <stdio.h>
#include <string.h>

void boyerMoore(char text[], char pat[]) {
    int n = strlen(text), m = strlen(pat);
    int i, j, shift;

    for (i = 0; i <= n - m; i++) {
        j = m - 1;

        while (j >= 0 && pat[j] == text[i + j])
            j--;

        if (j < 0) {
            printf("Pattern found at index %d\n", i);
        } else {
            shift = 1;

            for (int k = j - 1; k >= 0; k--) {
                if (pat[k] == text[i + j]) {
                    shift = j - k;
                    break;
                }
            }

            i += shift - 1;
        }
    }
}

int main() {
    char text[100], pat[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pat);

    boyerMoore(text, pat);

    return 0;
}
