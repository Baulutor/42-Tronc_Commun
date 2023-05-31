/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:25:41 by dbaule            #+#    #+#             */
/*   Updated: 2023/05/16 17:47:48 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv)
{
    int		id;
    int		fd[2];
    int		startfd;
    int		outfd;

    if (argc != 5)
        return (1);
    if (pipe(fd) == -1)
        return (perror("pipe"), 1);
    id = fork();
    if (id == 0)
    {
        close(fd[0]);
        startfd = open(argv[1], O_RDONLY);
        if (startfd == -1)
            return(perror("open") , 1);
        if (dup2(startfd, STDIN_FILENO) == -1)
            return (perror("dup2"), 1);
        if ( dup2(fd[1], STDOUT_FILENO == -1))
            return (perror("dup2"), 1);
        close(startfd);
        if (exec_hub(argv[2]) == -1)
            return(1);
    }
    else
    {
        wait(NULL);
        close(fd[1]);
        outfd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH);
        if (outfd == -1)
            return(perror("open"), 1);
        if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfd, STDOUT_FILENO) == -1)
            return(perror("dup2"), 1);
        close(outfd);
        if (exec_hub(argv[3]) == -1)
            return(1);
    }
}