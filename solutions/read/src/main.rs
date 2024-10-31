fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let m: usize = s.next().unwrap().parse().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let s = input.split_whitespace();
    let mut note = [-1;100];
    let mut cur = 0;
    let mut cnt = 0;
    for i in s.into_iter() {
        let i: i32 = i.parse().unwrap();
        let mut flag = false;
        for j in note.iter() {
            if j == &i {
                flag = true;
                break;
            }
        }
        if !flag {
            note[cur] = i;
            cur = (cur + 1) % m;
            cnt += 1;
        }
    }
    println!("{}", cnt);
}
