#include <stdio.h>
#include <stdbool.h>

int Calc(int First, char cal, int Second)
{
    int sum = 0;
    do {
    switch (cal)
    {
    case '+':
        sum = First + Second;
        break;
    
    case '-':
        sum = First - Second;
        break;
    
    case '*':
        sum = First * Second;
        break;
    
    case '/':
        sum = First / Second;
        break;
    
    default: {
        printf("잘못된 계산입니다. 다시 입력해주세요.\n");
        printf("식 : ");
        scanf(" %d %c %d", &First, &cal, &Second);
    }
        continue;
    }
    } while (cal != '+' && cal != '-' && cal != '/' && cal != '*');
    
    return sum;
}

int quit(char h) {
    int o = 0;
    bool Loop = true;
    do {
    
    o = 0;
    
    switch (h)
    {
    case 'y': {
        o = 1;
        Loop = false;
    }
        break;
    
    case 'n': {
        o = 2;
        Loop = false;
    }
        break;
    
    default: {
        printf("y 또는 n으로 입력해주세요. (y/n) : ");
        scanf(" %c", &h);
        continue;
    }
    }

    } while (Loop);

    return o;
}

int main() {
    int a, b;
    char c;
    int sum, qq = 0;
    char q = 'y';

    printf("계산하고자 하는 사칙연산 식을 입력해주세요.\nEx) : 20 - 20\n");
    do {
    printf("식 : ");
    scanf(" %d %c %d", &a, &c, &b);

    sum = Calc(a, c, b);

    printf("계산 결과 : %d\n", sum);

    printf("다른 계산을 하시겠습니까? (y/n) : ");
    scanf(" %c", &q);

    qq = quit(q);

    switch (qq)
    {
    case 1:
        printf("처음으로 돌아갑니다.\n");
        continue;
        
    case 2:
        printf("프로그램을 종료합니다.\n");
        return 0;
    
    case 3:
        printf("?\n");
        break;
    }
    } while (qq == 1);

    return 0;
}