import java.util.Scanner;
import java.io.PrintStream;

class Main
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		double pi = 3.14159;
		double a = scan.nextDouble();

		double area = pi * a * a;

		System.out.format("A=%.4f\n",area);
	}
}