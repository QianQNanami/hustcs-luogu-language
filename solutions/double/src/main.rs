use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n: i32 = input.trim().parse().unwrap();
    let mut cnt=0;
    while n > 1{
        n /= 2;
        cnt += 1;
    }
    println!("{}", cnt+1);
}
