```c
#include <stdio.h>

#define SIZE 6

int negativos(float *vet, int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (vet[i] < 0) {
      count++;
    }
  }

  return count;
}

void print_array(float *vet, int n) {
  printf("Array:\n");
  for (int i = 0; i < n; i++) {
    printf("%.2f ", vet[i]);
  }
  printf("\n\n");
}

int main() {
  float vet[] = {1.0f, -2.0f, 4.0f, 0.2f, -2.1f, 1.2f};

  print_array(vet, SIZE);

  printf("Qtd de valores negativos = %d\n",
         negativos(vet, sizeof(vet) / sizeof(int)));

  return 0;
}
```
