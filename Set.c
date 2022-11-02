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

Set* set_add(Set *set, void *element)
{
    if(set->root == NULL)
    {
        set->root = node_new(element);
        return set;
    }else
    {
        Node *current = set->root;
        while (current != NULL)
        {
            if(!set->compare(current->element, element))
            {
                return set;
            }else if(set->compare(current->element, element) > 0)
            {
                if(current->right == NULL)
                {
                    current->right = node_new(element);
                    break;
                }

                current = current->right;
            }else
            {
                if(current->left == NULL)
                {
                    current->left = node_new(element);
                    break;
                }

                current = current->left;
            }
        }
    }
    return set;
}

int set_contains(Set *set, void *element)
{
    if(set->root == NULL)
    {
        return 0;
    }else
    {
        Node *current = set->root;
        while (current != NULL)
        {
            if(!set->compare(current->element, element))
            {
                return 1;
            }else if(set->compare(current->element, element) > 0)
            {
                if(current->right == NULL)
                {
                    current->right = node_new(element);
                    break;
                }

                current = current->right;
            }else
            {
                if(current->left == NULL)
                {
                    current->left = node_new(element);
                    break;
                }

                current = current->left;
            }
        }
    }
    return set;
}


