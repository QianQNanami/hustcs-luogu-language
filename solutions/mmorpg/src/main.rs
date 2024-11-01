use std::collections::HashSet;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let m: i32 = s.next().unwrap().parse().unwrap();
    let k: i32 = s.next().unwrap().parse().unwrap();
    let mut v: Vec<String> = Vec::new();
    for _ in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        v.push(input);
    }
    let mut v_exhaust: HashSet<String> = HashSet::new();
    for _ in 0..m {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        v_exhaust.insert(input);
    }
    for _ in 0..k{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        v.push(input);
    }
    v.sort();
    for i in &v{
        if !v_exhaust.contains(i){
            print!("{}", i);
        }
    }
}
