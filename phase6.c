#include <stdio.h>
#include <stdlib.h>


typedef struct s_list {
	int i1;
	int i2;
	struct s_list *next;
} t_list;

t_list node6 = {0x1B0,0,NULL};
t_list node5 = {0xD4,0,&node6};
t_list node4 = {0x3E5,0,&node5};
t_list node3 = {0x12D,0,&node4};
t_list node2 = {0x2D5,0,&node3};
t_list node1 = {0xFD,0,&node2};

void explode_bomb(void)
{
	printf("BOOM\n");
	exit(1);
}

void read_six_numbers(char *input, int numbers[6])
{
	sscanf(input,"%d %d %d %d %d %d",&numbers[0],&numbers[1],&numbers[2],&numbers[3],&numbers[4],&numbers[5]);
}

int main(int argc, char **argv)
{
	char *input = argv[1];

	int index;
	t_list *list;
	t_list *local_34;
	t_list *nodeForSetup [5];
	int numbers [6];
	t_list *currentNode;
	int i;
	t_list *intptr;
	
	list = &node1;
	read_six_numbers(input,numbers);
	
	printf("Numbers: ");
	for (int x = 0; x < 6; x++) {
		printf("%d ",numbers[x]);
	}
	printf("\n");

	index = 0;
	do {
										/* Every number is [1;6] */
		i = index;
		if (5 < numbers[index] - 1U) {
			explode_bomb();
		}
										/* No repeat number */
		while (i = i + 1, i < 6) {
			if (numbers[index] == numbers[i]) {
				explode_bomb();
			}
		}
		index = index + 1;
										/*			*/
	} while (index < 6);

	printf("Array creation\n");
	index = 0;
	do {
		printf("============== Checking %d ===============\n",index);
		printf("Numbers[%d] = %d\n",index,numbers[index]);
		i = 1;
		currentNode = list;
		if (numbers[index] > 1) {
			do {
				printf("next\n");
				currentNode = currentNode->next;
				i = i + 1;
			} while (i < numbers[index]);
		}
		printf("setting nodeForSetup[%d]\n",index - 1);
		if (index == 0) {
			local_34 = currentNode;
		} else {
			nodeForSetup[index + -0x1] = currentNode;
		}
		index = index + 1;
	} while (index < 6);
	printf("Array creation done\n");
										/*			 */

	printf("List creation\n");
	index = 1;
	currentNode = local_34;
	printf("currentNode = %p\n",currentNode);
	do {
		printf("Index %d\n",index);
		intptr = nodeForSetup[index + -1];
		printf("Got %p\n",intptr);
		currentNode->next = intptr;
		currentNode = intptr;
		index = index + 1;
	} while (index < 6);
	intptr->next = (t_list *)0x0;
	printf("List creation done\n");

	printf("======= Printing List ========\n");
	t_list* local_34e = local_34;
	do {
		printf("i1: %d\n",local_34e->i1);
		local_34e = local_34e->next;
	} while (local_34e != (t_list *)0x0);
	printf("======= End of List ========\n");
										/*				*/
	index = 0;
	do {
		printf("Doing check %d/5\n",index);
		printf("Is %d < %d?\n",local_34->i1,local_34->next->i1);
		if (local_34->i1 < local_34->next->i1) { // node4 node2 node3 node1 node5
			explode_bomb();
		}
		local_34 = local_34->next;
		index = index + 1;
	} while (index < 5);
	printf("YAY\n");
}
