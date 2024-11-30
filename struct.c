#include <stdio.h>  
#include <stdlib.h>
#include <string.h>  
#include <inttypes.h>

struct Person{
	char  nome[10];
	uint8_t age;
	uint8_t height;
	
};

void createPerson( char name[],
	uint8_t age,
	uint8_t height,
	void(*function_pointer)(struct Person)) {
		struct Person person;
		strcpy(person.nome, "Fabio");
		person.age = 43;
		person.height = 172;
		(*function_pointer)(person);
		
	}
	
void printPerson(struct Person person) 
{
	printf("Person: %s %d %d\n", person.nome, person.age, person.height);
}
	
void main(){

	createPerson("Fabio", 43, 172, &printPerson);
	createPerson("gtb", 18, 172, &printPerson);
	return;
}
