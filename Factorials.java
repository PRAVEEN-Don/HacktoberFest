import java.util.Scanner;

public class Factorials {

    // Recursive method to calculate factorial
    public static long factorialRecursive(int n) {
        if (n == 0) {
            return 1; // Base case: 0! = 1
        }
        return n * factorialRecursive(n - 1); // Recursive case
    }

    // Iterative method to calculate factorial
    public static long factorialIterative(int n) {
        long result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i; // Multiply result by the current number
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a non-negative integer: ");
        int number = scanner.nextInt();

        if (number < 0) {
            System.out.println("Factorial is not defined for negative numbers.");
        } else {
            // Calculate factorial using both methods
            long recursiveResult = factorialRecursive(number);
            long iterativeResult = factorialIterative(number);

            // Display the results
            System.out.println("Factorial of " + number + " (using recursion): " + recursiveResult);
            System.out.println("Factorial of " + number + " (using iteration): " + iterativeResult);
        }

        scanner.close(); // Close the scanner to avoid resource leaks
    }
}
