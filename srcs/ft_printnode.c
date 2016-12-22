#include "lem_in.h"

void		ft_printnode(t_node *nodedummie)
{
	t_node *nodetmp;
	t_node *nodetmp1;
	nodetmp = nodedummie;
	while(nodetmp)
	{
		nodetmp1 = nodetmp;
		while (nodetmp)
		{
			printf("%s ",nodetmp->name);
			nodetmp = nodetmp->nextr;
		}
		printf("\n");
		nodetmp = nodetmp1;
		nodetmp = nodetmp->nextl;
	}
}
