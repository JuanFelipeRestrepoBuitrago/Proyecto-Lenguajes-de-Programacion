package FileHandling;

import POJO.Employee;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Read {

    // This method reads the file and return a list of employees with the file data
    public static List<Employee> read() throws IOException{
        String fileName = "src\\FileHandling\\employees.csv";
        List<Employee> employees;

        Stream<String> lines = Files.lines(Path.of(fileName).toAbsolutePath());

        employees = lines
                .map(line -> line.split(";"))
                .map(data -> new Employee(Integer.parseInt(data[0]), data[1], data[2], Double.parseDouble(data[3]), data[4]))
                .collect(Collectors.toList());

        return employees;

    }
}
