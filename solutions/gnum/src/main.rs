use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let x: i32 = input.trim().parse().unwrap();
    let cond1 = x % 2 == 0;
    let cond2 = x >= 4 && x <= 12;
    println!("{} {} {} {}", (cond1 && cond2) as i32, (cond1 || cond2) as i32, (cond1 ^ cond2) as i32, (!(cond2&& cond2)) as i32);
}
