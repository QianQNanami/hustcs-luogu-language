fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: usize = s.next().unwrap().parse().unwrap();
    let m: i64 = s.next().unwrap().parse().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let s = input.split_whitespace();
    let mut c = vec![1];
    for i in s {
        let t: i64 = i.parse().unwrap();
        c.push(t*c.last().unwrap());
    }
    let mut b = vec![m%c[1]];
    for i in 2..=n{
        b.push((m%c[i] - m%c[i-1])/c[i-1]);
    }
    for i in b{
        print!("{} ", i);
    }
}
