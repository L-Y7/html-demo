#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

/************** 线性表（顺序表） **************/
typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

void initList(SeqList *L) {
    L->length = 0;
}

void insertList(SeqList *L, int x) {
    if (L->length < MAXSIZE) {
        L->data[L->length++] = x;
    }
}

void printList(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

/************** 栈（用于括号匹配） **************/
char stack[MAXSIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int match(char a, char b) {
    return (a=='('&&b==')') || (a=='['&&b==']') || (a=='{'&&b=='}');
}

int bracketMatch(char str[]) {
    top = -1;   // 重置栈
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{') {
            push(str[i]);
        } else if (str[i]==')' || str[i]==']' || str[i]=='}') {
            if (top == -1 || !match(pop(), str[i])) {
                return 0;
            }
        }
    }
    return top == -1;
}

/************** 主函数 **************/
int main() {

    printf("=== 顺序表测试 ===\n");
    SeqList L;
    initList(&L);

    insertList(&L, 10);
    insertList(&L, 20);
    insertList(&L, 30);

    printf("顺序表内容：");
    printList(L);

    printf("\n=== 括号匹配测试 ===\n");
    char str[MAXSIZE];
    printf("请输入括号字符串：");
    scanf("%s", str);

    if (bracketMatch(str)) {
        printf("括号匹配正确\n");
    } else {
        printf("括号不匹配\n");
    }

    return 0;
}

