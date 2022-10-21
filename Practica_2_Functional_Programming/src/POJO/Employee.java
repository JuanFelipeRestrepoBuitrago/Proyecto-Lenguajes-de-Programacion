package POJO;

public class Employee {
    private int id;
    private String name;
    private String lastname;
    private double salary;
    private String department;

    public Employee(int id, String name, String lastname, double salary, String department) {
        this.id = id;
        this.name = name;
        this.lastname = lastname;
        this.salary = salary;
        this.department = department;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "Id='" + id +
                ", Name='" + name + '\'' +
                ", Lastname='" + lastname + '\'' +
                ", Salary=" + salary +
                ", Department='" + department + '\'' +
                '}';
    }
}
