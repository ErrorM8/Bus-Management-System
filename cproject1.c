#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TOTAL_SEATS 10
#define MAX_ROUTES 5
#define MAX_NAME_LENGTH 50

// Struct to store bus route information
typedef struct {
    int routeNumber;
    char source[50];
    char destination[50];
    int totalSeats;
    bool seats[TOTAL_SEATS];
} BusRoute;

BusRoute routes[MAX_ROUTES];  // Array to store bus routes
int numRoutes = 0;  // Current number of routes

// Function prototypes
void displayAvailableSeats(int routeIndex);
void bookTicket(int routeIndex, int seatNumber);
void cancelTicket(int routeIndex, int seatNumber);
void viewBusSchedule();
void addNewRoute();
void viewAvailableSeats();
void searchAvailableBus(char source[], char destination[]);
void passengerRegistration();
float calculateTheTicket(int routeIndex, int seatNumber);
void paymentDetails(float amount);

// Initialize routes for testing
void initializeRoutes() {
    // Sample data for demonstration
    addNewRoute(1, "IIUC", "CUET", TOTAL_SEATS);
    addNewRoute(2, "CUET", "CU", TOTAL_SEATS);
}

// Function to display available seats for a specific route
void displayAvailableSeats(int routeIndex) {
    printf("\nAvailable Seats for Route %d (%s to %s):\n", routes[routeIndex].routeNumber, routes[routeIndex].source, routes[routeIndex].destination);
    printf("----------------\n");
    for (int i = 0; i < routes[routeIndex].totalSeats; ++i) {
        printf("Seat %d: %s\n", i + 1, routes[routeIndex].seats[i] ? "Booked" : "Available");
    }
    printf("----------------\n");
}

// Function to book a ticket for a specific route and seat number
void bookTicket(int routeIndex, int seatNumber) {
    if (seatNumber < 1 || seatNumber > routes[routeIndex].totalSeats) {
        printf("Invalid seat number. Please enter a seat number between 1 and %d.\n", routes[routeIndex].totalSeats);
        return;
    }

    if (routes[routeIndex].seats[seatNumber - 1]) {
        printf("Seat %d is already booked. Please choose another seat.\n", seatNumber);
    } else {
        routes[routeIndex].seats[seatNumber - 1] = true;
        printf("Seat %d booked successfully for Route %d (%s to %s).\n", seatNumber, routes[routeIndex].routeNumber, routes[routeIndex].source, routes[routeIndex].destination);
    }
}

// Function to cancel a booked ticket for a specific route and seat number
void cancelTicket(int routeIndex, int seatNumber) {
    if (seatNumber < 1 || seatNumber > routes[routeIndex].totalSeats) {
        printf("Invalid seat number. Please enter a seat number between 1 and %d.\n", routes[routeIndex].totalSeats);
        return;
    }

    if (!routes[routeIndex].seats[seatNumber - 1]) {
        printf("Seat %d for Route %d (%s to %s) is not booked.\n", seatNumber, routes[routeIndex].routeNumber, routes[routeIndex].source, routes[routeIndex].destination);
    } else {
        routes[routeIndex].seats[seatNumber - 1] = false;
        printf("Booking cancelled successfully for Seat %d on Route %d (%s to %s).\n", seatNumber, routes[routeIndex].routeNumber, routes[routeIndex].source, routes[routeIndex].destination);
    }
}

// Function to view bus schedule
void viewBusSchedule() {
    printf("\nBus Schedule:\n");
    printf("-------------\n");
    for (int i = 0; i < numRoutes; ++i) {
        printf("Route %d: %s to %s\n", routes[i].routeNumber, routes[i].source, routes[i].destination);
    }
    printf("-------------\n");
}

