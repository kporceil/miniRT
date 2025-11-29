/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:32:33 by kporceil          #+#    #+#             */
/*   Updated: 2025/11/28 13:44:17 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "libft.h"
#include "tests.h"

static void	integer_test(__unused void **state)
{
	char*	nptr = "12";
	char*	endptr;

	assert_double_equal(12, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 2);
}

static void	double_test(__unused void **state)
{
	char*	nptr = "12.15";
	char*	endptr;

	assert_double_equal(12.15, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 5);
}

static void	zero_integer_test(__unused void **state)
{
	char*	nptr = "0";
	char*	endptr;

	assert_double_equal(0, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 1);
}

static void	zero_double_test(__unused void **state)
{
	char*	nptr = "0.00";
	char*	endptr;

	assert_double_equal(0, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 4);
}

static void	char_after_nbr_test(__unused void **state)
{
	char*	nptr = "1.15blabla";
	char*	endptr;

	assert_double_equal(1.15, ft_strtod(nptr,&endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 4);
}

static void	char_before_nbr_test(__unused void **state)
{
	char*	nptr = "blabla1.15";
	char*	endptr;
	
	assert_double_equal(0, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr);
}

static void	whitespace_before_nbr_test(__unused void **state)
{
	char*	nptr = "                  \n\n\n\n1.15";
	char*	endptr;

	assert_double_equal(1.15, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 26);
}

static void	negative_nbr_test(__unused void **state)
{
	char*	nptr = "-12.56";
	char*	endptr;

	assert_double_equal(-12.56, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr + 6);
}

static void	invalid_negative_nbr_test(__unused void **state)
{
	char	*nptr = "-12.-56";
	char	*endptr;

	assert_double_equal(-12, ft_strtod(nptr, &endptr), 0.0001);
	assert_ptr_equal(endptr, nptr);
}

int	test_ft_strtod(void)
{
	const struct CMUnitTest	ft_strtod_tests[] = {
		cmocka_unit_test(integer_test),
		cmocka_unit_test(double_test),
		cmocka_unit_test(zero_integer_test),
		cmocka_unit_test(zero_double_test),
		cmocka_unit_test(char_after_nbr_test),
		cmocka_unit_test(char_before_nbr_test),
		cmocka_unit_test(whitespace_before_nbr_test),
		cmocka_unit_test(negative_nbr_test),
		cmocka_unit_test(invalid_negative_nbr_test),
	};
	return (cmocka_run_group_tests(ft_strtod_tests, NULL, NULL));
}
