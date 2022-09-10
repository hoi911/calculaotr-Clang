#include <stdio.h>
#include <stdbool.h>

void ClearBuffer(void)          //입력 버퍼 클리어
{
    while (getchar() != '\n');
}

int Calc(int First, char cal, int Second)           //사칙 연산 함수
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

int quit(char Text) {           //종료 여부 다른 글자 판단 함수
    int Per = 0;
    bool Loop = true;
    do {
    
    Per = 0;
    
    switch (Text)
    {
    case 'y': {
        Per = 1;
        Loop = false;
        break;
    }
    
    case 'n': {
        Per = 2;
        Loop = false;
        break;
    }
    
    default: {
        printf("y 또는 n으로 입력해주세요. (y/n) : ");
        //getchar();
        Text = getchar();
        fflush(stdin);
        continue;
    }
    }

    } while (Loop);

    return Per;
}

int main() {
    int fir, sec;
    char cal;
    int sum, exit = 0;
    char exitChar = 0;

    printf("계산하고자 하는 사칙연산 식을 입력해주세요.\nEx) : 20 - 20\n");
    do {
    printf("식 : ");
    scanf("%d %c %d", &fir, &cal, &sec);

    sum = Calc(fir, cal, sec);

    printf("계산 결과 : %d\n", sum);
    printf("다른 계산을 하시겠습니까? (y/n) : ");

    /*fflush(stdin);
    i = sizeof(getchar());*/
    ClearBuffer();
    //getchar();
    exitChar = getchar();
    //ClearBuffer();
    fflush(stdin);
    exit = quit(exitChar);

    switch (exit)
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
    } while (exit == 1);

    return 0;
}