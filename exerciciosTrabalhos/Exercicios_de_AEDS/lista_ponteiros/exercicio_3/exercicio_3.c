#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __adr__ {
char *avenue;
int number;
char *country;
} __ADRESS__;
typedef struct __record__ {
char *last_name;
char *first_name;
char *middle_name;
__ADRESS__ adr;
} __NAME_AND_ADRESS__;
typedef struct __record_all__ {
__NAME_AND_ADRESS__ name;
int employee_number;
float hours_worked;
} __INPUT_RECORD__;

int main(int argc, char** argv) {

	__INPUT_RECORD__ *ptr_data_input;//declaração do ponteiro

	ptr_data_input = (__INPUT_RECORD__*) calloc( 3, sizeof(__INPUT_RECORD__*));	

	ptr_data_input->name.adr.avenue[100];

	ptr_data_input->name.adr.country[50];

	ptr_data_input->name.last_name[10];

	ptr_data_input->name.first_name[100];

	ptr_data_input->name.middle_name[50];

	ptr_data_input->name.adr.avenue;

	fgets(ptr_data_input->name.adr.avenue, 100, stdin);

	fgets(ptr_data_input->name.first_name, 100, stdin);

	printf("%s\n", ptr_data_input->name.adr.avenue);

	printf("%s\n", ptr_data_input->name.first_name);

	free(ptr_data_input->name.first_name);

	free(ptr_data_input->name.adr.avenue);

	free(ptr_data_input);
}