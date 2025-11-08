// Leetcode Problem #125: Valid Palindrome

import java.util.Scanner;

public class PalindromeString {

    public static boolean solve(String s) {
        if(s == null || s.length() == 0) {
            return false;
        }

        s = s.toLowerCase();
        // System.out.println("s: " + s);

        int leftPtr = 0;
        int rightPtr = s.length() - 1;

        while(leftPtr < rightPtr) {
            // System.out.println("leftPtr: " + leftPtr + " | rightPtr: " + rightPtr);
            // System.out.println("charAtLeftPtr: " + s.charAt(leftPtr) + " | charAtRightPtr: " + s.charAt(rightPtr));
            
            if(!Character.isLetterOrDigit(s.charAt(leftPtr))) {
                leftPtr++;
            } else if(!Character.isLetterOrDigit(s.charAt(rightPtr))) {
                rightPtr--;
            } else if(s.charAt(leftPtr) == s.charAt(rightPtr)) {
                leftPtr++;
                rightPtr--;
            } else {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String input = " ";
        System.out.println(solve(input));
    }
}