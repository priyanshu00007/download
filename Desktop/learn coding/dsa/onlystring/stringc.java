import java.util.Arrays;

public class stringc{
    public static void main(String [] args)
    {
        String s1 = "Hello world";
        String s2 = "hello";

        System.out.println("charAt(1) is "+ s1.charAt(1));
        System.out.println("indexof " + s1.indexOf('o'));
        System.out.println("substring "+s1.substring(2,6));
        System.out.println("toLowercase "+s1.toLowerCase());
         System.out.println("toUpperCase: " + s2.toUpperCase());
        System.out.println("contains(\"World\"): " + s1.contains("World"));
        System.out.println("start with" + s1.toLowerCase().startsWith("hello"));
        System.out.println("endsWith(\"ld  \"): " + s2.endsWith("ld  "));
         System.out.println("equals(s2): " + s1.equals(s2));
        System.out.println("equalsIgnoreCase(s2): " + s1.trim().equalsIgnoreCase(s2));

        // 8. replace / replaceAll
        System.out.println("replace('o','0'): " + s2.replace('o', '0'));
        System.out.println("replaceAll(\"l\",\"x\"): " + s2.replaceAll("l", "x"));
         
        String fruits = "apple,banana,orange";
        String[] arr = fruits.split(",");
        System.out.println("split by , : " + Arrays.toString(arr));

        // 10. trim
        System.out.println("trim(): '" + s1.trim() + "'");
         String emptyStr = "";
        String blankStr = "   ";
        System.out.println("isEmpty: " + emptyStr.isEmpty());
        System.out.println("isBlank: " + blankStr.isBlank());

        // 12. compareTo
        System.out.println("compareTo(\"World\"): " + s2.compareTo("World"));

        // 13. repeat
        System.out.println("repeat 3 times: " + "ha".repeat(3));

        // 14. matches
        System.out.println("\"12345\" matches digits: " + "12345".matches("\\d+"));
        System.out.println("\"abc123\" matches digits: " + "abc123".matches("\\d+"));
    }    

} 