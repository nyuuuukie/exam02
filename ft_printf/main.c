#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *format, ... );

void string_test()
{
	ft_printf("|%15.5s|\n", "hello!");
	printf("|%15.5s|\n", "hello!");

	ft_printf("|%15.s|\n", "hello!");
	printf("|%15.s|\n", "hello!");

	ft_printf("|%15s|\n", "hello!");
	printf("|%15s|\n", "hello!");

	ft_printf("|%15s|\n", NULL);
	printf("|%15s|\n", NULL);

	ft_printf("|%15.s|\n", NULL);
	printf("|%15.s|\n", NULL);

	char *str = NULL;
	ft_printf("|%15.3s|\n", str); //invalid case
	printf("|%15.3s|\n", str);
}

void digit_test()
{
	ft_printf("|%15.4d|\n", 43);
	printf("|%15.4d|\n", 43);
	
	ft_printf("|%15.d|\n", 42);
	printf("|%15.d|\n", 42);
	
	ft_printf("|%15d|\n", 41);
	printf("|%15d|\n", 41);
	
	ft_printf("|%15.4d|\n", -43);
	printf("|%15.4d|\n", -43);
	
	ft_printf("|%15.d|\n", -42);
	printf("|%15.d|\n", -42);
	
	ft_printf("|%15d|\n", -41);
	printf("|%15d|\n", -41);
	
	ft_printf("|%15.0d|\n", 43);
	printf("|%15.0d|\n", 43);
	
	ft_printf("|%15.d|\n", 0);
	printf("|%15.d|\n", 0);
}

void hex_test()
{
	ft_printf("|%15.4x|\n", 43);
	printf("|%15.4x|\n", 43);
	
	ft_printf("|%15.x|\n", 42);
	printf("|%15.x|\n", 42);
	
	ft_printf("|%15x|\n", 41);
	printf("|%15x|\n", 41);
	
	ft_printf("|%15.4x|\n", -43);
	printf("|%15.4x|\n", -43);
	
	ft_printf("|%15.x|\n", -42);
	printf("|%15.x|\n", -42);
	
	ft_printf("|%15x|\n", -41);
	printf("|%15x|\n", -41);
	
	ft_printf("|%15.0x|\n", 43);
	printf("|%15.0x|\n", 43);
	
	ft_printf("|%15.x|\n", 0);
	printf("|%15.x|\n", 0);
}

int main(void)
{
	//STRING

	printf("############# STRING ###############\n");
	string_test();	

	//DIGITAL

	printf("############# DIG ###############\n");
	digit_test();
	
	//HEX
	printf("############### HEX ###########\n");
	hex_test();
	
	return (0);
}