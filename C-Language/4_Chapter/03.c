#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Division by zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                op1 = pop();
                push(op1 - op2 * floor(op1 / op2));
            }
            else
                printf("Division by zero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Unknown operation %s\n", s);
            break;
        }
    }

    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Stack oversized: can't push %f value\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("No value to pop\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i = 0, c, t;
    while ((s[i] = c = getch()) == ' ' || c == '\t')
        ;
    if (!isdigit(c) && c != '.')
    {
        if (c == '-')
        {
            if (isdigit(t = getch()) || t == '.')
            {
                c = t;
                s[++i] = c;
            }
            else
            {
                ungetch(t);
                return c;
            }
        }
        else
        {
            return c;
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: oversize\n");
    else
        buf[bufp++] = c;
}