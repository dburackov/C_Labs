#include <stdio.h>

int length(const char *str) {
    int result;
    for (result = 0; str[result]; ++result);
    return result;
}

int equals(const char* s, const char* t) {
    int result = 1;
    if (length(s) == length(t)) {
        int i;
        for (i = 0; i < length(s); ++i) {
            if (s[i] != t[i]) {
                result = 0;
            }
        }
    } else {
        result = 0;
    }
    return result;
}