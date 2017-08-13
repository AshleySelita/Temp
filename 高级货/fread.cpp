#include <ctime>
#include <cctype>
#include <cstdio>

const int L = 10000;
char buf[L], *end = buf, *p = buf;
inline char getChar() {
  if (p == end) {
    if (feof(stdin)) return '\0';
    p = buf;
    end = buf + fread(buf, 1, L, stdin);
  }
  return *(p++);
}
inline int readInt() {
  int ans = 0;
  char c;
  do c = getChar();
  while(!isdigit(c));
  do {
    ans = ans * 10 + c - '0';
    c = getChar();
  } while (isdigit(c));
  return ans;
}
const int N = 10000000;
int A[N];
inline void readInts(int *begin, int *end) {
  bool t = false, t2;
  char c;
  while (begin != end) {
    if (t2 = isdigit(c = getChar()))
      *begin = *begin * 10 + c - '0';
    else if (t)
      ++begin;
    t = t2;
  }
}
int main() {
  //readInts(A, A + N);
  for (int i = 0; i < N; ++i)
    A[i] = readInt();
  printf("%d\n", clock());
  return 0;
}