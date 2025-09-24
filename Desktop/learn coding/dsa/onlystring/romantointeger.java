import java.util.HashMap;

class romantointeger{

    public static void main(String[] args)
    {
        String str = "MCMXCIV";
        System.out.println(romanToInt(str)); 
    }
    public static  int romanToInt(String s)
    {
        HashMap<Character,Integer> roman = new HashMap<>();
        roman.put('I',1);
        roman.put('V',5);
        roman.put('X',10);
        roman.put('L',50);
        roman.put('C',100);
        roman.put('D',500);
        roman.put('M',1000);

        int result = 0;

        for(int i =0;i<s.length();i++)
        {
            int curr = roman.get(s.charAt(i));
            if(i + 1 < s.length() && curr < roman.get(s.charAt(i+1)))
            {
                result -=curr;
            }
            else{
                result += curr;
            }
        }
        return result;
    }
}