fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut a: Vec<i32> = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    a.sort();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut b: Vec<i32> = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    b.sort();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut c: Vec<i32> = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    c.sort();
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut d: Vec<i32> = input.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    d.sort();
    let mut ans = 0;
    for &i in &[&a, &b, &c, &d] {
        let t = dfs(&mut i.to_vec(), &mut vec![], &mut vec![]);
        ans += (i.iter().sum::<i32>() - t)/2 + t;
    }
    println!("{}", ans);
}

fn dfs(i: &mut Vec<i32>, g: &mut Vec<i32>, l: &mut Vec<i32>) -> i32 {
    if i.len() == 0 {
        return (g.iter().sum::<i32>() - l.iter().sum::<i32>()).abs();
    }
    let a = i.pop().unwrap();
    g.push(a);
    let mut ans = dfs(i, g, l);
    g.pop();
    l.push(a);
    ans = std::cmp::min(ans, dfs(i, g, l));
    l.pop();
    i.push(a);
    ans
}