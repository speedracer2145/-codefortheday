//Program NO 1
#include <stdio.h>
struct student {
  char name[100];
  int m[5];
} s1;
void main() {
  float p;
  fgets(s1.name, 100, stdin);
  for (int i = 0; i < 5; i++) {
    scanf("%d", &s1.m[i]);
  }
 p=( (float)(s1.m[0]+s1.m[1]+s1.m[2]+s1.m[3]+s1.m[4])/5);
  printf("Name: %s", s1.name);
  printf("Total: %d \n", s1.m[0]+s1.m[1]+s1.m[2]+s1.m[3]+s1.m[4]);
  printf("Percentage: %0.2f",p);
}