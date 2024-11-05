fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: usize = s.next().unwrap().parse().unwrap();
    let mut a = vec![];
    for _ in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let s: Vec<i32> = input.split_whitespace().into_iter().map(|x| x.parse::<i32>().unwrap()).collect();
        a.push(s.clone());
    }
    for i in 0..n{
        let mut flag = false;
        for j in 0..n {
            if cmp_vec(&a[j],&a[i]) {
                println!("{}", j+1);
                flag = true;
                break;
            }
        }
        if !flag {
            println!("0");
        }
    }
}

fn cmp_vec(a: &Vec<i32>, b: &Vec<i32>) -> bool {
    for i in 0..a.len() {
        if a[i] <= b[i] {
            return false;
        }
    }
    true
}