// Function to add a new route
void addNewRoute(int routeNumber, char source[], char destination[], int totalSeats) {
    if (numRoutes < MAX_ROUTES) {
        routes[numRoutes].routeNumber = routeNumber;
        strcpy(routes[numRoutes].source, source);
        strcpy(routes[numRoutes].destination, destination);
        routes[numRoutes].totalSeats = totalSeats;
        for (int i = 0; i < totalSeats; ++i) {
            routes[numRoutes].seats[i] = false;  // Initially all seats are available
        }
        numRoutes++;
        printf("Route added successfully.\n");
    } else {
        printf("Cannot add more routes. Maximum limit reached.\n");
    }
}

// Function to view available seats for all routes
void viewAvailableSeats() {
    printf("\nAvailable Seats:\n");
    printf("----------------\n");
    for (int i = 0; i < numRoutes; ++i) {
        displayAvailableSeats(i);
    }
    printf("----------------\n");
}

// Function to search for available buses based on source and destination
void searchAvailableBus(char source[], char destination[]) {
    printf("\nAvailable Buses from %s to %s:\n", source, destination);
    printf("----------------\n");
    for (int i = 0; i < numRoutes; ++i) {
        if (strcmp(routes[i].source, source) == 0 && strcmp(routes[i].destination, destination) == 0) {
            printf("Route %d: %s to %s\n", routes[i].routeNumber, routes[i].source, routes[i].destination);
            displayAvailableSeats(i);
        }
    }
    printf("----------------\n");
}

// Struct to store passenger information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
} Passenger;

// Function to register a new passenger
void passengerRegistration() {
    Passenger passenger;
    printf("\nEnter passenger details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", passenger.name);
    printf("Age: ");
    scanf("%d", &passenger.age);
    printf("Gender (M/F): ");
    scanf(" %c", &passenger.gender);
    // Additional code can be added here to store or process passenger information
    printf("Passenger registered successfully.\n");
}

// Function to calculate ticket fare based on route and seat number
float calculateTheTicket(int routeIndex, int seatNumber) {
    // Dummy calculation based on seat number, can be expanded
    float baseFare = 100.0;
    return baseFare;
}

// Function to display payment details
void paymentDetails(float amount) {
    printf("\nPayment Details:\n");
    printf("---------------\n");
    printf("Total Amount: $%.2f\n", amount);
    printf("---------------\n");
}

int main() {
    initializeRoutes();  // Initialize sample routes for demonstration

    int choice;
    int routeIndex, seatNumber;
    char source[MAX_NAME_LENGTH], destination[MAX_NAME_LENGTH];

    while (1) {
        printf("\nBus Ticket Management System\n");
        printf("----------------------------\n");
        printf("1. View Bus Schedule\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Booking\n");
        printf("4. Add New Route\n");
        printf("5. View Available Seats\n");
        printf("6. Search Available Buses\n");
        printf("7. Passenger Registration\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewBusSchedule();
                break;
            case 2:
                viewAvailableSeats();
                printf("Enter route number: ");
                scanf("%d", &routeIndex);
                printf("Enter seat number to book: ");
                scanf("%d", &seatNumber);
                bookTicket(routeIndex - 1, seatNumber);
                break;
            case 3:
                viewAvailableSeats();
                printf("Enter route number: ");
                scanf("%d", &routeIndex);
                printf("Enter seat number to cancel booking: ");
                scanf("%d", &seatNumber);
                cancelTicket(routeIndex - 1, seatNumber);
                break;
            case 4:
                printf("Enter route number: ");
                scanf("%d", &routeIndex);
                printf("Enter source: ");
                scanf(" %[^\n]s", source);
                printf("Enter destination: ");
                scanf(" %[^\n]s", destination);
                addNewRoute(routeIndex, source, destination, TOTAL_SEATS);
                break;
            case 5:
                viewAvailableSeats();
                break;
            case 6:
                printf("Enter source: ");
                scanf(" %[^\n]s", source);
                printf("Enter destination: ");
                scanf(" %[^\n]s", destination);
                searchAvailableBus(source, destination);
                break;
            case 7:
                passengerRegistration();
                break;
            case 8:
                printf("Exiting program. Thank you.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}