fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let mut ans = String::new();
    let mut col = 0;
    let mut row = 0;
    for i in s.map(|x| x.parse::<i32>().unwrap()) {
        
    }
}
