fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let q: i32 = s.next().unwrap().parse().unwrap();
    let mut goods: Vec<i32> = vec![];
    for _ in 0..n{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let s: i32 = input.trim().parse().unwrap();
        goods.append(&mut vec![s]);
    }
    for _ in 0..q{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let len: u32 = s.next().unwrap().parse().unwrap();
        let factor = 10_i32.pow(len);
        let code: i32 = s.next().unwrap().parse().unwrap();
        let mut v: Vec<i32> = vec![];
        for i in goods.iter(){
            if i % factor == code{
                v.append(&mut vec![*i]);
            }
        }
        v.sort();
        println!("{}",match v[..]{
            [] => -1,
            _ => v[0]
        });
    }

}
