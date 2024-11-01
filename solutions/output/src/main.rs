fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: u32 = input.trim().parse().unwrap();
    let ans = to_pow(n);
    println!("{}", ans);
}

fn to_pow(n: u32) -> String {
    let mut num: u32 = n;
    let mut v = Vec::new();
    let mut pow = 0;
    while num > 0 {
        if num & 1 == 1 {
            v.push(pow);
        }
        num >>= 1;
        pow += 1;
    }
    v.reverse();
    to_str(&v)
}

fn to_str(v: &[u32]) -> String {
    let mut result = String::new();
    for &component in v.iter() {
        if component == 1 {
            result.push_str("2");
        } else if component > 1 {
            result.push_str(&format!("2({})", to_pow(component)));
        } else {
            result.push_str("2(0)");
        }
        result.push('+');
    }
    result.pop();
    result
}
