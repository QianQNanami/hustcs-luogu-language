fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let m: i32 = s.next().unwrap().parse().unwrap();
    let mut delta = [0,0];
    for _ in 0..n{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let a: i32 = s.next().unwrap().parse().unwrap();
        let b: i32 = s.next().unwrap().parse().unwrap();
        delta[0] += a;
        delta[1] += b;
    }
    for _ in 0..m{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let c: i32 = s.next().unwrap().parse().unwrap();
        let d: i32 = s.next().unwrap().parse().unwrap();
        println!("{} {}", c + delta[0], d + delta[1]);
    }
}
