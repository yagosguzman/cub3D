void	tab_to_space(char *w_map, int *j, int *k)
{
	int nbr_spaces;
	int i;

	i = -1;
	nbr_space = 4 - (j % 4);
	while (++i < nbr_space)
		w_map[(*j)++] = ' ';
	(*k)++;
}