#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_nicolas_bomber.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamkaba2 <lamkaba2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/11 02:02:31 by lamkaba2          #+#    #+#              #
#    Updated: 2015/09/11 02:02:31 by lamkaba2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

grep -i -e '\(nicolas\)\|\(bomber[[:blank:]]nicolas\)' $1
