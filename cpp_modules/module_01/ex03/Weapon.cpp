/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:35:54 by csamakka          #+#    #+#             */
/*   Updated: 2026/10/27 11:38:01 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(std::string const& type)
{
	_type = type;
}

Weapon::Weapon(std::string const& type): _type(type) {}
