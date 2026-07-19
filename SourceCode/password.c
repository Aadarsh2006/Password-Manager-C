#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "password.h"

#define VAULT_FILE "../Data/vault.dat"


/* Add Password */
void addPassword()
{
    FILE *fp;
    Password p;
    int choice;

    fp = fopen(VAULT_FILE, "ab");

    if (fp == NULL)
    {
        printf("\nUnable to open vault file.\n");
        return;
    }

    printf("\n========== ADD PASSWORD ==========\n");

    printf("Enter Website : ");
    scanf("%s", p.website);

    printf("Enter Username : ");
    scanf("%s", p.username);

    printf("Enter Password : ");
    scanf("%s", p.password);

    printf("\nChoose Category\n");
    printf("---------------------\n");
    printf("1. Social\n");
    printf("2. Email\n");
    printf("3. Banking\n");
    printf("4. Shopping\n");
    printf("5. Work\n");
    printf("6. Entertainment\n");
    printf("7. Others\n");

    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            strcpy(p.category, "Social");
            break;

        case 2:
            strcpy(p.category, "Email");
            break;

        case 3:
            strcpy(p.category, "Banking");
            break;

        case 4:
            strcpy(p.category, "Shopping");
            break;

        case 5:
            strcpy(p.category, "Work");
            break;

        case 6:
            strcpy(p.category, "Entertainment");
            break;

        default:
            strcpy(p.category, "Others");
    }

    fwrite(&p, sizeof(Password), 1, fp);

    fclose(fp);

    printf("\nPassword Added Successfully.\n");
}
/* Display All Passwords */
void displayPasswords()
{
    FILE *fp;
    Password p;
    int found = 0;

    fp = fopen(VAULT_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo passwords found.\n");
        return;
    }

    printf("\n========== ALL PASSWORDS ==========\n");

    while (fread(&p, sizeof(Password), 1, fp))
    {
        found = 1;

        printf("\nWebsite  : %s", p.website);
        printf("\nUsername : %s", p.username);
        printf("\nPassword : %s", p.password);
        printf("\nCategory : %s", p.category);
        printf("\n-------------------------------");
    }

    if (!found)
    {
        printf("\nNo passwords stored.\n");
    }

    fclose(fp);
}
/* Display Passwords by Category */
void displayPasswordsByCategory()
{
    FILE *fp;
    Password p;
    int choice;
    int found = 0;
    char category[20];

    fp = fopen(VAULT_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo passwords found.\n");
        return;
    }

    printf("\nChoose Category\n");
    printf("---------------------\n");
    printf("1. Social\n");
    printf("2. Email\n");
    printf("3. Banking\n");
    printf("4. Shopping\n");
    printf("5. Work\n");
    printf("6. Entertainment\n");
    printf("7. Others\n");

    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            strcpy(category, "Social");
            break;

        case 2:
            strcpy(category, "Email");
            break;

        case 3:
            strcpy(category, "Banking");
            break;

        case 4:
            strcpy(category, "Shopping");
            break;

        case 5:
            strcpy(category, "Work");
            break;

        case 6:
            strcpy(category, "Entertainment");
            break;

        default:
            strcpy(category, "Others");
    }

    printf("\n========== %s PASSWORDS ==========\n", category);

    while (fread(&p, sizeof(Password), 1, fp))
    {
        if (strcmp(p.category, category) == 0)
        {
            found = 1;

            printf("\nWebsite  : %s", p.website);
            printf("\nUsername : %s", p.username);
            printf("\nPassword : %s", p.password);
            printf("\nCategory : %s", p.category);
            printf("\n-------------------------------");
        }
    }

    if (!found)
    {
        printf("\nNo passwords found in this category.\n");
    }

    fclose(fp);
}
/* Search Password */
void searchPassword()
{
    FILE *fp;
    Password p;
    int choice;
    int found = 0;
    char search[50];

    fp = fopen(VAULT_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo passwords found.\n");
        return;
    }

    printf("\nSearch By\n");
    printf("---------\n");
    printf("1. Website\n");
    printf("2. Username\n");
    printf("3. Category\n");

    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:

            printf("Enter Website : ");
            scanf("%s", search);

            printf("\n========== SEARCH RESULT ==========\n");

            while (fread(&p, sizeof(Password), 1, fp))
            {
                if (strcmp(p.website, search) == 0)
                {
                    found = 1;

                    printf("\nWebsite  : %s", p.website);
                    printf("\nUsername : %s", p.username);
                    printf("\nPassword : %s", p.password);
                    printf("\nCategory : %s", p.category);
                    printf("\n-------------------------------");
                }
            }

            break;

        case 2:

            printf("Enter Username : ");
            scanf("%s", search);

            printf("\n========== SEARCH RESULT ==========\n");

            while (fread(&p, sizeof(Password), 1, fp))
            {
                if (strcmp(p.username, search) == 0)
                {
                    found = 1;

                    printf("\nWebsite  : %s", p.website);
                    printf("\nUsername : %s", p.username);
                    printf("\nPassword : %s", p.password);
                    printf("\nCategory : %s", p.category);
                    printf("\n-------------------------------");
                }
            }

            break;

        case 3:

            printf("\nChoose Category\n");
            printf("---------------------\n");
            printf("1. Social\n");
            printf("2. Email\n");
            printf("3. Banking\n");
            printf("4. Shopping\n");
            printf("5. Work\n");
            printf("6. Entertainment\n");
            printf("7. Others\n");

            printf("\nEnter Choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    strcpy(search, "Social");
                    break;

                case 2:
                    strcpy(search, "Email");
                    break;

                case 3:
                    strcpy(search, "Banking");
                    break;

                case 4:
                    strcpy(search, "Shopping");
                    break;

                case 5:
                    strcpy(search, "Work");
                    break;

                case 6:
                    strcpy(search, "Entertainment");
                    break;

                default:
                    strcpy(search, "Others");
            }

            printf("\n========== SEARCH RESULT ==========\n");

            while (fread(&p, sizeof(Password), 1, fp))
            {
                if (strcmp(p.category, search) == 0)
                {
                    found = 1;

                    printf("\nWebsite  : %s", p.website);
                    printf("\nUsername : %s", p.username);
                    printf("\nPassword : %s", p.password);
                    printf("\nCategory : %s", p.category);
                    printf("\n-------------------------------");
                }
            }

            break;

        default:

            printf("\nInvalid Choice.\n");
    }

    if (!found)
    {
        printf("\nNo matching password found.\n");
    }

    fclose(fp);
}
/* Update Password */
void updatePassword()
{
    FILE *fp, *temp;
    Password p;
    char website[50];
    char username[50];
    int found = 0;
    int choice;

    fp = fopen(VAULT_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo passwords found.\n");
        return;
    }

    temp = fopen("../Data/temp.dat", "wb");

    printf("\nEnter Website : ");
    scanf("%s", website);

    printf("Enter Username : ");
    scanf("%s", username);

    while (fread(&p, sizeof(Password), 1, fp))
    {
        if (strcmp(p.website, website) == 0 &&
            strcmp(p.username, username) == 0)
        {
            found = 1;

            printf("\nCurrent Details\n");
            printf("-------------------------\n");
            printf("Website  : %s\n", p.website);
            printf("Username : %s\n", p.username);
            printf("Password : %s\n", p.password);
            printf("Category : %s\n", p.category);

            printf("\nEnter New Password : ");
            scanf("%s", p.password);

            printf("\nChoose New Category\n");
            printf("1. Social\n");
            printf("2. Email\n");
            printf("3. Banking\n");
            printf("4. Shopping\n");
            printf("5. Work\n");
            printf("6. Entertainment\n");
            printf("7. Others\n");

            printf("\nEnter Choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    strcpy(p.category, "Social");
                    break;

                case 2:
                    strcpy(p.category, "Email");
                    break;

                case 3:
                    strcpy(p.category, "Banking");
                    break;

                case 4:
                    strcpy(p.category, "Shopping");
                    break;

                case 5:
                    strcpy(p.category, "Work");
                    break;

                case 6:
                    strcpy(p.category, "Entertainment");
                    break;

                default:
                    strcpy(p.category, "Others");
            }

            printf("\nPassword Updated Successfully.\n");
        }

        fwrite(&p, sizeof(Password), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(VAULT_FILE);
    rename("../Data/temp.dat", VAULT_FILE);

    if (!found)
    {
        printf("\nRecord Not Found.\n");
    }
}
/* Delete Password */
void deletePassword()
{
    FILE *fp, *temp;
    Password p;
    char website[50];
    char username[50];
    int found = 0;

    fp = fopen(VAULT_FILE, "rb");

    if (fp == NULL)
    {
        printf("\nNo passwords found.\n");
        return;
    }

    temp = fopen("../Data/temp.dat", "wb");

    printf("\nEnter Website : ");
    scanf("%s", website);

    printf("Enter Username : ");
    scanf("%s", username);

    while (fread(&p, sizeof(Password), 1, fp))
    {
        if (strcmp(p.website, website) == 0 &&
            strcmp(p.username, username) == 0)
        {
            found = 1;

            printf("\nPassword Deleted Successfully.\n");

            continue;
        }

        fwrite(&p, sizeof(Password), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(VAULT_FILE);
    rename("../Data/temp.dat", VAULT_FILE);

    if (!found)
    {
        printf("\nRecord Not Found.\n");
    }
}