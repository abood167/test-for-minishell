/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbokhari <sbokhari@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 05:41:16 by sbokhari          #+#    #+#             */
/*   Updated: 2023/01/06 05:41:23 by sbokhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printarr(char **arr)
{
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

void	printlist(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

t_list	*ft_arrtolst(char **arr)
{
	t_list	*list;

	list = NULL;
	while (*arr)
	{
		ft_lstadd_back(&list, ft_lstnew((void *)ft_strdup(*arr)));
		arr++;
	}
	return (list);
}

char	**ft_lsttoarr(t_list *list)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	i = 0;
	while (list)
	{
		arr[i++] = ft_strdup((char *)list->content);
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_copyarr(char **arr)
{
	char	**copy;
	int		len;

	len = ft_2dlen((void **)arr);
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	copy[len] = NULL;
	while (len--)
		copy[len] = strdup(arr[len]);
	return (copy);
}

char	*ft_lsttostr(t_list *arr)
{
	char	*str;
	int		len;
	t_list	*start;

	len = 0;
	start = arr;
	while (arr)
	{
		len += ft_strlen((char *)arr->content);
		arr = arr->next;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len = 0;
	while (start)
	{
		ft_strcpy(&str[len], (char *)start->content);
		len += ft_strlen((char *)start->content);
		start = start->next;
	}
	return (str);
}

char	*arrtostr(char **arr)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i])
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	len = 0;
	while (arr[i])
	{
		ft_strcpy(&str[len], arr[i]);
		len += ft_strlen(arr[i]);
		i++;
	}
	return (str);
}

void	sort_lst(t_list *list)
{
	t_list *tmp;
	t_list *tmp2;
	char *tmp3;

	tmp = list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp->content, tmp2->content) > 0)
			{
				tmp3 = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp3;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}