#include <stdio.h>

char b[10] = {'0','1','2','3','4','5','6','7','8','9'};

void display() {
    printf("\n%c | %c | %c\n", b[1], b[2], b[3]);
    printf("---------\n");
    printf("%c | %c | %c\n", b[4], b[5], b[6]);
    printf("---------\n");
    printf("%c | %c | %c\n", b[7], b[8], b[9]);
}

int win() {
    int w[8][3]={{1,2,3},{4,5,6},{7,8,9},
                 {1,4,7},{2,5,8},{3,6,9},
                 {1,5,9},{3,5,7}};
    for(int i=0;i<8;i++)
        if(b[w[i][0]]==b[w[i][1]] &&
           b[w[i][1]]==b[w[i][2]])
            return 1;
    return 0;
}

int main() {
    int pos, comp;

    printf("TIC-TAC-TOE\n");
    printf("You are X\nComputer is O\n");

    while(1) {
        printf("Enter position (1-9): ");
        scanf("%d",&pos);

        if(pos<1 || pos>9 || b[pos]=='X' || b[pos]=='O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        b[pos]='X';

        if(win()) {
            display();
            printf("You win!\n");
            break;
        }

        comp=1;
        while(comp<=9 && (b[comp]=='X' || b[comp]=='O'))
            comp++;

        if(comp>9) {
            display();
            printf("Draw!\n");
            break;
        }

        b[comp]='O';
        printf("Computer chose position: %d\n", comp);

        if(win()) {
            display();
            printf("Computer wins!\n");
            break;
        }

        display();
    }

    return 0;
}
