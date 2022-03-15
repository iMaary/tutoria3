#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define  QNT_THREADS 3
int array_size = 0;

void *average(int *numbers)
{
	int sum = 0;
	for (int i = 0; i < array_size; i++)
		sum += numbers[i];
	printf("The average value is %d\n", (int)sum/array_size);
	
	return NULL;
}

void *miniNum(int *numbers)
{
	int lowest = 0;

	for (int i = 0; i < array_size; i++) {
		if (i == 0 || numbers[i] < lowest)
			lowest = numbers[i];
	}
	printf("The minimum value is %d\n", lowest);

	return NULL;
}

void *maxNum(int *numbers)
{
	int biggest = 0;

	for (int i = 0; i < array_size; i++) {
		if (numbers[i] > biggest)
			biggest = numbers[i];
	}
	printf("The maximum value is %d\n", biggest);

	return NULL;
}

int main()
{
	pthread_t threads[QNT_THREADS];

	scanf("%d", &array_size);
  int inputed_numbers[array_size];

	for (int i = 0; i < array_size; i++)
		scanf("%d", &inputed_numbers[i]);

	pthread_create(&threads[0], NULL, average, inputed_numbers);
	pthread_create(&threads[1], NULL, miniNum, inputed_numbers);
	pthread_create(&threads[2], NULL, maxNum, inputed_numbers);

	for (int i = 0; i < QNT_THREADS; i++)
		pthread_join(threads[i], NULL);

	return 0;
}