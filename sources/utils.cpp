#include <iostream>

void	display_set(fd_set set)
{
	int	i = 0;

	std::cout << "ready fd: ";
	while (set.fds_bits[i])
	{
		for (int j = 0; j < 64; j++)
		{
			if ((set.fds_bits[i] >> j) % 2)
				std::cout << i * 64 + j << ", ";
		}
		i++;
	}
	std::cout << std::endl;
}
