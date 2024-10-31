fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: f32 = input.trim().parse().unwrap();
    let mut steps = 0;
    let mut dist: f32 = 0.0;
    let mut next_dist: f32 = 2.0;
    while dist < n {
        steps += 1;
        dist += next_dist;
        next_dist *= 0.98;
    }
    println!("{}", steps);
}
