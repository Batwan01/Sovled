#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// ( : 40, ) : 41
//[ : 91, ] : 93
//{ : 123, } : 125
typedef struct Stack {
	int top;
	char word[100];
} Stack;

void init(Stack* s) {
	s->top = -1;
}

void push(Stack* s, char data) {
	if (s->top == 100) { //��ȭ���� Ȯ��
		printf("��ȭ�����Դϴ�.");
		exit(1);
	}
	else s->word[++s->top] = data; //top�� +1�ϰ� data����
}

char pop(Stack* s) {
	if (s->top == -1) { //�������� Ȯ��(���� �����̸� �񱳰��� ���� ���̱� ������ ����)
		return -1;
	}
	else return s->word[s->top--]; //���� ��ȯ�ϰ� top -1
}

int check(Stack* s) {
	int answer = 0;
	char ch;
	char word[100];
	int len = strlen(s->word); //���� ����
	for (int i = 0; i <= len; i++) {
		ch = s->word[i]; //�� ���ڿ� ����

		switch (ch)
		{
		case '(': //���� ��ȣ�� push
			push(s, ch);
			break;
		case '{':
			push(s, ch);
			break;
		case '[':
			push(s, ch);
			break;
		case ')': //���� ��ȣ�� pop
			if (ch - 1 == pop(s)) { answer++; continue; } //���� Ƚ�� ����(���� 0�̸� �۵��� ���� �ʾҴٴ� �ǹ�)
			else return -1;
		case '}':
			if (ch - 2 == pop(s)) { answer++; continue; }
			else return -1;
		case ']':
			if (ch - 2 == pop(s)) { answer++; continue; }
			else return -1;
		}

	}
	if (s->top != -1) return -1; //������ ���������� ����
	if (answer > 0) return 0; //case�� �۵������� ����
	else return -1;//0�̸� ����
}

int main(void) {
	Stack s;
	
	int n=0,m=0;
	scanf("%d", &n);
	while (n != 0) {
		init(&s); //top �ʱ�ȭ
		scanf("%d", &m);
		scanf("%[^\n]s", s.word);
		int a = check(&s);
		if (a == -1) printf("NO\n");
		else printf("YES\n");
		n--;
	}
}