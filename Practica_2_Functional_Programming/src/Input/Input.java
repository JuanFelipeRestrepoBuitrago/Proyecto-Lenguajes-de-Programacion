package Input;

import java.util.Scanner;

public class Input {
    public static double[] getSalaryRange(){
        Scanner scanner = new Scanner(System.in);
        double[] salaryRange = new double[2];

        System.out.println("Enter the minimum salary: ");
        salaryRange[0] = scanner.nextDouble();

        System.out.println("Enter the maximum salary: ");
        salaryRange[1] = scanner.nextDouble();

        return salaryRange;
    }
}
