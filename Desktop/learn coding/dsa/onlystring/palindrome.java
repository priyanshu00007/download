public class palindrome
{
    public static boolean palin(String s)
    {
        int left = 0,right = s.length()-1;
        while(left<right)
        {
            if(s.charAt(left) != s.charAt(right))
            {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
   public static void main(String args[])
   {
        String s1 = "racecar";
        String s2 = "hello";
        
        System.out.println(s1 + " -> " + palin(s1)); // true
        System.out.println(s2 + " -> " + palin(s2)); // false
   }
}