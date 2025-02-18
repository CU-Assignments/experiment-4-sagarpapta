/**
Write a Java program to implement an ArrayList that stores employee details (ID, Name, and Salary). Allow users to add, update, remove, and search employees.
*/


import java.util.ArrayList;
import java.util.Scanner;

class Employee {
    int id;
    String name;
    double salary;

    Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Salary: " + salary;
    }
}

public class EmployeeManager {
    static ArrayList<Employee> employees = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nEmployee Management System");
            System.out.println("1. Add Employee");
            System.out.println("2. Update Employee");
            System.out.println("3. Remove Employee");
            System.out.println("4. Search Employee");
            System.out.println("5. Display All Employees");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addEmployee(scanner);
                    break;
                case 2:
                    updateEmployee(scanner);
                    break;
                case 3:
                    removeEmployee(scanner);
                    break;
                case 4:
                    searchEmployee(scanner);
                    break;
                case 5:
                    displayAllEmployees();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        } while (choice != 6);
    }

    public static void addEmployee(Scanner scanner) {
        System.out.print("Enter Employee ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();  // Consume newline
        System.out.print("Enter Employee Name: ");
        String name = scanner.nextLine();
        System.out.print("Enter Employee Salary: ");
        double salary = scanner.nextDouble();

        employees.add(new Employee(id, name, salary));
        System.out.println("Employee added successfully!");
    }

    public static void updateEmployee(Scanner scanner) {
        System.out.print("Enter Employee ID to update: ");
        int id = scanner.nextInt();
        scanner.nextLine();  // Consume newline

        for (Employee emp : employees) {
            if (emp.id == id) {
                System.out.print("Enter new Employee Name: ");
                emp.name = scanner.nextLine();
                System.out.print("Enter new Employee Salary: ");
                emp.salary = scanner.nextDouble();
                System.out.println("Employee updated successfully!");
                return;
            }
        }
        System.out.println("Employee not found!");
    }

    public static void removeEmployee(Scanner scanner) {
        System.out.print("Enter Employee ID to remove: ");
        int id = scanner.nextInt();

        for (Employee emp : employees) {
            if (emp.id == id) {
                employees.remove(emp);
                System.out.println("Employee removed successfully!");
                return;
            }
        }
        System.out.println("Employee not found!");
    }

    public static void searchEmployee(Scanner scanner) {
        System.out.print("Enter Employee ID to search: ");
        int id = scanner.nextInt();

        for (Employee emp : employees) {
            if (emp.id == id) {
                System.out.println(emp);
                return;
            }
        }
        System.out.println("Employee not found!");
    }

    public static void displayAllEmployees() {
        if (employees.isEmpty()) {
            System.out.println("No employees found!");
        } else {
            for (Employee emp : employees) {
                System.out.println(emp);
            }
        }
    }
}


