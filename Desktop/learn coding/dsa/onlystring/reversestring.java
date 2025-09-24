public class reversestring
{
    public static reverse1(String s)
    {
        char [] arr = s.toCharArray();
        int left =0,right = s.length()-1;
        while(left<right)
        {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        return new string(arr);
    }
    public static void main(String[] args) {
        int str = "this";
        System.out.println(reverse1(str));
    }
}