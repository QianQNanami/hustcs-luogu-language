fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let n: i32 = input.next().unwrap().parse().unwrap();
    let x: &str = input.next().unwrap();
    let mut sum = 0;
    for i in 1..=n {
        let mut ch = i.to_string();
        while ch.contains(x) {
            sum += 1;
            ch = ch.replacen(x, "", 1);
        }
    }
    println!("{}", sum);
}
