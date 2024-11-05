fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let _n: i32 = s.next().unwrap().parse().unwrap();
    let m: i32 = s.next().unwrap().parse().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut v: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    v.sort();
    v.reverse();
    let mut t = m;
    let mut lev = 1;
    let mut flag = true;
    while let Some(x) = v.pop() {
        if lev <= x{
            t-=1;
        }else{
            flag = false;
            break;
        }
        if t==0{
            lev+=1;
            t = m;
        }
    }
    if flag {
        println!("Yes");
    } else {
        println!("No");
    }
}
