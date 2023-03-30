import java.util.*;

public class Sieve
{
	static void sieve1(int sz)
	{
		List<Boolean> isprime = new ArrayList<>();

		isprime.add(false);
		for (int i=1; i<=sz; i++)
			isprime.add(true);

		for (int i=2; i<sz; i++)
		{
			if (isprime.get(i))
			{
				for (int j=2*i; j<=sz; j+=i)
					isprime.set(j,false);
			}
		}

		List<Integer> primes = new LinkedList<>();
		for (int i=1; i<=sz; i++)
		{
			if (isprime.get(i))
				primes.add(i);
		}
		System.out.println(primes.get(primes.size()-1));
	}

	static void sieve2(int sz)
	{
		List<Boolean> isprime = new LinkedList<>();

		isprime.add(false);
		for (int i=1; i<=sz; i++)
			isprime.add(true);

		for (int i=2; i<sz; i++)
		{
			if (isprime.get(i))
			{
				for (int j=2*i; j<=sz; j+=i)
					isprime.set(j,false);
			}
		}

		List<Integer> primes = new LinkedList<>();
		int i=0;
		for (Boolean f : isprime)
		{
			if (f)
				primes.add(i);
			i++;
		}
		System.out.println(primes.get(primes.size()-1));
	}

	static void sieve3(int sz)
	{
		List<Integer> all = new LinkedList<>();

		for (int i=2; i<=sz; i++)
			all.add(i);

		int idx = 0;
		for (ListIterator<Integer> p=all.listIterator(); p.hasNext(); )
		{
			Integer i = p.next();
			// This wont work :))
			for (ListIterator<Integer> m=p; m.hasNext(); )
			{
				Integer j = m.next();
				if ((j%i)==0)
					m.remove();
			}
		}

		List<Integer> primes = new LinkedList<>();
		primes.add(1);
		for (int i : all)
			primes.add(i);

		System.out.println(primes.get(primes.size()-1));
	}

	public static long timer()
	{
		return System.nanoTime()/1000;
	}

	public static void main(String[] argv)
	{
		int size = 100;

		if (argv.length > 0)
			size = Integer.parseInt(argv[0]);

		long t0,t1;
		float elapsed;

		t0 = timer();
		sieve1(size);
		t1 = timer();
		elapsed = (float)(t1-t0)/1000.0f;
		System.out.println("Test 1: "+elapsed+" ms");

		//t0 = timer();
		//sieve2(size);
		//t1 = timer();
		//elapsed = (float)(t1-t0)/1000.0f;
		//System.out.println("Test 2: "+elapsed+" ms");

		// OJO: Incorrecto
		t0 = timer();
		sieve3(size);
		t1 = timer();
		elapsed = (float)(t1-t0)/1000.0f;
		System.out.println("Test 3: "+elapsed+" ms");
	}
}
