/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:39:51 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/03 17:49:31 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

int	main(int argc, char **argv)
{
	char	str[100];
	int		listen_fd;
	int 	status;
    if (argc != 2 || (argc == 2 && (atoi(argv[1]) < 1024 || atoi(argv[1]) > 65535)))
    {
        fprintf(stderr, "Invalid port, enter (1024 - 65535.)\n");
        return (-1);
    }
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);
	server_address.sin_port = htons(atoi(argv[1]));
	bind(listen_fd, (struct sockaddr *) &server_address, sizeof(server_address));
	listen(listen_fd, 10);
	status = accept(listen_fd, (struct sockaddr*) NULL, NULL);
	while (1)
	{
		bzero(str, 100);
		read(status,str,100);
		if (status)
		{
			fprintf(stdout,"CLIENT:\n");
			fprintf(stdout,"%s",str);
		}
		if ((strcmp(str, "ping\n")) == 0)
			write(status, "pong\npong\n", 11);
        else
			write(status, str, strlen(str)+1);
	}
	return (0);
}
