#include <stdio.h>
#include <string.h>

#define N 1000

typedef enum s {
    a,
    b,
    c,
    d
} state;

typedef struct str {
    char tape[N];
    int head;
    state status;
} Tmashine;
//    
// 2-4
//   ^

int main() {
    Tmashine TM;
    memset(TM.tape, ' ', N);

}