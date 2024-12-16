/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:01:52 by pda-silv          #+#    #+#             */
/*   Updated: 2024/12/16 19:14:44 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#ifdef BONUS
# include "ft_printf.h"
# else
# include "ft_printf.h"
#endif

#define BREAK	"\n————————————————————————————————————————\n"
typedef struct {
	const char* format;
	void* arg;
} TestCase;

TestCase test_cases[] = {
	{"-->|No Flags|<-- ", NULL},
	{"-->|%c|<-- ", (void*)'A'},
	{"-->|%s|<-- ", (void*)"Hello, world!"},
	{"-->|%p|<-- ", (void*)test_cases},
	{"-->|%d|<-- ", (void*)123},
	{"-->|%i|<-- ", (void*)456},
	{"-->|%u|<-- ", (void*)789},
	{"-->|%x|<-- ", (void*)0xabc},
	{"-->|%X|<-- ", (void*)0xDEF},
	{"-->|%%|<-- ", NULL}
};

TestCase test_cases_bonus[] = {
	{"-->|No Flags|<-- ", NULL},
    {"-->|%c|<-- ", (void*)'B'},
    {"-->|%s|<-- ", (void*)"Bonus test"},
    {"-->|%p|<-- ", (void*)test_cases_bonus},
    {"-->|%d|<-- ", (void*)321},
    {"-->|%i|<-- ", (void*)654},
    {"-->|%u|<-- ", (void*)987},
    {"-->|%x|<-- ", (void*)0x123},
    {"-->|%X|<-- ", (void*)0x456},
    {"-->|%%|<-- ", NULL},
    {"-->|%-10d|<-- ", (void*)123},
    {"-->|%+d|<-- ", (void*)123},
    {"-->|% d|<-- ", (void*)123},
    {"-->|%#x|<-- ", (void*)0xabc},
    {"-->|%010d|<-- ", (void*)123},
    {"-->|%10.5d|<-- ", (void*)123},
    {"-->|%.5s|<-- ", (void*)"Hello, world!"},
    {"-->|%-10s|<-- ", (void*)"Left"}
};

typedef enum e_test
{
	MANDATORY,
	BONUS,
	OTHER
}	t_test;

static void	test_log_append(const char *str);
static void	test_mandatory(void);
static void test_bonus(void);

int			main(int argc, char *argv[])
{
	t_test	test = MANDATORY;

	if (argc > 1 && !strcmp(argv[1], "bonus"))
		test = BONUS;
	else if(argc > 1 && !strcmp(argv[1], "other"))
		test = OTHER;
	
	if (test == OTHER)
	{
		int	a;
		int	b;

		a = printf("o:%c$", 'a');
		ft_printf("\n");
		b = ft_printf("f:%c$", 'a');
		ft_printf("\n");
		ft_printf("size og: %d\n", a);
		ft_printf("size ft: %d\n", b);
	}
	else
	{
		FILE *log_file = freopen("results.log", "a", stdout);
		if (!log_file)
		{
			perror("freopen");
			return 1;
		}

		test_log_append(BREAK);
		
		if (test == BONUS)
			test_bonus();
		else
			test_mandatory();


		if (log_file)
			fclose(log_file);

		test_log_append(BREAK);
		test_log_append("\n");
	}
	
	return (0);
}

static void	test_log_append(const char *str)
{
	FILE	*file = fopen("results.log", "a");
	if (file != NULL)
	{
		fprintf(file, "%s", str);
		fclose(file);
	}
}

static void	test_mandatory(void)
{
	int		ret, ret_ft;
	int		error_count = 0;
	int		tests = (int)(sizeof(test_cases) / sizeof(test_cases[0]));
	int		error_indices[tests];
	
	for (int i = 0; i < tests; i++)
	{
		printf("\nTest case: %s\n", test_cases[i].format);
		printf("\n%-18s: ","Printf output");
		// Control:
		ret = printf(test_cases[i].format, test_cases[i].arg);
		printf("\n%-18s: ","Ft_printf output");
		fflush(stdout);
		// Test:
		ret_ft = ft_printf(test_cases[i].format, test_cases[i].arg);
		fflush(stdout);
		printf("\n\n%-14s: %d","Printf len", ret);
		printf("\n%-14s: %d\n","Ft_printf len", ret_ft);
		fflush(stdout);

		if (ret != ret_ft)
			error_indices[error_count++] = i;

		test_log_append(BREAK);
	}
	
    printf("\nTests: %d\t\tErrors: %d\n", tests, error_count);
	
    if (error_count > 0)
    {
        printf("\tFailing test cases:\n");
        for (int i = 0; i < error_count; i++)
            printf("\t\tTest case %d: %s\n", error_indices[i], test_cases_bonus[error_indices[i]].format);
    }
}

static void test_bonus(void)
{
	int		ret, ret_ft;
	int		error_count = 0;
	int		tests = (int)(sizeof(test_cases_bonus) / sizeof(test_cases_bonus[0]));
	int		error_indices[tests];
	
	for (int i = 0; i < tests; i++)
	{
		printf("\nTest case: %s\n", test_cases_bonus[i].format);
		printf("\n%-18s: ","Printf output");
		// Control:
		ret = printf(test_cases_bonus[i].format, test_cases_bonus[i].arg);
		printf("\n%-18s: ","Ft_printf output");
		fflush(stdout);
		// Test:
		ret_ft = ft_printf(test_cases_bonus[i].format, test_cases_bonus[i].arg);
		fflush(stdout);
		printf("\n\n%-14s: %d","Printf len", ret);
		printf("\n%-14s: %d\n","Ft_printf len", ret_ft);
		fflush(stdout);

		if (ret != ret_ft)
			error_indices[error_count++] = i;

		test_log_append(BREAK);
	}
	
    printf("\nTests: %d\tErrors: %d\n", tests, error_count);
	
    if (error_count > 0)
    {
        printf("Failing test cases:\n");
        for (int i = 0; i < error_count; i++)
            printf("\tTest case %d: %s\n", error_indices[i], test_cases_bonus[error_indices[i]].format);
    }
}