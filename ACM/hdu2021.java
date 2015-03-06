import java.util.Scanner;
public class Main{
public static void main(String args[]) 
{
    Scanner r = new Scanner(System.in);
    int value[] = {100, 50, 10, 5, 2, 1}, n;
    while(true)
    {
	n = r.nextInt();
	if(n == 0)
return;
        int ans = 0;
        while(n != 0)
        {
n--;
            int num = r.nextInt();
          //  scanf("%d", &num);
            for(int i = 0; i < 6; i++)
            {
                ans += num / value[i];
                num %= value[i];
            }    
        }
        System.out.println(ans);
    }
}
}
