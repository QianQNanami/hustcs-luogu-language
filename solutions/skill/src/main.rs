fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: i32 = s.next().unwrap().parse().unwrap();
    let mut m: i32 = s.next().unwrap().parse().unwrap();
    let k: i32 = s.next().unwrap().parse().unwrap();
    let mut h = std::collections::BinaryHeap::new();
    for _ in 0..n{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let time: i32 = s.next().unwrap().parse().unwrap();
        let pts: i32 = s.next().unwrap().parse().unwrap();
        h.push(Skill{time, pts});
    }
    loop{
        let mut s = h.pop().unwrap();
        if s.time == k || s.pts > m || m==0{
            h.push(s);
            break;
        }
        m -= s.pts;
        s.time -= 1;
        h.push(s);
    }
    println!("{}", h.peek().unwrap().time);
}


#[derive(PartialEq, Eq, Debug)]
struct Skill{
    time: i32,
    pts: i32,
}

impl std::cmp::Ord for Skill {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.time.cmp(&other.time)
    }
}

impl std::cmp::PartialOrd for Skill {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

