import FileHandling.Read;
import Input.Input;
import POJO.Employee;
import Processing.ProcessEmployees;

import java.io.IOException;
import java.util.List;

public class Test {
    public static void test1() {
        System.out.println("Test 1");
        try {
            List<Employee> employees = Read.read();

            ProcessEmployees.printEmployees(employees);

            double[] salaryRange = Input.getSalaryRange();
            ProcessEmployees.printSalaryRange(employees, salaryRange[0], salaryRange[1]);

            ProcessEmployees.printAllDepartmentEmployees(employees);

            ProcessEmployees.amountByDepartment(employees);

            ProcessEmployees.salaryByDepartment(employees);

            ProcessEmployees.maxSalaryByDepartment(employees);

            ProcessEmployees.minSalaryByDepartment(employees);

            ProcessEmployees.maxSalary(employees);

            ProcessEmployees.minSalary(employees);

            ProcessEmployees.salaryAverage(employees);

            ProcessEmployees.salaryAverageByDepartment(employees);

            ProcessEmployees.totalSalary(employees);


        } catch (IOException e) {
            System.out.println("Error reading file");
        }
    }
}
