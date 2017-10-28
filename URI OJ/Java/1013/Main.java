import java.util.Scanner;
import java.lang.*;

class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();

		int maior = (a + b + Math.abs(a-b)) / 2;
		maior = (c + maior + Math.abs(maior - c)) / 2;

		System.out.println(maior + " eh o maior");
	}
}