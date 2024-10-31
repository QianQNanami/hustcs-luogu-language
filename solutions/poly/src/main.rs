fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: u64 = input.trim().parse().unwrap();
    let mut cnt = 0;
    let mut sum: u64 = 0;
    let mut i: u64 = 2;
    loop {
        if is_prime(i) {
            sum += i;
            if sum > n {
                break;
            }
            println!("{}", i);
            cnt += 1;
        }

        i += 1;
    }
    println!("{}", cnt);
}
fn is_prime(n: u64) -> bool {
    if n <= 1 {
        return false;
    }
    let x = n as f64;
    for i in 2..=x.sqrt() as u64{
        if n % i == 0 {
            return false;
        }
    }
    true
}