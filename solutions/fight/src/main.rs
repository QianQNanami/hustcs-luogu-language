fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i64 = input.trim().parse().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut v = input
        .split_whitespace()
        .map(|x| x.parse::<i64>().unwrap())
        .collect::<Vec<i64>>();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let mut m: i64 = s.next().unwrap().parse().unwrap();
    m -= 1;
    let p1: usize = s.next().unwrap().parse().unwrap();
    let s1: i64 = s.next().unwrap().parse().unwrap();
    let s2: i64 = s.next().unwrap().parse().unwrap();
    let mut sum_b: i64 = 0;
    let mut sum_h: i64 = 0;
    v[p1 - 1] += s1;
    for i in 0..m {
        sum_b += v[i as usize] * (m-i);
    }
    for i in m+1..n{
        sum_h += v[i as usize] * (i-m);
    }
    let diff_orig = sum_b - sum_h;
    let mut num = m+1;
    let mut diff = diff_orig.abs();
    for i in 0..m{
        let diff_new = (s2 * (m-i) + diff_orig).abs();
        if diff_new < diff{
            diff = diff_new;
            num = i+1;
        }
    }
    for i in m+1..n{
        let diff_new = (s2* (i-m) - diff_orig).abs();
        if diff_new < diff{
            diff = diff_new;
            num = i+1;
        }
    }
    println!("{}", num);
}
