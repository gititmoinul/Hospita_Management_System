#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Patient
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

// Structure for Doctor
struct Doctor {
    int id;
    char name[50];
    char specialization[50];
};

// Function to add a patient
void addPatient() {
    FILE *file = fopen("patients.txt", "a");
    struct Patient p;
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Disease: ");
    scanf("%s", p.disease);

    fprintf(file, "%d %s %d %s\n", p.id, p.name, p.age, p.disease);
    fclose(file);
    printf("Patient record added successfully!\n");
}

// Function to view patients
void viewPatients() {
    FILE *file = fopen("patients.txt", "r");
    struct Patient p;
    printf("\nPatient Records:\n");
    printf("ID\tName\tAge\tDisease\n");
    while (fscanf(file, "%d %s %d %s", &p.id, p.name, &p.age, p.disease) != EOF) {
        printf("%d\t%s\t%d\t%s\n", p.id, p.name, p.age, p.disease);
    }
    fclose(file);
}

// Function to remove a patient
void removePatient() {
    FILE *file = fopen("patients.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Patient p;
    int id, found = 0;
    printf("Enter Patient ID to remove: ");
    scanf("%d", &id);
    while (fscanf(file, "%d %s %d %s", &p.id, p.name, &p.age, p.disease) != EOF) {
        if (p.id != id)
            fprintf(temp, "%d %s %d %s\n", p.id, p.name, p.age, p.disease);
        else
            found = 1;
    }
    fclose(file);
    fclose(temp);
    remove("patients.txt");
    rename("temp.txt", "patients.txt");
    if (found)
        printf("Patient record removed successfully!\n");
    else
        printf("Patient ID not found!\n");
}

// Function to add a doctor
void addDoctor() {
    FILE *file = fopen("doctors.txt", "a");
    struct Doctor d;
    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Name: ");
    scanf("%s", d.name);
    printf("Enter Specialization: ");
    scanf("%s", d.specialization);

    fprintf(file, "%d %s %s\n", d.id, d.name, d.specialization);
    fclose(file);
    printf("Doctor record added successfully!\n");
}

// Function to view doctors
void viewDoctors() {
    FILE *file = fopen("doctors.txt", "r");
    struct Doctor d;
    printf("\nDoctor Records:\n");
    printf("ID\tName\tSpecialization\n");
    while (fscanf(file, "%d %s %s", &d.id, d.name, d.specialization) != EOF) {
        printf("%d\t%s\t%s\n", d.id, d.name, d.specialization);
    }
    fclose(file);
}

// Function to remove a doctor
void removeDoctor() {
    FILE *file = fopen("doctors.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Doctor d;
    int id, found = 0;
    printf("Enter Doctor ID to remove: ");
    scanf("%d", &id);
    while (fscanf(file, "%d %s %s", &d.id, d.name, d.specialization) != EOF) {
        if (d.id != id)
            fprintf(temp, "%d %s %s\n", d.id, d.name, d.specialization);
        else
            found = 1;
    }
    fclose(file);
    fclose(temp);
    remove("doctors.txt");
    rename("temp.txt", "doctors.txt");
    if (found)
        printf("Doctor record removed successfully!\n");
    else
        printf("Doctor ID not found!\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Remove Patient\n");
        printf("4. Add Doctor\n");
        printf("5. View Doctors\n");
        printf("6. Remove Doctor\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                removePatient();
                break;
            case 4:
                addDoctor();
                break;
            case 5:
                viewDoctors();
                break;
            case 6:
                removeDoctor();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
