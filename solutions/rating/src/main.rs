fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    let mut v = Vec::new();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let s = input.split_whitespace();
    for i in s.into_iter() {
        let num: i32 = i.parse().unwrap();
        v.push(num);
    }
    v.sort();
    let mut sum = 0.0;
    for i in v[1..n as usize -1].iter() {
        sum += *i as f64;
    }
    println!("{:.2}", sum / (n as f64 - 2.0));
}
