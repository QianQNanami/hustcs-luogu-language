use std::collections::BTreeSet;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut reader = stdin.lock().lines();
    
    if let Some(Ok(first_line)) = reader.next() {
        let mut s = first_line.split_whitespace();
        let n: i64 = s.next().unwrap().parse().unwrap();
        let q: i64 = s.next().unwrap().parse().unwrap();
        
        let mut v = Vec::new();
        for _ in 0..n {
            if let Some(Ok(line)) = reader.next() {
                let s: Vec<i64> = line.trim().split(&['x', '=']).filter_map(|x| x.parse::<i64>().ok()).collect();
                v.push((s[2] - s[1]) / s[0]);
            }
        }
        let ans = BTreeSet::from_iter(v);
        for _ in 0..q {
            if let Some(Ok(line)) = reader.next() {
                let mut s = line.trim().split_whitespace();
                if let (Some(Ok(l)), Some(Ok(r))) = (s.next().map(|x| x.parse::<i64>()), s.next().map(|x| x.parse::<i64>())) {
                    println!("{}", ans.range(l..=r).count());
                }
            }
        }
    }
}
