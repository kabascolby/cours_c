#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_sh.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamkaba2 <lamkaba2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/02 16:15:46 by lamkaba2          #+#    #+#              #
#    Updated: 2014/07/02 16:16:16 by lamkaba2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

find . -name "*.sh" -exec basename {} + | sed 's/...$//'