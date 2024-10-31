fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let a: f32 = s.next().unwrap().parse().unwrap();
    let b: f32 = s.next().unwrap().parse().unwrap();
    let c: f32 = s.next().unwrap().parse().unwrap();
    println!("{}", (a*0.2 + b*0.3 + c*0.5) as i32);
}
