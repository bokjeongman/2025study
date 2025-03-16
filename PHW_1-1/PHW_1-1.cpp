/*
	File: PHW_1-1.cpp
	Name : ╪шеб╠т
	Stundent Number : 202235063
	Date : 2025/03/15
	Summary of this File :
	This is the program that has 5 functions(enqueue, dequeue, queue_full, queue_empty, print_queue) and you can choice the number to en/dequeue
	//  10+ 50+ 20+ 70+ 10- 100+ 40+ 140+(x) 50- 20- 70-  main function have to excute this array of numbers in ppt page 59-60.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5 // MAX queue size

int queue[MAX];
int front = -1;
int rear = -1;
int count = 0;
int choice = 0;
int numbers[20] = {};

int queue_full() { // Check if queue is full, return 1 or 0
	if (count == MAX)
		return 1;
	else
		return 0;
}

int queue_empty() { // Check if queue is empty, return 1 or 0
	if (count == 0)
		return 1;
	else
		return 0;
}

int enqueue(int value) { // enqueue the number to queue, and update front, rear and count value
	if (count == 0)
		front = rear = 0;
	else
		rear = (rear + 1) % MAX;
	queue[rear] = value;
	count++;
	return queue[rear];
}

int dequeue() { // dequeue the number to queue, and update front, rear and count value
	int value = queue[front];
	count--;
	if (count == 0) // front == back, queue is empty
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front + 1) % MAX;
	return value;
}

void overwrite(int value) {

	queue[(rear + 1) % MAX] = value;
	rear = (rear + 1) % MAX;
}

void print_queue() { // print the queue
	printf("\n\nElements in Circular Queue are : ");

	if (((rear + 1) % MAX) >= front)
	{
		for (int i = front; i <= rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	else
	{
		for (int i = front; i < MAX; i++)
		{
			printf("%d ", queue[i]);
		}
		for (int i = 0; i <= rear; i++)
		{
			printf("%d ", queue[i]);
		}
	}
	printf("\n\n");
}

void main() { // main function can choice that you can en/dequeue number you want and print queue + shut the program!
	printf("Hello! I like your choice Please choice the number (0, 1, 2)");
	printf("\nIf enter 0, I will call enqueue function but if queue is full, you can't");
	printf("\nIf enter 1, I will call dequeue function but if queue is empty, you can't");
	printf("\nIf you want to stop, enter 2\n");

	while (choice != 2) // if you not choice 2, you can en/dequeue numbers you want but max size is 5 
	{					// if you choice 2, the program will print the queue and shut the program
		printf("\nYour choice : ");
		scanf("%d", &choice); // choice the number (0(enqueue), 1(dequeue), 2(print queue and shut the program)
		if (choice == 0) // choice is 0, enequeue the number
		{
			if (queue_full() != 1) // Check if queue is full or not and enqueue
			{
				int i = 0;
				printf("Enter a number you want to enqueue : ");
				scanf("%d", &numbers[i]);
				int k = enqueue(numbers[i]);
				printf("New number %d enqueue", k);
				i++;
			}
			else // If queue is full, you can't enqueue the number
			{
				printf("You can't enqueue that value because queue is full!");
			}
		}
		else if (choice == 1) // choice is 1, dequeue the queue[front] value
		{
			if (queue_empty() != 1) // Check if queue is empty and dequeue
			{
				printf("Dequeue the value : ");
				printf("Number %d dequeue", dequeue());
			}
			else // If queue is empty, you can't dequeue the number
			{
				printf("You can't dequeue because queue is empty!");

			}
		}
	}
	printf("You entered 2 so I will print the queue and shut the program. Goodbye.");
	print_queue(); // print the queue

}