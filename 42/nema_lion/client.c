/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:51:00 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/03 17:52:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra.h"

int main(int argc,char **argv)
{
    int     net_socket,n;
    int     status;
    char    sendline[100];
    char    recvline[100];
    
    if (argc != 2 || (argc == 2 && (atoi(argv[1]) < 1024 || atoi(argv[1]) > 65535)))
    {
        fprintf(stderr, "Invalid port, enter (1024 - 65535.)\n");
        return (-1);
    }
    net_socket=socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_address,sizeof server_address);
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = INADDR_ANY;
   
    status = connect(net_socket,(struct sockaddr *)&server_address,sizeof(server_address));
    if (status == -1)
    {
        fprintf(stderr, "Connection error\n");
        return 0;
    }
    while(1)
    {
        bzero(sendline, 100);
        bzero(recvline, 100);
        fgets(sendline, 100, stdin);
        write(net_socket, sendline, strlen(sendline)+1);
        read(net_socket, recvline, 100);
        printf("%s",recvline);
    }
    return (0);
}
