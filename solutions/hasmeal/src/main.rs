fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let a: f32 = input.next().unwrap().parse().unwrap();
    let b: f32 = input.next().unwrap().parse().unwrap();
    let tot: f32 = a + b*0.1;
    println!("{}", (tot/1.9).floor() as i32);
}
