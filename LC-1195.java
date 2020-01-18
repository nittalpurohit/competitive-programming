class FizzBuzz {
    private int n;
    public volatile int cnt=1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        for(int i=1;i<=n;)
        {
            if(i%3==0 && i%5!=0 && cnt==i)
            {
                //synchronized(this)
                {
                    cnt++;
                    printFizz.run();
                    notifyAll();
                    i++;
                }
            }
            else
            {
                wait();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        for(int i=1;i<=n;)
        {
            if(i%3!=0 && i%5==0 && cnt==i)
            {
                //synchronized(this)
                {
                    cnt++;
                    printBuzz.run();
                    notifyAll();
                    i++;
                }
            }
            else
            {
                wait();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i=1;i<=n;)
        {
            if(i%3==0 && i%5==0 && cnt==i)
            {
                //synchronized(this)
                {
                    cnt++;
                    printFizzBuzz.run();
                    notifyAll();
                    i++;
                }
            }
            else
            {
                wait();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;)
        {
            if(i%3!=0 && i%5!=0 && cnt==i)
            {
                synchronized(this)
                {
                    cnt++;
                    printNumber.accept(i);
                    notifyAll();
                    i++;
                }
            }
            else
            {
                wait();
            }
        }
    }
}
