fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let mut ans = String::new();
    let mut col = 1;
    let mut num = 0;
    for i in s.map(|x| x.parse::<i32>().unwrap()) {
        for _ in 0..i {
            ans.push_str(&(num%2).to_string());
            col += 1;
            if col == n+1{
                ans.push('\n');
                col = 1;
            }
        }
        num += 1;
    }
    println!("{}", ans);
}
