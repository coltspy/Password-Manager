#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void addPassword();
void viewPasswords();

// Structure to store password details
struct Password {
    char website[50];
    char username[50];
    char password[50];
};

int main() {
    int choice;
    while(1) {
        printf("\n=== Password Manager ===\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to add a new password
void addPassword() {
    FILE *file = fopen("passwords.txt", "a");
    struct Password newPass;
    
    printf("Enter website: ");
    scanf("%s", newPass.website);
    
    printf("Enter username: ");
    scanf("%s", newPass.username);
    
    printf("Enter password: ");
    scanf("%s", newPass.password);
    
    fprintf(file, "%s %s %s\n", newPass.website, newPass.username, newPass.password);
    
    fclose(file);
}

// Function to view all passwords
void viewPasswords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: No passwords stored.\n");
        return;
    }
    
    struct Password tempPass;
    printf("\nStored Passwords:\n");
    
    while(fscanf(file, "%s %s %s", tempPass.website, tempPass.username, tempPass.password) != EOF) {
        printf("Website: %s | Username: %s | Password: %s\n", tempPass.website, tempPass.username, tempPass.password);
    }
    
    fclose(file);
}
