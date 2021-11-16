#include "menu.h"
#include "tree.h"

int main(void)
{
    // Root of the tree
    node_t *tree = NULL;

    while (1)
    {
        node_t *user = NULL;
        uint32_t user_id = 0;
        char name[MAX_NAME_SIZE] = {0};

        printf("I) Insert a new user in to the tree\n");
        printf("S) Search for a user in the tree\n");
        printf("D) Delete a user from the tree\n");
        printf("P) Print the tree\n");
        printf("Q) Quit the program\n");
        printf("\nEnter the command: ");

        switch (get_command())
        {
        case 'I':
            user_id = get_user_id();
            get_user_name(name);
            user = search_node(tree, user_id);
            if (user == NULL)
            {
                tree = insert_node(tree, user_id, name);
                if (tree == NULL)
                {
                    printf("\nFailed to insert the user in to the tree.\n\n");
                }
                else
                {
                    printf("\nThe user was inserted in the tree.\n\n");
                }
            }
            else
            {
                printf("\nThe user ID is duplicate.\n\n");
            }
            break;

        case 'S':
            user_id = get_user_id();
            user = search_node(tree, user_id);
            if (user == NULL)
            {
                printf("\nThe user was not found.\n\n");
            }
            else
            {
                printf("\nThe user was found.\n");
                printf("\nUser ID: %d\n", user->id);
                printf("User Name: %s\n\n", user->name);
            }
            break;

        case 'P':
            printf("\nUser ID\t\tUser Name\n");
            print_tree(tree);
            printf("\n\n");
            break;

        case 'D':
            user_id = get_user_id();
            user = search_node(tree, user_id);
            if (user == NULL)
            {
                printf("\nThe user was not found.\n\n");
            }
            else
            {
                tree = delete_node(tree, user_id);
                printf("\nThe user was deleted from the tree.\n\n");
            }
            break;

        case 'Q':
            free_tree(tree);
            return 0;
            break;

        default:
            printf("\nInvalid command!\n\n");
            break;
        }
    }

    return 0;
}
