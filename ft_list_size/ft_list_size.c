
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int ft_list_size(t_list *begin_list)
{
    int len =1;
    if (begin_list == 0)
    {
		return (0);
    }
    else
    {
        return(1 + ft_list_size(begin_list->next));
    }
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		i = ft_lstsize((*lst).next);
		return (i + 1);
	}
	else
		return (i);
}