#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Number of cities
#define MAX 20

int n; // Number of cities
int dist[MAX][MAX]; // Distance matrix
int dp[1 << MAX][MAX]; // DP table for memoization

// Function to find the minimum cost using TSP dynamic programming
int tsp(int mask, int pos) {
    // If all cities have been visited, return to starting city
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // If already computed, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int answer = INT_MAX; // Initialize answer

    // Try to go to every other city
    for (int city = 0; city < n; city++) {
        // If the city is not visited yet
        if ((mask & (1 << city)) == 0) {
            int newAnswer = dist[pos][city] + tsp(mask | (1 << city), city);
            answer = min(answer, newAnswer); // Update the minimum answer
        }
    }

    return dp[mask][pos] = answer; // Store the result in the DP table
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter distance matrix (0 if same city):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Initialize the DP table with -1
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    int result = tsp(1, 0); // Start the TSP with the first city visited
    cout << "The minimum cost of visiting all cities is: " << result << endl;

    return 0;
}
