import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class MissingSieveOfEratosthenes {

    // Function to generate all prime numbers up to n using the Sieve of Eratosthenes
    public static List<Integer> sieveOfEratosthenes(int n) {
        boolean[] isPrime = new boolean[n + 1];
        List<Integer> primes = new ArrayList<>();

        // Initialize all entries as true
        for (int i = 2; i <= n; i++) {
            isPrime[i] = true;
        }

        // Mark non-prime numbers
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        // Collecting all prime numbers
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.add(i);
            }
        }

        return primes;
    }

    // Function to find missing prime numbers from the given list
    public static List<Integer> findMissingPrimes(List<Integer> primes, List<Integer> givenNumbers) {
        Set<Integer> givenSet = new HashSet<>(givenNumbers);
        List<Integer> missingPrimes = new ArrayList<>();

        for (Integer prime : primes) {
            if (!givenSet.contains(prime)) {
                missingPrimes.add(prime);
            }
        }

        return missingPrimes;
    }

    public static void main(String[] args) {
        int limit = 20; // Limit for finding primes
        List<Integer> givenNumbers = List.of(2, 3, 5, 7, 11, 13, 17, 19); // Example input list

        // Generate primes up to the limit
        List<Integer> primes = sieveOfEratosthenes(limit);
        System.out.println("Generated Primes: " + primes);

        // Find missing primes
        List<Integer> missingPrimes = findMissingPrimes(primes, givenNumbers);
        if (missingPrimes.isEmpty()) {
            System.out.println("No missing prime numbers.");
        } else {
            System.out.println("Missing prime numbers: " + missingPrimes);
        }
    }
}
