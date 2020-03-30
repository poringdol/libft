#include <stdlib.h>
#include "libft.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list *list;

// 	list = (t_list *)malloc(sizeof(t_list));
// 	if (list != NULL)
// 	{
// 		list->content = content;
// 		list->next = NULL;
// 	}
// 	return (list);
// }

// t_list *ft_lstnew(void *content){

//  t_list *new_list;

//  if (!(new_list = malloc(sizeof(t_list))))
//   return ((void*)0);

//  /*if (!content){
//   new_list->content = (void*)0;
//   new_list->next = (void*)0;
//  }else{
//  if(!(new_list = malloc((sizeof(content))))){
//   free(new_list);
//   return ((void*)0);
//  };*/
//  new_list->content = (void*)content;
//  new_list->next = (void*)0;

//  return (new_list);
// }

t_list  *ft_lstnew(void *content)
{
  t_list *list;

  if(!(list = malloc(sizeof(t_list))))
  return (NULL);
  list->content = content;
  list->next = NULL;
  return (list);
}