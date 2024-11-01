fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.trim().to_string();
    let n = s.len();
    let chars: Vec<char> = s.chars().collect();
    for l in 0..n {
        for r in l..n {
            let mut temp = chars.clone();
            temp[l..=r].reverse();
            let candidate: String = temp.into_iter().collect();
            if candidate < s {
                s = candidate;
            }
        }
    }
    println!("{}", s);
}
