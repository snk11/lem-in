/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:02:24 by syusof            #+#    #+#             */
/*   Updated: 2016/10/05 15:42:03 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"





#include <stdio.h>
void ft_proceed(t_node *node1,t_node **processnodes,t_node **path1begi,char *strbegi,char *strend)
{

	//	t_node		*nodetmp;
//	*path1begi = NULL;
	//	nodetmp = node1;
	int ind1;
	ind1 = 0;
	*processnodes = lst_add_downl(processnodes,"0");
//		ft_search1(node1,node1,strend,path1begi,0,strbegi,&ind1);
//	ft_solv(node1,node1,strend,path1begi,strbegi,&ind1);
	ft_roam(node1,processnodes,path1begi,strend,strbegi,&ind1);
}

/*
void	ft_search1(t_node *node1,t_node *noderef,char *strend,t_node **path1begi,int nbelem,char *strbegi,int *ind1)
{
	int	ind2;
	int	ind3;
	int	ind5;
	int	ind6;
	int	p;
	int	nbelem1;
	t_node	*nodetmp;
	t_node	*nodeinit;
	t_node	*path1;

	ind2 = 0;
	ind3 = 0;
	ind5 = 0;
	ind6 = 0;
	p = 0;
	nodeinit = NULL;
	nbelem1 = nbelem;
	path1 = *path1begi;

	printf("search %s\n",noderef->name);
	nodetmp = node1;
	while (nodetmp && ind2 == 0)
	{
		if(ft_strcmp((nodetmp->name),(noderef->name)) == 0)
			ind2 = 1;
		else
			nodetmp = nodetmp->nextl;
	}
	nodetmp = nodetmp->nextr;
	if(nodetmp)
	{
		while(nodetmp)
		{
			printf("donc search %s\n",nodetmp->name);
			if(*ind1 == 0 && ind6 == 0)
				*path1begi = lst_add_downlrnew(path1begi,p,strbegi);
			ft_printfpath(*path1begi);
			if (ind6 == 1)
			{
				ind6 = 0;
				*path1begi = lst_add_downlrnew_minus(path1begi,p,strbegi);
			}
			ind5 = 0;
			printf("p = %d\n",p);
			printf("\ntour boucle  ");
			printf("sur le suivant de  %s\n",nodetmp->name);
			if (nodetmp)
				printf("nodetmp evalued = %s\n",nodetmp->name);
			//					if(ft_checknew(*path1begi))
			//					{
			//						printf("new\n");
			//					if(ft_strcmp(strbegi,nodetmp->name) != 0)
			//							*path1begi = lst_add_downlrnewminus(path1begi,p,strbegi);
			//						ind5 = 1;
			//					}
			//					ind1 = 0;
			path1 = *path1begi;
			while (path1->nextl)
				path1 = path1->nextl;
			ft_printfpath(*path1begi);
			if(nodetmp && ft_checknode(path1,nodetmp->name) == 1 && ind5 == 0)
			{
				printf("gg\n");
				lst_add_down_downr(path1begi,nodetmp->name);
				if(ft_strcmp(nodetmp->name,strend) == 0)
				{
					*ind1 = 0;
					printf("RR %s\n\n",nodetmp->name);
					ind3 = 1;
					ind6 = 1;
//					lst_add_down_downr(path1begi,"");
				}
				else
				{
					printf("FT_SEARCH\n");
					*ind1 = 1;
					ft_search1(node1,nodetmp,strend,path1begi,nbelem1,strbegi,ind1);
				}
			}
			else
			{
				printf("NOO\n");
				*ind1 = 1;
			}
			p++;
			nodetmp = nodetmp->nextr;
		}
		//			nodetmp = nodetmp->nextl;
	}


	printf("======END SEARCH========\n");
}
*/
