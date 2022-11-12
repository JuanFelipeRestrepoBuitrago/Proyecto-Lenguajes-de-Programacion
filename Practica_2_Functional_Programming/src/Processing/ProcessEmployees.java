package Processing;

import POJO.Employee;
import java.util.List;
import java.util.stream.Collectors;

public class ProcessEmployees {

    // This method prints all the employees
    public static void printEmployees(List<Employee> employees){
        System.out.println("List of employees:");
        employees.forEach(System.out::println);

        System.out.println();
    }

    // This method prints all the employees with a salary between the minimum and maximum salary
    public static void printSalaryRange(List<Employee> employees, double min, double max){
        System.out.println("Employees with salary between " + min + " and " + max + ":");
        employees.stream()
                .filter(employee -> employee.getSalary() >= min && employee.getSalary() <= max)
                .forEach(System.out::println);
        System.out.println();
    }

    // This method prints all the employees by department
    public static void printAllDepartmentEmployees(List<Employee> employees){
        System.out.println("Employees by department:");
        employees.stream()
                .collect(Collectors.groupingBy(Employee::getDepartment)).forEach((department, employees1) -> {
            System.out.println(department + ":");
            employees1.forEach(System.out::println);
                });
        System.out.println();
    }

    // This method prints the amount of employees by department
    public static void amountByDepartment(List<Employee> employees){
        System.out.println("Count by department:");
        employees
                .stream().collect(Collectors.groupingBy(Employee::getDepartment))
                        .forEach((department, employees1) -> {
                            System.out.println(department + " has " + employees1.stream().count() + " employee(s)");
                        });
        System.out.println();
    }

    // This method prints the total salary by department
    public static void salaryByDepartment(List<Employee> employees){
        System.out.println("Total salary by department:");
        employees
                .stream().collect(Collectors.groupingBy(Employee::getDepartment))
                        .forEach((department, employees1) -> {
                            System.out.println(department + " has " + employees1.stream().mapToDouble(Employee::getSalary).sum() + " in total salary");
                        });
        System.out.println();
    }

    // This method prints the name, lastname and salary of the employee who has the max salary by department
    public static void maxSalaryByDepartment(List<Employee> employees){
        System.out.println("Max salary by department:");
        employees
                .stream().collect(Collectors.groupingBy(Employee::getDepartment))
                        .forEach((department, employees1) -> {
                            Employee max = employees1.stream().reduce((employee, employee2) -> employee.getSalary(
                                    ) > employee2.getSalary() ? employee : employee2).get();
                            System.out.println("The employee who has the max salary of " + department + " is: " + max.getName() +
                                    " " + max.getLastname() + " with " + max.getSalary());

                        });
        System.out.println();
    }

    // This method prints the name, lastname and salary of the employee who has the min salary by department
    public static void minSalaryByDepartment(List<Employee> employees){
        System.out.println("Min salary by department:");
        employees
                .stream().collect(Collectors.groupingBy(Employee::getDepartment))
                .forEach((department, employees1) -> {
                    Employee min = employees1.stream().reduce((employee, employee2) -> employee.getSalary(
                    ) < employee2.getSalary() ? employee : employee2).get();
                    System.out.println("The employee who has the min salary of " + department + " is: " + min.getName() +
                            " " + min.getLastname() + " with " + min.getSalary());

                });
        System.out.println();
    }

    // This method prints the name, lastname and salary of the employee who has the max salary of all the employees
    public static void maxSalary(List<Employee> employees){
        // Employee max = employees.stream().reduce((employee, employee2) -> employee.getSalary() > employee2.getSalary() ? employee : employee2).get();
        Employee max = employees.stream().max((employee, employee2) -> Double.compare(employee.getSalary(), employee2.getSalary())).get();
        System.out.println("The employee who has the highest salary of everyone is: " + max.getName() + " " + max.getLastname() + " with " + max.getSalary());

        System.out.println();
    }

    // This method prints the name, lastname and salary of the employee who has the min salary of all the employees
    public static void minSalary(List<Employee> employees){
        //Employee min = employees.stream().reduce((employee, employee2) -> employee.getSalary() < employee2.getSalary() ? employee : employee2).get();
        Employee min = employees.stream().min((employee, employee2) -> Double.compare(employee.getSalary(), employee2.getSalary())).get();
        System.out.println("The employee who has the lowest salary of everyone is: " + min.getName() + " " + min.getLastname() + " with " + min.getSalary());

        System.out.println();
    }

    // This method prints the average salary of all the employees
    public static void salaryAverage(List<Employee> employees){
        System.out.println("Average salary of all employees: " + employees.stream().mapToDouble(Employee::getSalary).average().getAsDouble());

        System.out.println();
    }

    // This method prints the average salary by department
    public static void salaryAverageByDepartment(List<Employee> employees){
        System.out.println("Average salary by department:");
        employees
                .stream().collect(Collectors.groupingBy(Employee::getDepartment))
                .forEach((department, employees1) -> {
                    System.out.println(department + " has an average salary of " + employees1.stream().mapToDouble(Employee::getSalary).average().getAsDouble());

                });
        System.out.println();
    }

    // This method prints the sum of all the salaries
    public static void totalSalary(List<Employee> employees){
        System.out.println("Total salary of all employees: " + employees.stream().mapToDouble(Employee::getSalary).sum());

        System.out.println();
    }
}
