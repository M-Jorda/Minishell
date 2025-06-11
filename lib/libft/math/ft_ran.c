/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ran.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:52:29 by jjorda            #+#    #+#             */
/*   Updated: 2025/02/19 20:18:31 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <time.h> // You can initialize with any non-zero value

/**
 * @brief Generates a random number within a specified range.
 *
 * This function generates a pseudo-random number between the given minimum
 * and maximum values (inclusive). It uses a linear congruential generator
 * (LCG) algorithm for the random number generation.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return A random number between min and max (inclusive). If min is greater
 *         than max, the function returns LONG_MAX. If min is equal to max,
 *         the function returns min.
 */
long	ft_ran(int min, int max)
{
	static unsigned long long	random_seed;

	if (min > max)
		return (LONG_MAX);
	if (min == max)
		return (min);
	if (random_seed == 0)
		random_seed = time(NULL);
	random_seed = (1103515245ULL * random_seed + 12345ULL) % 2147483648ULL;
	return (min + (random_seed % (max - min + 1)));
}
