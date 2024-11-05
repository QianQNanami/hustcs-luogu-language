fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut s = input.split_whitespace();
    let n: usize = s.next().unwrap().parse().unwrap();
    let m: usize = s.next().unwrap().parse().unwrap();
    let mut rotate_list = vec![0];
    let mut stretch_list = vec![0];
    let mut rotate_cnt = 0;
    let mut stretch_cnt = 0;
    let mut rotate = vec![0.0];
    let mut stretch = vec![1.0];
    for _ in 1..=n{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let op: usize = s.next().unwrap().parse().unwrap();
        let num: f64 = s.next().unwrap().parse().unwrap();
        match op{
            1 => {
                stretch.push(num * stretch.last().unwrap());
                stretch_cnt += 1;
                
            },
            2 => {
                rotate.push(num + rotate.last().unwrap());
                rotate_cnt += 1;
            },
            _ => (),
        }
        stretch_list.push(stretch_cnt);
        rotate_list.push(rotate_cnt);
    }
    for _ in 0..m{
        input.clear();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut s = input.split_whitespace();
        let i: usize = s.next().unwrap().parse().unwrap();
        let j: usize = s.next().unwrap().parse().unwrap();
        let x: f64 = s.next().unwrap().parse().unwrap();
        let y: f64 = s.next().unwrap().parse().unwrap();
        let rotate_begin: usize = rotate_list[i - 1];
        let rotate_end: usize = rotate_list[j];
        let stretch_begin: usize = stretch_list[i - 1];
        let stretch_end: usize = stretch_list[j];
        let rot = rotate[rotate_end] - rotate[rotate_begin];
        let stre = stretch[stretch_end] / stretch[stretch_begin];
        let mut ans_x = x * rot.cos() - y * rot.sin(); 
        let mut ans_y = x * rot.sin() + y * rot.cos();
        ans_x *= stre;
        ans_y *= stre;
        println!("{:.2} {:.2}", ans_x, ans_y);
    }
}



