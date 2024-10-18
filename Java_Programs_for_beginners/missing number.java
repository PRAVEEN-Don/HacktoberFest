class ListNode {
    int val;
    ListNode next;
    
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class MissingNumberInLinkedList {

    public static int findMissingNumber(ListNode head, int n) {
        boolean[] found = new boolean[n + 1]; // Create an array to track found numbers
        
        ListNode current = head;
        while (current != null) {
            found[current.val] = true; // Mark the number as found
            current = current.next; // Move to the next node
        }
        
        // Find the missing number
        for (int i = 1; i <= n; i++) {
            if (!found[i]) {
                return i; // Return the missing number
            }
        }
        
        return -1; // If no number is missing (should not happen based on the problem)
    }

    public static void main(String[] args) {
        // Creating a sample linked list: 1 -> 2 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(4);
        head.next.next.next = new ListNode(5);
        
        int n = 5; // Assuming numbers are from 1 to 5
        int missingNumber = findMissingNumber(head, n);
        
        if (missingNumber != -1) {
            System.out.println("The missing number is: " + missingNumber);
        } else {
            System.out.println("No missing number found.");
        }
    }
}
