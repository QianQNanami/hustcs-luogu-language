fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let s = input.split_whitespace();
    let mut v = Vec::new();
    for i in s.into_iter() {
        v.push(i.parse::<i32>().unwrap());
    }
    v.sort();
    for i in v.iter() {
        print!("{} ", i);
    }
}
