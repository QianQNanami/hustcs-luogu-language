fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let b: i32 = s.next().unwrap().parse().unwrap();
    let mut v = Vec::new();
    for _ in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let h: i32 = input.trim().parse().unwrap();
        v.push(h);
    }
    v.sort();
    v.reverse();
    let mut cnt=0;
    let mut sum=0;
    loop{
        if sum>=b{
            break;
        }
        sum+=v[cnt];
        cnt+=1;
    }
    println!("{}",cnt);
}
