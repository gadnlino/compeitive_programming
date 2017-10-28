import java.util.Scanner;
import java.util.Locale;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		//Locale.SetDefault("en");

		double pi = 3.14159;

		double raio = scan.nextDouble();

		double area = raio * raio * pi;

		System.out.formar("A=" + area + "\n");
	}

}
