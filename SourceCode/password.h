#ifndef PASSWORD_H
#define PASSWORD_H

/* Password Structure */

typedef struct
{
    char website[50];
    char username[50];
    char password[50];
    char category[20];

} Password;


/* Password Management Functions */

void addPassword();

void displayPasswords();

void displayPasswordsByCategory();

void searchPassword();

void updatePassword();

void deletePassword();

#endif