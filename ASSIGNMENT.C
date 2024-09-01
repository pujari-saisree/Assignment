11-QUESTION:
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayInventory(int *inventory, int size);
int* resizeInventory(int *inventory, int old_size, int new_size);

int main() {
    int *inventory = NULL;  // Pointer to hold the inventory array
    int current_size = 0;   // Current size of the inventory
    int new_size;           // Size to resize the inventory to
    int i;                 // Loop variable
    char choice;           // User choice for resizing

    // Initial inventory setup
    printf("Enter the initial number of product packets: ");
    scanf("%d", &current_size);

    // Allocate memory for initial inventory
    inventory = (int*)malloc(current_size * sizeof(int));
    if (inventory == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize inventory with sample data
    for (i = 0; i < current_size; i++) {
        inventory[i] = i + 1;  // Sample data: Packet numbers 1, 2, ..., n
    }

    // Display the initial inventory
    printf("Initial Inventory:\n");
    displayInventory(inventory, current_size);

    // Manage resizing of inventory
    while (1) {
        printf("\nDo you want to resize the inventory? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }

        // Prompt for new size
        printf("Enter the new size of the inventory: ");
        scanf("%d", &new_size);

        // Resize the inventory
        inventory = resizeInventory(inventory, current_size, new_size);

        // Update the current size
        current_size = new_size;

        // Display the updated inventory
        printf("Updated Inventory:\n");
        displayInventory(inventory, current_size);
    }

    // Free the allocated memory
    free(inventory);

    return 0;
}

// Function to display the inventory
void displayInventory(int *inventory, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Packet %d: %d\n", i + 1, inventory[i]);
    }
}

// Function to resize the inventory
int* resizeInventory(int *inventory, int old_size, int new_size) {
    int *new_inventory;
    int i;

    // Allocate new memory block
    new_inventory = (int*)realloc(inventory, new_size * sizeof(int));
    if (new_inventory == NULL) {
        printf("Memory allocation failed during resizing.\n");
        free(inventory);
        exit(1);
    }

    // Initialize new packets if the inventory size increased
    if (new_size > old_size) {
        for (i = old_size; i < new_size; i++) {
            new_inventory[i] = i + 1;  // Sample data for new packets
        }
    }

    return new_inventory;
}

12-QUESTION:
#include <stdio.h>

int main() {
    int num_treasures = 5;  // Number of treasures
    int weights[num_treasures];  // Array to store weights of the treasures
    int total_weight = 0;  // Variable to store the total weight
    int i;  // Loop variable

    // Input weights of the treasures
    printf("Enter the weights of the %d treasures:\n", num_treasures);
    for (i = 0; i < num_treasures; i++) {
        printf("Weight of treasure %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    // Calculate total weight
    for (i = 0; i < num_treasures; i++) {
        total_weight += weights[i];
    }

    // Output the total weight
    printf("\nTotal weight collected from the treasures: %d\n", total_weight);

    return 0;
}

13-QUESTION:
#include <stdio.h>

// Structure to hold the Square data
typedef struct {
    float area;
} Square;

// Structure to hold the Rectangle data
typedef struct {
    float length;
    float breadth;
} Rectangle;

// Structure to hold both Square and Rectangle
typedef struct {
    Square square;
    Rectangle rectangle;
} Shape;

int main() {
    // Create a Shape instance
    Shape shape;

    // Input data for Square
    printf("Enter the area of the square: ");
    scanf("%f", &shape.square.area);

    // Input data for Rectangle
    printf("Enter the length of the rectangle: ");
    scanf("%f", &shape.rectangle.length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &shape.rectangle.breadth);

    // Display the input data
    printf("\nShape Details:\n");
    printf("Square Area: %.2f\n", shape.square.area);
    printf("Rectangle Length: %.2f\n", shape.rectangle.length);
    printf("Rectangle Breadth: %.2f\n", shape.rectangle.breadth);

    // Calculate and display the rectangle's area
    float rectangleArea = shape.rectangle.length * shape.rectangle.breadth;
    printf("Rectangle Area: %.2f\n", rectangleArea);

    return 0;
}

14-QUESTION:
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

int main() {
    // Array to hold student names
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int count = 0; // Number of students in the list
    char name[MAX_NAME_LENGTH];
    char choice;

    while (1) {
        // Check if we have reached the maximum number of students
        if (count >= MAX_STUDENTS) {
            printf("The list is full. Cannot add more students.\n");
            break;
        }

        // Input the student's name
        printf("Enter the name of the student who has submitted their assignment: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        // Remove newline character from fgets
        name[strcspn(name, "\n")] = '\0';

        // Add the student's name to the list
        strncpy(students[count], name, MAX_NAME_LENGTH);
        count++;

        // Display the updated list of students
        printf("\nList of students who have submitted their assignments:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, students[i]);
        }

        // Ask if the teacher wants to add another student
        printf("\nDo you want to add another student? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Clear the newline character left by scanf

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    printf("\nFinal List of students who have submitted their assignments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }

    return 0;
}

15-QUESTION:
#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid; // Key found
        }
        
        // If key greater, ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    return -1; // Key not found
}

int main() {
    // Define an ordered list of book IDs
    int bookIDs[] = {101, 203, 305, 407, 509}; // Example IDs
    int size = sizeof(bookIDs) / sizeof(bookIDs[0]);
    int searchID;
    int result;

    // Input the book ID to search
    printf("Enter the book ID to search: ");
    scanf("%d", &searchID);

    // Perform binary search
    result = binarySearch(bookIDs, size, searchID);

    // Display the result
    if (result != -1) {
        printf("Book with ID %d is available in the list.\n", searchID);
    } else {
        printf("Book with ID %d is not available in the list.\n", searchID);
    }

    return 0;
}

16-QUESTION:
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, char name) {
    printf("Enter the elements of matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, char name) {
    printf("Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int C[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], C[MAX_ROWS][MAX_COLS];

    // Input matrix dimensions
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Input matrices
    inputMatrix(A, rows, cols, 'A');
    inputMatrix(B, rows, cols, 'B');

    // Perform matrix addition
    addMatrices(A, B, C, rows, cols);

    // Display matrices
    printMatrix(A, rows, cols, 'A');
    printMatrix(B, rows, cols, 'B');
    printMatrix(C, rows, cols, 'C');

    return 0;
}

12-MARKS:
17)a.
#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 5
#define MAX_NAME_LENGTH 100

// Define a structure for student records
typedef struct {
    int registerNumber;
    char name[MAX_NAME_LENGTH];
    int age;
    float cgpa;
} Student;

// Function to input student records
void inputStudentRecords(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Register Number: ");
        scanf("%d", &students[i].registerNumber);
        getchar(); // Clear the newline character from the buffer

        printf("Name: ");
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        // Remove newline character if present
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);

        printf("\n");
    }
}

// Function to find the student with the greatest CGPA
Student findTopStudent(Student students[], int numStudents) {
    Student topStudent = students[0];
    for (int i = 1; i < numStudents; i++) {
        if (students[i].cgpa > topStudent.cgpa) {
            topStudent = students[i];
        }
    }
    return topStudent;
}

int main() {
    Student students[NUM_STUDENTS];

    // Input student records
    inputStudentRecords(students, NUM_STUDENTS);

    // Find the student with the greatest CGPA
    Student topStudent = findTopStudent(students, NUM_STUDENTS);

    // Display the student with the greatest CGPA
    printf("Student with the highest CGPA:\n");
    printf("Register Number: %d\n", topStudent.registerNumber);
    printf("Name: %s\n", topStudent.name);
    printf("Age: %d\n", topStudent.age);
    printf("CGPA: %.2f\n", topStudent.cgpa);

    return 0;
}

17)b.

Let's break down your request into the two parts as specified.

### (i) Asymptotic Notations for Algorithm Analysis

Asymptotic notations are used to describe the behavior of an algorithm's runtime or space requirements in terms of the input size, typically denoted as \( n \). These notations provide a way to express the efficiency of an algorithm in terms of growth rates and allow for the comparison of different algorithms.

#### Common Asymptotic Notations:

1. **Big O Notation (\( O \))**:
   - Describes the upper bound of the runtime or space complexity.
   - Represents the worst-case scenario.
   - Example: If an algorithm's runtime is \( O(n^2) \), it means that as the input size \( n \) grows, the runtime will not exceed \( c \cdot n^2 \) for some constant \( c \).

2. **Omega Notation (\( \Omega \))**:
   - Describes the lower bound of the runtime or space complexity.
   - Represents the best-case scenario.
   - Example: If an algorithm's runtime is \( \Omega(n) \), it means that for sufficiently large \( n \), the runtime will be at least \( c \cdot n \) for some constant \( c \).

3. **Theta Notation (\( \Theta \))**:
   - Describes both the upper and lower bounds of the runtime or space complexity.
   - Represents the average-case scenario if the algorithm behaves consistently.
   - Example: If an algorithm's runtime is \( \Theta(n \log n) \), it means that the runtime grows asymptotically as \( c_1 \cdot n \log n \leq \text{runtime} \leq c_2 \cdot n \log n \) for some constants \( c_1 \) and \( c_2 \).

4. **Little o Notation (\( o \))**:
   - Describes an upper bound that is not tight.
   - Example: If an algorithm’s runtime is \( o(n^2) \), it grows slower than \( n^2 \) but may not be bounded by \( n^2 \) exactly.

5. **Little omega Notation (\( \omega \))**:
   - Describes a lower bound that is not tight.
   - Example: If an algorithm’s runtime is \( \omega(n) \), it grows faster than \( n \) but is not bounded below by \( n \) exactly.

### (ii) Time and Space Complexity of the Given Code

Let's analyze the time and space complexity of the given C code:

#include <stdio.h>
int main() {
    int i = 1, sum = 0, n;
    while (i <= n) {
        i = i + 1;
        sum = sum + i;
    }
    return 0;
}



#### Time Complexity

1. **Initialization**: The initialization of variables `i`, `sum`, and `n` takes constant time, \( O(1) \).

2. **While Loop**:
   - The condition of the loop (`i <= n`) is checked in every iteration.
   - The increment operation (`i = i + 1`) and the sum operation (`sum = sum + i`) each take constant time, \( O(1) \).

3. **Number of Iterations**:
   - The loop starts with `i = 1` and increments `i` by 1 in each iteration until `i` exceeds `n`.
   - Thus, the loop runs \( n \) times, assuming \( n \) is a positive integer.

**Overall Time Complexity**: The dominant factor is the loop running \( n \) times, so the time complexity is \( O(n) \).

#### Space Complexity

1. **Variable Storage**:
   - The code uses a constant amount of extra space to store variables `i`, `sum`, and `n`.
   - This storage does not depend on the input size \( n \).

**Overall Space Complexity**: The space complexity is \( O(1) \), as the amount of extra space used is constant regardless of the input size.

### Summary

- **Time Complexity**: \( O(n) \)
- **Space Complexity**: \( O(1) \)

This analysis provides an understanding of how the execution time and space requirements of the code grow with the size of the input, helping in evaluating its efficiency.

18-QUESTION:
a)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Main function to count two-digit primes formed by adjacent digits
int main() {
    char numStr[20];
    int length, count = 0;

    // Input the number
    printf("Enter a number: ");
    scanf("%s", numStr);

    length = strlen(numStr);

    // Process adjacent digits
    for (int i = 0; i < length - 1; i++) {
        // Form two-digit number from adjacent digits
        int twoDigitNum = (numStr[i] - '0') * 10 + (numStr[i + 1] - '0');

        // Check if the two-digit number is prime
        if (twoDigitNum >= 10 && isPrime(twoDigitNum)) {
            count++;
        }
    }

    // Print the result
    printf("Count of two-digit prime numbers: %d\n", count);

    return 0;
}

18)
b.
#include <stdio.h>

