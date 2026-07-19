#include <stdio.h>

#include "password.h"
#include "master_password.h"

int main()
{
    int choice;

    /* Create Master Password (Only on First Run) */
    createMasterPassword();

    /* Login */
    if (authenticateUser() == 0)
    {
        return 0;
    }

    while (1)
    {
        printf("\n");
        printf("==================================\n");
        printf("        SECURE VAULT\n");
        printf("      PASSWORD MANAGER\n");
        printf("==================================\n");

        printf("1. Add Password\n");
        printf("2. Display All Passwords\n");
        printf("3. Display Passwords by Category\n");
        printf("4. Search Password\n");
        printf("5. Update Password\n");
        printf("6. Delete Password\n");
        printf("7. Change Master Password\n");
        printf("8. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPassword();
                break;

            case 2:
                displayPasswords();
                break;

            case 3:
                displayPasswordsByCategory();
                break;

            case 4:
                searchPassword();
                break;

            case 5:
                updatePassword();
                break;

            case 6:
                deletePassword();
                break;

            case 7:
                changeMasterPassword();

                printf("\nPlease Login Again.\n");

                if (authenticateUser() == 0)
                {
                    return 0;
                }

                break;

            case 8:
                printf("\nThank You for Using Secure Vault!\n");
                return 0;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}