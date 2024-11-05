fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    let mut primes = std::collections::HashSet::new();
    primes.insert(2);
    for _ in 0..n{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.trim().split_whitespace();
        let a: i64 = input.next().unwrap().parse().unwrap();
        let b: i64 = input.next().unwrap().parse().unwrap();
        let factors = prime_factors(a, &mut primes, b);
        let mut ans=1;
        //println!("{:?}", factors);
        for factor in factors{
            if factor[1] >=b{
                ans *= factor[0].pow(factor[1] as u32);
            }
        }
        println!("{}", ans);
    }
}

fn is_prime(n: i64) -> bool {
    if n < 2 {
        return false;
    }
    for i in 2..(n as f64).sqrt() as i64 + 1 {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn prime_factors(n: i64, prime_table:&mut std::collections::HashSet<i64>, a: i64) -> Vec<[i64; 2]> {
    let mut factors = Vec::new();
    let mut num = n;
    for i in 2..n/2 {
        if num==1{
            break;
        }
        if i.pow(a as u32) > n {
            break;
        }
        if is_prime(i) {
            prime_table.insert(i);
        }
        if prime_table.contains(&i) && num % i == 0 {
            let mut count = 0;
            while num % i == 0 {
                num /= i;
                count += 1;
            }
            factors.push([i, count]);
        }
    }
    factors
}
