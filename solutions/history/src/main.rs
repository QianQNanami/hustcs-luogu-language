fn main() {
    let mut s = String::new();
    let mut t = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    std::io::stdin().read_line(&mut t).unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let q = input.trim().parse::<i32>().unwrap();
    for _ in 0..q {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.trim().split_whitespace();
        let a: usize = iter.next().unwrap().parse().unwrap();
        let b: usize = iter.next().unwrap().parse().unwrap();
        let c: usize = iter.next().unwrap().parse().unwrap();
        let d: usize = iter.next().unwrap().parse().unwrap();
        let s = &s[a - 1..b];
        let t = &t[c - 1..d];
        if s < t {
            println!("yifusuyi");
        } else if s>t {
            println!("erfusuer");
        }else{
            println!("ovo");
        }
    }

}
