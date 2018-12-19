import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int N = 105;

		PriorityQueue<BigInteger> inc = new PriorityQueue<BigInteger>();
		//优先队列默认小的优先 是增序队列
		PriorityQueue<BigInteger> dec = new PriorityQueue<BigInteger>(N,
				new Comparator<BigInteger>() {
					public int compare(BigInteger o1, BigInteger o2) {
						return -o1.compareTo(o2);
					}
				}); //匿名实现Comparator接口  降序大的优先

		int n, k;
		BigInteger a, b, one = BigInteger.ONE;
		List<BigInteger> list = new ArrayList<BigInteger>();

		while (in.hasNext()) {
			n = in.nextInt();
			k = in.nextInt();

			list.clear();
			for (int i = 0; i < n; ++i) {
				a = in.nextBigInteger();
				list.add(a);
			}

			inc.addAll(list);
			while (inc.size() > 1) {
				a = inc.poll();
				b = inc.poll();
				inc.add(a.multiply(b).add(one));
			}

			dec.addAll(list);
			while (dec.size() > 1) {
				a = one;
				for (int i = 0; i < k; ++i)
					if (dec.size() > 0)
						a = a.multiply(dec.poll());
				a = a.add(one);
				dec.add(a);
			}
			System.out.println(inc.poll().subtract(dec.poll()));
		}

		in.close();
	}
}
