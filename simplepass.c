#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_password(char *buffer, int length) {
    const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()-_=+[]{};:,.<>/?";

    size_t charset_size = sizeof(charset) - 1;

    for (int i = 0; i < length; i++) {
        buffer[i] = charset[rand() % charset_size];
    }
    buffer[length] = '\0';
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int length = 16;  // default

    if (argc >= 2) {
        length = atoi(argv[1]);
        if (length <= 0) {
            printf("Invalid length. Using default (16).\n");
            length = 16;
        }
    }

    char *password = malloc(length + 1);
    if (!password) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generate_password(password, length);

    printf("Your new password is: %s\n", password);

    free(password);
    return 0;
}
