#include <stdio.h>
#include <string.h>
#include "master_password.h"

#define MASTER_FILE "../Data/master.dat"

/* Create Master Password */
void createMasterPassword()
{
    FILE *fp;
    char password[50];
    char confirm[50];

    fp = fopen(MASTER_FILE, "rb");

    // Master password already exists
    if (fp != NULL)
    {
        fclose(fp);
        return;
    }

    printf("\n===== CREATE MASTER PASSWORD =====\n");

    while (1)
    {
        printf("Enter Master Password : ");
        scanf("%49s", password);

        printf("Confirm Password      : ");
        scanf("%49s", confirm);

        if (strcmp(password, confirm) == 0)
        {
            fp = fopen(MASTER_FILE, "wb");

            if (fp == NULL)
            {
                printf("\nError creating master password!\n");
                return;
            }

            fwrite(password, sizeof(password), 1, fp);

            fclose(fp);

            printf("\nMaster Password Created Successfully!\n");
            break;
        }
        else
        {
            printf("\nPasswords do not match. Try again.\n\n");
        }
    }
}


/* Authenticate User */
int authenticateUser()
{
    FILE *fp;
    char storedPassword[50];
    char enteredPassword[50];
    int attempts = 3;

    fp = fopen(MASTER_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nMaster Password not found!\n");
        return 0;
    }

    fread(storedPassword, sizeof(storedPassword), 1, fp);

    fclose(fp);

    while (attempts > 0)
    {
        printf("\nEnter Master Password : ");
        scanf("%49s", enteredPassword);

        if (strcmp(storedPassword, enteredPassword) == 0)
        {
            printf("\nLogin Successful!\n");
            return 1;
        }

        attempts--;

        if (attempts > 0)
        {
            printf("\nIncorrect Password!");
            printf("\nAttempts Left : %d\n", attempts);
        }
    }

    printf("\nAccess Denied!\n");

    return 0;
}


/* Change Master Password */
void changeMasterPassword()
{
    FILE *fp;
    char storedPassword[50];
    char currentPassword[50];
    char newPassword[50];
    char confirmPassword[50];

    fp = fopen(MASTER_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nMaster Password file not found!\n");
        return;
    }

    fread(storedPassword, sizeof(storedPassword), 1, fp);

    fclose(fp);

    printf("\nEnter Current Password : ");
    scanf("%49s", currentPassword);

    if (strcmp(currentPassword, storedPassword) != 0)
    {
        printf("\nIncorrect Master Password!\n");
        return;
    }

    printf("Enter New Password     : ");
    scanf("%49s", newPassword);

    printf("Confirm New Password   : ");
    scanf("%49s", confirmPassword);

    if (strcmp(newPassword, confirmPassword) != 0)
    {
        printf("\nPasswords do not match!\n");
        return;
    }

    fp = fopen(MASTER_FILE, "wb");

    if (fp == NULL)
    {
        printf("\nError updating Master Password!\n");
        return;
    }

    fwrite(newPassword, sizeof(newPassword), 1, fp);

    fclose(fp);

    printf("\nMaster Password Changed Successfully!\n");
    printf("Please login again.\n");
}