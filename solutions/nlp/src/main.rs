fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let m: i32 = s.next().unwrap().parse().unwrap();
    let mut dict = std::collections::HashMap::new();
    for _ in 0..n{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let a: String = s.next().unwrap().parse().unwrap();
        let b: i32 = s.next().unwrap().parse().unwrap();
        dict.insert(a, b);
    }
    for _ in 0..m{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let s = input.split('{');
        for i in s.into_iter(){
            let mut j = i.split('}');
            let k = j.next().unwrap();
            if let Some(cont) = j.next(){
                print!("{}{}",dict.get(k).unwrap(), cont);
            }else{
                print!("{}",k);
            }
        }
    }
}
