use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    println!{"{}", if n*5 > n*3 + 11{"Luogu"}else{"Local"}};
}