#define MAX_SIZE 100

// Function to display the list
void displayList(int list[], int size) {
    if (size == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to add an element to the list
void addElement(int list[], int *size, int element) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot add more elements.\n");
        return;
    }
    list[*size] = element;
    (*size)++;
    printf("Element %d added.\n", element);
}

// Function to remove an element from the list
void removeElement(int list[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Index out of bounds.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    (*size)--;
    printf("Element at index %d removed.\n", index);
}

// Function to find an element in the list
int findElement(int list[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int list[MAX_SIZE];
    int size = 0; // Current size of the list
    int choice, element, index;

    while (1) {
        printf("\nList Operations Menu:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. Display List\n");
        printf("4. Find Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Element
                printf("Enter the element to add: ");
                scanf("%d", &element);
                addElement(list, &size, element);
                break;
            
            case 2: // Remove Element
                printf("Enter the index of the element to remove: ");
                scanf("%d", &index);
                removeElement(list, &size, index);
                break;

            case 3: // Display List
                displayList(list, size);
                break;

            case 4: // Find Element
                printf("Enter the element to find: ");
                scanf("%d", &element);
                index = findElement(list, size, element);
                if (index != -1) {
                    printf("Element %d found at index %d.\n", element, index);
                } else {
                    printf("Element %d not found in the list.\n", element);
                }
                break;

            case 5: // Exit
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}


   


