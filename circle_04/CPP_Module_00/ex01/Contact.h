/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:56:27 by nsaillez          #+#    #+#             */
/*   Updated: 2025/09/03 08:17:36 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

class Contact {
	private:
		void force_fill(std::string& obj_var,const std::string& name);
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
		std::string darkestsecret;
		bool is_set;
	public:
		Contact()
		{
			is_set = false;
		}
		void fill_form();
		bool isSet();
		std::string get_firstname();
		std::string get_lastname();
		std::string get_nickname();
		std::string get_phonenumber();
		std::string get_darkestsecret();
};