//
// Created by jplop on 02/11/2022.
//

#include "Set.h"

typedef struct node
{
    void *element;
    struct node *left;
    struct node *right;
}Node;

struct set
{
    Node *root;
    int (*compare)(void*, void *);
};

Node* node_new(void *element)
{
    Node *new_node = malloc(sizeof (Node));
    new_node->element = element;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

Set* set_new(int (*compare)(void* a, void* b))
{
    Set *new_set = malloc(sizeof (Set));
    new_set->root = NULL;
    new_set->compare = compare;

    return new_set;
}

void add_to_set(Set *set, Node *current, void *to_add)
{
    if(set->root == NULL)
    {
        set->root = node_new(to_add);
    } else
    {
        if(set->compare(current->element, to_add) > 0)
        {
            if(current->right == NULL)
            {
                current->right = node_new(to_add);
            } else
            {
                current = current->right;
                add_to_set(set, current, to_add);
            }
        } else if(set->compare(current->element, to_add) < 0)
        {
            if(current->left == NULL)
            {
                current->left = node_new(to_add);
            } else
            {
                current = current->left;
                add_to_set(set, current, to_add);
            }
        }else
        {
            printf("Error, couldn't add [%d] element to set because an element with the same value is already in the set\n", *(int *)to_add);
            return;
        }
    }
}

Set* set_add(Set *set, void *element)
{

    Node *current = set->root;
    add_to_set(set, current, element);

    return set;
}

//int set_contains(Set *set, void *element)
//{
//    if(set->root == NULL)
//    {
//        return 0;
//    }else
//    {
//        Node *current = set->root;
//        while (current != NULL)
//        {
//            if(!set->compare(current->element, element))
//            {
//                return 1;
//            }else if(set->compare(current->element, element) > 0)
//            {
//                if(current->right == NULL)
//                {
//                    current->right = node_new(element);
//                    break;
//                }
//
//                current = current->right;
//            }else
//            {
//                if(current->left == NULL)
//                {
//                    current->left = node_new(element);
//                    break;
//                }
//
//                current = current->left;
//            }
//        }
//    }
//    return set;
//}


