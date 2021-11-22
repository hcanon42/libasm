/******************************************************************************/
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcanon <hcanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 00:56:42 by hcanon            #+#    #+#             */
/*   Updated: 2020/07/09 10:31:42 by user42           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libasm.h"

void	test_write(void)
{
	int	fd;

	fd = open("text.txt", O_WRONLY);
	printf("\n\nwrite\n");
	printf("-------------------MINE-------------------\n");
	printf("%ld \n", ft_write(1, "Hello", 0));
	printf("%ld \n", ft_write(1, "Hello", 5));
	printf("%ld \n", ft_write(fd, "This is a test", 10));
	printf("%ld \n", ft_write(42, "No idea anymore", 3));
	printf("ERRNO = %d \n", errno);
	printf("-------------------TRUE-------------------\n");
	printf("%ld \n", write(1, "Hello", 0));
	printf("%ld \n", write(1, "Hello", 5));
	printf("%ld \n", write(fd, "This is a test", 10));
	printf("%ld \n", write(42, "No idea anymore", 3));
	printf("ERRNO = %d \n", errno);
}

void	test_read(void)
{
	char	buffer[100];
	int		fdm;
	int		fdt;

	fdm = open("ft_read.s", O_RDONLY);
	fdt = open("ft_read.s", O_RDONLY);
	printf("\n\nread\n");
	printf("-------------------MINE-------------------\n");
	printf("%ld \n", ft_read(0, buffer, 8));
	printf("%.8s\n", buffer);
	printf("%ld \n", ft_read(fdm, buffer, 15));
	printf("%.15s\n", buffer);
	printf("%ld \n", ft_read(42, buffer, 0));
	printf("%.0s\n", buffer);
	printf("ERRNO = %d \n", errno);
	printf("-------------------TRUE-------------------\n");
	printf("%ld \n", read(0, buffer, 8));
	printf("%.8s\n", buffer);
	printf("%ld \n", read(fdt, buffer, 15));
	printf("%.15s\n", buffer);
	printf("%ld \n", read(42, buffer, 0));
	printf("%.0s\n", buffer);
	printf("ERRNO = %d \n", errno);
}

void	test_strdup(void)
{
	char *dst;

	dst = NULL;
	printf("\n\nstrdup\n");
	printf("-------------------MINE-------------------\n");
	printf("%s \n", (dst = ft_strdup("")));
	free(dst);
	printf("%s \n", (dst = ft_strdup("Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld \nThis is me!")));
	free(dst);
	printf("-------------------TRUE-------------------\n");
	printf("%s \n", (dst = strdup("")));
	free(dst);
	printf("%s \n", (dst = strdup("Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld \nThis is me!")));
	free(dst);
}

void	test_strlen(void)
{
	printf("\nstrlen\n");
	printf("-------------------MINE-------------------\n");
	printf("%zu \n", ft_strlen(""));
	printf("%zu \n", ft_strlen("bonjour"));
	printf("%zu \n", ft_strlen("Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld !"));
	printf("-------------------TRUE-------------------\n");
	printf("%zu \n", strlen(""));
	printf("%zu \n", strlen("bonjour"));
	printf("%zu \n", strlen("Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld !"));
}

void	test_strcpy(void)
{
	char dst[300];

	printf("\n\nstrcpy\n");
	printf("-------------------MINE-------------------\n");
	printf("%s \n", ft_strcpy(dst, ""));
	printf("%s \n", ft_strcpy(dst, "bonjour"));
	printf("%s \n", ft_strcpy(dst, "Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld !"));
	printf("-------------------TRUE-------------------\n");
	printf("%s \n", strcpy(dst, ""));
	printf("%s \n", strcpy(dst, "bonjour"));
	printf("%s \n", strcpy(dst, "Hello Woooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorld !"));
}

void	test_strcmp(void)
{
	printf("\n\nstrcmp\n");
	printf("-------------------MINE-------------------\n");
	printf("%d \n", ft_strcmp("", "bonjour"));
	printf("%d \n", ft_strcmp("bonjour", ""));
	printf("%d \n", ft_strcmp("bonjour", "bonjoir"));
	printf("%d \n", ft_strcmp("\200", "\0"));
	printf("%d \n", ft_strcmp("Aello World !", "H"));
	printf("-------------------TRUE-------------------\n");
	printf("%d \n", strcmp("", "bonjour"));
	printf("%d \n", strcmp("bonjour", ""));
	printf("%d \n", strcmp("bonjour", "bonjoir"));
	printf("%d \n", strcmp("\200", "\0"));
	printf("%d \n", strcmp("Aello World !", "H"));
}

int	main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return (0);
}
