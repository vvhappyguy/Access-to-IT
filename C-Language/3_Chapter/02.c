#include <stdio.h>

int escape(char *s, char *t);
int unescape(char *s, char *t);

int main() {

  return 0;
}

int unescape(char *s, char *t) {

  int i;
  int j;

  for (i = 0, j = 0; s[i] != '\0'; i++) {

    if (s[i] != '\\')
      t[j++] = s[i];
    else
      switch (s[++i]) {
      case 'a': 
        t[j++] = '\a';
        break;
      case 'b':
        t[j++] = '\b';
        break;
      case 'f': 
        t[j++] = '\f';
        break;
      case 'n': 
        t[j++] = '\n';
        break;
      case 'r': 
        t[j++] = '\r';
        break;
      case 't': 
        t[j++] = '\t';
        break;
      case 'v':
        t[j++] = '\v';
        break;
      case '\'': 
        t[j++] = '\'';
        break;
      case '"': 
        t[j++] = '\"';
        break;
      case '?': 
        t[j++] = '\?';
        break;
      default:
        t[j++] = s[i];
      } 

    t[j] = '\0';
  } 

  return 0;
}

int escape(char *s, char *t) {
  int i = 0;
  int j = 0;

  for (i, j; s[i] != '\0'; i++)
    switch (s[i]) {
    case '\a':
      t[j++] = '\\';
      t[j++] = 'a';
      break;
    case '\b':
      t[j++] = '\\';
      t[j++] = 'b';
      break;
    case '\f':
      t[j++] = '\\';
      t[j++] = 'f';
      break;
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\r':
      t[j++] = '\\';
      t[j++] = 'r';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    case '\v':
      t[j++] = '\\';
      t[j++] = 'v';
      break;
    case '\\':
      t[j++] = '\\';
      t[j++] = '\\';
      break;
    case '\'':
      t[j++] = '\\';
      t[j++] = '\'';
      break;
    case '\"':
      t[j++] = '\\';
      t[j++] = '\"';
      break;
    case '\?':
      t[j++] = '\\';
      t[j++] = '?';
      break;
    default:
      t[j++] = s[i];
    }

  t[j++] = '\0';
  return 0;
}