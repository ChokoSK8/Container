/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_empty.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:38:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 14:39:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_Utils.hpp"

int	main	(void)
{
	NAMESPACE::vector<int>	v;

	PRINT_EXECUTE(*(v.begin()));
}
