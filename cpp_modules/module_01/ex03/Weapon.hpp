/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:36:03 by csamakka          #+#    #+#             */
/*   Updated: 2026/10/27 11:36:07 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		const std::string& getType() const;
		void	setType(std::string const& type);
		Weapon(std::string const& type);
};
#endif