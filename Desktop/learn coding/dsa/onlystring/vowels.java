public class vowels
{
    public static void counts(String s)
    {
        s = s.toLowerCase();
        int vowels = 0,consonents = 0;

        for(int i = 0;i<s.length();i++)
        {
            char ch = s.charAt(i);
            if(ch>= 'a' && ch <= 'z')
            {
                if("aeiou".indexOf(ch) != -1)
                {
                    vowels++;
                }
                else{
                    consonents++;
                }
            }
        }
        
        System.out.println("Vowels: " + vowels);
        System.out.println("Consonants: " + consonants);
    }
   public static void main(String args[])
   {
       String s = "hello world";
        countVC(s);
   }
}