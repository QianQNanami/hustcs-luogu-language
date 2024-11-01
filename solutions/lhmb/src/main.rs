fn main() {
    let mut input = String::new();  
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let _n: i32 = s.next().unwrap().parse().unwrap();
    let k: i32 = s.next().unwrap().parse().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut v = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    v.sort();
    v.dedup();
    if v.len() < k as usize {
        println!("NO RESULT");
    } else {
        println!("{}", v[k as usize -1]);
    }
}
